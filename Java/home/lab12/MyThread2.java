class MyThread2 extends Thread
{

	public MyThread2()
	{
		System.out.println("Hi!");
	}


	public void run()
	{
		try
		{
		    System.out.println("Calling System.gc()");
		    Thread.sleep(2000);
		    System.gc();
			
			System.out.println("Calling System.runFinalization()");
			Thread.sleep(2000);
			System.runFinalization();
	
			
		}
		catch(InterruptedException e)
		{
			e.printStackTrace();
		}	
	}

	protected void finalize() throws Throwable
	{
		System.out.println("Bye!");
		Thread.sleep(10000);
	}
}