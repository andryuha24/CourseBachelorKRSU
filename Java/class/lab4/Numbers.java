import java.util.*;
import java.text.*;

 class Numbers
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

	public static boolean almostEqual(float a, float b, float eps)
	{
    	return Math.abs(a-b)<eps;
	}

	public static void main(String[] arg)
	{
		Numbers.task("First");
		Scanner sc = new Scanner(System.in);
		try
		{
			System.out.print("Input line: ");
			String str=sc.next();

			int n=Integer.parseInt(str);
			System.out.println("Number: "+n);
		}
		catch(NumberFormatException e ){  System.out.println(e);}
		Numbers.getch();

		Numbers.task("Second");
		Float f1=new Float(1.23);
		Float f2=new Float(1.23);
		System.out.println("Float.equals: "+f1.equals(f2));
		Numbers.getch();

		Numbers.task("Third");
		Float f3=new Float(1.23);
		Float f4=new Float(1.27);
		System.out.println(almostEqual(f3,f4,0.05f));
		Numbers.getch();

		Numbers.task("Forth");
		float n1=Math.round(3.13445566*100);
		float n2=Math.round(3.13445566*10);
		System.out.println(n1/100);
		System.out.println(n2/10);
		Numbers.getch();

		Numbers.task("Fivth");
		NumberFormat nf=NumberFormat.getNumberInstance(Locale.GERMAN);
		double d=1623542.765;
		System.out.println("Number Format: "+nf.format(d));
		Numbers.getch();

		Numbers.task("Sixth");
		float f=0.80f;
		System.out.println("Percent Format: "+NumberFormat.getPercentInstance().format(f));
		Numbers.getch();

		Numbers.task("Seventh");
		double value=567123678.99;
		System.out.println("Currency Format: "+NumberFormat.getCurrencyInstance(Locale.US).format(value));
		Numbers.getch();

		Numbers.task("Eighth");
		int number=24;
		System.out.println("Number: "+number);
		System.out.println("Binary: "+Integer.toBinaryString(number));
		System.out.println("Hex: "+Integer.toHexString(number));
		System.out.println("Octal: "+Integer.toOctalString(number));
		Numbers.getch();

		Numbers.task("Ninth");
		Random rd=new Random();
		System.out.println("Random int: "+rd.nextInt(100));
		System.out.println("Random double: "+String.format("%.4f",rd.nextDouble()));
		System.out.println("Math.rand int: "+(int)(Math.random()*100));
		System.out.println("Math.rand double: "+String.format("%.4f",(double)(Math.random()*100)));
		Numbers.getch();

		Numbers.task("Tenth");
		System.out.println("Sin(45): "+ Math.sin(Math.toRadians(45)));
		System.out.println("Cos(45): "+ Math.cos(Math.toRadians(45)));
		System.out.println("Tg(45): "+ Math.tan(Math.toRadians(45)));
		Numbers.getch();

		Numbers.task("Eleventh");
		System.out.println("Log(125.5)= "+Math.log(125.5));
		Numbers.getch();


	}
}