import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.io.*;

class Reg
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

	public static void main (String[] arg)
	{
		Reg.task("First");
		String st = "This is Jim and Timothy";
		String pattern = "[TJ]im";
		Pattern p=Pattern.compile(pattern);
		Matcher m=p.matcher(st);
		m.find();
		System.out.println(m.group());
		System.out.println(m.start());
		System.out.println(m.end());
		Reg.getch();

		Reg.task("Second");
		String rep="John";
		System.out.println(m.replaceAll(rep));
		Reg.getch();

		Reg.task("Third");
		String st2="My dad and My mom";
		String rep2="Our";
		StringBuffer sb=new StringBuffer();
		Pattern p1=Pattern.compile("My");
		Matcher m1=p1.matcher(st2);
		while(m1.find()){m1.appendReplacement(sb,rep2);}
		System.out.println(sb.toString());
		Reg.getch();

		Reg.task("Fourth");
		String st3="The words are town torn ton toon house.";
		Pattern p3=Pattern.compile("\\st(\\w)*o(\\w)*");
		Matcher m3=p3.matcher(st3);
		while(m3.find())System.out.println(m3.group());
		Reg.getch();

		Reg.task("Fifth");
		try{
			String str5;
			BufferedReader br=new BufferedReader(new FileReader("input.txt"));
			Pattern p5=Pattern.compile("^a");
			Matcher mat=p5.matcher("");
			while((str5=br.readLine())!=null){
				mat.reset(str5);
				while(mat.find()){System.out.println(mat.group());}
			}
		}
		catch(Exception ex){}
		Reg.getch();

		Reg.task("Sixth");
		Pattern pat6=Pattern.compile("\\d$");
		Matcher mat6=pat6.matcher("This is line 1\n Here is line 2\n This is line 3\n");
		while(mat6.find()) {System.out.println(mat6.group());}
		Reg.getch();

	}




}