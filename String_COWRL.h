/*
* File:   String.h
*
* Created on February 18, 2016, 6:17 PM
*/

#ifndef STRING_H2
#define	STRING_H2

class String_COWRL{
private:
	StringBuffer_COWRL* _str;
public:
	String_COWRL();
	~String_COWRL();
	String_COWRL(const String_COWRL&);
	String_COWRL(char*, int);
	void append(char);
	int length() const;
	char charAt(int) const;
};


#endif	/* STRING_H2 */

