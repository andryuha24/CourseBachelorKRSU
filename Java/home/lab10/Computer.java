import java.util.*;
import java.io.*;

public class Computer implements Serializable 
{
	private String procType;
	private double procFreq;
	private int ram;
	private int hdd;

	public Computer()
	{
	 procType="i7-4702HQ";
	 procFreq=3.2;
	 ram=8;
	 hdd=1024;
	}
	
	public Computer(String procType,double procFreq, int ram, int hdd)
	{
	  this.procType=procType;
	  this.procFreq=procFreq;
	  this.ram=ram;
	  this.hdd=hdd;
	}
	
	public String getProc(){return procType;}
	public double getFrequency(){return procFreq;}
	public int getRAM(){return ram;}
	public int getHDD(){return hdd;}

	
	public void setProc(String procType){this.procType=procType;}
	public void setFrequency( double procFreq){this.procFreq=procFreq;}
	public void setRAM(int ram){this.ram=ram;}
	public void setHDD(int hdd){this.hdd=hdd;}
	
	public String toString()
	{return "\nCPU: "+procType+"\nProcessor Frequency: " + procFreq+"GHz"+"\nRAM: " +ram+"GB"+"\nHDD: "+hdd+"GB";}

	void show(){System.out.println(this);}

}