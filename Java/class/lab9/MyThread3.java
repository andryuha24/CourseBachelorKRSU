class MyThread3
{
	Thread mth = new Thread(new Runnable(){
		public void run()
		{
			System.out.println("May force be with you");
		}
	});

	public MyThread3()
	{
		mth.start();
	}
	
	public static void main(String[] arg)
	{
		MyThread3 mth = new MyThread3();
	}

}