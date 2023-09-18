#pragma once
#include <string>

/*
* ќткрыта€ адресаци€ (квадратичное пробирование).
* —труктура элемента:
* номер телефона (10 символов) -> адрес
* 
* ƒопущение: валидаци€ номера не происходит,
* т.е. в качестве номера сработает
* ЋёЅјя последовательность из 10 символов.
*/

/*
*  вадратичное пробирование
* адрес = h(x)+ci+d(i^2)
*/

/*
* ќпределение хэша
* h(x) = x mod size
* где x Ц ключевое значение, 
* size Ц наибольшее необходимое количество различных значений хешфункции\
* (и, как следствие, допустимое количество записей в динамическом множестве).
*/




namespace HashTable
{
	struct HashNode {
		std::string phoneNumber;
		std::string address;
	};

	// TODO: overload operator []
	// TODO: overload operator <<
	class StringHashTable
	{
	public:
		StringHashTable();
		bool insert(HashNode node);
		bool remove(std::string const& key);
		bool exists(std::string const& key);
		HashNode getValue(std::string const& key);
		~StringHashTable();
	private:
		static const int initialCapacity = 20;
		size_t size = 0;
		size_t capacity = initialCapacity;
		size_t c = 0;
		size_t d = 1;
		float rebuidlLoadFactor = 0.5;
		HashNode** table;

		size_t findIndex(std::string const& key);
		bool isIndexEmpty(size_t const index);

		size_t getHash(std::string const& key, size_t const& i);
		size_t getAsciiSum(std::string str);
		bool checkRebuild();
		void rehash();

	};

	class FreeIndexNotFoundException : public std::exception 
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