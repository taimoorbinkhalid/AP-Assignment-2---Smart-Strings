#ifndef STRINGBUFFER_H3
#define	STRINGBUFFER_H3

class StringBuffer_OP{
public:
	StringBuffer_OP();
	~StringBuffer_OP();
	StringBuffer_OP(const StringBuffer_OP&);
	StringBuffer_OP(char*, int);

	char charAt(int) const;
	int length() const;
	void smartCopy(char*, int);
	void smartCopy(StringBuffer_OP*);
	void revSmartCopy(char* newString);
	void reserve(int);
	void append(char);
	int _refcount;

	bool owned;
private:
	char* _strbuf;
	int _length;

};

#endif	/* STRINGBUFFER_H3 */

