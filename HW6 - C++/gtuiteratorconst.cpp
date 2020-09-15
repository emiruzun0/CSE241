#include <iostream>
#include "gtuiteratorconst.h"


namespace EmirUzun{
	template<class T>
	GTUIteratorConst<T>::GTUIteratorConst(T* object){
		ptr = object;
	}

	template <class T>
	GTUIteratorConst<T>::~GTUIteratorConst(){

	}

	template<class T>
	GTUIteratorConst<T>& GTUIteratorConst<T>::operator=(const GTUIteratorConst<T>& other){
		ptr=other.ptr;
		return *this;
	};


	template<class T>
	GTUIteratorConst<T>& GTUIteratorConst<T>::operator++()
	{
		ptr++;
		return *this;
	}

	template<class T>
	GTUIteratorConst<T> GTUIteratorConst<T>::operator++(int)
	{
		GTUIteratorConst<T> temp = *this;
 		++ptr;
  		return temp;
	}

	template<class T>	
	GTUIteratorConst<T>& GTUIteratorConst<T>::operator--(){
		ptr--;
		return *ptr;
	};

	template<class T>
	GTUIteratorConst<T> GTUIteratorConst<T>::operator--(int){
		GTUIteratorConst<T> temp = *this;
  		--ptr;
  		return temp;
	};

	template<class T>
	T& GTUIteratorConst<T>::operator*()const{
		return *ptr;
	};

	template<class T>
	T* GTUIteratorConst<T>::operator->()const{
		return ptr;
	};

	template <class T>
	T* GTUIteratorConst<T>::getPtr()const{
		return ptr;
	}

	template<class T>
	bool GTUIteratorConst<T>::operator==(const GTUIteratorConst<T>& other)const{
		return (this->ptr == other.ptr);
	};

	template<class T>
	bool GTUIteratorConst<T>::operator!=(const GTUIteratorConst<T>& other)const{
		return (this->ptr != other.ptr);
	};

}
