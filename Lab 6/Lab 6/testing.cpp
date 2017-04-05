//testing.cpp

#include <cstring>
#include <assert.h>
#include <iostream>
#include <fstream>

#include "DynString.h"

using namespace std;

int main()
{
	system("cls");
	
	
	char buff[50] = "Hello There";
	char buff1[50] = "Fred Flintstone";

	//TESTING CONSTRUCTOR
	DynString temp = DynString(buff, 2);
	cout << temp << endl;	//should output "He"
	DynString temp2 = DynString(&buff[6], 5);
	cout << temp2 << endl;	//should output "There"
	
	//TESTING COPY CONSTRUCTOR
	DynString test(buff);	
	DynString test2(buff1);
	cout << test << endl;	//should output "Hello There" 
	cout << test2 << endl;	//should output "Fred Flintstone"
	

	//TESTING OPERATOR= OVERRIDE 
	//DynString test3 = test2;
	DynString test3;
	test3 = test2;
	cout << test3 << endl;	//should output "Fred Flintstone"
	
	/*
	//TESTING READ LINE....have to start debugging instead of start without debugging
	DynString s;
	ifstream in("sample.txt");
	s.readLine(in);
	cout << s << endl; //should output "This is a sample"
	s.readLine(in);
	cout << s << endl; //should output "test program to test functinality of functions."
	*/
	

	//TESTING CONCATENATE
	/*
	char buff2[50] = "Charlie";
	char buff3[50] = "Ang";
	DynString test4(buff2);	//test4 would have "Charlie"
	DynString test5(buff3);	//test5 would have "Ang"
	cout << test4 << endl;	//"Charlie"
	cout << test4.length() << endl;
	cout << test5 << endl;	//"Ang"
	test4.concat(test5);	//"CharlieAng"
	cout << test4 << endl;
	*/

	/*
	char buff2[50] = "Charlie";
	char buff3[50] = "Ang";
	DynString test4(buff2);	//test4 would have "Charlie"
	DynString test5(buff3);	//test5 would have "Ang"
	cout << test4 << endl;	//"Charlie"
	cout << test4.length() << endl;
	cout << test5 << endl;	//"Ang"
	test5.concat(test4);	//"AngCharlie"
	cout << test5 << endl;
	*/

	/*
	char buff2[50] = "This is cool";
	char buff3[50] = "I love this";
	char buff4[4] = "\n";
	char buff5[50] = "Let's concatenate this on.";
	DynString test4(buff2);	//test4 would have "This is cool"
	DynString test5(buff3);	//test5 would have "I love this"
	DynString test6(buff4);	//"(new line)"
	DynString test7(buff5);	//"Let's concatenate this on."
	//cout << test4 << endl;	
	//cout << test4.length() << endl;
	//cout << test5 << endl;	
	test5.concat(test4);	//"I love thisThis is cool"
	test5.concat(test6);	//"I love thisThis is cool(new line) "
	test5.concat(test7);	//"I love thisThis is cool(new line) Let's concatenatate this on."
	cout << test5 << endl;
	*/

	//TESTING READ FILE
	//DynString t;
	//t.readFile("sample.txt");
	//cout << t << endl;

	//TESTING FIND LINE NUMBER
	//cout << t.findLineNumber(5) << endl; //should be line 1
	//cout << t.findLineNumber(16) << endl; //should be line 1
	//cout << t.findLineNumber(17) << endl; //should be line 2
	//cout << t.findLineNumber(64) << endl; //should be line 2
	//cout << t.findLineNumber(65) << endl; //should be line 3

	//TESTING FIND LINE
	//DynString ds = t.findLine(2); //"Let's see if this works or not."
	//cout << ds.toString() << endl;

	/*
	//TESTING GET CHAR
	char test[50] = "Hello There";
	char test2[50] = "ThisisCharlieAngandheistestinghiscode.";
	DynString one(test);
	DynString two(test2);
	cout << one << endl;
	cout << two << endl;
	cout << one.getChar(6) << endl;	//T
	cout << one.getChar(-1) << endl; //returns 0
	cout << one.getChar(10) << endl;	//e
	cout << one.getChar(11) << endl;	//0
	cout << two.getChar(3) << endl;	//s
	cout << two.getChar(5) << endl;	//s

	cout << one.findChar('l', 0) << endl;	//2
	cout << one.findChar('l', 2) << endl;	//2
	cout << two.findChar('A', 5) << endl;	//13
	cout << two.findChar('A', 100) << endl;	//13
	*/
	
	
	system("PAUSE");
	return 0;
}