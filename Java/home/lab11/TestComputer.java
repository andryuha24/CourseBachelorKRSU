import java.lang.reflect.*;
import java.util.*;
class TestComputer
{
  	private static ArrayList<Object> arr=new ArrayList<Object>();
  	public  static Class className;

  	public void addObj(Object ob)
	{
		if (ob.getClass()==className) arr.add(ob);
		else System.out.println("This type is wrong! for only "+className);
	}
	public void show()
	{
		for (int i=0;i<arr.size();i++)
		System.out.println(arr.get(i));
	}

	public static void main(String[] argv)
	{  
		TestComputer testPC = new TestComputer();
		//ArrayList<Object> arr=new ArrayList<Object>();
		Computer newPC = new Computer("Quad-Core Intel Core i5",3.1,4,2048);
		className = newPC.getClass();
		arr.add(newPC);
		testPC.addObj("lenovo A360");
		Computer pc2=new Computer();
		testPC.addObj(pc2);
		testPC.show();
    }
}