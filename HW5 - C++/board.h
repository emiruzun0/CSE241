#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

#ifndef BOARD_H
#define BOARD_H

#include <string>
using namespace std;

namespace EmirBoard{
	class AbstractBoard
	{
	public:
		AbstractBoard();
		void setSize(int _row ,int _column) ;
		char lastMove() ;
		void temp_coordinates(int& tempx,int& tempy);
		static int numberOfMoves();
		static int NumberOfBoards();
		virtual void writeToFile(string destination_f) = 0;
		virtual void print() = 0;
		virtual void reset() = 0 ;
		virtual void readFromFile(string filename) = 0;
		virtual void move(char move_char)= 0;
		virtual bool isSolved()= 0;
		virtual void fill_finalboard() = 0;
		virtual void fillRandomBoard() = 0;
		virtual string int_to_str(int count) = 0;
		virtual void find_elements() = 0;
		virtual void find_coordinates() = 0;
		virtual string operator()(int row,int column) = 0;
		//virtual bool operator==(const AbstractBoard& other)const =0 ;
	protected:
		int row,column;
		int x,y; 	
		int numOfElements = 0;
		static int countMoves ;	
		static int countBoards ;
		char last_move = 'S'; 
	};
	bool ValidSequence(vector <AbstractBoard*> board);
}

#endif