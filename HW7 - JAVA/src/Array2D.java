import java.util.Scanner;
import java.util.Random;
import java.io.*; 
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;



/**
 * This class is the  sub class 2D Array of Homework 7
 * Student ID : 171044019
 * @author Emirhan Uzun
 * 
 *
 */
public class Array2D extends Abstractboard{
	
	
	/**
	 * This is the string 2D array which includes the board 
	 */
	private String board[][];
	
	/**
	 * This is the final solution board in 2D array
	 */
	private String finalboard[][];

	/**
	 * This constructor calls the super class' constructor and initializes the values 
	 */
	public Array2D()
	{
		super();
	}

	public void setSize(int a,int b){
		row = a;
		column = b;
		board = new String[row][column];
		fillRandomBoard();
	}

	public String toString(){
		int i,j;
		String printArr = "";
		printArr += "\n";
		for(i=0;i<row;++i){
			for(j=0;j<column;++j){
		  		printArr += board[i][j] ;
		  		printArr += " ";
		  	}
		 	printArr += "\n";
		}
		printArr += "\n";
		return printArr;	
	}

	public void readFromFile(String filename){
		String read,fromfile;
		int tempcount = 0;
		int i,j;
		try  
		{  
		//the file to be opened for reading  
			FileInputStream fis=new FileInputStream(filename);       
			Scanner sc=new Scanner(fis);    //file to be scanned  
		//returns true if there is another line to read  
		while(sc.hasNextLine())  
		{  
			//System.out.println(sc.nextLine());      //returns the line that was skipped  
			read = sc.nextLine();
			//text += sc.append(line);

			row++;
		}  
		sc.close();     //closes the scanner  
		}  
		catch(IOException e)  
		{  
			e.printStackTrace();  
		} 


		BufferedReader in = null;
		try {
		    in = new BufferedReader(new FileReader(filename));
		    fromfile = null;
		    while ((fromfile = in.readLine()) != null) {
		        String[] splitedstring = fromfile.split("\\s+");	//finding column
		    	for (String temp : splitedstring) {
		    		tempcount++;
		        }
		    }
		    in.close();
		}
		catch (IOException e) {
		    e.printStackTrace();
		}


		column = tempcount/row;


		board = new String[row][column];

		i = j = 0;
		try{
			in = new BufferedReader(new FileReader(filename));
		    fromfile = null;
		    while ((fromfile = in.readLine()) != null) {
		        String[] splitedstring = fromfile.split("\\s+");
		    	for (String temp : splitedstring) {
		    		if(j < column-1){
		    			board[i][j]=temp;
		    			j++;
		    		}
		    		else{
		    			board[i][j]=temp;
		    			i++;
		    			j=0;
		    		}
		        }
		    }
		}
		catch (IOException e) {
		    e.printStackTrace();
		}

		fill_finalboard();
		find_coordinates();
	}

	public void writeToFile(String dest){
		//String fileContent = "Hello Learner !! Welcome to howtodoinjava.com.";
		try{
			int i,j;
		    FileWriter fileWriter = new FileWriter(dest);
		    PrintWriter printWriter = new PrintWriter(fileWriter);
		    for(i=0;i<row;++i){
		    	for(j=0;j<column;++j){
		    		printWriter.print(board[i][j]);
		    		printWriter.print(" ");
		    	}
		    	printWriter.print("\n");
		    }
	    //printWriter.print(fileContent);
	    //printWriter.printf("Blog name is %s", "howtodoinjava.com");
	    	printWriter.close();
		}
		catch (IOException e) {
		    e.printStackTrace();
		}
     	
	}

	public void fill_finalboard(){
		int count = 1;
		int i,j;
		finalboard = new String[row][column];

    	for(i=0;i<row;++i){
    		for(j=0;j<column;++j){
    			finalboard[i][j] = board[i][j];
    		}
    	}

    	find_elements();
	    for(i=0;i<row;++i){              
	        for(j=0;j<column;++j){
	           	if(!(finalboard[i][j].equals("00"))){
		      	   	if(i == row-1 && j == column-1) 	  finalboard[i][j] = "bb";
		      	   	else{
		      	   		if(count < 10) finalboard[i][j] = "0" + Integer.toString(count);
		      		 	else finalboard[i][j] = Integer.toString(count);
		      		   count++;
	      			}	
	      		}
	   		}
	 	}


	}

	public void fillRandomBoard(){
		Random rand=new Random();
		int i,j,c;
	  	int s = row*column; 
		int temp = 0 ;
		int f = 0;
		int arr2[] = new int[s];
		int arr[][] = new int[row][column];
		i = 0;
		board = new String[row][column];
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
		    c=rand.nextInt(s);
		    f=0;
		    while(f<s){
		      if(arr2[f] == c){
		        c=rand.nextInt(s);
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
		  	if(arr2[c] < 10 )	board[i][j]= "0" + Integer.toString(arr2[c]);
		  	else board[i][j]=  Integer.toString(arr2[c]);
		  	c++;
		  	if(board[i][j].equals("00"))		board[i][j]="bb";
		 }
		}
		find_coordinates();
		fill_finalboard();
	}


	public void find_coordinates(){
		int i,j;
	 	for(i=0;i<row;++i){
	    	for(j=0;j<column;++j){
	      		if(board[i][j].equals("bb") ){
		        	x = i;
		        	y = j;
		        	break;
	      		}
	    	}
	  	}
	}

	public void find_elements(){		//it finds the number of elements which is not "00"
		int i,j,count = 0 ;
		for(i=0;i<row;++i){
			for(j=0;j<column;++j){
				if(!(board[i][j].equals("00"))  ){
					count++;
				}
			}
		}
		numOfElements = count;
	}

	public void reset(){
	 	int i,j=0,count = 1;
	 	find_elements();
	    for(i=0;i<row;++i){              
	        for(j=0;j<column;++j){
	           	if(!(board[i][j].equals("00"))){
		      	   	if(i == row-1 && j == column-1) 	  board[i][j] = "bb";
		      	   	else{
		      	   		if(count < 10 ) board[i][j] = "0" + Integer.toString(count);
		      			else board[i][j] = Integer.toString(count);
		      			count++;
	      			}	
	      		}
	   		}
	 	}
	  	x=i-1;
	  	y=j-1;
	}

	public String cell(int a,int b)
	{
			if(a <= 0 || a > row || b <= 0 || b > column){
				//throw new IOException("Sorry, invalid value");  
				System.exit(0);
			}
			return board[a-1][b-1] ;
	}

	public boolean Equals(){

		for(int i=0;i<row;++i){
			for(int j=0;j<column;++j)
				if(!(board[i][j].equals(finalboard[i][j]))) 	return false;
		}
		return true;
		
	}


	public boolean isSolved(){	//it controls the board for the finish

		if (Equals()) return true;
		return false;
	}

	public void move(char move_char){
		String temp;
		switch(move_char){
			case 'l':
			case 'L':
				if(y != 0 && !(board[x][y-1].equals("00"))){
				  //if(intelligence == 1) cout<<endl<<"Intelligent move choose : L"<<endl;
				  	temp = board[x][y-1];
				 	board[x][y-1] = board[x][y];
				    board[x][y] = temp; 
				    y--;
				    last_move = 'L';
				    countMoves++;
				}
  				else  System.out.printf("\nThis is invalid move.Try again !\n\n") ;
				break;
			case 'r':
			case 'R':
				if(y != column-1 && !(board[x][y+1].equals("00"))){
				    //if(intelligence == 1) cout<<endl<<"Intelligent move choose : R"<<endl;
				    temp = board[x][y+1];
				    board[x][y+1] = board[x][y];
				    board[x][y] = temp; 
				    y++;
				    last_move = 'R';
				    countMoves++;
				}
				else  System.out.printf("\nThis is invalid move.Try again !\n\n")  ;
				break;
			case 'u':
			case 'U':
			  	if(x != 0 && !(board[x-1][y].equals("00"))){
				   // if(intelligence == 1) cout<<endl<<"Intelligent move choose : U"<<endl;
				    temp = board[x-1][y];
				    board[x-1][y] = board[x][y];
				    board[x][y] = temp; 
				    x--;
			    	last_move = 'U';
			    	countMoves++;
			  	}
			  	else  System.out.printf("\nThis is invalid move.Try again !\n\n") ;
				break;
			case 'd':
			case 'D':
			 	if(x != row-1 && !(board[x+1][y].equals("00"))){
				    //if(intelligence == 1) cout<<endl<<"Intelligent move choose : D"<<endl;
				    temp = board[x+1][y];
				    board[x+1][y] = board[x][y];
				    board[x][y] = temp; 
				    x++;
				    last_move = 'D';
				    countMoves++;
				}
				else   System.out.printf("\nThis is invalid move.Try again !\n\n") ;
				break;
		}
	}

}