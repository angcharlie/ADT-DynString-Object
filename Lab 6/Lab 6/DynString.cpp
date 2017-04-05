// DynString.cpp
// Charlie Ang
// 03/01/16
//Implementation file for DynString.h

#include <cstring>
#include <assert.h>
#include <iostream>
#include <fstream>
#include "DynString.h"

// Default and Convert Constructor
// Default parameters are provided for both s and len
DynString::DynString(const char s[], const int len)
{
	curLength = len;							// new string length
	int maxLen = strlen(s);						// limit
	if(curLength < 0 || curLength > maxLen)
		curLength = maxLen;

	pBuff = new char[curLength + 1];
	assert(pBuff);

	for(int i=0; i<curLength; ++i)		// or, strncpy_s(pBuff, curLength+1, s, curLength);
		pBuff[i] = s[i];

	pBuff[curLength] = 0;
}

// Copy Constructor
DynString::DynString(const DynString &s)
{
	curLength = s.curLength;
	pBuff = new char[curLength + 1];	//allocate new array with room for '\0' sentinel

	//Copy array values from s
	for (int i = 0; i < curLength; i++)
	{
		pBuff[i] = s.pBuff[i];
	}
	pBuff[curLength] = 0;		//append end of string sentinel
}

// Assignment operator=
DynString& DynString::operator=(const DynString &rhs)
{
	if(this != &rhs)
	{
		// Delete old string-value and create new pBuff that
		// is copy of rhs string-value
		delete[] pBuff;		//delete old cstring array

		//Make deep copy of rhs
		curLength = rhs.curLength;
		pBuff = new char[curLength + 1];		//allocate new array with room for '\0' sentinel

		//Copy array values from rhs
		for (int i = 0; i < curLength; i++)
		{
			pBuff[i] = rhs.pBuff[i];
		}
		pBuff[curLength] = 0;		//append end of string sentinel
	}

	return *this;
}

// Destructor
DynString::~DynString()
{
	delete[] pBuff;
}

const int DynString::length() const
{
	return(curLength);
}

const char* DynString::toString() const
{
   return pBuff;
}

bool DynString::readLine(std::istream& in)
{
	if(in.eof())
	{
		*this = DynString();	// Default string value.
		return(false);
	}

	char s[257];
	in.getline(s, 257);

	// Replace existing string-value with copy of line s
	delete[] pBuff;		//delete pBuff cstring variable 
	curLength = strlen(s);	//length of s
	pBuff = new char[curLength + 1];	//create new pBuff variable of updated size leaving room for newline and null
	for (int i = 0; i < curLength; i++)
	{
		pBuff[i] = s[i];
	}
	pBuff[curLength] = 0;	//append null byte sentinel

	return(true);
}

// Open file
// Read entire input file into string
// Close file
bool DynString::readFile(const char filename[])
{
	std::ifstream in(filename);
	if(! in.is_open() )
	{
		*this = DynString();	// Default string value.
		return(false);
	}

	// Delete old string-value and //gets deleted in concatenate
	// Read the file-contents into a new pBuff string
	//	 Replace existing DynString value with the first line
	//   Concatenate any additional lines

	DynString temp;	//temporary DynString object 
	char n[2] = "\n";
	DynString newLine(n);
	bool success = bool(readLine(in));	//true
	while (success)	//while success == true (not end of file)
	{
		temp.concat(pBuff);	//concatenate line that was just read in to temp's
		temp.concat(newLine);	//concatenate \n character 
		success = bool(readLine(in));	//true
	}
	concat(temp);	//copy everything over into pBuff
	
	in.close();
	return(true);
}

void DynString::concat(const DynString &s)
{
	int pBuffLength = curLength;	//length of pBuff
	DynString temp = pBuff;	//copies pBUff into a temp dynstring variable 
	curLength = pBuffLength + s.curLength;	//string value's current length + s's current length
	delete[] pBuff;
	pBuff = new char[curLength + 1];	//pBuff dynamically updated to fit size of original plus concatenated plus room for 0 null
	strncpy_s(pBuff, curLength + 1, temp.pBuff, temp.curLength);	//copies temp into pBuff excluding null byte
	strcat_s(pBuff, curLength + 1, s.pBuff);	//concatenates s onto pBuff
	pBuff[curLength] = 0;	//append null byte
	return;
}

const int DynString::compare(const DynString &s) const
{
	return(strcmp(pBuff, s.pBuff));  // use the cstring function
}

const char DynString::getChar(const int position) const
{
	if (position < 0 || position > curLength)	//if out of range
	{
		return 0;
	}
	else
	{
		return(pBuff[position]);	//return char at that position
	}
}

const int DynString::findChar(const char ch, const int startoffset) const
{
	if (startoffset < 0 || startoffset >= curLength)	//if startoffset not within bounds
	{
		std::cerr << "startoffset does not exist" << std::endl;
		return (-1);
	}
	for (int i = startoffset; i < curLength; i++)
	{
		if (pBuff[i] == ch)
		{
			return i;	//return poition
		}
	}
	return(-1);	//returns -1 if position not found
}

DynString DynString::substr(const int start, const int len) const
{
	if(start < 0 || start >= curLength)  	// Validate start range
		return(DynString());

	return(DynString(&pBuff[start], len) );	// Utilize constructor to create substr
}

// Return substring of original corresponding to linenum (1 .. n)
// Do not include '\n' at end of line
DynString DynString::findLine(const int linenum) const
{
	if (linenum <= 0)
	{
		std::cerr << "Line could not be found." << std::endl;
		return(DynString());	//returns an empty string
	}

	int lineNumber = 1;
	int start = 0;
	for (int i = 0; i < curLength; i++)
	{
		if (pBuff[i] == '\n')
		{
			lineNumber++;	//increment line number
			if (lineNumber == linenum)
			{
				start = i + 1;	//start postion
			}
		}
	}

	int j = start;
	while (pBuff[j] != '\n')
	{
		j++;	//increment j until it reaches \n
	}

	int length = j - start;	//length of stubstring for line
	return substr(start, length);	//return the extracted substring from linenum
	
	return(DynString());
}

// Return line number corresponding to position in string
int DynString::findLineNumber(const int position) const
{
	int lineNumber = 1;
	for (int i = 0; i < curLength; i++) //or i <= position
	{
		if (pBuff[i] == '\n')
		{
			lineNumber++;	//increment line number
		}
		if (i == position)
		{
			return lineNumber;
		}
	}
	return(-1);	//if position not found
}

// Overload << operator for DynStrings
// Note: friend function, not a class method, so must use toString() method
std::ostream &operator<<(std::ostream& out, const DynString &s)
{
	// Use insertion << operator with stream out to output the string value of s.

	out << s.toString();    // could use s.pBuff if friend operator<< overload in class
	return(out);		    // enables cascaded calls
}
