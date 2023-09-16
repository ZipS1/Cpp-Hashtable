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
	class StringHashTable
	{
	public:
		StringHashTable();
		bool insert(std::string key, std::string value);
		bool remove(std::string key);
		std::string getValue(std::string key);
		// TODO: make it iterable
		// TODO: overload operator []
		~StringHashTable();
	private:
		static const int initialSize = 10;
		int size = initialSize;
		std::string* table;

		int hash(std::string key);
		int getAsciiSum(std::string str);

	};
}