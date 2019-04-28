#include "PageList.h"



PageList::PageList() : pageList(0)
{}

PageList::~PageList()
{
}

bool PageList::chooseAction()
{
	try
	{
		int temp;
		cout << "1 - ������� ��������" << endl
		  	 << "2 - ������� ��������" << endl
			 << "3 - �������� ��������" << endl
			 << "4 - �������� ��������" << endl
			 << "5 - �������� ������ �������" << endl
			 << "6 - � ������ ������������� �������" << endl
			 << "7 - ��������� �����" << endl;
		cin >> temp;
		cout << endl;
		Action action = static_cast<Action>(temp);
		switch (action)
		{
		case CREATE_PAGE:
			createPage();
			break;
		case DELETE_PAGE:
			deletePage();
			refresh();
			break;
		case CHANGE_PAGE:
			changePage();
			break;
		case SHOW_ONE:
			showOne();
			break;
		case SHOW_ALL:
			showAll();
			break;
		case TASK:
			task();
			break;
		case EXIT:
			return false;
			break;
		default:
			break;
		}
	}
	catch (...)
	{}
	cin.clear();
	cin.ignore();
	return true;
}

void PageList::createPage()
{
	try
	{
		int temp;
		cout << "1 - ��������� �������� ���������� ����������" << endl
			<< "2 - ����������� �������� ������������ ��������" << endl
			<< "3 - ��������� �������" << endl;
		cin >> temp;
		cout << endl;
		Create create = static_cast<Create>(temp);
		switch (create)
		{
		case RANDOM_PAGE:
			addRandomPage();
			break;
		case COPY_PAGE:
			addCopyPage();
			break;
		case NEW_PAGE:
			addNewPage();
			break;
		default:
			break;
		}
	}
	catch (...)
	{}
}

void PageList::deletePage()
{
	try
	{
		int number;
		cout << "������� ����� �������� ��� ��������: ";
		cin >> number;
		cout << endl;
		for(list<Page>::iterator i = pageList.begin(); i!=pageList.end();i++)
		{
			if (i->get(PAGE_NUMBER) == number)
			{
				pageList.erase(i);
				break;
			}
		}
	}
	catch (...)
	{
		cout << "ERROR" << endl;
	}
}

void PageList::changePage()
{
	try
	{
		int number;
		cout << "������� ����� ���������� ��������: ";
		cin >> number;
		cout << endl;
		int temp;
		cout << "1 - �������� ��� ���������" << endl
			<< "2 - �������� ���� ��������" << endl;
		cin >> temp;
		cout << endl;
		Change change = static_cast<Change>(temp);
		switch (change)
		{
		case CHANGE_ALL:
			changeAll(number);
			break;
		case CHANGE_ONE:
			changeOne(number);
			break;
		default:
			break;
		}
	}
	catch (...)
	{}
}

void PageList::showOne()
{
	try
	{
		int number;
		cout << "������� ����� ��������: ";
		cin >> number;
		cout << endl;
		for (Page i : pageList)
		{
			if (i.get(PAGE_NUMBER) == number)
			{
				i.showAll();
				return;
			}
		}
		cout << "�������� ����� ��������!" << endl;
	}
	catch (...)
	{}
}

void PageList::showAll()
{
	for (Page i : pageList)
	{
		i.showAll();
		cout << endl;
	}
}

void PageList::task()
{
	try
	{
		int temp;
		cout << "1 - ����� ������ �������, ���������� ���������� ���� ������ ���������" << endl
			 << "2 - ����� ������ ������� ������� � ��������� ��������� ���� �� ���" << endl
			 << "3 - ����� �������� ���������� ���� �� ��������" << endl;
		cin >> temp;
		cout << endl;
		Task task = static_cast<Task>(temp);
		switch (task)
		{
		case TASK_1:
			task1();
			break;
		case TASK_2:
			task2();
			break;
		case TASK_3:
			task3();
			break;
		default:
			break;
		}
	}
	catch (...)
	{}
}

void PageList::addRandomPage()
{
	Page newPage(pageList.size() + 1);
	pageList.push_back(newPage);
}

void PageList::addCopyPage()
{
	try
	{
		int number;
		cout << "������� ����� ���������� ��������: ";
		cin >> number;
		cout << endl;
		for (Page i : pageList)
		{
			if (i.get(PAGE_NUMBER) == number)
			{
				Page newPage = i;
				newPage.setPageNumber(pageList.size() + 1);
				pageList.push_back(newPage);
				return;
			}
		}
		cout << "�������� ����� ��������!" << endl;
	}
	catch (...)
	{}
}

void PageList::addNewPage()
{
	Page newPage;
	newPage.setAll();
	newPage.setPageNumber(pageList.size() + 1);
	pageList.push_back(newPage);
}

void PageList::changeAll(int number)
{
	for (Page i : pageList)
	{
		if (i.get(PAGE_NUMBER) == number)
		{
			i.setAll();
			return;
		}
	}
	cout << "�������� ����� ��������!" << endl;
}

void PageList::changeOne(int number)
{
	try
	{
		int temp;
		cout << "1 - �������� ���������� ����" << endl
			<< "2 - �������� ���������� �������" << endl
			<< "3 - �������� ������ ������" << endl
			<< "4 - �������� ���������� ����������" << endl
			<< "5 - �������� ���������� �����" << endl;
		cin >> temp;
		cout << endl;
		for (Page i : pageList)
		{
			if (i.get(PAGE_NUMBER) == number)
			{
				i.set(static_cast<Type>(temp));
				return;
			}
		}
		cout << "�������� ����� ��������!" << endl;
	}
	catch (...)
	{}
}

void PageList::task1()
{
	try
	{
		cout << "������� ����������� ���������� ��������: ";
		int number;
		cin >> number;
		cout << endl;
		for (Page i : pageList)
		{
			if (i.get(NUMBER_OF_LETTERS) > number)
			{
				i.showAll();
			}
		}
	}
	catch (...)
	{}
}

void PageList::task2()
{
	for (Page i : pageList)
	{
		cout << i.get(PAGE_NUMBER) << " - " 
			 << (i.get(NUMBER_OF_LETTERS) - i.get(NUMBER_OF_VOWEL)) << endl;
	}
}

void PageList::task3()
{
	int temp = 0;
	for (Page i : pageList)
	{
		temp += i.get(NUMBER_OF_LETTERS);
	}
	cout << (temp / pageList.size()) << endl;
}

void PageList::refresh()
{
	int count = 1;
	for (list<Page>::iterator i = pageList.begin(); i != pageList.end(); i++)
	{
		i->setPageNumber(count);
		count++;
	}
}

