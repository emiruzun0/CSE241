#ifndef GTUCONTAINER_H
#define GTUCONTAINER_H

#include <iostream>
#include <memory>
#include <exception>
#include "gtuiterator.h"
#include "gtuiterator.cpp"

namespace EmirUzun{
		template<class T>
		class GTUContainer{
		public:
			virtual bool empty()const = 0 ;
			virtual int size()const = 0 ;
			virtual int max_size() = 0 ;
			virtual void insert(const T& element) = 0 ;
			//virtual void print() = 0;
			virtual void erase(const T& element) = 0 ;
			virtual void clear() = 0 ;
			virtual GTUIterator<T> begin()const = 0 ;
			virtual GTUIterator<T> end()const = 0 ;
		protected:
			int usedSize;
			int capacity;
			std::shared_ptr<T> container;
	};
}
#endif