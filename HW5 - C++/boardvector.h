#include <iostream>
#include <fstream>
#include <vector>
#include <string>


#ifndef BOARDVECTOR_H
#define BOARDVECTOR_H

#include "board.h"
#include <string>
using namespace std;

namespace EmirBoard{
	class BoardVector : public AbstractBoard
	{
	public:
		BoardVector();
		void print() ;
		void readFromFile(string filename) ;
		void writeToFile(string destination_f) ;
		void reset() ;
		void move(char move_char);
		bool isSolved();
		int str_to_int(string arr);
		void fill_finalboard();
		void fillRandomBoard();
		string int_to_str(int count);
		string operator()(int row,int column) ;
		bool operator==(const BoardVector& other)const  ;
		void find_coordinates();
		void find_elements();
		~BoardVector();
	private:
		vector <vector<string>> board;
		vector <vector<string>> finalboard;
	};
}

#endif