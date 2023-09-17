#include "pch.h"
#include "framework.h"
#include "hash-table.h"
using namespace std;

HashTable::StringHashTable::StringHashTable()
{
	table = new string[size];
}

bool HashTable::StringHashTable::insert(std::string key, std::string value)
{
	return false;
}

bool HashTable::StringHashTable::remove(std::string key)
{
	return false;
}

std::string HashTable::StringHashTable::getValue(std::string key)
{
	return std::string();
}

HashTable::StringHashTable::~StringHashTable()
{
	delete table;
}

int HashTable::StringHashTable::hash(std::string key)
{
	return getAsciiSum(key) % size;
}

int HashTable::StringHashTable::getAsciiSum(std::string str)
{
	int sum = 0;
	for (char chr : str)
		sum += static_cast<int>(chr);
	return sum;
}
