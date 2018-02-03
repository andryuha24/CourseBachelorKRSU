
class MyThread extends Thread
{
	private String name;
	public MyThread(String name)
	{
		this.name=name;

	}


	public void run()
	{
		System.out.println(name+" ");
	}
}