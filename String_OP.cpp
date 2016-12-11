#include "StringBuffer_OP.h"
#include "String_OP.h"
#include <memory>
#include <iostream>

using namespace std;
//default constructor

String_OP::String_OP() {
	this->_str = new StringBuffer_OP();
	this->_str->owned = true;
}
//destructor

String_OP::~String_OP() {

	//decrement the refcount and only if it is =0, delete the buffer.
	if (--this->_str->_refcount < 1 && this->_str->owned) {
		this->_str = NULL;
		delete[] this->_str;
	}

}

//copy a const String into this string

String_OP::String_OP(const String_OP& newString) {
	this->_str = newString._str;

	newString._str->owned = false;
	this->_str->owned = true;

	//increment the refcount by 1
	++this->_str->_refcount;
}

//copy a char* into your string

String_OP::String_OP(char* newString, int length) {
	this->_str = new StringBuffer_OP(newString, length);
	this->_str->owned = true;

	//increment the refcount by 1
	this->_str->_refcount = 1;

}

void String_OP::append(char c) {

	//    char* tempbuf = new char[this->_str->length()+1];
	//    this->_str->revSmartCopy(tempbuf);
	if (this->_str->_refcount > 1) {
		//more than 1 reference to this string
		auto_ptr<StringBuffer_OP> newdata(new StringBuffer_OP);
		newdata.get()->reserve(this->_str->length() + 1);
		newdata.get()->smartCopy(this->_str);

		//decrement the reference count to this String
		--this->_str->_refcount;

		//cout<<"length at newdata"<<newdata.get()->length()<<endl;
		//now split the object instances
		this->_str = newdata.release();
		this->_str->owned = true;
	}
	else {
		this->_str->reserve(this->_str->length() + 1);
	}

	//copy the new character at the end of this string
	this->_str->append(c);

}

//get length of the string

int String_OP::length() const {
	return this->_str->length();
}

//get character at index if it is less than length

char String_OP::charAt(int index) const {
	if (index < this->_str->length()) {
		return this->_str->charAt(index);
	}
	else {
		//throw new IndexOutOfBoundException();
		return '-1';
	}
}