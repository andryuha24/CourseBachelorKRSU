package MyLib;

public class MyException extends  Exception
{
	public MyException(){};
	public MyException(String msg)
	{
		super(msg);
	}
}