#include <iostream>
#include "gtuiterator.h"


namespace EmirUzun{
	template<class T>
	GTUIterator<T>::GTUIterator(T* object){
		ptr = object;
	}

	template <class T>
	GTUIterator<T>::~GTUIterator(){

	}

	template<class T>
	GTUIterator<T>& GTUIterator<T>::operator=(const GTUIterator<T>& other){
		ptr=other.ptr;
		return *this;
	};


	template<class T>
	GTUIterator<T>& GTUIterator<T>::operator++()
	{
		ptr++;
		return *this;
	}

	template<class T>
	GTUIterator<T> GTUIterator<T>::operator++(int)
	{
		GTUIterator<T> temp = *this;
 		++ptr;
  		return temp;
	}

	template<class T>	
	GTUIterator<T>& GTUIterator<T>::operator--(){
		ptr--;
		return *ptr;
	};

	template<class T>
	GTUIterator<T> GTUIterator<T>::operator--(int){
		GTUIterator<T> temp = *this;
  		--ptr;
  		return temp;
	};

	template<class T>
	T& GTUIterator<T>::operator*(){
		return *ptr;
	};

	template<class T>
	T* GTUIterator<T>::operator->(){
		return ptr;
	};

	template <class T>
	T* GTUIterator<T>::getPtr()const{
		return ptr;
	}

	template<class T>
	bool GTUIterator<T>::operator==(const GTUIterator<T>& other)const{
		return (this->ptr == other.ptr);
	};

	template<class T>
	bool GTUIterator<T>::operator!=(const GTUIterator<T>& other)const{
		return (this->ptr != other.ptr);
	};

}
