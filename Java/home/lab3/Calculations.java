import java.util.*;

public class Calculations
{
	static final double eps =0.000001;
	
	int[] arr;

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

	public double sumEps(double eps)
	{
		double sum = 0, tmp = 1;
		long k1=1, k2=1;
		int n = 0;
		while (Math.abs(tmp)>=eps)
        {
            tmp=k1*k2/(Math.pow(n,n+1)+1.);
            sum+=tmp;
			n++;
			k1=-k1;
			k2*=2;
        }
		return sum;
	}

	public double sum10(int n)
	{
		double sum10 = 0, tmp = 1;
		long k1=1, k2=1;
		for(int i=0; i<n; i++)
		{
			tmp=k1*k2/(Math.pow(i,i+1)+1.);
            sum10+=tmp;
            k1=-k1;
			k2*=2;
		}
		return sum10;
	}

	public double t1(double x)
	{
		double a=0.1, b=0.2, t1=0;
		if(x>0)
		{
			 t1=(1/Math.pow(a,3))*(Math.log(x)+(2*b/x)-Math.pow(b,2)/(2*Math.pow(x,2)));
		}
		else System.out.println("Не верно введены данные! ОДЗ: x>0.");
		return t1;
	}
	public double t2(double x)
	{
		double a=0.1, t2=0;
		if(Math.sin(a*x)>0&&(1-Math.cos(a*x))>0)
		{
			t2=(1/(2*a))*((1/Math.tan(a*x))/Math.sin(a*x)+Math.log(1-Math.cos(a*x))-Math.log(Math.sin(a*x)));
		}
		else System.out.println("Не верно введены данные! ОДЗ: sin(ax)>0; 1-cos(ax)>0");
	
		return t2;
	}


	public void FillMassiv(int n)
	{
		arr=new int[n];
		for(int i=0;i<arr.length;i++)
		{
			arr[i]=(int)(Math.random()*200-100);
		}	
	}
	public void sortMassiv()
	{
		int temp=0;
		for(int i=0; i< arr.length;i++)
		{
			for(int j=0; j<arr.length-1;j++)
			{
				if(arr[j]>arr[j+1])
				{
					temp = arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
	}

	public void showMas()
	{
		for(int i=0;i<arr.length;i++)
		{
			if(i%10==0)System.out.println();
			System.out.print(" "+arr[i]);
		}
		System.out.println();	
	}


	public static void main(String[] arg)
	{
	    Calculations cl = new Calculations();

	    cl.task("First");
	    System.out.println("Суума ряда: "+cl.sumEps(eps)+" с точностью "+eps);
	    System.out.println("Суума первых 10 членов ряда: "+cl.sum10(10));
	    cl.getch();
	    cl.task("Second");
		Scanner sc=new Scanner(System.in);
		System.out.print("Введите значение x1 и x2: ");
		double	x1=sc.nextDouble();
		double	x2=sc.nextDouble();
		System.out.println("t1= " + cl.t1(x1));	
		System.out.println("t2= " + cl.t2(x2));	
		cl.getch();
		cl.task("Third");
		cl.FillMassiv(100);
		cl.showMas();
		cl.sortMassiv();
		System.out.println("Отсортированный массив:");
		cl.showMas();
		cl.getch();
	}
	
}