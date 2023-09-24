#include <iostream>
#include "hash-table.h"
#include "console-menu.h"
using namespace std;

void bar1();
void bar2();
void bar3();
void bar4();

int main()
{
	vector<string> menuItems{ "Insert", "Remove", "Get Value", "Show all" };
	vector<void (*)()> funcs{ &bar1, &bar2, &bar3, &bar4 };

	ConsoleMenu::ConsoleMenu menu(menuItems, funcs);
	menu.run();
}

bool insert(HashTable::StringHashTable& table)
{
	string phoneNumber;
	string address;
	cout << "Enter record: " << endl;;
	cout << "Phone number - ";
	cin >> phoneNumber;
	cout << "Address - ";
	cin >> address;
	bool returnValue = table.insert({ phoneNumber, address });
	return returnValue;
}

bool foo(HashTable::StringHashTable& table)
{
	return false;
}

void bar1()
{
	cout << "bar1" << endl;
}

void bar2()
{
	cout << "bar2" << endl;
}

void bar3()
{
	cout << "bar3" << endl;
}

void bar4()
{
	cout << "bar4" << endl;
}
