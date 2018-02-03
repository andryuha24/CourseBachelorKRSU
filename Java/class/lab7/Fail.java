import java.util.*;
import java.io.*;

class Fail
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

	public void getFiles(final File dir)
	{
		for (final File file : dir.listFiles()) 
		{
			if(file.isDirectory())
			{
				getFiles(file);
			} 	
			else 
				if(file.isFile())System.out.println(file.getName());
 		}
	}

	public void getHTMLfiles(final File dir)
	{
		//локальный класс
		class HTMLFileFilter implements FileFilter
		{
			public boolean accept(File file){
				return file.getName().endsWith(".html");
			}
		}
		File[] files =dir.listFiles(new HTMLFileFilter());
		for(File file: files){

			System.out.println(file.getName());
		}
	}
	private void printDirectoryList(File rootDir) throws IOException 
	{
		if (rootDir.isDirectory()) {
		    System.out.println(rootDir.getCanonicalPath());
		    for (File file : rootDir.listFiles()) {
		        printDirectoryList(file);
		    }
		}
	}

	public static void main(String[] arg)
	{
		try
		{
			Fail fail = new Fail();

			Fail.task("First");
			  File file=new File("1.txt");
			  boolean cf=file.createNewFile();
			  System.out.println("File created: "+ cf);
			  File f=File.createTempFile("tmp", ".txt");
			  System.out.println("File path: "+f.getAbsolutePath());
			  //файл удаляется как только перестает работать вирутальная машина
			  f.deleteOnExit();
			Fail.getch();

			Fail.task("Second");
		      File f1=new File("myfile.txt");
			  File f2=new File("2.txt");
			  System.out.println("File Renamed: "+ f1.renameTo(f2));
			  File fd=new File("Direct");
			  File dir=new File("NewDirectory");
			  fd.mkdir();
			  System.out.println("Directory Renamed: "+ fd.renameTo(dir));
			Fail.getch();

			Fail.task("Third");
	 		  System.out.println("File deleted: "+f1.delete());
			Fail.getch();
			  
			Fail.task("Forth");
			  System.out.println("Atribute changed read: "+file.setReadable(true ));
	          System.out.println("Atribute changed write: "+file.setWritable(false ));
			Fail.getch();

		    Fail.task("Fifth");
		      Date dt1=new Date(115,8,25);
		  	  long ln=dt1.getTime();
	          System.out.println("Set new last modifie Date: "+file.setLastModified(ln));
	    	Fail.getch();

			Fail.task("Sixth");
			  System.out.println(f2.length()+" bytes");	
			Fail.getch();

			Fail.task("Seventh");
			  System.out.println("File exist: "+f2.exists());
			Fail.getch();

			Fail.task("Eighth");
			  File newfile = new File("t.txt");
         	  System.out.println(file.renameTo(new File(dir,newfile.getName())));
			Fail.getch();

			Fail.task("Ninth");
			   System.out.println("File path: "+newfile.getAbsolutePath());
			Fail.getch();

			Fail.task("Tenth");
			  if(dir.exists())
			  {
				if(dir.isFile())System.out.println("This is file!");
				else if(dir.isDirectory())System.out.println("This is directory!");
			  }
			Fail.getch();

			Fail.task("Eleventh");
			    File dir1 = new File (".");
			    //System.out.println ("Current dir : " + dir1.getCanonicalPath());
			    fail.getFiles(dir1);
			Fail.getch();

			Fail.task("Twelfth");
         		fail.getHTMLfiles(dir);
			Fail.getch();

			Fail.task("Thirteenth");
			   fail.printDirectoryList(new File("."));
			Fail.getch();
		}
		catch(Exception e){}
	}


}