#include <iostream>
#include "hash-table.h"
#include "console-menu.h"
using namespace std;

void bar1(HashTable::StringHashTable);
void bar2(HashTable::StringHashTable);
void bar3(HashTable::StringHashTable);
void bar4(HashTable::StringHashTable);

int main()
{
	vector<string> menuItems{ "Insert", "Remove", "Get Value", "Show all" };
	vector<void (*)(HashTable::StringHashTable)> funcs{ &bar1, &bar2, &bar3, &bar4};

	ConsoleMenu::ConsoleMenu<HashTable::StringHashTable> menu(menuItems, funcs);
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

void bar1(HashTable::StringHashTable& table)
{
	cout << "bar1" << endl;
}

void bar2(HashTable::StringHashTable& table)
{
	cout << "bar2" << endl;
}

void bar3(HashTable::StringHashTable& table)
{
	cout << "bar3" << endl;
}

void bar4(HashTable::StringHashTable& table)
{
	cout << "bar4" << endl;
}
