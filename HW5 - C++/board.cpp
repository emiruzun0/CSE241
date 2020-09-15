#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "board.h"

using namespace std;

namespace EmirBoard{
	int AbstractBoard::countBoards = 0;
	int AbstractBoard::countMoves = 0;


	AbstractBoard::AbstractBoard(){
		row = column = 0;
		x = y = 0; 	
		numOfElements = 0;
		last_move = 'S';
		countBoards++;
	}

	void AbstractBoard::setSize(int _row ,int _column){
		row = _row;
		column = _column;
	}

	char AbstractBoard::lastMove(){
		return last_move;
	}

	int AbstractBoard::numberOfMoves(){
		return countMoves;
	}

	int AbstractBoard::NumberOfBoards(){
		return countBoards;
	}

	void AbstractBoard::temp_coordinates(int& tempx,int& tempy){
		tempx = x;
		tempy = y;
	}

	bool ValidSequence(vector <AbstractBoard*> board){
		int i,size;
		int x1,x2,y1,y2;

		//size = sizeof(*board) / sizeof(AbstractBoard);
		//cout << size << endl << endl;
		for(i=0;i<board.size()-1;++i){
			board[i]->temp_coordinates(x1,y1);
			board[i+1]->temp_coordinates(x2,y2);
			cout << x1 << " "<< y1 << " " << x2 << " " << y2 ;
			else if((x1 != x2) && (y1 != y2))	return false;	//if its coordinates change both of them, then it is not valid.
		}

		if (board.back()->isSolved() )	return true;
		//return false;

		return true;

	}


	/*string AbstractBoard::operator()(int row,int column){}
	bool AbstractBoard::operator==(const AbstractBoard& other) {}*/
}

