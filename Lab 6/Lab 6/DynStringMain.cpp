// DynStringMain.cpp    CSC2430 Homework Dynamic Strings		Mike Tindall

#include <iostream>
using namespace std;

#include "DynString.h"

// Print report of all lines in s that contain instances of substring look
void findAll(const DynString& s, const DynString& look)
{
	cout << "Find lines containing " << look.toString() << ":" << endl;

	char ch = look.getChar(0);		// starting character of look

	// Look through s character by character to find substrings that match
	int pos = 0;
	do {
		pos = s.findChar(ch, pos);	// Find next possible position
		if(pos >= 0)
		{
			// See if substring of s matches the look string
			if(look.compare(s.substr(pos, look.length())) == 0)
			{
				// Output the entire line from s that contains look

				// First, determine the linenumber that corresponds to pos
				int lnum = s.findLineNumber(pos);

				// Now, retrieve the lnum line as a substring from s
				DynString ds = s.findLine(lnum);

				// Output a line in the report
				cout.width(4);
				cout << lnum << ": " << ds.toString() << endl;
			//	cout << lnum << ": " << ds << endl;	 // using operator<< overload
			}

			++pos;	// Move on to the next position
		}
	} while(pos >= 0);

	cout << endl;
}

int main()
{
	DynString s;

	s.readFile("DynString.cpp");

	findAll(s, DynString("DynString"));
	findAll(s, DynString("pBuff"));

	system("PAUSE");
	return(0);
}
