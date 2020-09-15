#include <iostream>

#ifndef GTUITERATOR_H
#define GTUITERATOR_H
namespace EmirUzun{
	template<class T>
	class GTUIterator{
	public:
		GTUIterator(T* object);
		~GTUIterator();

		GTUIterator& operator++();
		GTUIterator operator++(int);	
		GTUIterator& operator--();
		GTUIterator operator--(int);
		T& operator*();
		T* operator->();
		T* getPtr()const;
		GTUIterator& operator=(const GTUIterator& other);
		bool operator==(const GTUIterator& other)const;
		bool operator!=(const GTUIterator& other)const;

	private:
		T* ptr;

	};
}
#endif