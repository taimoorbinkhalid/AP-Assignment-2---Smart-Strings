/*
* File:   String.h
*
* Created on February 18, 2016, 6:17 PM
*/

#ifndef STRING_H3
#define	STRING_H3

class String_OP{
private:
	StringBuffer_OP* _str;
public:
	String_OP();
	~String_OP();
	String_OP(const String_OP&);
	String_OP(char*, int);
	void append(char);
	int length() const;
	char charAt(int) const;
};


#endif	/* STRING_H3 */

