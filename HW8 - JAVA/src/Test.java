import java.security.InvalidParameterException;

public class Test {
	public static void main(String args[]) {
		/* GTUVector<Integer> vector = new GTUVector<Integer>(Integer[].class,10);
		 for(int i=0;i<10;++i) {
			 vector.container[i] = i;
			 System.out.printf("%d\n",vector.container[i]);
			 vector.usedSize++;
		 }
		 System.out.println(vector.empty());*/
		GTUVector<Integer> vector = new GTUVector<Integer>(Integer[].class,10);
		
		System.out.println("---------EMIRHAN UZUN'S VECTOR CONTAINER TEST ----------");
		vector.insert(77);
		System.out.println(vector.toString());
		vector.insert(155);
		System.out.println(vector.toString());
		vector.insert(236);
		System.out.println(vector.toString());
		vector.insert(345);
		System.out.println(vector.toString());
		vector.insert(418);
		System.out.println(vector.toString());
		vector.insert(468);
		System.out.println(vector.toString());
		vector.insert(467);
		System.out.println(vector.toString());
		vector.insert(466);
		System.out.println(vector.toString());
		vector.insert(465);
		System.out.println(vector.toString());
		vector.insert(464);
		System.out.println(vector.toString());
		vector.insert(463);
		System.out.println(vector.toString());
		vector.insert(462);
		System.out.println(vector.toString());
		vector.insert(558);
		System.out.println(vector.toString());
		vector.insert(41);
		System.out.println(vector.toString());
		vector.erase(155);
		System.out.println(vector.toString());
		vector.erase(41);
		System.out.println(vector.toString());
		vector.erase(345);
		System.out.println(vector.toString());

		
		System.out.printf("The last vector is : ");
                System.out.println(vector.toString());
                                
        System.out.printf("The size of vector is %d \n",vector.size());
        System.out.printf("The capacity of vector is %d \n",vector.max_size());
        if(vector.empty()) System.out.printf("The vector is empty \n");
        else System.out.printf("The vector is not empty \n");
        
        int elm = 77;
        if(vector.contains(77))	System.out.println("This vector includes "+elm);
        else System.out.println("This vector doesn't include "+elm);
        
        vector.clear();
        System.out.println("We clear all content ! ");
        
        if(vector.empty()) System.out.printf("The vector is empty \n");
        else System.out.printf("The vector is not empty \n");
        
        System.out.printf("---------------------------------------------------------------- \n");
        System.out.println("---------EMIRHAN UZUN'S SET CONTAINER TEST -------------------- \n");
        
        GTUSet<Integer> set = new GTUSet<Integer>(Integer[].class,10);
		
		set.insert(619);
		System.out.println(set.toString());
		set.insert(466);
		System.out.println(set.toString());
		set.insert(781);
		System.out.println(set.toString());
		set.insert(312);
		System.out.println(set.toString());
		set.insert(976);
		System.out.println(set.toString());
		set.insert(17);
		System.out.println(set.toString());
		set.erase(466);
		System.out.println(set.toString());
		set.erase(781);
		try {
			set.insert(555);
			set.insert(555);
		} catch (InvalidParameterException e) {
			System.out.printf("%s\n", e);
		}
		
		System.out.printf("The last set:\n");
                System.out.println(set.toString());
                                
        System.out.printf("The size of set is %d \n",set.size());
        System.out.printf("The capacity of set is %d \n",set.max_size());
        if(set.empty()) System.out.printf("The set is empty \n");
        else System.out.printf("The set is not empty \n");
        
        int setelm = 632;
        if(set.contains(632))	System.out.println("This set includes "+setelm);
        else System.out.println("This set doesn't include "+setelm);
        
        set.clear();
        System.out.println("We clear all content ! ");
        
        if(vector.empty()) System.out.printf("The set is empty \n");
        else System.out.printf("The set is not empty \n");
        
	}
}