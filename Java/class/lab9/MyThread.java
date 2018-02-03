class MyThread extends Thread
{
	public void run()
	{
		System.out.println("May force be with you");
	}

	public static void main(String[] arg)
	{
		MyThread mth = new MyThread();
		mth.start();
	}

}