/********************************************************
 * stat							*
 * 	Produce statistics about a program		*
 *							*
 * Usage:						*
 *	stat [options] <file-list>			*
 *							*
 ********************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <assert.h>

#include "ch_type.h"
#include "token.h"

/********************************************************
 * stat -- general purpose statistic			*
 *							*
 * Member functions:					*
 * 	take_token -- receives token and uses it to 	*
 *			compute statistic		*
 *	line_start -- output stat at the beginning of	*
 *			a line.				*
 *	eof 	-- output stat at the end of the file	*
 ********************************************************/
class a_stat {
    public:
	virtual void take_token(TOKEN_TYPE token) = 0;
	virtual void line_start() {};
	virtual void eof() {};
	// Default constructor
	// Default destructor
	// Copy constructor defaults as well (probably not used)
};

/********************************************************
 * line_counter -- handle line number / line count	*
 *		stat.					*
 *							*
 * Counts the number of T_NEW_LINE tokens seen and	*
 * output the current line number at the beginning	*
 * of the line.						*
 *							*
 * At EOF it will output the total number of lines	*
 ********************************************************/
class line_counter: public a_stat {
    private:
	int cur_line;	// Line number for the current line
    public:
	// Initialize the line counter -- to zero
	line_counter() { 
	    cur_line = 0; 
	};
	// Default destrctor
	// Default copy constructor (probably never called)

	// Consume tokens,  count the number of new line tokens
	void take_token(TOKEN_TYPE token) {
	    if (token == T_NEWLINE) 
		++cur_line;
	}

	// Output start of line statistics 
	// namely the current line number
	void line_start() {
	    std::cout << std::setw(4) << cur_line << ' ' << std::setw(0);
	}

	// Output eof statistics
	// namely the total number of lines
	void eof() {
	    std::cout << "Total number of lines: " << cur_line << '\n';
	}
};

/********************************************************
 * paren_count -- count the nesting level of ()		*
 *							*
 * Counts the number of T_L_PAREN vs T_R_PAREN tokens	*
 * and writes the current nesting level at the beginning*
 * of each line.					*
 *							*
 * Also keeps track of the maximum nesting level.	*
 ********************************************************/
class paren_counter: public a_stat {
    private:
	int cur_level;		// Current nesting level
	int max_level;		// Maximum nesting level
    public:
	// Initialize the counter
	paren_counter() { 
	    cur_level = 0; 
	    max_level = 0;
	};
	// Default destructor
	// Default copy constructor (probably never called)

	// Consume tokens,  count the nesting of () 
	void take_token(TOKEN_TYPE token) {
	    switch (token) {
		case T_L_PAREN:
		    ++cur_level;
		    if (cur_level > max_level)
			max_level = cur_level;
		    break;
		case T_R_PAREN:
		    --cur_level;
		    break;
		default:
		    // Ignore
		    break;
	    }
	}

	// Output start of line statistics 
	// namely the current line number
	void line_start() {
	    std::cout.setf(std::ios::left);
	    std::cout.width(2);

	    std::cout << '(' <<  cur_level << ' ';

	    std::cout.unsetf(std::ios::left);
	    std::cout.width();
	}

	// Output eof statistics
	// namely the total number of lines
	void eof() {
	    std::cout << "Maximum nesting of () : " << max_level << '\n';
	}
};

/********************************************************
 * brace_counter -- count the nesting level of {}	*
 *							*
 * Counts the number of T_L_CURLY vs T_R_CURLY tokens	*
 * and writes the current nesting level at the beginning*
 * of each line.					*
 *							*
 * Also keeps track of the maximum nesting level.	*
 *							*
 * Note: brace_counter and paren_counter should 	*
 * probably be combined.				*
 ********************************************************/
class brace_counter: public a_stat {
    private:
	int cur_level;		// Current nesting level
	int max_level;		// Maximum nesting level
    public:
	// Initialize the counter
	brace_counter() { 
	    cur_level = 0; 
	    max_level = 0;
	};
	// Default destructor
	// Default copy constructor (probably never called)

	// Consume tokens,  count the nesting of () 
	void take_token(TOKEN_TYPE token) {
	    switch (token) {
		case T_L_CURLY:
		    ++cur_level;
		    if (cur_level > max_level)
			max_level = cur_level;
		    break;
		case T_R_CURLY:
		    --cur_level;
		    break;
		default:
		    // Ignore
		    break;
	    }
	}

	// Output start of line statistics 
	// namely the current line number
	void line_start() {
	    std::cout.setf(std::ios::left);
	    std::cout.width(2);

	    std::cout << '{' <<  cur_level << ' ';

	    std::cout.unsetf(std::ios::left);
	    std::cout.width();
	}

	// Output eof statistics
	// namely the total number of lines
	void eof() {
	    std::cout << "Maximum nesting of {} : " << max_level << '\n';
	}
};

/********************************************************
 * comment_counter -- count the number of lines		*
 *	with and without comments.			*
 *							*
 * Outputs nothing at the beginning of each line, but	*
 * will output a ratio at the end of file		*
 *							*
 * Note: This class makes use of two bits:		*
 *	CF_COMMENT  -- a comment was seen		*
 *	CF_CODE     -- code was seen			*
 * to collect statistics.				*
 *							*
 * These are combined to form an index into the counter	*
 * array so the value of these two bits is very 	*
 * important.						*
 ********************************************************/
static const int CF_COMMENT = (1<<0);	// Line contains comment
static const int CF_CODE    = (1<<1);   // Line contains code
// These bits are combined to form the statistics
//
//   	0                  -- [0] Blank line
//	CF_COMMENT         -- [1] Comment only line
//	CF_CODE            -- [2] Code only line
//	CF_COMMENT|CF_CODE -- [3] Comments and code on this line

class comment_counter: public a_stat {
    private:
	int counters[4];	// Count of various types of stats.
	int flags;		// Flags for the current line
    public:
	// Initialize the counters
	comment_counter() { 
	    memset(counters, '\0', sizeof(counters));
	    flags = 0;
	};
	// Default destructor
	// Default copy constructor (probably never called)

	// Consume tokens,  count the nesting of () 
	void take_token(TOKEN_TYPE token) {
	    switch (token) {
		case T_COMMENT:
		    flags |= CF_COMMENT;
		    break;
		default:
		    flags |= CF_CODE;
		    break;
		case T_NEWLINE:
		    assert(flags >= 0);
		    assert(flags < sizeof(counters)/sizeof(counters[0]));
		    ++counters[flags];
		    flags = 0;
		    break;
	    }
	}

	// void line_start() -- defaults to base

	// Output eof statistics
	// namely the total number of lines
	void eof() {
	    std::cout << "Number of blank lines ................." <<   
	 	    counters[0] << '\n';
	    std::cout << "Number of comment only lines .........." << 
	            counters[1] << '\n';
	    std::cout << "Number of code only lines ............." << 
		    counters[2] << '\n';
	    std::cout << "Number of lines with code and comments " << 
		    counters[3] << '\n';
	    std::cout.setf(std::ios::fixed);
	    std::cout.precision(1);
	    std::cout << "Comment to code ratio " <<
	       float(counters[1] + counters[3]) /
	       float(counters[2] + counters[3]) * 100.0 << "%\n";
	}
};


static line_counter line_count;		// Counter of lines
static paren_counter paren_count;	// Counter of () levels
static brace_counter brace_count;	// Counter of {} levels
static comment_counter comment_count;	// Counter of comment info

// A list of the statistics we are collecting
static a_stat *stat_list[] = {
    &line_count,
    &paren_count,
    &brace_count,
    &comment_count,
    NULL
};


/********************************************************
 * do_file -- process a single file			*
 *							*
 * Parameters						*
 *	name -- the name of the file to process		*
 ********************************************************/
static void do_file(const char *const name)
{
    input_file in_file(name);	// File to read
    token token;		// Token reader/parser
    TOKEN_TYPE cur_token;	// Current token type
    class a_stat **cur_stat;	// Pointer to stat for collection/writing

    if (in_file.bad()) {
	std::cerr << "Error: Could not open file " << 
		name << " for reading\n";
	return;
    }
    while (true) {
	cur_token = token.next_token(in_file);
	for (cur_stat = stat_list; *cur_stat != NULL; ++cur_stat)
	   (*cur_stat)->take_token(cur_token);
#ifdef DEBUG
	assert(cur_token >= 0);
	assert(cur_token < sizeof(TOKEN_NAMES)/sizeof(TOKEN_NAMES[0]));
	std::cout << "   " << TOKEN_NAMES[cur_token] << '\n';
#endif /* DEBUG */

	switch (cur_token) {
	    case T_NEWLINE:
		for (cur_stat = stat_list; *cur_stat != NULL; ++cur_stat)
		    (*cur_stat)->line_start();
		in_file.flush_line();
		break;
	    case T_EOF:
		for (cur_stat = stat_list; *cur_stat != NULL; ++cur_stat)
		   (*cur_stat)->eof();
		return;
	    default:
		// Do nothing
		break;
	}
    }
}

int main(int argc, char *argv[])
{
    char *prog_name = argv[0];	// Name of the program

    if (argc == 1) {
	std::cerr << "Usage is " << prog_name << "[options] <file-list>\n";
	exit (8);
    }

    for (/* argc set */; argc > 1; --argc) {
       do_file(argv[1]);
       ++argv;
    }
    return (0);
}


/*** End of file ***/
