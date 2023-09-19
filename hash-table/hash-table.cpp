#include "pch.h"
#include "framework.h"
#include "hash-table.h"
using namespace std;


HashTable::StringHashTable::StringHashTable()
{
	table = new HashNode*[capacity];
}

bool HashTable::StringHashTable::insert(string const& phoneNumber, string const& address)
{

	size_t index = findEmptyIndex(phoneNumber);
	HashNode* hashNode = new HashNode{ phoneNumber, address };
	table[index] = hashNode;

	size++;
	checkRebuild();
	return true;
}

bool HashTable::StringHashTable::remove(std::string const& key)
{
	return false;

}

bool HashTable::StringHashTable::exists(std::string const& key)
{
	size_t index = findEmptyIndex(key);
	return table[index] != nullptr;
}

HashTable::HashNode HashTable::StringHashTable::getValue(std::string const& key)
{
	size_t index = findEmptyIndex(key);
	if (table[index] == nullptr)
		throw HashTable::KeyNotExistsException();

	return *table[index];
}

HashTable::StringHashTable::~StringHashTable()
{
	for (size_t i = 0; i < capacity; i++) {
		if (table[i] != nullptr) {
			delete table[i];
		}
	}
	delete[] table;
}

size_t HashTable::StringHashTable::findEmptyIndex(std::string const& key)
{
	for (int i = 0; i < capacity; i++)
	{
		size_t hash = getHash(key, i);
		if (isIndexEmpty(hash))
			return hash;
	}
	throw HashTable::EmptyIndexNotFoundException();
}

bool HashTable::StringHashTable::isIndexEmpty(size_t const index)
{
	return table[index] == nullptr;
}

size_t HashTable::StringHashTable::getHash(std::string const& key, size_t const& i)
{
	return (getAsciiSum(key) + c * i + d * i * i) % capacity;
}

size_t HashTable::StringHashTable::getAsciiSum(std::string str)
{
	size_t sum = 0;
	for (char chr : str)
		sum += size_t(chr);
	return sum;
}

bool HashTable::StringHashTable::checkRebuild()
{
	if ((float)size / capacity < rebuidlLoadFactor)
		return false;

	rehash();
	return true;
}

void HashTable::StringHashTable::rehash()
{
	size_t oldCapacity = capacity;
	HashNode** oldTable = table;
	capacity *= 2;
	size = 0;
	table = new HashNode*[capacity];

	for (size_t i = 0; i < oldCapacity; i++)
	{
		if (oldTable[i] != nullptr)
		{
			insert(, );
			delete oldTable[i];
		}
	}
	delete[] oldTable;
}
