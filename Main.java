//Author: Katherine Castro
//Module 8: Portfolio Project Part II
//Java Concurrency Program
//CSC 450 Programming III
//Colorado State University Global Campus
//Professor Lawrence Meadors



public class Main extends Thread
{
	public static void main(String[] args)
	{
		//t1 referenced as Main thread of program
		Thread t1 = Thread.currentThread();
		
		  
		//Priority is set to max so t1 runs first
		t1.setPriority(MAX_PRIORITY);
		  
		//Counts up to 20
		for (int i = 1; i <= 20; i++)
		{
			System.out.println("Counting Up : " + i);
		}
		
		//t2 declared as Child process
		SecondThread t2 = new SecondThread();
		  
		//starts the second thread t2
		t2.start();
	}
}

/**
 * extended Class acts as thread. 
 * t2.start() calls run() 
 * */
class SecondThread extends Thread
{ 
	@Override
	public void run()			//run() method part of thread class used 
	{							//when thread constructed using separate 
								//runnable object
		
		//counts up to 20
		for (int i = 20; i >= 1; i--)
		{
			System.out.println("Counting Down : " + i);
		}
		
		
	}   
}
