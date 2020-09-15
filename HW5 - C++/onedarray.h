#include <iostream>
#include <fstream>


#ifndef ONEDARRAY_H
#define ONEDARRAY_H


#include "board.h"
#include <string>
using namespace std;

namespace EmirBoard{
	class OneDArray : public AbstractBoard
	{
	public:
		OneDArray();
		void print() ;
		void readFromFile(string filename) ;
		void writeToFile(string destination_f) ;
		void move(char move_char);
		void reset();
		void find_coordinates();
		void find_elements();
		bool isSolved();
		int str_to_int(string arr);
		void fill_finalboard();
		void fillRandomBoard();
		string int_to_str(int count);
		string operator()(int row,int column) ;
		bool operator==(const OneDArray& other)const ;
		~OneDArray();
	private:
		string* board;
		string* finalboard;
	};
}


#endif