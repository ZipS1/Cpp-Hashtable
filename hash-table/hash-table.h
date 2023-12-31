#pragma once
#include <string>

/*
* �������� ��������� (������������ ������������).
* ��������� ��������:
* ����� �������� (10 ��������) -> �����
* 
* ���������: ��������� ������ �� ����������,
* �.�. � �������� ������ ���������
* ����� ������������������ ��������.
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

		friend bool operator==(const Record& a, const Record& b);
	};

	inline bool operator==(const Record& a, const Record& b)
	{
		return a.phoneNumber == b.phoneNumber && a.address == b.address;
	}

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

	class StringHashTable
	{
	public:
		StringHashTable();
		bool insert(Record const& record);
		bool remove(std::string const& key);
		bool exists(std::string const& key);
		Record getValue(std::string const& key);
		size_t getSize() const { return size; }
		size_t getCapacity() const { return capacity; }
		~StringHashTable();

		Record operator[](std::string const& key) { return getValue(key); }

#pragma region iterator
		class iterator : public std::iterator
			<std::input_iterator_tag, HashNode, int, const Record*, Record>
		{
		public:
			iterator(HashNode** const table, size_t const capacity, size_t index) :
				table(table), index(index), capacity(capacity) {}
			iterator& operator++() 
			{
				for (index++; index != capacity && isIndexEmpty(); index++);
				return *this;
			}
			iterator operator++(int) 
			{
				auto retval = *this;
				for (index++; index != capacity && isIndexEmpty(); index++);
				return retval;
			}
			bool operator==(iterator other) const { return this->index == other.index; }
			bool operator!=(iterator other) const { return !(*this == other); }
			reference operator*() const { return table[index]->record; }
			pointer operator->() const { return &table[index]->record; }

		private:
			HashNode** const table;
			size_t const capacity;
			size_t index;
			bool isIndexEmpty() { return table[index] == nullptr || table[index]->status == NodeStatus::Deleted; }
		};
#pragma endregion
		iterator begin();
		iterator end();
	private:
		static const int initialCapacity = 100;
		size_t size = 0;
		size_t capacity = initialCapacity;
		size_t c = 0;
		size_t d = 1;
		float rebuidlLoadFactor = 0.5;
		HashNode** table;

		void insertExistingKey(Record const& record);
		void insertNewKey(Record const& record);
		IndexSearchResult findIndex(std::string const& key);
		IndexSearchResult findEmptyIndex(std::string const& key);
		bool isIndexExists(size_t const index);

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