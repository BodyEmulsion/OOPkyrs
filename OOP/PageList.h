
#ifndef PAGE_LIST_H
#define PAGE_LIST_H

#include"Page.h"
#include<list>

enum Action
{
	CREATE_PAGE = 1,
	DELETE_PAGE,
	CHANGE_PAGE,
	SHOW_ONE,
	SHOW_ALL,
	TASK,
	EXIT
};

enum Create
{
	RANDOM_PAGE=1,
	COPY_PAGE,
	NEW_PAGE
};

enum Change
{
	CHANGE_ALL=1,
	CHANGE_ONE
};

enum Task
{
	TASK_1 = 1,
	TASK_2,
	TASK_3
};

class PageList
{
public:
	PageList();
	~PageList();

	bool chooseAction();

private:

	void createPage();
	void deletePage();
	void changePage();
	void showOne();
	void showAll();
	void task();

	void addRandomPage();
	void addCopyPage();
	void addNewPage();

	void changeAll(int);
	void changeOne(int);

	void task1();
	void task2();
	void task3();

	void refresh();
	list<Page> pageList;
};

#endif