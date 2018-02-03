import MyLib.*;

class TestException
{

	private static double dev(double a, double b) throws MyException
	{
		if(b==0) throw new MyException("Devide by zero");
		return a/b;

	}

	public static void main(String arg[])
	{
		try
		{
			System.out.println(dev(2,0));
		}
		catch(MyException ex){System.out.println(ex);}
		System.out.println("Ok!");

	}
}