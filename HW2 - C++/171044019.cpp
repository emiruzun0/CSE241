#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

int show_game(string board[][9],int row,int column);   // Show function
void find_coordinates(string arr[][9],int row,int column,int& x,int &y);  //This function finds the empty cell's coordinates 
inline int find_row(string k);
inline int find_column(int row,string k);
int move_left(string board[][9],int& x,int& y,int intelligence);
int move_right(string board[][9],int column,int& x,int& y,int intelligence);
int move_down(string board[][9],int row,int& x,int& y,int intelligence);
int move_up(string board[][9],int& x,int& y,int intelligence);
int check_array(string board[][9],int a,string final_board[],int row,int column);
void gameplay(string board[][9],int a,string final_board[],int row,int column,int x,int y); 
int find_elements(string board[][9],int row,int column); 
void shuffle(string board[][9],int &row,int &column,int& x,int &y);
string i_to_s(int count);
int s_to_i(string value);
int intelligence(string board[][9],int &row,int &column,int& x,int &y,int& pre);
int find_min_2(int a,int b);
int find_min_3(int a,int b,int c );
void save(string board[][9],int row,int column);
void fill_array(string board[][9],const int row,const int column);

int main(int argc,char* argv[]){
	srand(time(NULL));
	int a,i,j,x,y,row,column;
	char c;
	string s;
	string board[9][9];
	
	if(argc == 1){			//if user don't enter the file bane,program creates a random board.
		cout << "Please enter row and column size : " ;
		cin >> row >> column;
		fill_array(board,row,column);
 	}
 	else if(argc == 2){		//read from file.
 		s = *(argv+1);
	 	fstream input;
		input.open(s);
		//while(getline(input,s))	i++;
		row  =  find_row(s);
		column  = find_column(row,s);
		i = j = 0;
		while(input >> board[i][j]){
			j++;
			if(j == column ){
				j = 0;
				i++;
			}
		}
		input.close();
 	}
	
	a = find_elements(board,row,column);
	string final_board[a];
	check_array(board,a,final_board,row,column);
	show_game(board,row,column);
	find_coordinates(board,row,column,x,y);
	gameplay(board,a,final_board,row,column,x,y);
	
	return 0;
}

void fill_array(string board[][9],const int row,const int column){			//This function creates random board 
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
  		if(board[i][j] == "00")
  			board[i][j]="bb";
  	}
  }

}
void gameplay(string board[][9],int a,string final_board[],int row,int column,int x,int y){
	char c='q';
	int i,j;
	int random,flag,control = 1,count=0,pre = -1;
	int move = 1000;
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
		 << "Y : Asks a file name and loads the current board configuration from the shape file." << endl 
		 << "Q : Quit the game " << endl << endl ; 
	while(control){
	    cout  << "Your move  : ";
	    cin >> c;
	    cout << endl;
	    switch(c){
	      case 'l':
	      case 'L':
	        	flag = move_left(board,x,y,0);    // '0' means it is not the intelligent move.
	       		 show_game(board,row,column);
	       		 if(flag) count++;
	        	break;
	        case 'r':
	      	case 'R':
	        	flag = move_right(board,column,x,y,0);    // '0' means it is not the intelligent move.
	       		 show_game(board,row,column);
	       		 if(flag) count++;
	        	break;
	        case 'd':
	        case 'D':
	        	flag = move_down(board,row,x,y,0);
	        	show_game(board,row,column); 
	        	if(flag) count++;
	        	break;
	        case 'u':
	        case 'U':
	        	flag = move_up(board,x,y,0);
	        	show_game(board,row,column); 
	        	if(flag) count++;
	        	break;
	        case 's':
     		case 'S':
        		flag = 1;
        		shuffle(board,row,column,x,y);
        		count++;
        //cout << x << y;
        		break;
        	case 'I':
        	case 'i':
        		flag = intelligence(board,row,column,x,y,pre);
        		show_game(board,row,column);
        		count++;
        		break;
        	case 'E':
        	case 'e':
        		flag = 1;
        		save(board,row,column);
        		show_game(board,row,column);
		       	break;
		   	case 'y':
		    case 'Y':
		    	flag = 1;
				cout << "Enter a txt file which you'd like to load(Please enter  with '.txt' !) : ";
				cin >> text;
				
				input.open(text);
				//while(getline(input,s))	i++;
				row  =  find_row(text);
				column  = find_column(row,text);
				i = j = 0;
				while(input >> board[i][j]){
					j++;
					if(j == column ){
						j = 0;
						i++;
					}
				}
				input.close();
				a = find_elements(board,row,column);
				//string final_board[a];
				check_array(board,a,final_board,row,column);
				show_game(board,row,column);
				find_coordinates(board,row,column,x,y);
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
				while(move >= 0){
					cout << move << "moves left ! " << endl;
					intelligence(board,row,column,x,y,pre);
					show_game(board,row,column);
					if(control != check_array(board,a,final_board,row,column)) 	break;
					count++;
					move--;
				}
				if(control == 1)	cout << "Intelligence has done 1000 moves but couldn't solve the puzzle " << endl ;
				show_game(board,row,column);
        		count++;
        		move = 1000;
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
	       	 	show_game(board,row,column);
        		break;
        }
        if(c != 'q')  control = check_array(board,a,final_board,row,column);
        if(control == 0 && c != 'q')  cout << "Problem Solved ! "<< endl << "Total number of moves : " << count << endl;
    	if(!flag && control == 1){
      		cout<<"This is invalid move.Try again ! "<<endl;
      		show_game(board,row,column);
   		}
	}
}

void save(string board[][9],int row,int column){			//this function saves the board to file.
	int i,j;
	string filename;
	ofstream text_file; //ofstream sınıfından bir nesne oluşturduk.Herhangi bir isim verebilirsiniz.
	cout << "Enter a file name for save : (Please write the name with '.txt' ) : ";
	cin >> filename;
	text_file.open(filename); //deneme.txt isimli bir text_file açtık.
	for(i=0;i<row;++i){
		for(j=0;j<column;++j){
			text_file << board[i][j] << "  " ; 
		}
		text_file << endl;
	}//Dikkat edin burada oluşturduğumuz nesneyi cout gibi kullanıyoruz.
	text_file.close(); //dosyayı kapattık.
	cout << endl << "Saved successfully ! " << endl << endl;
}

int intelligence(string board[][9],int &row,int &column,int& x,int &y,int& pre){
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
				flag = move_down(board,row,x,y,1);
				pre = 2;
			}
		}
		else if(min == r){
			if(pre != 1){
				flag =  move_right(board,column,x,y,1);
				pre = 3;
			}
		}
		else if(min == u){
			if(pre != 2){
				flag = move_up(board,x,y,1);
				pre = 0;
			}
		}
		else {
			if(pre != 3){
				flag = move_left(board,x,y,1);
				pre = 1;
			}	
		}


	if(flag != 1 ){		
		do{
			random = rand() %4;
			if(pre != 2 && random == 0){
				flag = move_up(board,x,y,1);
				pre = 0;
			}
			else if(pre != 3 && random == 1){
				flag = move_left(board,x,y,1);
				pre = 1;
			}
			else if(pre != 0 && random == 2){
				flag = move_down(board,row,x,y,1);
				pre = 2;
			}
			else {
				flag = move_right(board,column,x,y,1);
				pre = 3;
			}
		}while(flag == 0);
	}

	return 1;
	/*int flag = 1;
	switch(min){

	}*/
}

int s_to_i(string arr){		//converts from string to integer.
	int val=0;

	val+=(arr[0]-48)*10;
	val+=arr[1]-48;

	return val;
}

string i_to_s(int count){		//converts from integer to string.
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

void shuffle(string board[][9],int& row,int& column,int& x,int &y){
  int i,j,count = 1,move=0,random,flag;
  for(i=0;i<row;++i){              // Firstly, I ordered the table and then I move the board random row*column moves.
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
  //board[i-1][j-1] = 0;

	show_game(board,row,column);  
	while(move < row*column){
    random = rand()%4;
    switch(random){
      case 0:
        flag =  move_up(board,x,y,0);     // If the random moves is not available, the flag will be 0 and it produces new random number.
        if(flag){
          move++;
          cout << move << ". random move is : up   " << endl;
        	show_game(board,row,column);
        }
        break;
      case 1:
        flag = move_down(board,row,x,y,0);
        if(flag){
          move++;
          cout << move << ". random move is : down : " << endl;
        	show_game(board,row,column);        
        }
        break;
       case 2:
        flag =  move_right(board,column,x,y,0);
        if(flag){
          move++;
          cout << move << ". random move is : right : " << endl;
        show_game(board,row,column);        
    	}
        break;
      case 3:
        flag =	move_left(board,x,y,0);
        if(flag){
          move++;
          cout << move << ". random move is : left : " << endl;
        show_game(board,row,column);        
    	}
        break;
    }
  }
}

int find_min_2(int a,int b){    //find minimum number in 2 numbers.
  if(a < b) return a;
  else if(b <a )return b;
  else return 0;
}

int find_min_3(int a,int b,int c ){   //find minimum number in 3 numbers.
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

int find_elements(string board[][9],int row,int column){			//finds the elements which is not '00'.
	int i,j,count = 0 ;
	for(i=0;i<row;++i){
		for(j=0;j<column;++j){
			if(board[i][j] != "00"  ){
				count++;
			}
		}
	}
	//cout << count << endl;
	return count;
}

int check_array(string board[][9],int a,string final_board[],int row,int column){		//checks the board to finish the game.
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
		//cout << real_board[i] << endl;
	}

	for(i=0;i<a-1;++i){
		if(real_board[i] >= real_board[i+1]){
			flag=1;
			break;
		}

	}
	return flag;
}


int move_left(string board[][9],int& x,int& y,int intelligence){
  string temp;
  if(y != 0 && board[x][y-1] != "00"){
    if(intelligence == 1) cout<<endl<<"Intelligent move choose : L"<<endl;
    temp = board[x][y-1];
    board[x][y-1] = board[x][y];
    board[x][y] = temp; 
    y--;
    return 1;
  }
  else  return 0;
}

int move_right(string board[][9],int column,int& x,int& y,int intelligence){
  string temp;
  if(y != column-1 && board[x][y+1] != "00"){
    if(intelligence == 1) cout<<endl<<"Intelligent move choose : R"<<endl;
    temp = board[x][y+1];
    board[x][y+1] = board[x][y];
    board[x][y] = temp; 
    y++;
    return 1;
  }
  else  return 0;
}

int move_down(string board[][9],int row,int& x,int& y,int intelligence){
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

int move_up(string board[][9],int& x,int& y,int intelligence){
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


int show_game(string board[][9],int row,int column){     // Show function
	int i,j;
	for(i=0;i<row;++i){
		for(j=0;j<column;++j){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout <<endl;
}

inline int find_row(string k){			//finds the row number.
	int i=0;
	string s;
	fstream input;
	input.open(k);
	while(getline(input,s))	i++;
	input.close();
	return i;
}

inline int find_column(int row,string k){		//find the column number.
	int j=0;
	string board[9][9];
	fstream input;
	input.open(k);
	while(input >> board[0][j])	j++;
	input.close();
	return j/row;
}

void find_coordinates(string board[][9],int row,int column,int& x,int& y){    //This function finds the empty cell's coordinates 
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

