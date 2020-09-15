#include <iostream>
#include <string>
#include "boardvector.h"


using std::cout;

namespace EmirBoard{

	BoardVector::BoardVector() :
		AbstractBoard()
	{}

	void BoardVector::readFromFile(string filename){
		string temp,text;
		fstream input;
		int num_of_lines=0,_row=0,_column=0 ;
		input.open(filename);
		if(!input){
			cout << "The file didn't found ! \n";
			exit(1);
		}
		while(getline(input,temp)){
			++_row;
		}
		row = _row;
		input.close();
		input.open(filename);
		while(input >> temp){	//finding how many element area has
			_column++;
		}
		column = _column / row;
		_row = _column = 0;
		input.close();
		input.open(filename);
		board.resize(row);
		while( _row<row){
			board[_row].resize(column);
			++_row;
		}
		_row = _column = 0;
		while(input >> text){
			board[_row][_column]=text;

			if(_column<column-1){	//filling area with informations within file
				_column++;
			}
			else{
				_column=0;
				_row++;
			}
		}
		input.close();

		find_coordinates();
	}

	void BoardVector::find_coordinates(){
		int i,j;
	 	for(i=0;i<row;++i){
	    	for(j=0;j<column;++j){
	      		if(board[i][j] == "bb" ){
		        	x = i;
		        	y = j;
		        	break;
	      		}
	    	}
	  	}
 	}

 	int BoardVector::str_to_int(string arr){		//converts from string to integer.
		int val=0;

		val+=(arr[0]-48)*10;
		val+=arr[1]-48;

		return val;
	}

	string BoardVector::int_to_str(int count){		//converts from integer to string.
		char arr[2];
		int a,b;
		if(count < 10){
			arr[0] = '0';
			arr[1] = char(count+48);
		}
		else{
			a = count/10;
			b = count - a*10;
			arr[0] = char(a+48);
			arr[1] = char(b+48);
		}
		return arr;
	}

	void BoardVector::fillRandomBoard(){
		int i,j,c;
	  	decltype(i) s = row*column; 
		auto temp = 0 ;
		auto f = 0;
		int arr2[s],arr[row][column];
		i = 0;
		board.resize(row);
		while(i<row){
			board[i].resize(column);
			++i;
		}
		for(i=0;i<s; ++i){      //Firstly, I filled the array with '-1' 
		  arr2[i] = -1;
		}
		for(i=0;i<row;++i){
		  for(j=0;j<column;++j){
		    arr[i][j] = -1;   
		  }
		}
		for (i = 0; i < row; ++i){       //  This loop is used for we do not want to reproduce a generated number
		  for (j = 0; j < column; ++j){
		    c = rand() %s ;
		    f=0;
		    while(f<s){
		      if(arr2[f] == c){
		        c = rand() %s ;
		        f=0;
		      }
		      else f++;
		    }
		    arr2[temp] = c;
		    arr[i][j] = c;
		    temp++; 
		  }
		}
		c=0;
		for(i=0;i<row;++i){
		  for(j=0;j<column;++j){
		  	board[i][j]=int_to_str(arr2[c]);
		  	c++;
		  	if(board[i][j] == "00")		board[i][j]="bb";
		 }
		}
		find_coordinates();
	}


	void BoardVector::move(char move_char){
		string temp;
		switch(move_char){
			case 'l':
			case 'L':
				if(y != 0 && board[x][y-1] != "00"){
				  //if(intelligence == 1) cout<<endl<<"Intelligent move choose : L"<<endl;
				  	temp = board[x][y-1];
				 	board[x][y-1] = board[x][y];
				    board[x][y] = temp; 
				    y--;
				    last_move = 'L';
				    countMoves++;
				}
  				else  cout<< endl << "This is invalid move.Try again ! "<<endl << endl ;
				break;
			case 'r':
			case 'R':
				if(y != column-1 && board[x][y+1] != "00"){
				    //if(intelligence == 1) cout<<endl<<"Intelligent move choose : R"<<endl;
				    temp = board[x][y+1];
				    board[x][y+1] = board[x][y];
				    board[x][y] = temp; 
				    y++;
				    last_move = 'R';
				    countMoves++;
				}
				else  cout<< endl << "This is invalid move.Try again ! "<<endl << endl ;
				break;
			case 'u':
			case 'U':
			  	if(x != 0 && board[x-1][y] != "00"){
				   // if(intelligence == 1) cout<<endl<<"Intelligent move choose : U"<<endl;
				    temp = board[x-1][y];
				    board[x-1][y] = board[x][y];
				    board[x][y] = temp; 
				    x--;
			    	last_move = 'U';
			    	countMoves++;
			  	}
			  	else  cout<< endl << "This is invalid move.Try again ! "<<endl << endl ;
				break;
			case 'd':
			case 'D':
			 	if(x != row-1 && board[x+1][y] != "00"){
				    //if(intelligence == 1) cout<<endl<<"Intelligent move choose : D"<<endl;
				    temp = board[x+1][y];
				    board[x+1][y] = board[x][y];
				    board[x][y] = temp; 
				    x++;
				    last_move = 'D';
				    countMoves++;
				}
				else   cout<< endl << "This is invalid move.Try again ! "<<endl << endl ;
				break;
		}
	}

	string BoardVector::operator()(int row,int column){
		return board[row][column];
	}

	void BoardVector::writeToFile(string destination_f){
		int i,j;
		string filename;
		ofstream text_file; 
		//cout << "Enter a file name for save : (Please write the name with '.txt' ) : ";
		//cin >> filename;
		text_file.open(destination_f);
		for(i=0;i<row;++i){
			for(j=0;j<column;++j){
				text_file << board[i][j] << "  " ; 
			}
			text_file << endl;
		}
		text_file.close(); 
		cout << endl << "Saved successfully ! " << endl << endl;
	}

	void BoardVector::fill_finalboard(){
		int count = 1;
		int i,j;
		i = j = 0;
		finalboard.resize(row);
		while(i < row){
			finalboard[i].resize(column);
			++i;
		}

    	for(i=0;i<row;++i){
    		for(j=0;j<column;++j){
    			finalboard[i][j] = board[i][j];
    		}
    	}

    	find_elements();
	    for(i=0;i<row;++i){              
	        for(j=0;j<column;++j){
	           	if(finalboard[i][j] != "00"){
		      	   	if(i == row-1 && j == column-1) 	  finalboard[i][j] = "bb";
		      	   	else{
		      		   finalboard[i][j] = int_to_str(count);
		      		   count++;
	      			}	
	      		}
	   		}
	 	}
	}

	void BoardVector::print(){
		int i,j;
		cout << endl;
		for(i=0;i<row;++i){
			for(j=0;j<column;++j){
			cout.width(3);
		  	cout << board[i][j] << "  " ;
		  	}
		 	cout << endl;
		}
		cout << endl;
	}

	void BoardVector::reset(){
	 	int i,j,count = 1;
	    int size = row*column;
	    for(i=0;i<row;++i){              
	        for(j=0;j<column;++j){
	           	if(board[i][j] != "00"){
		      	   	if(i == row-1 && j == column-1) 	  board[i][j] = "bb";
		      	   	else{
		      		   board[i][j] = to_string(count);
		      		   count++;
	      			}	
	      		}
	   		}
	 	}
	  	x=i-1;
	  	y=j-1;
	}

	void BoardVector::find_elements(){		//it finds the number of elements which is not "00"
		int i,j,count = 0 ;
		for(i=0;i<row;++i){
			for(j=0;j<column;++j){
				if(board[i][j] != "00"  ){
					count++;
				}
			}
		}
		numOfElements = count;
	}

	bool BoardVector::isSolved(){	//it controls the board for the finish
		BoardVector otherboard;
		otherboard.board.resize(row);
		for(int i=0;i<row;++i)
			otherboard.board[i].resize(column);

		for(int i=0;i<row;++i){
			for(int j=0;j<column;++j)
				otherboard.board[i][j] = finalboard[i][j];
		}

		if(*this == otherboard) return true;
		else return false;
	}

	bool BoardVector::operator==(const BoardVector& other)const  {
		for(int i=0;i<row;++i){
			for(int j=0;j<column;++j){
				if(board[i][j] != other.board[i][j] ) 	return false;
			}
		}
		return true;
	}

	BoardVector::~BoardVector(){
		countBoards--;
	}
}

/*int main(int argc,char* argv[]){
	return 0;
}*/