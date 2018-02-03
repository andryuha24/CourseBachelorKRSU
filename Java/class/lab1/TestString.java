import java.io.*;
import java.util.*;
class TestString
{
   static void task(String s)
   {
       System.out.println(s);
   }
   public static void main(String[] arg)
   {
        TestString.task("First\n");
		String st=new String("qwe");
		String str=new String("asd");
		if(st==str){System.out.println("Strings Equals");}
		else {System.out.println("Strings Not Equals");}
		
		if(st.equals(str)==true) System.out.printf("Method equals: Strings equals\n");
		else System.out.printf("Method equals: Strings not equals\n");
		
		if(st.equalsIgnoreCase(str)==true)System.out.printf("Method equalsIgnoreCase: Strings equals\n");
		else {System.out.println("Method equalsIgnoreCase: Strings not equals");}
		
		TestString.task("\nSecond\n");
		int result=st.compareTo(str);//для упорядочивания
		if(result<0) {System.out.println(st);System.out.println(str);}
		else {System.out.println(str);System.out.println(st);}
		
		TestString.task("\nThird\n");
		String addr="gorod Bishkek ulica Zhukeeva-Pudovkina/Doneckaya dom 6";
		String ul=addr.substring(20,47);
		System.out.println(ul);
		String ul1="ulica";
		System.out.println(addr.indexOf(ul1));
		System.out.println(addr.indexOf("d",10));

		TestString.task("\nForth\n");
		for(int i=0;i<st.length();i++)
		System.out.println(st.charAt(i));
		
		StringReader sr=new StringReader(st);//считывание строки
		try
		{
			for(int i=0;i<st.length();i++)
			{
				char c=(char)sr.read();//посимвольное считывание
				System.out.println(c);
				
			}
			//закрыть поток
			sr.close();
		}
		catch (java.io.IOException ex) 
		{
				ex.printStackTrace();//вывод ошибки в консоль
        }
		
		TestString.task("\nFifth\n");
		StringBuffer sb=new StringBuffer("TestString");
		sb.reverse();
		System.out.println(sb);
	
	    TestString.task("\nSixth\n");
		String st6="odin dva tri chetyre pyat";

		Stack stack = new Stack ();
		StringTokenizer stt=new StringTokenizer(st6," ");
		String st1;
		sb.setLength(0);
		while(stt.hasMoreTokens())
			{
				st1=stt.nextToken();
				stack.push(st1);
			}
			while(!stack.empty())
			{
				sb.append(stack.pop());
				sb.append(" ");
			}
		System.out.println(st6);
		System.out.println(sb);

		TestString.task("\nSeventh\n");
		System.out.println(addr.toUpperCase());
		System.out.println(addr.toLowerCase());

		TestString.task("\nEight\n");
		String s = "          Hello World        ";
		System.out.println(s);
		System.out.println(s.trim());
		
		TestString.task("\nNine\n");
		String newSt = "odin, dva, tri, chetyre";
		String[] tmp = newSt.split(",");//деление на лексемы
		for(int i=0;i<tmp.length;i++)System.out.println(tmp[i]);
		StringTokenizer stt1=new StringTokenizer(newSt,",");
		while(stt1.hasMoreTokens())
		{
			String st3=stt1.nextToken();
			System.out.println(st3);
		}
   }
}