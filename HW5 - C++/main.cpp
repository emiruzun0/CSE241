#include <iostream>
#include <cstdlib>
#include "boardvector.h"
#include "onedarray.h"
#include "twodarray.h"
#include "board.h"

using namespace EmirBoard;
using namespace std;

int main(int argc,char* argv[]){
	srand(time(NULL));
	int choice;
	AbstractBoard *a ;
	cout << "Which board type do you want ? " << endl
	 	 << "1 - BoardVector " << endl
	 	 << "2 - One dimensional array" << endl
	 	 << "3 - Two dimensional array" << endl;
	do{
	cin >> choice;	
	if(choice  < 1 || choice > 3) cout << "You've entered wrong value ! Please try again";	
	}while(choice < 1 || choice > 3);

	if(choice == 1){
		BoardVector *puzzle;
		puzzle = new BoardVector;
		a = puzzle;
	}
	else if(choice == 2){
		OneDArray *puzzle;
		puzzle = new OneDArray;
		a = puzzle;
	}
	else{
		TwoDArray *puzzle;
		puzzle = new TwoDArray;
		a = puzzle;
	}

	
	//BoardVector puzzle;
	//OneDArray puzzle;
	//TwoDArray puzzle;
	//a = &puzzle;
 	
	
	string s;
	if(argc == 1){
		int row,column;
		cout << "Enter row and column in ordered : ";
		cin >> row >> column;
		a -> setSize(row,column);
		a -> fillRandomBoard();
	}
	else if(argc == 2){		//read from file.
 		s = *(argv+1);
 		a -> readFromFile(s);
 	}

 	a -> fill_finalboard();
 	a -> print();

 	char c;					//************************************************** GAMEPLAY *********************************************
	int random,control = 1,size;
	int move = 5000;
	string text;
	fstream input;
	cout << endl 
		 << "U : move the empty cell up." << endl 
		 << "D : move the empty cell down." << endl 
		 << "L : move the empty cell left." << endl
		 << "R : move the empty cell right." << endl
		 << "E : Asks a file name and saves the current board configuration as a loadable shape file." << endl
		 << "O : Asks a file name and loads the current board configuration from the shape file." << endl 
		 << "Q : Quit the game " << endl << endl ; 

	while(!(a->isSolved())){
		cout  << "Your move  : ";
		cin >> c;
		switch(c){
		        case 'l':
		        case 'L':
		      	case 'r':
		      	case 'R':
		        case 'd':
		        case 'D':
		        case 'u':
		        case 'U':
					a -> move(c);
					break;
				case 'E':
				case 'e':
					cout << "Enter a name for save(include .txt ) : " ;
					cin >> text;
					a -> writeToFile(text);
					break;
			   	case 'O':
			    case 'o':
					cout << "Enter a txt file which you'd like to load(Please enter  with '.txt' !) : ";
					cin >> text;
					a -> readFromFile(text);
 					a -> fill_finalboard();
					cout << "Loaded successfully ! " << endl << endl;
					break;
		        case 'q':
		        case 'Q':
		        	control = 0;
		        	cout << "Game is closing ... "<< endl;
		        	//cout << "Total number of moves : " << count << endl;
	        		//cout << "Total number of moves : " << count << endl;
		        	break;
				default : 
		       		cout << "You've entered wrong character.Try again ! " << endl;
		       	 	//print();
	        		break;
	    }
	   // cout << a->ValidSequence(a.board) ;
	    //control = a -> isSolved();
        if(c != 'q') a -> print();
        else break;;
        if(a->isSolved() && c != 'q') {
        	cout << "Problem Solved ! " << endl;
        }
   	}
   	cout << "Total move :" << a-> numberOfMoves() << endl;
   	cout << "Total created board : " << a->NumberOfBoards() << endl;
	return 0;
}