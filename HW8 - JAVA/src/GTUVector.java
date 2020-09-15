import java.lang.reflect.Array;
import java.util.NoSuchElementException;

/**
 * The Set Class which is extends from GTUContainer class.
 * @author Emirhan Uzun - 171044019
 */
public class GTUVector<T> extends GTUContainer<T>{

	/**
	 * @param classtype  The type of the container
	 * @param givencapacity This is capacity that is given from user.
	 */
	public GTUVector(Class<T[]> classtype, int givencapacity) {
		super(classtype,givencapacity);
    }
	
	
	/**
	 * This is the inner class that in the GTUVector class.It extends the GTUIterator methods and assign index.
	 *
	 */
	public class GTUVectorIter extends GTUIterator<T>{
		int index = 0;
		
		@Override
		public boolean hasNext(){
	        if(index < usedSize ) return true;
	        return false;
	    }

	    
	    public T next() throws NoSuchElementException
	    {
	        try{
	            if(!hasNext())
	                throw new NoSuchElementException("This is an exception that array has no more element");
	            else return container[index++];
	        }
	        catch(Exception e){
	            System.out.println(e);
	            return null;
	        }
	    }


		@Override
		public int getIndex() {
			return index;
		}
	}

	@Override
	public boolean empty() {
		if(this.usedSize == 0) 	return true;
        else return false;
	}

	@Override
	public int size() {
		return this.usedSize;
	}

	@Override
	public int max_size() {
		return this.capacity;
	}

	@Override
	public void insert(T element) {
		if(usedSize + 1 == capacity) {
			capacity += 10;
			T[] tempArr = classtype.cast(Array.newInstance(classtype.getComponentType(), capacity ));
			for(int i=0; i<usedSize; i++)
				tempArr[i] = container[i];
			container = classtype.cast(Array.newInstance(classtype.getComponentType(), capacity ));
			for(int i=0; i<usedSize; i++)
				container[i] = tempArr[i];
		}
		container[usedSize] = element;
		usedSize++;	
		System.out.println(element+" was inserted the vector container ! ");
	}

	@Override
	public void erase(T element) {
		boolean flag = false;
		GTUIterator<T> it = iterator();
		while(it.hasNext()) {
			T val = it.next();
			if(val.equals(element)) {
				flag = true;
				break;
			}
		}
		if(flag) {
			for(int i=it.getIndex(); i< usedSize; i++)
				container[i-1] = container[i];
			usedSize--;
			System.out.println(element+" was erased from the vector container ! ");
		}
		else System.out.println(element+" is not in the vector !");
	}

	@Override
	public void clear() {
		this.usedSize = 0;
	}

	@Override
	public GTUIterator<T> iterator() {
		return new GTUVectorIter();
	}
	
	/**
	 *This method prints the container 
	 */
	public String toString(){
        String printArr = "";
        printArr += "\n";
        GTUIterator<T> iter = this.iterator();

        do {
                T element = iter.next();
                printArr += element;
                printArr += " ";
        }while(iter.hasNext());
        printArr += "\n";
        return printArr;
    }

	@Override
	public boolean contains(Object element) {
		GTUIterator<T> it = this.iterator();
		while(it.hasNext()) {
			T value = it.next();
			if(value == element) {
				return true;
			}
		}
		return false;
	}

}
