import java.util.Scanner;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;



public class Test {

    public static void main(String[] args) {
    	String s;
    	Scanner scanner = new Scanner (System.in);
    	System.out.printf("Which type represent board do you want ?\n1-1D dimensional array\n2-2D dimensional array\n");
    	System.out.printf("Choice : ");
    	int choice = scanner.nextInt();
    	if(choice == 1){
    		System.out.printf("1D dimensional array was created ! \n");
            Array1D game = new Array1D();
            if(args.length == 0){
				System.out.printf("Enter row and column in ordered : ");
				int row = scanner.nextInt();
				int column = scanner.nextInt();
				game.setSize(row,column);
				game.fillRandomBoard();
			}
			else if(args.length == 1){		//read from file.
		 		s = args[0];
		 		game.readFromFile(s);
		 		System.out.printf("----READ TEST IS COMPLETED !---\n");
		 	}
		 	System.out.printf(game.toString());
		 	System.out.printf("----MOVE TEST !---\n");
		 	System.out.printf("----MOVE RİGHT---\n");
		 	game.move('R');
		 	System.out.printf(game.toString());
		 	System.out.printf("----MOVE UP---\n");
		 	game.move('U');
		 	System.out.printf(game.toString());
		 	System.out.printf("----MOVE LEFT---\n");
		 	game.move('L');
		 	System.out.printf(game.toString());
		 	System.out.printf("----MOVE DOWN---\n");
		 	game.move('D');
		 	System.out.printf(game.toString());

		 	System.out.printf("------------------------------------------\n");
		 	System.out.printf("----NUMBER OF MOVES TEST !---\n");
		 	System.out.println("Number of moves : "+game.numberOfMoves());
		 	System.out.printf("------------------------------------------\n");

		 	System.out.printf("------------------------------------------\n");
		 	System.out.printf("----LAST MOVE TEST !---\n");
		 	System.out.println("Last move  : "+game.lastMove());
		 	System.out.printf("------------------------------------------\n");

		 	System.out.printf("------------------------------------------\n");
		 	System.out.printf("----CELL TEST !---\n");
		 	System.out.printf("----In cell (1,2) coordinates content : ");
		 	System.out.println(game.cell(1,2));

		 	System.out.printf("------------------------------------------\n");
		 	System.out.printf("----WRITE TEST !---\n");
		 	game.writeToFile("dest.txt");
		  	System.out.printf("THE FILE IS READY IN THE FOLDER!\n");
		 	System.out.printf("------------------------------------------\n");

		 	System.out.printf("------------------------------------------\n");
		 	System.out.printf("----RESET TEST !---\n");
		 	game.reset();
		 	System.out.printf(game.toString());
		 	System.out.printf("------------------------------------------\n");

		 	System.out.printf("------------------------------------------\n");
		 	System.out.printf("----SOLVE TEST !---\n");
		 	if(game.isSolved()) System.out.printf("This is the solution !\n");
		 	else System.out.printf("This is not the solution !\n");
		 	System.out.printf(game.toString());
		 	System.out.printf("------------------------------------------\n");

    	}
        else if(choice == 2){
        	System.out.printf("2D dimensional array was created ! \n");
            Array2D game = new Array2D();
            if(args.length == 0){
				System.out.printf("Enter row and column in ordered : ");
				int row = scanner.nextInt();
				int column = scanner.nextInt();
				game.setSize(row,column);
				game.fillRandomBoard();
			}
			else if(args.length == 1){		//read from file.
		 		s = args[0];
		 		game.readFromFile(s);
		 		System.out.printf("----READ TEST IS COMPLETED !---\n");
		 	}
		 	System.out.printf(game.toString());

		 	System.out.printf(game.toString());
		 	System.out.printf("----MOVE TEST !---\n");
		 	System.out.printf("----MOVE RİGHT---\n");
		 	game.move('R');
		 	System.out.printf(game.toString());
		 	System.out.printf("----MOVE UP---\n");
		 	game.move('U');
		 	System.out.printf(game.toString());
		 	System.out.printf("----MOVE LEFT---\n");
		 	game.move('L');
		 	System.out.printf(game.toString());
		 	System.out.printf("----MOVE DOWN---\n");
		 	game.move('D');
		 	System.out.printf(game.toString());

		 	System.out.printf("------------------------------------------\n");
		 	System.out.printf("----NUMBER OF MOVES TEST !---\n");
		 	System.out.println("Number of moves : "+game.numberOfMoves());
		 	System.out.printf("------------------------------------------\n");

		 	System.out.printf("------------------------------------------\n");
		 	System.out.printf("----LAST MOVE TEST !---\n");
		 	System.out.println("Last move  : "+game.lastMove());
		 	System.out.printf("------------------------------------------\n");

		 	System.out.printf("------------------------------------------\n");
		 	System.out.printf("----CELL TEST !---\n");
		 	System.out.printf("----In cell (2,2) coordinates content : ");
		 	System.out.println(game.cell(2,2));

		 	System.out.printf("------------------------------------------\n");
		 	System.out.printf("----WRITE TEST !---\n");
		 	game.writeToFile("dest.txt");
		 	System.out.printf("------------------------------------------\n");

		 	System.out.printf("------------------------------------------\n");
		 	System.out.printf("----RESET TEST !---\n");
		 	game.reset();
		 	System.out.printf(game.toString());
		 	System.out.printf("------------------------------------------\n");

		 	System.out.printf("------------------------------------------\n");
		 	System.out.printf("----SOLVE TEST !---\n");
		 	if(game.isSolved()) System.out.printf("This is the solution !\n");
		 	else System.out.printf("This is not the solution !\n");
		 	System.out.printf(game.toString());
		 	System.out.printf("------------------------------------------\n");
        }


        System.out.println("-----------VALID SEQUENCE TEST-------------");
        Array2D[] test2=new Array2D[3];

		for(int i=0;i<3;++i)
			test2[i]=new Array2D();

		test2[0].readFromFile("easy.txt");
		test2[1].readFromFile("easy.txt");
		test2[1].move('R');
		test2[2].readFromFile("easy.txt");
		test2[2].move('R');
		test2[2].move('R');

		for(int i=0;i<3;++i){
			System.out.println("-------------------"+(i+1)+".board"+"-------------------");
			System.out.printf(test2[i].toString());

		}

		if(Valid(test2))
			System.out.println("***This is valid sequence !! ");
		else System.out.println("***The is not valid sequence !! ");


		System.out.printf("------------------------------------------\n");
	 	System.out.printf("----NUMBER OF BOARDS TEST !---\n");
	 	System.out.println("The total created board number is : "+test2[2].NumberOfBoards());
	 	System.out.printf("------------------------------------------\n");
    }

	public static boolean Valid(Abstractboard[] tempboard){	
		int x1=0,x2=0;
		int y1=0,y2=0; 
		int i;
	
		for(i=0;i<tempboard.length-1;++i){
			x1=tempboard[i].tempx_coord();
			x2=tempboard[i+1].tempx_coord();
			y1=tempboard[i].tempy_coord();
			y2=tempboard[i+1].tempy_coord();
	
			if((x1 == x2) && (y1 == y2))	return false;
			else if((x1 != x2) && (y1 != y2))	return false;
	
		}
		if(tempboard[tempboard.length-1].isSolved())	return true;
		else 	return false;
	}
}
