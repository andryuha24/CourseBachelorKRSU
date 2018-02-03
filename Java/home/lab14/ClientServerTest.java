import java.io.*;
import java.net.*;
import java.util.*;
public class ClientServerTest 
{

	public ClientServerTest() 
	{
	  new Thread(new MyServer()).start(); 
	  new Thread(new MyClient()).start(); 
	}

	public static void main( String args[])
	{  
		new ClientServerTest();
	}  
}

class MyServer implements Runnable 
{
	public void run()
	{
		ServerSocket server = null; 
		Socket serverSocket = null;  
		OutputStream os = null;
		InputStream is = null;
		String s;
		int ch;

		byte[] currentTime = new byte[3];
		//int buf;
		try
		{
			server = new ServerSocket( 1177);
			serverSocket = server.accept();

			
			System.out.println( "Connect on the Server side!" );
			os = serverSocket.getOutputStream();
			is = serverSocket.getInputStream();
			s = new String();
			int count = 0;

			while(count<3)
			{
				while ((char)(ch = is.read()) != ' ' ) { s += (char)ch; }
				if (s.equals("Time"))
				{
					count++;
					Date bufDate = new Date();
					currentTime[0] = (byte)bufDate.getHours();
					currentTime[1] = (byte)bufDate.getMinutes();
					currentTime[2] = (byte)bufDate.getSeconds();
					os.write(currentTime);
					s = "";
				}

			}

			os.write(44); 
		}
		catch( IOException e){}
	} 
}

class MyClient implements Runnable 
{
	public void run()
	{
		Socket clientSocket = null;
	    InputStream  is = null;
	    OutputStream os = null;
		String s;
		byte[] buf = new byte[3];
		byte[] currentTime = new byte[3];
		try
		{ 
			clientSocket = new Socket( "127.000.000.001", 1177); 
			is = clientSocket.getInputStream();
			os = clientSocket.getOutputStream();
			s = new String();
			for (int i = 0; i < 3; i++)
			{
				os.write((new String("Time ")).getBytes());
				is.read(buf);
				System.out.println("\nServer time: "+buf[0] + ":" + buf[1] + ":" + buf[2]);
				Date bufDate = new Date();
				currentTime[0] = (byte)bufDate.getHours();
				currentTime[1] = (byte)bufDate.getMinutes();
				currentTime[2] = (byte)bufDate.getSeconds();
				System.out.println("Client time: "+currentTime[0] + ":" + currentTime[1] + ":" + currentTime[2]);
				Thread.sleep(5000);
			}
		}
		catch(UnknownHostException e){System.out.println( "UnknownHost" );}
		catch(IOException e){}
		catch (InterruptedException e) { System.out.println("InterruptedException"); }
	} 
} 
