/********************************************************
 * token -- token handling module			*
 *							*
 * Functions:						*
 *	next_token -- get the next token from the input	*
 ********************************************************/
#include <fstream>
#include <cstdlib>
#include <assert.h>

#include "ch_type.h"
#include "token.h"

/*
 * Define the token name list
 *	This makes use of a trick using the T macro
 *	and our TOKEN_LIST
 */
#define T(x) #x		// Define x as a string
const char *const TOKEN_NAMES[] = {
   TOKEN_LIST
};
#undef T		// Remove old temporary macro

static class char_type char_type;	// Character type information
/********************************************************
 * read_comment -- read in a comment			*
 *							*
 * Parameters						*
 *	in_file -- file to read 			*
 *							*
 * Returns						*
 *	Token read.  Can be a T_COMMENT or T_NEW_LINE	*
 *	depending on what we read.			*
 *							*
 *	Multi-line comments are split into multiple 	*
 *	tokens.						*
 ********************************************************/
TOKEN_TYPE token::read_comment(input_file& in_file)
{
    if (in_file.cur_char == '\n') {
	in_file.read_char();
	return (T_NEWLINE);
    }
    while (true) {
	in_comment = true;
	if (in_file.cur_char == EOF) {
	    std::cerr << "Error: EOF inside comment\n";
	    return (T_EOF);
	}
	if (in_file.cur_char == '\n')
	    return (T_COMMENT);
	if ((in_file.cur_char == '*') && 
	    (in_file.next_char == '/')) {
	    in_comment = false;
	    // Skip past the ending */
	    in_file.read_char();
	    in_file.read_char();
	    return (T_COMMENT);
	}
	in_file.read_char();
    }
}
/********************************************************
 * next_token -- read the next token in an input stream	*
 *							*
 * Parameters						*
 *	in_file -- file to read				*
 *							*
 * Returns						*
 *	next token					*
 ********************************************************/
TOKEN_TYPE token::next_token(input_file& in_file)
{

    if (need_to_read_one)
	in_file.read_char();
    
    need_to_read_one = 0;

    if (in_comment)
	return (read_comment(in_file));

    while (char_type.is(in_file.cur_char, char_type::C_WHITE)) {
	in_file.read_char();
    }
    if (in_file.cur_char == EOF)
	return (T_EOF);

    switch (char_type.type(in_file.cur_char)) {
	case char_type::C_NEWLINE:
	    in_file.read_char();
	    return (T_NEWLINE);
	case char_type::C_ALPHA:
	    while (char_type.is(in_file.cur_char, 
				char_type::C_ALPHA_NUMERIC))
		in_file.read_char();
	    return (T_ID);
	case char_type::C_DIGIT:
	    in_file.read_char();
	    if ((in_file.cur_char == 'X') || (in_file.cur_char == 'x')) {
		in_file.read_char();
		while (char_type.is(in_file.cur_char, 
					char_type::C_HEX_DIGIT)) {

		    in_file.read_char();
		}
		return (T_NUMBER);
	    }
	    while (char_type.is(in_file.cur_char, char_type::C_DIGIT))
		in_file.read_char();
	    return (T_NUMBER);
	case char_type::C_SLASH:
	    // Check for  /* characters 
	    if (in_file.next_char == '*') {
		return (read_comment(in_file));
	    }
	    // Now check for double slash comments
	    if (in_file.next_char == '/') {
		while (true) {
		    // Comment starting with // and ending with EOF is legal
		    if (in_file.cur_char == EOF)
			return (T_COMMENT);
		    if (in_file.cur_char == '\n')
			return (T_COMMENT);
		    in_file.read_char();
		}
	    }
	    // Fall through
	case char_type::C_OPERATOR:
	    in_file.read_char();
	    return (T_OPERATOR);
	case char_type::C_L_PAREN:
	    in_file.read_char();
	    return (T_L_PAREN);
	case char_type::C_R_PAREN:
	    in_file.read_char();
	    return (T_R_PAREN);
	case char_type::C_L_CURLY:
	    in_file.read_char();
	    return (T_L_CURLY);
	case char_type::C_R_CURLY:
	    in_file.read_char();
	    return (T_R_CURLY);
	case char_type::C_DOUBLE:
	    while (true) {
		in_file.read_char();
		// Check for end of string
		if (in_file.cur_char == '"')
		    break;

		// Escape character, then skip the next character
		if (in_file.cur_char == '\\')
		    in_file.read_char();
	    }
	    in_file.read_char();
	    return (T_STRING);
	case char_type::C_SINGLE:
	    while (true) {
		in_file.read_char();
		// Check for end of character
		if (in_file.cur_char == '\'')
		    break;

		// Escape character, then skip the next character
		if (in_file.cur_char == '\\')
		    in_file.read_char();
	    }
	    in_file.read_char();
	    return (T_STRING);
	default:
	    assert("Internal error: Very strange character" != 0);
    }
    assert("Internal error: We should never get here" != 0);
    return (T_EOF);	// Should never get here either
}