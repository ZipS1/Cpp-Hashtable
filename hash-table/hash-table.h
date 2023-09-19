#pragma once
#include <string>

/*
* �������� ��������� (������������ ������������).
* ��������� ��������:
* ����� �������� (10 ��������) -> �����
* 
* ���������: ��������� ������ �� ����������,
* �.�. � �������� ������ ���������
* ����� ������������������ �� 10 ��������.
*/

/*
* ������������ ������������
* ����� = h(x)+ci+d(i^2)
*/

/*
* ����������� ����
* h(x) = x mod size
* ��� x � �������� ��������, 
* size � ���������� ����������� ���������� ��������� �������� ����������\
* (�, ��� ���������, ���������� ���������� ������� � ������������ ���������).
*/




namespace HashTable
{
	enum class NodeStatus { Filled, Deleted };

	struct Record
	{
		std::string phoneNumber;
		std::string address;
	};

	struct HashNode 
	{
		Record record;
		NodeStatus status;
	};

	struct IndexSearchResult 
	{
		bool isFound;
		size_t index;
	};

	// TODO: overload operator []
	// TODO: overload operator <<
	class StringHashTable
	{
	public:
		StringHashTable();
		bool insert(std::string const& phoneNumber, std::string const& address);
		bool remove(std::string const& key);
		bool exists(std::string const& key);
		Record getValue(std::string const& key);
		~StringHashTable();
	private:
		static const int initialCapacity = 101;
		size_t size = 0;
		size_t capacity = initialCapacity;
		size_t c = 0;
		size_t d = 1;
		float rebuidlLoadFactor = 0.5;
		HashNode** table;

		IndexSearchResult findIndex(std::string const& key);
		IndexSearchResult findEmptyIndex(std::string const& key);
		bool isIndexExists(size_t const index);
		bool isIndexEmpty(size_t const index);

		size_t getHash(std::string const& key, size_t const& i);
		size_t getAsciiSum(std::string str);
		bool checkRebuild();
		void rehash();
	};

	class EmptyIndexNotFoundException : public std::exception 
	{
	public:
		const char* what() const override
		{
			return "Invalid probe function, cannot find free index";
		}
	};

	class KeyNotExistsException : public std::exception
	{
	public:
		const char* what() const override
		{
			return "Specified key not exists in hash table";
		}
	};
}