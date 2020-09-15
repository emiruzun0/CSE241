import java.lang.reflect.Array;

/**
 * This class is the abstract super class 
 * @author Emirhan Uzun 171044019
 *
 * @param <T> The type of the variable type
 */
public abstract class GTUContainer<T> {
	
	protected int usedSize;
	protected int capacity;
	public T[] container;
	protected Class<T[]> classtype;
	
	/**
	 * This constructor is assign the class type, capacity, used size and creates the array with given class type
	 * @param givenclass given class is the type of the container
	 * @param givencapacity this is the capacity which is given from user.
	 */
	public GTUContainer(Class<T[]> givenclass,int givencapacity) {		
		classtype = givenclass ;
		usedSize = 0;
		capacity = givencapacity;
		container = givenclass.cast(Array.newInstance(givenclass.getComponentType(), capacity));
	}

	/**
	 * Test whether container is empty
	 * @return true if the container is empty
	 */
	public abstract boolean empty()  ;
	/**
	 * It gives the container size
	 * @return Return container size
	 */
	public abstract int size()  ;
	/**
	 * It gives the container max size
	 * @return Return container capacity
	 */
	public abstract int max_size()  ;
	/**
	 * Insert element
	 * @param element This is the given element to insert the container
	 */
	public abstract void insert( T element)  ;
	/**
	 * Erase element from the container
	 * @param element This is the given element to erase from container
	 */
	public abstract void erase( T element)  ;
	/**
	 * Clear all content 
	 */
	public abstract void clear()  ;
	/**
	 * It creates a iterator and returns to beginning
	 * @return  iterator to beginning
	 */
	public abstract GTUIterator<T> iterator()  ;
	
	/**
	 * This method controls the given element in container or not
	 * @param element This is the given element which we controls that it is in the container
	 * @return true if the container contains element
	 */
	public abstract boolean contains(Object element);
}


