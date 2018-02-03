class MyThread2 implements Runnable
{
	public void run()
	{
		System.out.println("May force be with you");
	}

	public static void main(String[] arg)
	{
		Thread mth = new Thread(new MyThread2());
		mth.start();
	}

}