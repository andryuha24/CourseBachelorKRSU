import java.util.*;
import java.text.*;

class DateCal
{

	static String[] month={"January","Fabruary","March","April","May","June","July","August","September","October","November","December"};
	static String[] week={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

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
	

	public Date returnDate(Calendar cl)
	{
		return cl.getTime();
	}

	public Calendar returnCalendar(Date dt)
	{
		Calendar cl = Calendar.getInstance();
		cl.setTime(dt);
		return cl;
	}

	public int  avrg(int[] arr)
	{
		int sum=0;
		for(int i=0;i<arr.length;i++)sum+=arr[i];
		return sum/arr.length;
	}

	public static void main(String[] arg)
	{
		DateCal dc=new DateCal();
		SimpleDateFormat dateformat=new SimpleDateFormat("dd/MM/yyyy");

		DateCal.task("First");
		Date dt = new Date();
		System.out.println("Current Date: "+ dt);
		DateCal.getch();

		DateCal.task("Second");
		Calendar calendar = Calendar.getInstance();
		System.out.println("Current Date: " + calendar.getTime());//Возвращает объект класса Date, содержащий время,
												  //эквивалентное вызывающему объекту
		DateCal.getch();

		DateCal.task("Third");
		System.out.println("Calendar to Date: "+dc.returnDate(calendar));
		System.out.println("Date to Calendar: "+dc.returnCalendar(dt).getTime());
		DateCal.getch();

		DateCal.task("Forth");
		System.out.println("Current Date: "+ dateformat.format(dt));
		DateCal.getch();

		DateCal.task("Fifth");
		String dateString = "12.10.1996";
		try
		{
			DateFormat format = new SimpleDateFormat("dd.MM.yyyy", Locale.ENGLISH);
			Date date = format.parse(dateString);
			System.out.println(date);
		}
		catch(Exception e){}
		DateCal.getch();

		DateCal.task("Sixth");
		Date dt1=new Date();
		long ln=dt1.getTime();
		ln+=5*24*60*60*1000;
		Date date =new Date(ln);
		System.out.println(date);

		Calendar cal= Calendar.getInstance();
		long lnn=cal.getTime().getTime()+5*24*60*60*1000;
		cal.setTimeInMillis(lnn);
		System.out.println(	cal.getTime());
		DateCal.getch();

		DateCal.task("Seventh");
		Date date2 = new Date();
		Date dat=new Date(115,8,25);//устаревший
		System.out.println(dat);
		long lng=(date2.getTime()-dat.getTime())/(24 * 60 * 60 * 1000);
		System.out.println("Delta: "+lng);
		DateCal.getch();

		DateCal.task("Eighth");
		if(date2.equals(dat)){System.out.println("Dates Equals");}
		else {System.out.println("Dates Not Equals");}
		
		if(date2.before(dat)) System.out.printf("Date2 is before then Dat\n");
		else System.out.printf("Dat is before then Date2\n");
		DateCal.getch();

		DateCal.task("Ninth");
		Calendar cal2 = Calendar.getInstance();
		System.out.println(week[cal2.get(Calendar.DAY_OF_WEEK)-1]);
		System.out.println(month[cal2.get(Calendar.MONTH)]);
		System.out.println(cal2.get(Calendar.YEAR));
		DateCal.getch();

		DateCal.task("Tenth");
		long time1=System.currentTimeMillis();
		System.out.println("time #1: "+time1+"\n");
		Random random=new Random();
		int[] mass=new int[1000];
		for(int i=0;i<mass.length;i++)
		{
			mass[i]=random.nextInt()%100+1;
			System.out.printf("%2d ",mass[i]);
		}
		System.out.println("\n ");
		System.out.println("Srednee: "+dc.avrg(mass)+"\n");
		long time2=System.currentTimeMillis();
		System.out.println("time #2: "+time2+"\n");
		System.out.println("Delta: "+(time2-time1));
		DateCal.getch();
		
	}

}