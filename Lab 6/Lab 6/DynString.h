// DynString.h		
// Charlie Ang
// 03/01/16
// CSC 2430 Homework
// A variable-sized dynamic array implementation of a string ADT



#include <iostream>

class DynString
{
public:
	// Construct a new DynString, initialized to substring of s
	//   starting at position 0, of length len
	// If len < 0, utilize entire string s
	// If len > length of s, then utilize entire string s
	// Both s and len have default parameter values
	DynString(const char s[]="", const int len=-1);

	// Copy Constructor.  Construct new (deep) copy of s
	DynString(const DynString &s);
	// Assignment operator= override.  Make new (deep) copy of s.
	DynString& operator=(const DynString &s);
	// Destructor.  Delete allocated string-value
	~DynString();

	// Return current string-value length
	const int length() const;

	// Return ASCIIZ char* string pointer
	const char* toString() const;

	// Read next input line into string
	// Assumes that incoming input line has at most 256 characters
	// Returns true if a line is successfully input.
 	// Returns false and sets the string value to "" if the end-of-file is reached.
	bool readLine(std::istream& in = std::cin);

	// Read entire input file into string as single, long string-value
	//   with embedded \n newline characters marking the ends-of-lines.
	// Returns true if the filename is successfully opened and read.
 	// Returns false and sets the string value to "" if a file error occurs.
	bool readFile(const char filename[]);

	// Concatenate s to end of string-value
	void concat(const DynString &s);

	// Compare string-value to s.
	// Return (-), 0, or (+) depending on result of comparison
	const int compare(const DynString &s) const;

	// Retrieve string[position].  Return 0 if out of range
	const char getChar(const int position) const;

	// Find position of ch in string.  Return -1 if not found
	// Begin searching with [startoffset] position
	const int findChar(const char ch, const int startoffset=0) const;

	// Return new DynString with value that is substring of original
	DynString substr(const int start, const int len=-1) const;

	// Return substring of original corresponding to linenum (1 .. n)
	// Do not include '\n' at end of line
	DynString findLine(const int linenum) const;

	// Return line number 1 .. n corresponding to position in string
	int findLineNumber(const int position) const;

private:
	char *pBuff;				// The actual string buffer array
	int   curLength;			// current length of string-value

	// Added extra -- not required for lab assignment. Implementation provided.
	// Overload << operator for DynStrings
	// Note: friend function, not a class method
	friend std::ostream &operator<<(std::ostream& out, const DynString &s);
};
