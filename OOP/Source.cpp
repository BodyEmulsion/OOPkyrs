#include"PageList.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	bool isWork = true;
	PageList pageList;
	while (isWork)
	{
		isWork = pageList.chooseAction();
	}
}
