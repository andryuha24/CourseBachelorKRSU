import java.util.*;
class TestOuterInner
{
	
	static void getch()
	{
       try
	   {
	      System.in.read();
	   }
	   catch(Exception e){}
	}

	public static void main(String arg[])
	{
		MyOuter obj1 = new MyOuter();
		MyOuter.MyInner obj = MyOuter.createInner();
		obj.getOuterMonth(obj1);
		TestOuterInner.getch();
	}

}
