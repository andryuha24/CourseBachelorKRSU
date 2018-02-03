import java.io.*;
import java.util.*;
class MyFile
{
    
    public static void main(String[] args) throws IOException
    {
        MyFile mf = new MyFile();
        String strLine;
        int count =0;
        try
        {
            FileInputStream sourceFile=new FileInputStream(args[0]);
            BufferedReader bufferFile=new BufferedReader(new InputStreamReader(sourceFile));
            while((strLine=bufferFile.readLine())!=null)
            {
                strLine = strLine.replaceAll("[^ a-zA-Z]","");
                for (String word : strLine.split("\\s"))
                {
                    if(word.length()<5)
                    {
                        System.out.println(word);
                        count++;
                    }
                        
                }
            }
            System.out.println("Numbers of words, where word.length < 5: " + count);
        }
        catch(FileNotFoundException e)
        {
            System.out.println("File Not Found");
            System.exit(0);
        }
        catch(IOException e){}
    }

    
}



