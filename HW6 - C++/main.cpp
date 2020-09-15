#include <iostream>
#include <algorithm>
#include "gtuiteratorconst.cpp"
#include "gtuvector.cpp"
#include "gtuset.h"
#include "gtuset.cpp"

using namespace EmirUzun;
using std::cout;
using std::endl;

template <typename T>
void printContainer(const GTUContainer<T> &container);		//My print function. I couldn't do global functions


int main(){
	try{
		GTUVector<int> vector;		//Create vector container
		cout << "*********EMIRHAN UZUN'S VECTOR CONTAINER TEST*****************" << endl;
		vector.insert(77);
		printContainer(vector);
		vector.insert(155);
		printContainer(vector);
		vector.insert(236);
		printContainer(vector);
		vector.insert(345);
		printContainer(vector);
		vector.insert(418);
		printContainer(vector);
		cout << "Vector Size :  " << vector.size() << endl
			 << "Vector Maximum Size : " << vector.max_size() << endl;
		vector.erase(345);
		printContainer(vector);

		cout << endl << "Vector Size :  " << vector.size() << endl
			 << "Vector Maximum Size : " << vector.max_size() << endl;
		vector.erase(78);		//throw exception
		printContainer(vector);
	}
	catch(const std::exception &fault){
		std::cout << fault.what() << endl;  	//This what() function finds the exception handle and prints it.
	}

	cout << "**************************************************************" << endl
		 << "**************************************************************" << endl << endl;

	cout << "*********EMIRHAN UZUN'S SET CONTAINER TEST*****************" << endl;
	try{
		GTUSet<int> set;			//Create set container 
		set.insert(58);
		printContainer(set);
		cout << "Set Size :  " << set.size() << endl
			 << "Set Maximum Size : " << set.max_size() << endl;
		set.insert(97);
		printContainer(set);
		set.insert(110);
		printContainer(set);
		set.insert(288);
		printContainer(set);
		set.erase(110);				
		printContainer(set);
		cout << "Set Size :  " << set.size() << endl
			 << "Set Maximum Size : " << set.max_size() << endl;
		set.insert(97);				//to see the throw exception
		printContainer(set);
		
	} catch(const std::exception &fault){
		std::cout << fault.what() << endl;  	//This what() function finds the exception handle and prints it.
	}

	cout << "**************************************************************" << endl
		 << "************************FINISH********************************" << endl;
	return 0;
}

template <typename T>
void printContainer(const GTUContainer<T> &container){
	for(auto it = container.begin(); it != container.end(); ++it)
		cout << *(it) << " -- ";
	cout << endl << endl;
}
