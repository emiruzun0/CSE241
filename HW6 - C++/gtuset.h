#include "gtucontainer.h"

#ifndef GTUSET_H
#define GTUSET_H

namespace EmirUzun{
	template<class T>
	class GTUSet : public GTUContainer<T>
	{
	public:
		GTUSet();
		bool empty()const ;
		int size()const ;
		void insert(const T& element) ;
		void clear() ;
		void print();
		void erase(const T& element) ;
		int max_size() ;
		GTUIterator<T> begin()const;
		GTUIterator<T> end()const;
	};
}

#endif