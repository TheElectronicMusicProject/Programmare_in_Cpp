#include <string>
#include <iostream>
/********************************************************
 * token -- token handling module			*
 *							*
 * Functions:						*
 *	next_token -- get the next token from the input	*
 ********************************************************/

/*
 * A list of tokens
 *	Note, how this list is used depends on defining the macro T.
 *	This macro is used for defining the tokens types themselves
 *	as well as the string version of the tokens.
 */
#define TOKEN_LIST \
   T(T_NUMBER),		/* Simple number (floating point or integer) */	\
   T(T_STRING),		/* String or character constant */ 		\
   T(T_COMMENT),	/* Comment */					\
   T(T_NEWLINE),	/* Newline character */				\
   T(T_OPERATOR),	/* Arithmetic operator */			\
   T(T_L_PAREN),	/* Character "(" */				\
   T(T_R_PAREN),	/* Character ")" */				\
   T(T_L_CURLY),	/* Character "{" */				\
   T(T_R_CURLY),	/* Character "}" */				\
   T(T_ID),		/* Identifier */				\
   T(T_EOF)		/* End of File */

/*
 * Define the enumerated list of tokens.  
 *	This makes use of a trick using the T macro
 *	and our TOKEN_LIST
 */
#define T(x) x		// Define T() as the name
enum TOKEN_TYPE {
   TOKEN_LIST
};
#undef T		// Remove old temporary macro

// A list of the names of the tokens
extern const char *const TOKEN_NAMES[];

/********************************************************
 * input_file -- data from the input file		*
 *							*
 * The current two characters are store in 		*
 *	cur_char and next_char				*
 *							*
 * The member function read_char moves eveyone up 	*
 * one character.					*
 *							*
 * The line is buffered and output everytime a newline	*
 * is passed.						*
 ********************************************************/
class input_file: public std::ifstream {
    private:
	std::string line;	// Current line
    public:
        int cur_char;	// Current character (can be EOF)
        int next_char;	// Next character (can be EOF)

	/*
	 * Initialize the input file and read the first 2 
	 * characters.
	 */
	input_file(const char *const name) : 
	    std::ifstream(name),
	    line("")
	{
	    if (bad())
		return;
	    cur_char = get();
	    next_char = get();
	}

	/*
	 * Write the line to the screen
	 */
	void flush_line() {
	    std::cout << line;
	    std::cout.flush();
	    line = "";
        }
	/*
	 * Advance one character
	 */
	void read_char() {
	    line += cur_char;

	    cur_char = next_char;
	    next_char = get();
	}
};

/********************************************************
 * token class						*
 *							*
 *	Reads the next token in the input stream	*
 *	and returns its type.  				*
 ********************************************************/
class token {
    private:
	// True if we are in the middle of a comment
	int in_comment;	

	// True if we need to read a character
	// (This hack is designed to get the new lines right)
	int need_to_read_one;

	// Read a /* */ style comment
	TOKEN_TYPE read_comment(input_file& in_file);
    public:
	token() { 
	    in_comment = false;
	    need_to_read_one = 0;
	}

	// Return the next token in the stream
	TOKEN_TYPE next_token(input_file& in_file);
};


/*** End of file ***/
