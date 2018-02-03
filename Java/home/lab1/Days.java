import java.util.*;
public class Days
{
	public static void main(String[] arg)
   {
  	Scanner sc = new Scanner(System.in);
  	String[] dw = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  	System.out.println("Input day of week: ");
    int day = sc.nextInt();
	  if (day > 0 && day < 8) System.out.println("Name of week day is "+ dw[day - 1]);
		else  System.out.println("ErrorInput");
    }
}
