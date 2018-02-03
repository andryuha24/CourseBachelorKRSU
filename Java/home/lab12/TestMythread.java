class TestMyThread
{
	public static void main(String[] arg)
	{	
	    Object stateChanged = new Object();
		int n=7;
		Thread[] mt = new Thread[n];
		/*MyThread mth1 = new MyThread("thread#1");
		MyThread mth2 = new MyThread("thread#2");
		mth2.setPriority(Thread.MAX_PRIORITY);
		mth1.setPriority(Thread.MIN_PRIORITY);*/
		for (int i=0;i<n;i++)
		{
			mt[i] = new MyThread("thread#"+(i+1));
			if(i%2==0) mt[i].setPriority(10);
			mt[i].start();
		}
		/*mth1.start();
		mth2.start();*/
		/*for (int i=0;i<n;i++)
		{
			mt[i] = new MyThread("thread#"+(i+1));
			if(i%2==0) mt[i].setPriority(10);
			mt[i].start();
		}*/
		/*//mt[2].notifyAll();
		for(int j=0;j<20;j++)
		{
			for(int i=0;i<n;i++)
			{
				//synchronized(mt[i])
				//{
					
					mt[i].notify();
				//}
				try
				{
					Thread.sleep(100);

				}
				catch(InterruptedException e){e.printStackTrace();}	
			}
			System.out.println(j);
		}*/
	}


}
