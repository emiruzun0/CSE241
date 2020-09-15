
/**
 * This class is the abstract super class of Homework 7
 * Student ID : 171044019
 * @author Emirhan Uzun
 * @version 1.0
 *
 */
public abstract class Abstractboard{
	
	/**
	 * row  Row number of board
	 * column  Column number of board
	 *  X coordinate of blank
	 *  y  Y coordinate of blank 
	 *  last_move Shows the last move of game
	 */

	protected int row,column ;
	protected int x,y; 	
	protected int numOfElements = 0;
	/**
	 * Show the move number which is done successfully
	 */
	public static int countMoves = 0;
	/**
	 * Shows the board number which is created
	 */
	public static int countBoards = 0;
	protected char last_move = 'S'; 
		
	/**
	 * Constructor sets the values default is 0.And then it increments the number of board.
	 */
	public Abstractboard()
	{
		row = column = 0;
		x = y = 0; 	
		numOfElements = 0;
		last_move = 'S';
		countBoards++;
	}


	/**
	 * This method return the last move of game
 	 * @return returning character value which is last move
	 */
	public char lastMove()
	{
		return last_move;
	}

	/**
	 * This method return the move number of game
 	 * @return returning integer value which is number of moves
	 */
	public static int numberOfMoves()
	{
		return countMoves;
	}

	/**
	*This method is used for global function
	* @return the x value of empty box
	*/
	public int tempx_coord(){
		return x;
	}


	/**
	*This method is used for global function
	* @return the y value of empty box
	*/
	public int tempy_coord(){
		return y;
	}

	
	/**
	 * This method return the board number of game
 	 * @return returning integer value which is number of boards
	 */
	public static int NumberOfBoards()
	{
		return countBoards;
	}
	
	/**
	 * This method sets the row and column with given parameters
	 * @param a Temporary row size
	 * @param b Temporary column size
	 * 
	 */
	public abstract void setSize(int a,int b);
	/**
	 *produces the board as string
	 */
	public abstract String toString();
	/**
	 * Reads the board from the file given as function parameter.
	 * @param filename It includes the board 
	 */
	public abstract void readFromFile(String filename);
	/**
	 * Writes the board to the file given as function parameter
	 * @param dest The board is written to this parameter
	 */
	public abstract void writeToFile(String dest);
	/**
	 * Fills the correct final board.
	 */
	public abstract void fill_finalboard();
	/**
	 * It creates a random board with given row and column in setsize function.
	 */
	public abstract void fillRandomBoard();
	/**
	 * Find the coordinates of empty index
	 */
	public abstract void find_coordinates();
	/**
	 * It finds the elements which are not "00" (wall)
	 */
	public abstract void find_elements();
	/**
	 * Resets the board to the solution.
	 */
	public abstract void reset();
	/**
	 * Takes two indexes and returns the corresponding cell content.
	 * @param a Row coordinate
	 * @param b Column coordinate
	 * @return Corresponding cell content
	 */
	public abstract String cell(int a,int b);
	/**
	 * Two boards are equal, if the boards are the same. This operator does
	not consider last move or the number of steps
	 * @return It returns the equation of these board.
	 */
	public abstract boolean Equals();
	/**
	 * This method controls the board with final solution
	 * @return Returns true if the board is a solution
	 */
	public abstract boolean isSolved();
	/**
	 * Makes a move according to the given char parameter.
	 * @param move_char Given parameter to move
	 */
	public abstract void move(char move_char);

}