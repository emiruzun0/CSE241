#include <iostream>
#include "gtuvector.h"

namespace EmirUzun{

	template <class T>
	GTUVector<T>::GTUVector(){
		this->usedSize=0;
		this->capacity = 10;
		std::shared_ptr<T> temp(new T[this->capacity]);
		this->container = temp;
	}


	template <class T >
	bool GTUVector<T>::empty()const{
        if(this->usedSize == 0) 	return true;
        else return false;
	}

	template <class T>
	int GTUVector<T>::size()const{
		return this->usedSize;
	}

	template <class T>
	void GTUVector<T>::insert(const T& element){
		if(this->usedSize != this->capacity){
			*(this->end()) = element;
			this->usedSize++;
			std::cout << "'" << element << "' was inserted to vector container ! " << std::endl << std::endl; 

		}
		else if(this->usedSize == this->capacity){
			this->capacity += 10;
			std::shared_ptr<T> temp(new T[this->capacity]);
			int index = 0;
			for(auto it = this->begin() ; it != this->end();++it){
				temp.get()[index] = *(it);
				index++;
			}
			this->container = nullptr;
			this->container = temp;
			*(this->end()) = element;
			std::cout << "'" << element << "' was inserted to vector container ! " << std::endl << std::endl; 
			this->usedSize++;		
		}
	}

	template <class T>
	void GTUVector<T>::clear(){
		this->usedSize = 0;
	}

	template <class T>
	void GTUVector<T>::print(){
		
	}

	template <class T>
	void GTUVector<T>::erase(const T& element){
		for(auto it = this->begin(); it != this->end();++it){
			if(*(it) == element){
				for(auto it2 = it;it2 != this->end();++it2){
					*(it2) = *(it2.getPtr()+1);
				}
				std::cout << "'" << element << "' was erased to vector container ! " << std::endl << std::endl; 
				this->usedSize--;
				return;
			}
		}
		throw std::invalid_argument("This element is not in the vector ! ");
		return;
	}

	template <class T>
	GTUIterator<T> GTUVector<T>::begin()const{
		return (this->container).get();
	}

	template <class T>
	GTUIterator<T> GTUVector<T>::end()const{
		GTUIterator<T> it = (this->container).get() ;
		for(int i = 0;i<this->usedSize;++i){
			it++;
		}
		return it;
	}

	template <class T> 
	int GTUVector<T>::max_size(){
		return this->capacity;
	}

	template <class T>
	T GTUVector<T>::operator[](int index){
		return *(this->container);
	}
}

