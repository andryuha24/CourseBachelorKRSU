import java.util.*;
import java.io.*;
import java.util.zip.*;

class InOut
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
		InOut.task("First");
		try
		{
			BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
			StringBuffer strArr=new StringBuffer();
			String line=" ";
			int i=0;
			while(!(line=br.readLine()).equals("guit"))
			{
				strArr.append(line+"\n");
				i++;
			}
			System.out.println(strArr);
		}
		catch(Exception ex){}
		InOut.getch();

		InOut.task("Second");
		float hits=10, a=3;  
        Formatter ft= new Formatter();
        System.out.println(String.format("10/3 = %.3f", hits / a));
        System.out.println(ft.format("10/3= %.3f",hits/a));
		InOut.getch();

		InOut.task("Third");
 		Calendar cl=Calendar.getInstance();
        System.out.format("Local Time: %tT", cl);
		InOut.getch();

		InOut.task("Forth");
		cl.set(1994,8,24);
        System.out.format("My BirthDay: %te %tB, %tY\n",cl,cl,cl);
		InOut.getch();

	    InOut.task("Fifth");
	    String line;
		File f =new File("in.txt");
		try{
        	BufferedReader fr=new BufferedReader(new FileReader("in.txt"));
        	BufferedWriter bw= new BufferedWriter(new FileWriter("out.txt"));
        	StringBuffer buff=new StringBuffer();
        	String lineSeparator = System.getProperty("line.separator");
        	while((line=fr.readLine())!=null)
        	{
        		buff.append(line);
        		buff.append(lineSeparator);
        	}
        	bw.write(buff.toString());
        	bw.close();
        	System.out.println("The file is  successfully written!");
        	InOut.getch();

			InOut.task("Sixth");

			FileInputStream fs=new FileInputStream(f);
			//int b;
			byte[] bait=new byte[(int)f.length()];
			fs.read(bait);
			String s = new String(bait);
            System.out.println("File content:\n"+s);
           
			InOut.getch();

			InOut.task("Seventh");
			RandomAccessFile file =new RandomAccessFile("in.txt","r");
			file.seek(20);
			int b = file.read();
			System.out.println(b);
			String res="";
			while (b!= -1)//побитово читаем
			{	res += (char)b;
        		b = file.read();
			}
			file.close();
			System.out.println(res);
			InOut.getch();

			InOut.task("Eighth");
			Enumeration entries;
    		ZipFile zipFile = new ZipFile("books.zip");
			entries = zipFile.entries();
			String name;
			long size;
			while(entries.hasMoreElements()) 
			{
				ZipEntry entry = (ZipEntry)entries.nextElement();
				name = entry.getName(); 
                size=entry.getSize();  
                System.out.println("Name: "+ name + "  size: "+ size+ " byte");
			}
			InOut.getch();

			InOut.task("Ninth");
			FileInputStream fis= new FileInputStream(f);
			FileOutputStream fos= new FileOutputStream("1.zip");
			ZipOutputStream zos= new ZipOutputStream(fos);
			ZipEntry ze= new ZipEntry("in.txt");
			zos.putNextEntry(ze);
			byte[] buf = new byte[1024];
			while((b=fis.read(buf))>0)
			{
			 zos.write(buf, 0, b);
			}
			fis.close();
			zos.close();
			System.out.println("Archive was successfully created!");
			InOut.getch();
        }
		catch(Exception e){System.out.println(e.toString());}
	}
}