#include <iostream>
#include "onedarray.h"


using namespace std;

namespace EmirBoard{
	OneDArray::OneDArray():
		AbstractBoard()
	{}

	void OneDArray::print(){
		int i,j ;
		i = j = 0;
		cout << endl;
		while(i < row*column){
			while(j < column ){
				cout.width(3);
				cout << board[i] << " " ;
				j++;
				i++;
			}
			j = 0;
			cout << endl;
		}
		cout << endl;
	}

	void OneDArray::readFromFile(string filename){
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
		board = new string[row*column];
		_row = _column = 0;
		while(input >> text){
			board[_row]=text;	//filling area with informations within file
			_row++;
		}
		input.close();

		find_coordinates();
	}

	void OneDArray::writeToFile(string destination_f){
		int i,j;
		i = j = 0;
		string filename;
		ofstream text_file; 
		//cout << "Enter a file name for save : (Please write the name with '.txt' ) : ";
		//cin >> filename;

		text_file.open(destination_f);
		while(i < row*column){
			while(j < column){
				text_file << board[j] << "  " ; 
				j++;
				i++;
			}
			text_file << endl;
			j = 0;	
		}
		text_file.close(); 
		cout << endl << "Saved successfully ! " << endl << endl;
	}

	void OneDArray::fill_finalboard(){
		int count = 1;
		int i,j;
		finalboard = new string[row*column];

    	for(i=0;i<row*column;++i){
    		finalboard[i] = board[i];
    	}

    	find_elements();
	    for(i=0;i<row*column;++i){              
           	if(finalboard[i] != "00"){
	      	   	if(i == (row*column)-1 ) 	  finalboard[i] = "bb";
	      	   	else{
	      		   finalboard[i] = int_to_str(count);
	      		   count++;
      			}	
      		}
	 	}
	}

	void OneDArray::reset(){
	 	int i,j,count = 1;
	    int size = row*column;
	    for(i=0;i<size;++i){              
           	if(board[i] != "00"){
	      	   	if(i == size-1 ) 	  board[i] = "bb";
	      	   	else{
	      		   board[i] = int_to_str(count);
	      		   count++;
      			}	
      		}
	 	}
	  	y=i-1;
	}

	void OneDArray::find_coordinates(){
		int i,j;
	 	for(i=0;i<row*column;++i){
      		if(board[i] == "bb" ){
	        	y = i;
	        	break;
      		}
	  	}
 	}
	void OneDArray::move(char move_char){
 		string temp;
		switch(move_char){
			case 'l':
			case 'L':
				if(y%column != 0 && board[y-1] != "00"){
				  //if(intelligence == 1) cout<<endl<<"Intelligent move choose : L"<<endl;
				  	temp = board[y-1];
				 	board[y-1] = board[y];
				    board[y] = temp; 
				    y--;
				    last_move = 'L';
				    countMoves++;
				}
  				else  cout<< endl << "This is invalid move.Try again ! "<<endl << endl ;
				break;
			case 'r':
			case 'R':
				if(y%column != column-1 && board[y+1] != "00"){
				    //if(intelligence == 1) cout<<endl<<"Intelligent move choose : R"<<endl;
				    temp = board[y+1];
				    board[y+1] = board[y];
				    board[y] = temp; 
				    y++;
				    last_move = 'R';
				    countMoves++;
				}
				else  cout<< endl << "This is invalid move.Try again ! "<<endl << endl ;
				break;
			case 'u':
			case 'U':
			  	if(y > column && board[y-column] != "00"){
				   // if(intelligence == 1) cout<<endl<<"Intelligent move choose : U"<<endl;
				    temp = board[y-column];
				    board[y-column] = board[y];
				    board[y] = temp; 
				    y -= column;
			    	last_move = 'U';
			    	countMoves++;
			  	}
			  	else  cout<< endl << "This is invalid move.Try again ! "<<endl << endl ;
				break;
			case 'd':
			case 'D':
			 	if(y < (row-1)*column && board[y+column] != "00"){
				    //if(intelligence == 1) cout<<endl<<"Intelligent move choose : D"<<endl;
				    temp = board[y+column];
				    board[y+column] = board[y];
				    board[y] = temp; 
				    y += column;
				    last_move = 'D';
				    countMoves++;
				}
				else   cout<< endl << "This is invalid move.Try again ! "<<endl << endl ;
				break;
		}
	}

	void OneDArray::find_elements(){		//it finds the number of elements which is not "00"
		int i,j,count = 0 ;
		for(i=0;i<row*column;++i){
			if(board[i] != "00"  ){
				count++;
			}
		}
		numOfElements = count;
	}

	int OneDArray::str_to_int(string arr){		//converts from string to integer.
		int val=0;

		val+=(arr[0]-48)*10;
		val+=arr[1]-48;

		return val;
	}

	string OneDArray::int_to_str(int count){		//converts from integer to string.
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

	void OneDArray::fillRandomBoard(){
		int i,j,c;
	  	decltype(i) s = row*column; 
		auto temp = 0 ;
		auto f = 0;
		int arr2[s],arr[row][column];
		i = 0;
		board = new string[row*column];
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
		for(i=0;i<row*column;++i){
		  	board[i]=int_to_str(arr2[c]);
		  	c++;
		  	if(board[i] == "00")		board[i]="bb";
		}
		find_coordinates();
	}


	bool OneDArray::isSolved(){
		OneDArray otherboard;
		otherboard.board = new string[row*column];

		for(int i=0;i<row*column;++i){
			otherboard.board[i] = finalboard[i];
		}
		if(*this== otherboard) 	return true;
		else return false;
	}

	string OneDArray::operator()(int row,int column){
		return board[column];
	}

	bool OneDArray::operator==(const OneDArray& other)const {
		for(int i=0;i<row*column;++i){
			if(board[i] != other.board[i] ) 	return false;
		}
		return true;
	}

	OneDArray::~OneDArray(){
		countBoards--;
	}

}