/* 
 * File:   main.cpp
 *
 * Created on February 16, 2016, 9:51 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include "StringBuffer.h"
#include "StringBuffer_COWRL.h"
#include "StringBuffer_OP.h"
#include "String.h"
#include "String_COWRL.h"
#include "String_OP.h"

using namespace std;

bool test1() {
	//create a smart string
	//String ss;
	//create a smart string with const char*
	cout << "TEST CASE: 1 [Copied Pointers & COW with Reference Counting]" << endl;
	char* hello = "hello";

	String ss2(hello, 5);
	std::cout << "String \"ss2\" Length = " << ss2.length() << std::endl;
	cout << hello << endl;
	
	//multiple references
	String ss(ss2);
	cout << hello << endl;
	//output statements
	std::cout << "String \"ss\" Length = " << ss.length() << std::endl;
	std::cout << "New \"ss\" charAt 0 = " << ss.charAt(0) << std::endl;

	//append a character
	cout << "Appending a character in \"ss2\"." << endl;
	ss2.append('w');

	//cout<<hello<<endl;
	//hello = "bye";

	std::cout << "New \"ss\" Length = " << ss.length() << std::endl;
	std::cout << "New \"ss2\" Length = " << ss2.length() << std::endl;
	
	if (ss.length() == ss2.length() - 1) {
		cout << "TEST CASE: 1 [PASSED]" << endl;

		return true;
	}

	return false;
}

bool test2() {
	//create a smart string
	//String ss;
	//create a smart string with const char*
	cout << "TEST CASE: 2 [Copied Pointers & COW with Reference Linking]" << endl;
	char* hello = "hello";

	String_COWRL ss2(hello, 5);
	std::cout << "String \"ss2\" Length = " << ss2.length() << std::endl;
	cout << hello << endl;

	//multiple references
	String_COWRL ss(ss2);
	cout << hello << endl;
	//output statements
	std::cout << "String \"ss\" Length = " << ss.length() << std::endl;
	std::cout << "New \"ss\" charAt 0 = " << ss.charAt(0) << std::endl;

	//append a character
	cout << "Appending a character in \"ss2\"." << endl;
	ss2.append('w');

	//cout<<hello<<endl;
	//hello = "bye";

	std::cout << "New \"ss\" Length = " << ss.length() << std::endl;
	std::cout << "New \"ss2\" Length = " << ss2.length() << std::endl;

	if (ss.length() == ss2.length() - 1) {
		cout << "TEST CASE: 2 [PASSED]" << endl;

		return true;
	}

	return false;
}

bool test3() {
	//create a smart string
	//String ss;
	//create a smart string with const char*
	cout << "TEST CASE: 3 [Owned Pointers]" << endl;
	char* hello = "hello";

	String_OP ss2(hello, 5);
	std::cout << "String \"ss2\" Length = " << ss2.length() << std::endl;
	cout << hello << endl;

	//multiple references
	String_OP ss(ss2);
	cout << hello << endl;
	//output statements
	std::cout << "String \"ss\" Length = " << ss.length() << std::endl;
	std::cout << "New \"ss\" charAt 0 = " << ss.charAt(0) << std::endl;

	//append a character
	cout << "Appending a character in \"ss2\"." << endl;
	ss2.append('w');

	//cout<<hello<<endl;
	//hello = "bye";

	std::cout << "New \"ss\" Length = " << ss.length() << std::endl;
	std::cout << "New \"ss2\" Length = " << ss2.length() << std::endl;

	if (ss.length() == ss2.length() - 1) {
		cout << "TEST CASE: 3 [PASSED]" << endl;

		return true;
	}

	return false;
}

int main(int argc, char** argv) {
	bool test1_, test2_, test3_;
	test1_ = test2_ = test3_ = false;

	test1_ = test1();
	cout << endl;
	test2_ = test2();
	cout << endl;
	test3_ = test3();
	cout << endl;

	if (test1_ && test2_ && test3_) {
		cout << "All tests are passed!" << endl;
	}

    return 0;
}

