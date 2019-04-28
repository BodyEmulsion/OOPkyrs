#include "Page.h"

Page::Page() : numberOfLetters(0), numberOfVowel(0), fontSize(0), 
			   numberOfParagraphs(0), pageNumber(0), numberOfLines(0)
{}

Page::Page(int pageNumber)
{
	srand(time(NULL) * (pageNumber));
	numberOfLetters = 500 + (rand() % 2000);
	numberOfVowel = (numberOfLetters / 3) + (rand() % 100);
	fontSize = 5 + (rand() % 11);
	numberOfParagraphs = (numberOfLetters / 100) + (rand() % 5);
	numberOfLines = numberOfParagraphs + (rand() % 20);
	Page::pageNumber = pageNumber;
}

Page::~Page()
{}

void Page::set(Type type)
{
	try
	{
		int newdata;
		switch (type)
		{
		case NUMBER_OF_LETTERS:
			cout << "Введите количество букв: ";
			cin >> newdata;
			cout << endl;
			numberOfLetters = newdata;
			break;
		case NUMBER_OF_VOWEL:
			cout << "Введите количество гласных: ";
			cin >> newdata;
			cout << endl;
			numberOfVowel = newdata;
			break;
		case FONT_SIZE:
			cout << "Введите размер шрифта: ";
			cin >> newdata;
			cout << endl;
			fontSize = newdata;
			break;
		case NUMBER_OF_PARAGRAPHS:
			cout << "Введите количество абзацев: ";
			cin >> newdata;
			cout << endl;
			numberOfParagraphs = newdata;
			break;
		case NUMBER_OF_LINES:
			cout << "Введите количество строк: ";
			cin >> newdata;
			cout << endl;
			numberOfLines = newdata;
			break;
		default:
			break;
		}
	}
	catch (const std::exception&)
	{
		cout << "Некорректный ввод!" << endl;
	}
}

void Page::setPageNumber(int number)
{
	pageNumber = number;
}

int Page::get(Type type)
{
	switch (type)
	{
	case NUMBER_OF_LETTERS:
		return numberOfLetters;
		break;
	case NUMBER_OF_VOWEL:
		return numberOfVowel;
		break;
	case FONT_SIZE:
		return fontSize;
		break;
	case NUMBER_OF_PARAGRAPHS:
		return numberOfParagraphs;
		break;
	case PAGE_NUMBER:
		return pageNumber;
		break;
	case NUMBER_OF_LINES:
		return numberOfLines;
		break;
	default:
		break;
	}
}

void Page::show(Type type)
{
	switch (type)
	{
	case NUMBER_OF_LETTERS:
		cout << "Количество букв: " << numberOfLetters << endl;
		break;
	case NUMBER_OF_VOWEL:
		cout << "Количество гласных: " << numberOfVowel << endl;
		break;
	case FONT_SIZE:
		cout << "Размер шрифта: " << fontSize << endl;
		break;
	case NUMBER_OF_PARAGRAPHS:
		cout << "Количество абзацев: " << numberOfParagraphs << endl;
		break;
	case PAGE_NUMBER:
		cout << "Номер страницы: " << pageNumber << endl;
		break;
	case NUMBER_OF_LINES:
		cout << "Количество строк: " << numberOfLines << endl;
		break;
	default:
		break;
	}
}

void Page::setAll()
{
	set(NUMBER_OF_LETTERS);
	set(NUMBER_OF_VOWEL);
	set(FONT_SIZE);
	set(NUMBER_OF_PARAGRAPHS);
	set(NUMBER_OF_LINES);
}

void Page::showAll()
{
	show(NUMBER_OF_LETTERS);
	show(NUMBER_OF_VOWEL);
	show(FONT_SIZE);
	show(NUMBER_OF_PARAGRAPHS);
	show(NUMBER_OF_LINES);
	show(PAGE_NUMBER);
}
