#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
using namespace std;

class NPuzzle{
private:
	class Board{
	private:
		string board[9][9],final_board[81];
		int row;
		int column;
		int x,y ;		// bb's coordinates.
		int a,control,flag;
		int pre = -1;	//previous move for the intelligent.For instance, if the previous move is left,then intelligence doesn't move the rigth not to enter loop
	public:
		void print();
		void readFromFile(string s);
		void writeToFile();
		void reset();
		void setsize();
		int move(char c,int intelligence);
		bool isSolved();
		string i_to_s(int count);
		int s_to_i(string value);
		int find_elements();
		void fill_array();
		void find_coordinates();
		int move_left(int intelligence);
		int move_right(int intelligence);
		int move_up(int intelligence);
		int move_down(int intelligence);
		int findsize();
		void shuffle();
		inline int findrow()const;
		inline int findcolumn()const;
		void moveRandom(int size);
		void moveIntelligent();
		int find_min_2(const int a,const int b);
		int find_min_3(const int a,const int b,const int c);
	};
public:
	void print();
	void printReport();
	void readFromFile(string s);
	void writeToFile();
	void shuffle(int size);
	void reset();
	void setsize();
	void moveRandom(int size);
	void moveIntelligent();
	int move(char c,int intelligence);
	int solvePuzzle(int& move);
	int find_elements();
	void fill_array();
	bool isSolved();
	int findsize();
	Board gameboard;
};

int main(int argc,char* argv[]){
	NPuzzle game;
	srand(time(NULL));
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
	game.isSolved();
	game.print();


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
	        	case 'I':
	        	case 'i':
	        		flag = 1 ;
	        		game.moveIntelligent();
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
					cout << "The game hasn't been done and you've been done " << count << " moves. " << endl ;	
					break;
				case 'v':
				case 'V':
					flag = 1;
					control = game.solvePuzzle(move);
					
					//print();
	        		count = count + 5000 - move;
	        		move = 5000;
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
        if(c != 'q') game.print();
        if(c != 'q')  control = game.isSolved();
        if(control == 0 && c != 'q')  cout << "Problem Solved ! "<< endl << "Total number of moves : " << count << endl;
    	if(!flag && control == 1){
      		cout<< endl << "This is invalid move.Try again ! "<<endl << endl;
      		game.print();
   		}
   	}
}

int NPuzzle::solvePuzzle(int& move){
	int control = 1;
	while(move >= 0){
		cout << move << "moves left ! " << endl;
		moveIntelligent();
		print();
		if(control != isSolved()) 	return 0;
		isSolved();
		move--;
	}
	if(control == 1)	cout << "Intelligence has done 5000 moves but couldn't solve the puzzle " << endl ;
	return 1;
}

inline int NPuzzle::Board::findrow()const{
	return row;
}

inline int NPuzzle::Board::findcolumn()const{
	return column;
}

int NPuzzle::Board::find_min_2(const int a,const int b){    //find minimum number in 2 numbers.
  if(a < b) return a;
  else if(b <a )return b;
  else return 0;
}

int NPuzzle::Board::find_min_3(const int a,const int b,const int c ){   //find minimum number in 3 numbers.
  int min;
    min=a;
    if(a<b){
      if(a < c) min = a;
      else min = c;
    }
    else{
      if(b < c) min = b;
      else min = c;
    }

    return min;
}

void NPuzzle::moveIntelligent(){

	gameboard.moveIntelligent();
	
	/*int flag = 1;
	switch(min){

	}*/
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

void NPuzzle::Board::moveIntelligent(){		
	int i,j,min;
	int u,d,l,r;
	int count = 1,flag = 0;
	int value;
	int random;
	string control[row][column];
	for(i=0;i<row;++i){              // Firstly, this scope creates a ordered board and then checks with real board.
	    for(j=0;j<column;++j){
	     	if(board[i][j] != "00"){
	      		if(i == row-1 && j == column-1) 	control[i][j] = "bb";
	      		else{
	      			control[i][j] = i_to_s(count);
	      			count++;
	      		}	
	      	}
	      	else{
	      			control[i][j] = "00";
	      	}
	    }
  	}

  	value = s_to_i(control[x][y]);
  	//cout << value;

  	if(x == 0){          // These conditions find the difference between where the gap is located and the number that should be there.
	    if(y == 0){        // And then, if it is negative,it turns the positive.After that, find the minimum difference and move it.
	      d = value - s_to_i(board[x+1][y]);		//I send the s_to_i function to convert from string to integer.
	      r = value - s_to_i(board[x][y+1]);	
	      d = abs(d);
	      r= abs(r);
	      min = find_min_2(d,r);
	    }
	    else if(y == column-1){
	      d = value - s_to_i(board[x+1][y]);
	      l = value - s_to_i(board[x][y-1]);
	      d = abs(d);
	      l = abs(l);
	      min = find_min_2(d,l);
	    }
	    else{
	      d = value - s_to_i(board[x+1][y]);
	      r = value - s_to_i(board[x][y+1]);
	      l = value - s_to_i(board[x][y-1]);
	      //min = find_min_2(u,r);
	      d = abs(d);
	      r = abs(r);
	      l = abs(l);
	      min = find_min_3(d,r,l);
	    }
	}
	else if(x == row -1 ){
	    if(y == 0){
	      u = value - s_to_i(board[x-1][y]);
	      r = value - s_to_i(board[x][y+1]);
	      u = abs(u);
	      r= abs(r);
	      min = find_min_2(u,r);
		}
		else if(y == column-1){
	      u = value - s_to_i(board[x-1][y]);
	      l = value - s_to_i(board[x][y-1]);
	      u = abs(u);
	      l= abs(l);
	      min = find_min_2(u,l);
		}
	   	else{
	      u = value - s_to_i(board[x-1][y]);
	      r = value - s_to_i(board[x][y+1]);
	      l = value - s_to_i(board[x][y-1]);

	      u = abs(u);
	      r = abs(r);
	      l= abs(l);
	      min = find_min_3(u,r,l);
	    }
	}
	else if(y == 0){
	    u = value - s_to_i(board[x-1][y]);
	    r = value - s_to_i(board[x][y+1]);
	    d = value - s_to_i(board[x+1][y]);

	    u = abs(u);
	    r = abs(r);
	    d= abs(d);
	    min = find_min_3(u,r,d);
  	}
  	else if(y == column -1 ){
	    u = value - s_to_i(board[x-1][y]);
	    d = value - s_to_i(board[x+1][y]);
	    l = value - s_to_i(board[x][y-1]);

	    u = abs(u);
	    d = abs(d);
	    l= abs(l);
	    min = find_min_3(u,d,l);
	}
	else{
	    u = value - s_to_i(board[x-1][y]);
	    d = value - s_to_i(board[(x+1)][(y)]);
	    l = value - s_to_i(board[x][y-1]);
	    r = value - s_to_i(board[x][y+1]);

	    u = abs(u);
	    d = abs(d);
	    l= abs(l);
	    r = abs(r);

	    min = find_min_3(u,d,l);
	    min = find_min_2(min,r);
	}

	if(min == d){
		if(pre != 0){
			flag = move_down(1);
			pre = 2;
		}
	}
	else if(min == r){
		if(pre != 1){
			flag =  move_right(1);
			pre = 3;
		}
	}
	else if(min == u){
		if(pre != 2){
			flag = move_up(1);
			pre = 0;
		}
	}
	else {
		if(pre != 3){
			flag = move_left(1);
			pre = 1;
		}	
	}

	if(flag != 1 ){		
		do{
			random = rand() %4;
			if(pre != 2 && random == 0){
				flag = move_up(1);
				pre = 0;
			}
			else if(pre != 3 && random == 1){
				flag = move_left(1);
				pre = 1;
			}
			else if(pre != 0 && random == 2){
				flag = move_down(1);
				pre = 2;
			}
			else {
				flag = move_right(1);
				pre = 3;
			}
		}while(flag == 0);
	}

	
}

void NPuzzle::writeToFile(){
	gameboard.writeToFile();
}

int NPuzzle::findsize(){
	return gameboard.findsize();
}

int NPuzzle::Board::findsize(){
	return (row*column);
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


void NPuzzle::readFromFile(string s){
	gameboard.readFromFile(s);
}

void NPuzzle::Board::readFromFile(string s){
	fstream input;
	int i = 0;
	auto j = 0;
	string k;
	input.open(s);
	if(!input){
		cout << "The file didn't found ! \n";
		exit(1);
	}
	else{
		while(getline(input,k))	i++;
		row=i;
		input.close();
		input.open(s);
		while(input >> board[0][j])	j++;
		input.close();
		column = j/row;
		i = j = 0;
		input.open(s);
		while(input >> board[i][j]){
			j++;
			if(j == column ){
				j = 0;
				i++;
			}
		}
		input.close();
		find_coordinates();
	}
}

bool NPuzzle::isSolved(){
	return gameboard.isSolved();
}

bool NPuzzle::Board::isSolved(){		//it controls the board for the finish
	int i,j,k;
	int count = k = 0,flag=0;
	int real_board[a];
	for(i=0;i<row;++i){
		for(j=0;j<column;++j){
			if(board[i][j] != "00"){
				final_board[k] = board[i][j];
				k++;
			}
		}
	}
	k=0;
	for(i=0;i<a;++i){
		real_board[i]=s_to_i(final_board[i]);
	}

	for(i=0;i<a-1;++i){
		if(real_board[i] >= real_board[i+1]){
			flag=1;
			break;
		}

	}
	return flag;
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



int NPuzzle::find_elements(){			//finds the elements which is not '00'.
	gameboard.find_elements();
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

void NPuzzle::print(){
	gameboard.print();
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

void NPuzzle::setsize(){
	gameboard.setsize();
}

int NPuzzle::move(char c,int intelligence){
	gameboard.move(c,intelligence);
	
	//gameboard.move(c);
	//gameboard.print();
}

void NPuzzle::shuffle(int size){
	//gameboard.shuffle();
	reset();
	moveRandom(size);
}

void NPuzzle::reset(){
	gameboard.reset();
}



void NPuzzle::moveRandom(int size){
	gameboard.moveRandom(size);
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

int NPuzzle::Board::move(char c,int intelligence){		//send to functions for move
	switch(c){
		case 'l':
		case 'L':
			move_left(intelligence);
			break;
		case 'r':
		case 'R':
			move_right(intelligence);
			break;
		case 'u':
		case 'U':
			move_up(intelligence);
			break;
		case 'd':
		case 'D':
			move_down(intelligence);
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

void NPuzzle::Board::setsize(){						//takes the row and column from the user.
	do{
		cout << "Enter the row number :  (It must be between 1 and 9) ";
		cin>> row;
	}while(row < 1 || row > 9);
	do{
		cout << "Enter the column number : (It must be between 1 and 9 ";
		cin >> column ;
	}while(column < 1 || column > 9);	
}

void NPuzzle::fill_array(){
	gameboard.fill_array();
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

int NPuzzle::Board::s_to_i(string arr){		//converts from string to integer.
	int val=0;

	val+=(arr[0]-48)*10;
	val+=arr[1]-48;

	return val;
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