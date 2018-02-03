import java.lang.reflect.*;
import java.util.*;

class MyReflection
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

	public static void main(String[] args) throws NoSuchFieldException, IllegalAccessException
	{
		MyReflection MyReflection = new MyReflection();

		MyReflection.task("First");
			Class sclass=new String().getClass();
			System.out.println(sclass);
		MyReflection.getch();

		MyReflection.task("Second");
			Date date=new Date();
			Class dclass=date.getClass();
			System.out.println(dclass.getName());
		MyReflection.getch();
		
		MyReflection.task("Third");
			Calendar calendar = Calendar.getInstance();
			Class cClass1=calendar.getClass();
			int mods=cClass1.getModifiers();
			if(Modifier.isPublic(mods))System.out.println("public");
			if(Modifier.isAbstract(mods))System.out.println("abstract");
			if(Modifier.isFinal(mods))System.out.println("final");
		MyReflection.getch();
		
		MyReflection.task("Forth");
			Class aclass=new ArrayList().getClass();
			Class superclass=aclass.getSuperclass();
			System.out.println(superclass.getName());
		MyReflection.getch();
		
		MyReflection.task("Fifth");
			Class stringClass=new String().getClass();
			Class[] interf= stringClass.getInterfaces();
			for(Class cInterf: interf) System.out.println(cInterf.getName());
		MyReflection.getch();
		
		MyReflection.task("Sixth");
			Class cClass2=Calendar.getInstance().getClass();
			Field[] fields=cClass2.getFields();
			for(Field field: fields)
			{
				Class fieldType=field.getType();
				System.out.println(field.getName()+" type: "+ fieldType.getName());
			}
		MyReflection.getch();
			
		MyReflection.task("Seventh");
			Constructor[] constructors= sclass.getConstructors();
			for(Constructor constructor:constructors)
			{
				Class[] type =constructor.getParameterTypes();
				for (Class paramType : type) 
				{ 
					System.out.print(paramType.getName() + " "); 
				} 
				System.out.println();
			}
		MyReflection.getch();

		MyReflection.task("Eighth");
			Class cl= Math.class;
			Class mclass=cl.getClass();
			Method[] methods = mclass.getMethods();
			for(Method method: methods)
			{
				System.out.println(method.getName());
			}
			MyReflection.getch();
		MyReflection.getch();
		
		MyReflection.task("Ninth");
			class MyCalendar
			{
				public int year =  1812;
			}

			MyCalendar cal = new MyCalendar();
			Class c = cal.getClass();
			Field fld = c.getField("year");
			int value = fld.getInt(cal);
			System.out.println("Current year: "+ value);
			fld.setInt(cal,2015);
			System.out.println("New year: "+ fld.getInt(cal));
		MyReflection.getch();
	}
}



