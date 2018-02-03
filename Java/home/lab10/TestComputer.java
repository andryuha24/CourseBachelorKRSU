import java.io.*;
import java.util.*;
class TestComputer
{

  public static void main(String[] argv)
  {  
	try
	{
		ArrayList<Computer> objList=new ArrayList<Computer>();
		if(objList instanceof List) System.out.println("OK!");

		Computer pc1 =new Computer("i5-5200U",2.7,6,1024);
		Computer pc2=new Computer("Quad-Core Intel Core i5",3.1,4,2048);
		Computer pc3=new Computer();
		objList.add(pc1);
		objList.add(pc2);
		objList.add(pc3);
Serializable arList = new ArrayList();

		Class arrayList=new ArrayList<>().getClass();
		Class arrayList2=ArrayList.class;

		Class[] interf= arrayList.getInterfaces();
		for(Class cInterf: interf) System.out.println(cInterf.getName());

		FileOutputStream fileOut=new FileOutputStream("sdf.ser");
		ObjectOutputStream out=new ObjectOutputStream(fileOut);
		out.writeObject(objList);
		out.close();
		fileOut.close();
		System.out.println("Serialized: ");
		System.out.println(objList);
	}
	catch(Exception ex){}
	try 
	{ 
		FileInputStream fileIn = new FileInputStream("sdf.ser");
		ObjectInputStream in = new ObjectInputStream(fileIn);
		ArrayList<Computer> Computer = (ArrayList<Computer>) in.readObject();
		in.close();
		fileIn.close();
		System.out.println("Deserialized object:");
		System.out.println(Computer);
	} 
	catch (Exception e) {System.out.println("Exception in deserialization: " + e); }   
	
  }
}