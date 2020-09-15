#include <iostream>
#include "gtuset.h"

namespace EmirUzun{
	template <class T>
	GTUSet<T>::GTUSet(){
		this->usedSize=0;
		this->capacity = 10;
		std::shared_ptr<T> temp(new T[this->capacity]);
		this->container = temp;
	}


	template <class T >
	bool GTUSet<T>::empty()const{
        if(this->usedSize == 0) 	return true;
        else return false;
	}

	template <class T>
	int GTUSet<T>::size()const{
		return this->usedSize;
	}

	template <class T>
	void GTUSet<T>::insert(const T& element){

		for(auto it = this->begin(); it != this->end(); ++it){
			if(*(it) == element){
				throw std::invalid_argument("This element is already in the set container ! ");
				return;
			}
		}

		if(this->usedSize != this->capacity){
			*(this->end()) = element;
			std::cout << "'" << element << "' was inserted to set container ! " << std::endl; 
			this->usedSize++;
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
			std::cout << "'" << element << "' was inserted to set container ! " << std::endl; 
			this->usedSize++;		
		}
	}

	template <class T>
	void GTUSet<T>::clear(){
		this->usedSize = 0;
	}

	template <class T>
	void GTUSet<T>::print(){
		
	}

	template <class T>
	void GTUSet<T>::erase(const T& element){
		for(auto it = this->begin(); it != this->end();++it){
			if(*(it) == element){
				for(auto it2 = it;it2 != this->end();++it2){
					*(it2) = *(it2.getPtr()+1);
				}
				std::cout << "'" << element << "' was erased ! " << std::endl;
				this->usedSize--;
				return;
			}
		}
		std::cout << "This element '"  << element << "' was not found ! " << std::endl;
	}

	template <class T>
	GTUIterator<T> GTUSet<T>::begin()const{
		return (this->container).get();
	}

	template <class T>
	GTUIterator<T> GTUSet<T>::end()const{
		GTUIterator<T> it = (this->container).get() ;
		for(int i = 0;i<this->usedSize;++i){
			it++;
		}
		return it;
	}

	template <class T> 
	int GTUSet<T>::max_size(){
		return this->capacity;
	}

}
