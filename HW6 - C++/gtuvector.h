#include "gtucontainer.h"
//#include "gtuiterator.cpp"

#ifndef GTUVECTOR_H
#define GTUVECTOR_H

namespace EmirUzun{
	template<class T>
	class GTUVector : public GTUContainer<T>
	{
	public:
		GTUVector();
		bool empty()const ;
		int size()const ;
		void insert(const T& element) ;
		void clear() ;
		void print();
		void erase(const T& element) ;
		int max_size() ;
		GTUIterator<T> begin()const;
		GTUIterator<T> end()const;
		T operator[](int index);
	};
}

#endif