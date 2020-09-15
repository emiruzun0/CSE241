import java.util.NoSuchElementException;


/**
 * This class is the iterator class
 * @author Emirhan Uzun - 171044019
 *
 * @param <T> The type of the iterator
 */

public abstract class GTUIterator<T> {
	protected int index = 0;
	
	
	/**
	 * Returns true if the iteration has more elements. (In other words, returns true if next() would return an element rather than throwing an exception.)
	 * @return true if the iteration has more elements
	 */
	public abstract boolean hasNext();
	
	/**
	 * Returns the next element in the iteration.
	 * @return the next element in the iteration
	 * @throws NoSuchElementException  if the iteration has no more elements throw exception
	 */
	public abstract T next() throws NoSuchElementException;
	
	/**
	 * Finds the index 
	 * @return the index of iterator
	 */
	public abstract int getIndex();
}