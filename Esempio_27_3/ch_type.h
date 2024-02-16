/********************************************************
 * char_type -- Character type class			*
 *							*
 * Member functions:					*
 *	type -- returns the type of a character.	*
 *		(Limited to simple types)		*
 *	is(ch, char_type) -- check to see if ch is 	*
 *		a member of the given type.		*
 *		(Works for derrived types as well.)	*
 ********************************************************/
class char_type {
    public:
	enum CHAR_TYPE {
	    C_EOF,		// End of file character
	    C_WHITE,	// Whitespace or control character
	    C_NEWLINE,	// A newline character
	    C_ALPHA,	// A Letter (includes _)
	    C_DIGIT,	// A Number
	    C_OPERATOR,	// Random operator
	    C_SLASH,	// The character '/'
	    C_L_PAREN,	// The character '('
	    C_R_PAREN,	// The character ')'
	    C_L_CURLY,	// The character '{'
	    C_R_CURLY,	// The character '}'
	    C_SINGLE,	// The character '\''
	    C_DOUBLE,	// The character '"'
	    // End of simple types, more complex, derrived types follow
	    C_HEX_DIGIT,// Hexidecimal digit
	    C_ALPHA_NUMERIC	// Alpha numeric
	};
    private:
	static enum CHAR_TYPE type_info[256];	// Information on each character
	
	// Fill in a range of type info stuff
	void fill_range(int start, int end, CHAR_TYPE type);
    public:
	char_type();	// Initialize the data
	// ~char_type	-- default destructor

	// Returns true if character is a given type
	int is(int ch, CHAR_TYPE kind);

	CHAR_TYPE type(int ch);
};