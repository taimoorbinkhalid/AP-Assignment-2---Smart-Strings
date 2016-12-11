#ifndef STRINGBUFFER_H2
#define	STRINGBUFFER_H2

class StringBuffer_COWRL{
public:
	StringBuffer_COWRL();
	~StringBuffer_COWRL();
	StringBuffer_COWRL(const StringBuffer_COWRL&);
	StringBuffer_COWRL(char*, int);

	char charAt(int) const;
	int length() const;
	void smartCopy(char*, int);
	void smartCopy(StringBuffer_COWRL*);
	void revSmartCopy(char* newString);
	void reserve(int);
	void append(char);
	int _refcount;

	StringBuffer_COWRL* next;
	StringBuffer_COWRL* previous;
private:
	char* _strbuf;
	int _length;

};

#endif	/* STRINGBUFFER_H2 */

