
#ifndef PAGE_H
#define PAGE_H

#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Type
{
	NUMBER_OF_LETTERS=1,
	NUMBER_OF_VOWEL,
	FONT_SIZE,
	NUMBER_OF_PARAGRAPHS,
	NUMBER_OF_LINES,
	PAGE_NUMBER,
};

class Page
{
public:
	Page();
	Page(int pageNumber);
	~Page();

	void set(Type);
	void setPageNumber(int number);
	int get(Type);
	void show(Type);

	void setAll();
	void showAll();

private:
	int numberOfLetters;
	int numberOfVowel;
	int fontSize;
	int numberOfParagraphs;
	int pageNumber;
	int numberOfLines;
};

#endif