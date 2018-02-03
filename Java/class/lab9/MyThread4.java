class MyThread4 extends Thread
{
	private static boolean done = false;
	public void run()
	{
		System.out.println("Thread start!");
	}
	public void shutDown()
	{
		done = true;
		System.out.println("Thread stop!");
	}

	public static void main(String[] arg) throws InterruptedException
	{
		int n = 0;
		while(!done)
		{
			MyThread4 mth = new MyThread4();
			mth.start();	
			if(n==10)
			{
				Thread.sleep(5000);
				mth.shutDown();
			}
			n++;
		}
			
	}

}
