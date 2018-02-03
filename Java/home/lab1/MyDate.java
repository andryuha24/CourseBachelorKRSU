import java.util.*;
import java.text.*;
public class MyDate
{
   public static void main(String[] arg)
   {

      Calendar bd = Calendar.getInstance();//возвращает объект типа Calendar
	  bd.set(Calendar.YEAR, 1994);
 	  bd.set(Calendar.MONTH, 9);
	  bd.set(Calendar.DAY_OF_MONTH, 24);
 	  System.out.println("Birth Date " + bd.get(Calendar.YEAR) + "." + bd.get(Calendar.MONTH) + "." + bd.get(Calendar.DAY_OF_MONTH));
  	  System.out.println(new Date());
    }
  }