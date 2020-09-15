#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;
class Board;

class NPuzzle{
private:
	class Board{
	private:
		vector <vector<string>> board;
		vector <vector <string >> correct ;
		vector <string> temp;
		vector <int> final_board;
		int row;
		int column;
		int x,y ;		// bb's coordinates.
		int a,control,flag;
		int pre = -1;	//previous move for the intelligent.For instance, if the previous move is left,then intelligence doesn't move the rigth not to enter loop
		int last_move;
		int num_of_moves = 0;
		int NumberOfBoards = 0;
	public:
		void readFromFile(string s);
		void setsize(int a,int b);
		void fill_array();
		string i_to_s(int count);
		int s_to_i(string value);
		int move(char c,int intelligence);
		int move_left(int intelligence);
		int move_right(int intelligence);
		int move_up(int intelligence);
		int move_down(int intelligence);
		void print();
		int find_elements();
		void find_coordinates();
		bool isSolved();
		int findsize();
		void shuffle();
		void reset();
		void moveRandom(int size);
		void writeToFile();
		void printReport(int& count);
		void get_row_column(int& row,int& column);
		string operator()(int i,int j){
			return board[i][j]; 
		};
		bool operator==(Board& x){
			int i,j;
			int row,column;
			x.get_row_column(row,column);
			for(i=0;i<row;++i){
				for(j=0;j<column;++j){
					if(x.correct[i][j] != x.board[i][j]){
						return false;
					}
				}
			}
			return true;
		};
	};
public:
	void writeToFile(){
		gameboard[0].writeToFile();
	}

	void readFromFile(string s){
		gameboard.resize(1);
	gameboard[0].readFromFile(s);
	}

	void print(){
		gameboard[0].print();
	}

	void setsize();
	void fill_array(){
		gameboard[0].fill_array();
	}

	int move(char c,int intelligence){
		return gameboard[0].move(c,intelligence);
	}

	int find_elements(){
		gameboard[0].find_elements();
	}

	bool isSolved(){
		return gameboard[0].isSolved();
	}

	int solvePuzzle();
	int findsize(){
		return gameboard[0].findsize();
	}

	void shuffle(int size){
		reset();
		moveRandom(size);
	}

	void reset(){
		gameboard[0].reset();
	}

	void moveRandom(int size){
		gameboard[0].moveRandom(size);
	}

	void printReport(int& count){
		gameboard[0].printReport(count);
	}

	void get_row_column(int& a,int& b){
		gameboard[0].get_row_column(a,b);
	}

	vector  <Board> gameboard;
	friend ostream& operator<<(ostream& out, NPuzzle& object ){
		int i,j;
		int row,columnn;
		object.get_row_column(row,columnn);
		out << endl;
		for(i=0;i<row;++i){
		  for(j=0;j<columnn;++j){
		  	out << object.gameboard[0](i,j) << "  " ;
		  }
		  out << endl;
		}
		out << endl;

		return out;
	};
	
};

int main(int argc,char* argv[]){
	NPuzzle game;
	//vector <vector <string> > board;
	string s;
	if(argc == 1){			//if user don't enter the file bane,program creates a random board.
		game.setsize();
		game.fill_array();
 	}
 	else if(argc == 2){		//read from file.
 		s = *(argv+1);
 		game.readFromFile(s);
 	}

 	game.find_elements();
	//game.isSolved();
	//game.print();
	//cout << game;

	cout << game;
 	char c;					//************************************************** GAMEPLAY *********************************************
	int i,j;
	int random,flag,control = 1,count=0,pre = -1,size;
	int move = 5000;
	string text;
	fstream input;
	cout << endl 
		 << "U : move the empty cell up." << endl 
		 << "D : move the empty cell down." << endl 
		 << "L : move the empty cell left." << endl
		 << "R : move the empty cell right." << endl
		 << "S : takes the board to the final solution, and makes row*column random moves to shuffle the board." << endl
		 << "I : makes an “intelligent move" << endl
		 << "V : Solves the problem from the current configuration using the new intelligent algorithm." << endl
		 << "T : Prints a report about how many moves have been done and if the solution is found" << endl
		 << "E : Asks a file name and saves the current board configuration as a loadable shape file." << endl
		 << "O : Asks a file name and loads the current board configuration from the shape file." << endl 
		 << "Q : Quit the game " << endl << endl ; 


	while(control){
		cout  << "Your move  : ";
		cin >> c;
		switch(c){
		      case 'l':
		      case 'L':
		        	flag = game.move(c,0);    // '0' parameter means it is not the intelligent move.
		       		if(flag) count++;
		        	break;
		        case 'r':
		      	case 'R':
		        	flag = game.move(c,0);  
		       		if(flag) count++;
		        	break;
		        case 'd':
		        case 'D':
		        	flag = game.move(c,0);
		        	if(flag) count++;
		        	break;
		        case 'u':
		        case 'U':
		        	flag = game.move(c,0);
		        	if(flag) count++;
		        	break;
		        case 's':
	     		case 'S':
	        		flag = 1;
	        		size = game.findsize();
	        		game.shuffle(size);
	        		count++;
	        		break;
	        	case 'E':
	        	case 'e':
	        		flag = 1;
	        		game.writeToFile();
	        		//print();
			       	break;
			   	case 'O':
			    case 'o':
			    	flag = 1;
					cout << "Enter a txt file which you'd like to load(Please enter  with '.txt' !) : ";
					cin >> text;
					game.readFromFile(text);
					game.find_elements();
					cout << "Loaded successfully ! " << endl << endl;
					flag =1;
					break;
				case 't':
				case 'T':
					flag = 1;
					game.printReport(count);	
					break;
				case 'v':
				case 'V':
					flag = 1;
					//control = game.solvePuzzle();
					break;
		        case 'q':
		        case 'Q':
		        	control = 0;
		        	cout << "Game is closing ... "<< endl;
		        	cout << "Total number of moves : " << count << endl;
	        		//cout << "Total number of moves : " << count << endl;
		        	break;
				default : 
		       		cout << "You've entered wrong character.Try again ! " << endl;
		       	 	//print();
	        		break;
        }
        if(c != 'q') cout << game;
        if(c != 'q')  control = game.isSolved();
        if(control == 0 && c != 'q')  cout << "Problem Solved ! "<< endl << "Total number of moves : " << count << endl;
    	if(!flag && control == 1){
      		cout<< endl << "This is invalid move.Try again ! "<<endl << endl;
      		cout << game;
   		}
   	}
}
int NPuzzle::Board::findsize(){
	return (row*column);
}

void NPuzzle::Board::get_row_column(int& a,int& b){
	a = row;
	b = column;
}

void NPuzzle::Board::printReport(int& count){
	cout << "The game hasn't been done and you've been done " << count << " moves. " << endl ;
}

void NPuzzle::Board::writeToFile(){		//this function saves the board to file.
	int i,j;
	string filename;
	ofstream text_file; 
	cout << "Enter a file name for save : (Please write the name with '.txt' ) : ";
	cin >> filename;
	text_file.open(filename);
	for(i=0;i<row;++i){
		for(j=0;j<column;++j){
			text_file << board[i][j] << "  " ; 
		}
		text_file << endl;
	}
	text_file.close(); 
	cout << endl << "Saved successfully ! " << endl << endl;
}

void NPuzzle::Board::reset(){				//it orders the board
	int i,j,count = 1,move=0,random,flag;
  int size = row*column;
  for(i=0;i<row;++i){              
    for(j=0;j<column;++j){
      if(board[i][j] != "00"){
      	if(i == row-1 && j == column-1) 	board[i][j] = "bb";
      	else{
      		board[i][j] = i_to_s(count);
      		count++;
      	}
      }
    }
  }
  	x=i-1;
  	y=j-1;
}
void NPuzzle::Board::moveRandom(int size){			//random moving
	int random, move = 0;
	while(move < size){
	    random = rand()%4;
	    switch(random){
	      case 0:
	        flag =  move_up(0);     // If the random moves is not available, the flag will be 0 and it produces new random number.
	        if(flag){
	          move++;
	          cout << move << ". random move is : up   " << endl;
	        	print();
	        }
	        break;
	      case 1:
	        flag = move_down(0);
	        if(flag){
	          move++;
	          cout << move << ". random move is : down : " << endl;
	        	print();        
	        }
	        break;
	       case 2:
	        flag =  move_right(0);
	        if(flag){
	          move++;
	          cout << move << ". random move is : right : " << endl;
	        print();        
	    	}
	        break;
	      case 3:
	        flag =	move_left(0);
	        if(flag){
	          move++;
	          cout << move << ". random move is : left : " << endl;
	        print();        
	    	}
	        break;
	    }
	}
}

int NPuzzle::Board::find_elements(){		//it finds the number of elements which is not "00"
	int i,j,count = 0 ;
	for(i=0;i<row;++i){
		for(j=0;j<column;++j){
			if(board[i][j] != "00"  ){
				count++;
			}
		}
	}
	a = count;
}

bool NPuzzle::Board::isSolved(){		//it controls the board for the finish
	int i,j,k;
	k = 1;
	i = 0 ;
	int flag = 1;
	//int real_board[a];
	correct.resize(row);
	while(i<row){
		correct[i].resize(column);
		++i;
	}
	i=0;

	for(i=0;i<row;++i){
		for(j=0;j<column;++j){
			if(board[i][j] != "00"){
				correct[i][j] = i_to_s(k);
				k++;
			}
			else correct[i][j] = board[i][j];
		}
	}
	correct[i-1][j-1] = "bb";
	if(correct == board)	flag = 0;			//operator overloading
	/*for(i=0;i<row;++i){
		for(j=0;j<column;++j){
			
		}
	}*/

	
	return flag;
}

int NPuzzle::solvePuzzle(){
	int i = 0 ;
	while(gameboard[i].isSolved()){
		//gameboard[i].move('r',1);
		gameboard[i].move('r',1);
		//gameboard[i].move('u',1);
		//gameboard[i].move('d',1);
	}
}

void NPuzzle::setsize(){
	int row,column;
	do{
		cout << "Enter the row number :  (It must be between 1 and 9) ";
		cin>> row;
	}while(row < 1 || row > 9);
	do{
		cout << "Enter the column number : (It must be between 1 and 9 )";
		cin >> column ;
	}while(column < 1 || column > 9);
	gameboard.resize(1);
	gameboard[0].setsize(row,column);
}

void NPuzzle::Board::setsize(int a,int b){						//takes the row and column from the user.
	int i =0,j = 0;
	row = a;
	column = b;
	board.resize(row);
	while(i<row){
		board[i].resize(column);
		++i;
	}

}

void NPuzzle::Board::fill_array(){
	int i,j,c;
  	decltype(i) s = row*column; 
	auto temp = 0 ;
	auto f = 0;
	int arr2[s],arr[row][column];
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
	  	board[i][j]=i_to_s(arr2[c]);
	  	c++;
	  	if(board[i][j] == "00")		board[i][j]="bb";
	 }
	}
	find_coordinates();
}

void NPuzzle::Board::find_coordinates(){
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

string NPuzzle::Board::i_to_s(int count){		//converts from integer to string.
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

void NPuzzle::Board::readFromFile(string s){
	string k;
	fstream input;
	int num_of_lines=0,i=0,j=0 ;
	string text;
	//ifstream in(s);
	//ifstream in(s);
	input.open(s);
	if(!input){
		cout << "The file didn't found ! \n";
		exit(1);
	}
	while(getline(input,k)){
		++i;
	}
	row = i;
	input.close();
	input.open(s);
	while(input >> k){	//finding how many element area has
		j++;
	}
	column = j / row;
	//row=num_of_lines;
	//int column=j/row;

	//row=num_of_lines;
	i=j=0;
	input.close();
	input.open(s);
	board.resize(row);
	while(i<row){
		board[i].resize(column);
		++i;
	}
	//board.resize(row);
	i = j = 0;
	while(input >> text){
		//cout << k << endl;
		board[i][j]=text;

		if(j<column-1){	//filling area with informations within file
			j++;
		}
		else{
			j=0;
			i++;
		}
	}
	input.close();

	find_coordinates();
}

void NPuzzle::Board::print(){		//prints the board
	int i,j;
	cout << endl;
	for(i=0;i<row;++i){
	  for(j=0;j<column;++j){
	  	cout << board[i][j] << "  " ;
	  }
	  cout << endl;
	 }
	 cout << endl;

}

int NPuzzle::Board::move(char c,int intelligence){		//send to functions for move
	int flag ;
	temp.resize(1);
	switch(c){
		case 'l':
		case 'L':
			return move_left(intelligence);
			break;
		case 'r':
		case 'R':
			return move_right(intelligence);
			break;
		case 'u':
		case 'U':
			return move_up(intelligence);
			break;
		case 'd':
		case 'D':
			return move_down(intelligence);
			break;
	}
}

int NPuzzle::Board::move_left(int intelligence){
  string temp;
  if(y != 0 && board[x][y-1] != "00"){
    if(intelligence == 1) cout<<endl<<"Intelligent move choose : L"<<endl;
    temp = board[x][y-1];
    board[x][y-1] = board[x][y];
    board[x][y] = temp; 
    y--;
    return 1;
  }
  else  return 0;		//moving left
}

int NPuzzle::Board::move_right(int intelligence){
  string temp;
  if(y != column-1 && board[x][y+1] != "00"){
    if(intelligence == 1) cout<<endl<<"Intelligent move choose : R"<<endl;
    temp = board[x][y+1];
    board[x][y+1] = board[x][y];
    board[x][y] = temp; 
    y++;
    return 1;
  }
  else  return 0;		//moving right
}

int NPuzzle::Board::move_up(int intelligence){		//moving up
	string temp;
  	if(x != 0 && board[x-1][y] != "00"){
	    if(intelligence == 1) cout<<endl<<"Intelligent move choose : U"<<endl;
	    temp = board[x-1][y];
	    board[x-1][y] = board[x][y];
	    board[x][y] = temp; 
	    x--;
    return 1;
  }
  else  return 0;
}

int NPuzzle::Board::move_down(int intelligence){			//moving down
  string temp;
  if(x != row-1 && board[x+1][y] != "00"){
    if(intelligence == 1) cout<<endl<<"Intelligent move choose : D"<<endl;
    temp = board[x+1][y];
    board[x+1][y] = board[x][y];
    board[x][y] = temp; 
    x++;
    return 1;
  }
  else  return 0;
}

int NPuzzle::Board::s_to_i(string arr){		//converts from string to integer.
	int val=0;

	val+=(arr[0]-48)*10;
	val+=arr[1]-48;

	return val;
}


/*int NPuzzle::move(char c,int intelligence){

	return gameboard[0].move(c,intelligence);
	
	//gameboard.move(c);
	//gameboard.print();
}*/

/*void NPuzzle::print(){
	//cout << gameboard[0] ;
	gameboard[0].print();
} */

/*void NPuzzle::fill_array(){
	gameboard[0].fill_array();
}*/


/*void NPuzzle::readFromFile(string s){
	gameboard.resize(1);
	gameboard[0].readFromFile(s);
}*/

/*int NPuzzle::find_elements(){			//finds the elements which is not '00'.
	gameboard[0].find_elements();
}*/

/*bool NPuzzle::isSolved(){
	return gameboard[0].isSolved();
}*/

/*void NPuzzle::get_row_column(int& a,int& d){
	gameboard[0].get_row_column(a,d);
}*/



/*void NPuzzle::printReport(int& count){
	gameboard[0].printReport(count);
}*/


/*void NPuzzle::writeToFile(){
	gameboard[0].writeToFile();
}*/


/*int NPuzzle::findsize(){
	return gameboard[0].findsize();
}*/



/*void NPuzzle::shuffle(int size){
	//gameboard.shuffle();
	reset();
	moveRandom(size);
}*/

/*void NPuzzle::reset(){
	gameboard[0].reset();
}*/

/*void NPuzzle::moveRandom(int size){
	gameboard[0].moveRandom(size);
}*/

