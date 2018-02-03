import java.util.*;

class Massiv
{
	static void task(String s)
	{
		System.out.println("\n-----------------");
		System.out.println(s);
		System.out.println("-----------------\n");

	}
	static void getch()
	{
       try
	   {
	      System.in.read();
	   }
	   catch(Exception e){}
	}
	public static void main(String[] arg)
	{

		int n = 10;
		Massiv.task("First");
		
		int[] arr1 = new int[n];
		int[] arr2 = new int[n+10];
		for(int i=0;i<arr1.length;i++)
		{
			arr1[i]=(int)(Math.random()*100);
			System.out.printf("%2d ",arr1[i]);
		}
		System.arraycopy(arr1,0,arr2,0,arr1.length);
		System.out.println("");
		for(int i=0;i<arr2.length;i++)
		{
			System.out.printf("%2d ",arr2[i]);
		}
		arr1=arr2;
		System.out.println("");
		for(int i=0;i<arr1.length;i++)
		{
			System.out.printf("%2d ",arr1[i]);//итого две ссылки ссылаются на второй массив
		}
		Massiv.getch();

		Massiv.task("Second");
		int k1=1,k2=4,k3=7;
		String str1="qwe";
		String str2="asd";
		String str3="zxc";
		HashMap<Integer,String> map = new HashMap<Integer,String>();
		map.put(k1,str1);
		map.put(k2,str2);
		map.put(k3,str3);
		System.out.println(map.get(k1));
		Massiv.getch();

		Massiv.task("Third");
		int[] mass = {1,2,5,8,9,0,4,3,2,7};
		System.out.println("Massiv: "+Arrays.toString(mass));
		Arrays.sort(mass);
		System.out.println("Sorted massiv: "+Arrays.toString(mass));
		Massiv.getch();

		Massiv.task("Forth");
		ArrayList<String> list = new ArrayList<String>();
		list.add(str1);
		list.add(str2);
		list.add(str3);
		System.out.println(list);
		Collections.sort(list);
		System.out.println(list);
		Massiv.getch();

		Massiv.task("Fifth");
		TreeSet<String> tree = new TreeSet<String>();
		tree.add(str1);
		tree.add(str2);
		tree.add(str3);
		System.out.println(tree);
		Massiv.getch();

		Massiv.task("Sixth");
		System.out.println("Index "+ str1 + " : "+ list.indexOf(str1));
		System.out.println(map.containsKey(5));
		System.out.println(map.containsValue(str2));
		Massiv.getch();

		Massiv.task("Seventh");
		int index = Arrays.binarySearch(mass,4);
		System.out.println("Index = " + index);
		System.out.println("Value = " + mass[index]);
		Massiv.getch();

		Massiv.task("Eighth");
		String[] arr=new String[list.size()];
		arr = list.toArray(arr);
		for(String s: arr)System.out.println(s);
		Massiv.getch();

		Massiv.task("Ninth");
		Object ob2[] = map.entrySet().toArray();
		for(int i=0; i<ob2.length; i++)
			System.out.println(ob2[i]);
		Massiv.getch();


	}


}