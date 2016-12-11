#include "StringBuffer_COWRL.h"
#include "String_COWRL.h"
#include <memory>
#include <iostream>

using namespace std;
//default constructor

String_COWRL::String_COWRL() {
	this->_str = new StringBuffer_COWRL();
}
//destructor

String_COWRL::~String_COWRL() {

	//decrement the refcount and only if it is =0, delete the buffer.
	if (--this->_str->_refcount < 1) {
		this->_str->next = NULL;
		this->_str->previous = NULL;
		this->_str = NULL;
		delete[] this->_str;
	}
	else {
		if (this->_str->_refcount == 1) {
			this->_str->next = this->_str;
			this->_str->previous = this->_str;
		}
		else {
			this->_str->next->previous = this->_str->previous;
			this->_str->previous->next = this->_str->next;
		}
	}
}

//copy a const String into this string

String_COWRL::String_COWRL(const String_COWRL& newString) {
	this->_str = newString._str;

	if (this->_str->_refcount == 1) {
		this->_str->next = this->_str;
		this->_str->previous = this->_str;
	}
	else {
		newString._str->previous = this->_str;
		newString._str->next = this->_str->next;
		this->_str->next = newString._str;

		if (this->_str->_refcount == 2)
			this->_str->previous = newString._str;
	}

	//increment the refcount by 1
	++this->_str->_refcount;
}

//copy a char* into your string

String_COWRL::String_COWRL(char* newString, int length) {
	this->_str = new StringBuffer_COWRL(newString, length);

	this->_str->next = this->_str;
	this->_str->previous = this->_str;

	//increment the refcount by 1
	this->_str->_refcount = 1;

}

void String_COWRL::append(char c) {

	//    char* tempbuf = new char[this->_str->length()+1];
	//    this->_str->revSmartCopy(tempbuf);
	if (this->_str->_refcount > 1) {
		//more than 1 reference to this string
		auto_ptr<StringBuffer_COWRL> newdata(new StringBuffer_COWRL);
		newdata.get()->reserve(this->_str->length() + 1);
		newdata.get()->smartCopy(this->_str);

		this->_str->next->previous = this->_str->previous;
		this->_str->previous->next = this->_str->next;

		//decrement the reference count to this String
		--this->_str->_refcount;

		//cout<<"length at newdata"<<newdata.get()->length()<<endl;
		//now split the object instances
		this->_str = newdata.release();
	}
	else {
		this->_str->reserve(this->_str->length() + 1);
	}

	//copy the new character at the end of this string
	this->_str->append(c);

}

//get length of the string

int String_COWRL::length() const {
	return this->_str->length();
}

//get character at index if it is less than length

char String_COWRL::charAt(int index) const {
	if (index < this->_str->length()) {
		return this->_str->charAt(index);
	}
	else {
		//throw new IndexOutOfBoundException();
		return '-1';
	}
}