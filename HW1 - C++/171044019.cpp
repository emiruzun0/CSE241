//EMİRHAN UZUN 171044019
#include <iostream>
#include <ctime>
using namespace std;

int fill_array(int arr[][9],int size);
int show_game(int arr[][9],int size);
int find_coordinates(int arr[][9],int size,int *x,int *y);
int move_left(int arr[][9],int *x,int *y,int intelligence);
int move_right(int arr[][9],int size,int *x,int *y,int intelligence);
int move_down(int arr[][9],int size,int *x,int *y,int intelligence);
int move_up(int arr[][9],int *x,int *y,int intelligence);
void shuffle(int arr[][9],int size,int *x,int *y);
int intelligence(int arr[][9],int size,int *x,int *y);
int control_game(int arr[][9],int size,int *x,int *y);
int find_min_2(int a,int b);
int find_min_3(int a,int b,int c );
void gameplay(int arr[][9],int size,int x,int y);
bool isSolvable(int puzzle[][9],int size);
int get_count(int arr[],int size);


int main(){
  srand(time(NULL));
  int x,y,size;
  char c;
  cout << "Please enter the problem size  : ";
  cin >> size;
  while(size<3 || size>9){          //board size condition
    cout<< "Size must be between 3 and 9 \nPlease enter the problem size: " ;
    cin >> size;
  }
  int arr[9][9];
  do{
    fill_array(arr,size);
  }while(!isSolvable(arr,size));
  cout << "Your initial random board is " << endl ;
  show_game(arr,size);
  find_coordinates(arr,size,&x,&y);
  gameplay(arr,size,x,y);   
  return 0;
}

void gameplay(int arr[][9],int size,int x,int y){
  char c;
  int flag,control= 1,count =0;
  while(control){
    cout  << "Your move  : ";
    cin >> c;
    switch(c){
      case 'l':
      case 'L':
        flag = move_left(arr,&x,&y,0);    // '0' means it is not the intelligent move.
        show_game(arr,size);
        if(flag) count++;
        //cout << x << y;
        break;
      case 'r':
      case 'R':
        flag = move_right(arr,size,&x,&y,0);
        show_game(arr,size);
        if(flag) count++;
        //cout << x << y;
        break;
      case 'd':
      case 'D':
        flag = move_down(arr,size,&x,&y,0);
        show_game(arr,size);
        if(flag) count++;
        //cout << x << y;
        break;
      case 'u':
      case 'U':
        flag = move_up(arr,&x,&y,0);
        show_game(arr,size);
        if(flag) count++;
        //cout << x << y;
        break;
      case 's':
      case 'S':
        flag = 1;
        shuffle(arr,size,&x,&y);
        count++;
        //cout << x << y;
        break;
      case 'q':
      case 'Q':
        control =0;
        cout << "Game is closing ... "<< endl;
        cout << "Total number of moves : " << count << endl;
        break;
      case 'i':
      case 'I':
        flag = intelligence(arr,size,&x,&y);
        show_game(arr,size);
        count++;
        break;
      default : 
        cout << "You've entered wrong character.Try again ! " << endl;
        show_game(arr,size);
        break;
    }
    if(c != 'q')  control = control_game(arr,size,&x,&y);     //if user not enter the 'q', computer controls the board for finish.
    if(control == 0 && c != 'q')  cout << "Problem Solved ! "<< endl << "Total number of moves : " << count << endl;
    if(!flag && control == 1){
      cout<<"This is invalid move.Try again ! "<<endl;
      show_game(arr,size);
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
int intelligence(int arr[][9],int size,int *x,int *y){
  int i,j,count = 1;
  int u,d,l,r;
  int min;
  int arr2[9][9];
for(i=0;i<size;++i){        //this is the ordered array which I filled in it.
    for(j=0;j<size;++j){
      arr2[i][j] = count;
      count++;
    }
}
  arr2[i-1][j-1] = 0;

if((*x) == 0){          // These conditions find the difference between where the gap is located and the number that should be there.
    if(*y == 0){        // And then, if it is negative,it turns the positive.After that, find the minimum difference and move it.
      d = arr2[0][0] - arr[(*x)+1][*y];
      r = arr2[0][0] - arr[*x][(*y)+1];
      d = abs(d);
      r= abs(r);
      min = find_min_2(d,r);
      if(min == d ) move_down(arr,size,x,y,1);     // '1' means it is the intelligent move.
      else move_right(arr,size,x,y,1);
    }
    else if(*y == size-1){
      d = arr2[0][size-1] - arr[(*x)+1][*y];
      l = arr2[0][size-1] - arr[*x][(*y)-1];
      d = abs(d);
      l = abs(l);
      min = find_min_2(d,l);
      if(d == l){
        if(arr2[1][size-1] - arr[(*x)+1][*y] < arr2[0][size-2] - arr[*x][(*y)-1]) move_left(arr,x,y,1);
        else move_down(arr,size,x,y,1);
      }
      else if(min == d )  move_down(arr,size,x,y,1);
      else move_left(arr,x,y,1);
    }
    else{
      d = arr2[(*x)][*y] - arr[(*x)+1][*y];
      r = arr2[(*x)][*y] - arr[(*x)][(*y)+1];
      l = arr2[(*x)][*y] - arr[*x][(*y)-1];
      //min = find_min_2(u,r);
      d = abs(d);
      r = abs(r);
      l = abs(l);
      min = find_min_3(d,r,l);
      if(min == d)  move_down(arr,size,x,y,1);
      else if (min == r )move_right(arr,size,x,y,1);
      else move_left(arr,x,y,1);
    }
}
else if(*x == size -1 ){
    if(*y == 0){
      u = arr2[size-1][0] - arr[(*x)-1][*y];
      r = arr2[size-1][0] - arr[(*x)][(*y)+1];
      u = abs(u);
      r= abs(r);
      min = find_min_2(u,r);
    if(u == r ){
        if(arr2[size-2][0] - arr[(*x)-1][*y] < arr2[size-1][1] - arr[*x][(*y)+1]) move_right(arr,size,x,y,1);
        else move_up(arr,x,y,1);
      }
    else if(min == u) move_up(arr,x,y,1);
    else move_right(arr,size,x,y,1);
	}
	else if(*y == size-1){
      u = arr2[size-1][size-1] - arr[(*x)-1][*y];
      l = arr2[size-1][size-1] - arr[(*x)][(*y)-1];
      u = abs(u);
      l= abs(l);
      min = find_min_2(u,l);

      if(u == l){
        if(arr2[size-2][size-1] - arr[(*x)-1][*y] < arr2[size-2][size-1] - arr[(*x)-1][(*y)]) move_up(arr,x,y,1);
        else move_left(arr,x,y,1);
      }
      else if(min == u) move_up(arr,x,y,1);
      else move_left(arr,x,y,1);
	}
   	else{
      u = arr2[(*x)][*y] - arr[(*x)-1][*y];
      r = arr2[(*x)][*y] - arr[(*x)][(*y)+1];
      l = arr2[(*x)][*y] - arr[(*x)][(*y)-1];

      u = abs(u);
      r = abs(r);
      l= abs(l);
      min = find_min_3(u,r,l);
      if(u == r || u == l || r == l){   //  if the difference is 0 , it checks the areas of empty cells. It moves which difference is bigger than other.
        if((arr2[(*x)-1][*y] - arr[(*x)-1][*y] ) > ( arr2[(*x)][(*y)+1] - arr[(*x)][(*y)+1])  && (arr2[(*x)-1][*y] - arr[(*x)-1][*y] ) > ( arr2[(*x)][(*y)-1] - arr[(*x)][(*y)-1])) move_up(arr,x,y,1);
        else if ((arr2[(*x)][(*y)+1] - arr[(*x)][(*y)+1] ) > ( arr2[(*x)-1][*y] - arr[(*x)-1][*y])  && (arr2[(*x)][(*y)+1] - arr[(*x)][(*y)+1] ) > ( arr2[(*x)][(*y)-1] - arr[(*x)][(*y)-1])) move_right(arr,size,x,y,1);
        else move_left(arr,x,y,1);
      }
      else if(min == u) move_up(arr,x,y,1);
      else if (min == r ) move_right(arr,size,x,y,1);
      else move_left(arr,x,y,1);
    }
}
else if(*y == 0){
    u = arr2[(*x)][*y] - arr[(*x)-1][*y];
    r = arr2[(*x)][*y] - arr[(*x)][(*y)+1];
    d = arr2[(*x)][*y] - arr[((*x)+1)][(*y)];

    u = abs(u);
    r = abs(r);
    d= abs(d);
    min = find_min_3(u,r,d);
    if(u == r || u == d || r == d){   //  if the difference is 0 , it checks the areas of empty cells. It moves which difference is bigger than other.
      if((arr2[(*x)-1][0] - arr[(*x)-1][0] ) > ( arr2[(*x)+1][0] - arr[(*x)+1][0])  && (arr2[(*x)-1][0] - arr[(*x)-1][0] ) > ( arr2[(*x)][1] - arr[(*x)][1])) move_up(arr,x,y,1);
      else if ((arr2[(*x)+1][0] - arr[(*x)+1][0] ) > ( arr2[(*x)-1][0] - arr[(*x)-1][0])  && (arr2[(*x)+1][0] - arr[(*x)+1][0] ) > ( arr2[(*x)][1] - arr[(*x)][1])) move_down(arr,size,x,y,1);
      else move_right(arr,size,x,y,1);
    }
    else if(min == u) move_up(arr,x,y,1);
    else if (min == r )move_right(arr,size,x,y,1);
    else move_down(arr,size,x,y,1);
    
  }
  else if(*y == size -1 ){
    u = arr2[(*x)][*y] - arr[(*x)-1][(*y)];
    d = arr2[(*x)][*y] - arr[(*x)+1][(*y)];
    l = arr2[(*x)][*y] - arr[(*x)][(*y)-1];

    u = abs(u);
    d = abs(d);
    l= abs(l);
    min = find_min_3(u,d,l);
    if(min == u)  move_up(arr,x,y,1);
    else if (min == d )   move_down(arr,size,x,y,1);
    else move_left(arr,x,y,1);
  }
  else{
    u = arr2[(*x)][*y] - arr[(*x)-1][*y];
    d = arr2[(*x)][*y] - arr[((*x)+1)][(*y)];
    l = arr2[(*x)][*y] - arr[(*x)][(*y)-1];
    r = arr2[(*x)][*y] - arr[(*x)][(*y)+1];

    u = abs(u);
    d = abs(d);
    l= abs(l);
    r = abs(r);

    min = find_min_3(u,d,l);
    min = find_min_2(min,r);
    if(min == u)  move_up(arr,x,y,1);
    else if (min == d )   move_down(arr,size,x,y,1);
    else if(min == l) move_left(arr,x,y,1);
    else move_right(arr,size,x,y,1);
  }
}

int control_game(int arr[][9],int size,int *x,int *y){      //this function controls the board to finish the game
  int i,j,k=1;
  if((*x) != size-1 && (*y) != size-1) return 1;
  for(i=0;i<size;++i){
    for(j=0;j<size;++j){
      if(arr[i][j] != k ){
        if(i == size-1 && j==size-1) return 0;
        else return 1;
      }
      else k++;
    }
  }
  return 0;
}



void shuffle(int arr[][9],int size,int *x,int *y){
  int i,j,count=1,move=0,random,flag;
  for(i=0;i<size;++i){              // Firstly, I ordered the table and then I move the board random size*size moves.
    for(j=0;j<size;++j){
      arr[i][j] = count;
      count++;
    }
  }
  arr[i-1][j-1] = 0;
  (*x) = i-1;
  (*y) = j-1;
  show_game(arr,size);
  while(move < size*size){
    random = rand()%4;
    switch(random){
      case 0:
        flag = move_up(arr,x,y,0);      // If the random moves is not available, the flag will be 0 and it produces new random number.
        if(flag){
          move++;
          cout << move << ". random move is : up   " << endl;
          show_game(arr,size);
        }
        break;
      case 1:
        flag = move_down(arr,size,x,y,0);
        if(flag){
          move++;
          cout << move << ". random move is : down : " << endl;
          show_game(arr,size);
        }
        break;
       case 2:
        flag = move_right(arr,size,x,y,0);
        if(flag){
          move++;
          cout << move << ". random move is : right : " << endl;
          show_game(arr,size);
        }
        break;
      case 3:
        flag = move_left(arr,x,y,0);
        if(flag){
          move++;
          cout << move << ". random move is : left : " << endl;
          show_game(arr,size);
        }
        break;
    }
  }
}
int move_left(int arr[][9],int *x,int *y,int intelligence){
  int value;
  if(*y != 0){
    if(intelligence == 1) cout<<endl<<"Intelligent move choose : L"<<endl;
    value = arr[*x][(*y)-1];
    arr[*x][(*y)-1] = arr[*x][*y];
    arr[*x][*y] = value;
    (*y)--;
    return 1;
  }
  else  return 0;
}

int move_right(int arr[][9],int size,int *x,int *y,int intelligence){
  int value;
  if(*y != size-1){
    if(intelligence == 1) cout<<endl<<"Intelligent move choose : R"<<endl;
    value = arr[*x][(*y)+1];
    arr[*x][(*y)+1] = arr[*x][*y];
    arr[*x][*y] = value;
    (*y)++;
    return 1;
  }
  else  return 0;
}

int move_down(int arr[][9],int size,int *x,int *y,int intelligence){
  int value;
  if(*x != size-1){
    if(intelligence == 1) cout<<endl<<"Intelligent move choose : D"<<endl;
    value = arr[(*x)+1][(*y)];
    arr[(*x)+1][(*y)] = arr[*x][*y];
    arr[*x][*y] = value;
    (*x)++;
    return 1;
  }
  else  return 0;
}

int move_up(int arr[][9],int *x,int *y,int intelligence){
  int value;
  if(*x != 0){
    if(intelligence == 1) cout<<endl<<"Intelligent move choose : U"<<endl;
    value = arr[(*x)-1][(*y)];
    arr[(*x)-1][(*y)] = arr[*x][*y];
    arr[*x][*y] = value;
    (*x)--;
    return 1;
  }
  else  return 0;
}

int fill_array(int arr[][9],int size){
  int i,j,c,s,temp = 0, f=0;
  s = size*size;
  int arr2[s];
  for(i=0;i<s; ++i){      //Firstly, I filled the array with '-1' 
    arr2[i] = -1;
  }
  for(i=0;i<9;++i){
    for(j=0;j<9;++j){
      arr[i][j] = -1;   
    }
  }
  for (i = 0; i < size; ++i){       //  This loop is used for we do not want to reproduce a generated number
    for (j = 0; j < size; ++j){
      f=0;
      c = rand() %s ;
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
}

int show_game(int arr[][9],int size){     // Show function
  int i,j;
  for (i = 0; i < size; ++i){
    for (j = 0; j < size; ++j){
      if(arr[i][j] != 0 ){
        //if(arr[i][j]>9 ){
          cout.width(4);
          cout << arr[i][j] ;//<< " " ; 
        //else if (arr[i][j] <10 ) cout << arr[i][j] << "  " ;  
      }
      else {
        cout.width(4);
        cout << "   ";
      }
    }
      cout << endl;
  }
  cout<<endl;
}

int find_coordinates(int arr[][9],int size,int *x,int *y){    //This function finds the empty cell's coordinates 
  int i,j;
  for(i=0;i<size;++i){
    for(j=0;j<size;++j){
      if(arr[i][j] == 0 ){
        *x = i;
        *y = j;
        break;
      }
    }
  }
}

int get_count(int arr[],int size)                           //I didn't do last 2 functions myself.I copied the internet to avoid an unresolved question. 
{ 
    int inv_count = 0; 
    for (int i = 0; i < size - 1; i++) 
        for (int j = i+1; j < 9; j++) 
             // Value 0 is used for empty space 
             if (arr[j] && arr[i] &&  arr[i] > arr[j]) 
                  inv_count++; 

    return inv_count; 
} 
  
// This function returns true if given 8 puzzle is solvable. 
bool isSolvable(int puzzle[][9],int size) 
{ 
    // Count inversions in given 8 puzzle 
    int invCount = get_count((int *)puzzle,size); 
    // return true if inversion count is even. 
    return (invCount%2 == 0); 
} 
