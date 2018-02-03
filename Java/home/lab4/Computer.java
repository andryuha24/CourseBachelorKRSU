package MyLib;
/** 
*My first class
*@author Zhulin Andrew
*@version 1.0
*/
public class Computer
{
	private String procType;
	private double procFreq;
	private int ram;
	private int hdd;

	/**
 	*Constructor create object Computer
    */
	public Computer()
	{
	 procType="i7-4702HQ";
	 procFreq=3.2;
	 ram=8;
	 hdd=1024;
	}
	/**
 	*Constructor create object Computer with specific parameters
 	*@param procType  type of CPU
 	*@param procFreq  frequency of CPU
 	*@param ram  RAM of computer
 	*@param hdd  capacity of computer
    */
	public Computer(String procType,double procFreq, int ram, int hdd)
	{
	  this.procType=procType;
	  this.procFreq=procFreq;
	  this.ram=ram;
	  this.hdd=hdd;
	}
	/**
	*Method getProc
	* @return String: Name of CPU
	*/
	public String getProc(){return procType;}
	/**
	*Method getFrequency
	*@return double Frequency of CPU
	*/
	public double getFrequency(){return procFreq;}
	/**
	*Method getRAM
	*@return double RAM of Computer
	*/
	public int getRAM(){return ram;}
	/**
	*Method getHDD
	*@return double Capacity of HDD
	*/
	public int getHDD(){return hdd;}
	/**
	*Set Name of Proc
	*@param procType  Name of CPU
	*/
	public void setProc(String procType){this.procType=procType;}
	/**
	*Set Frequency of CPU
	*@param procFreq  frequency of CPU
	*/
	public void setFrequency( double procFreq){this.procFreq=procFreq;}
	/**
	*Set RAM of Computer
	*@param ram  RAM of Computer
	*/
	public void setRAM(int ram){this.ram=ram;}
	/**
	*Set Capacity of HDD
	*@param hdd  Capacity of HDD
	*/
	public void setHDD(int hdd){this.hdd=hdd;}

	/**
	*Returns a string representation of the object
	*@see java.lang.Object
	*/
	public String toString()
	{return "\nCPU: "+procType+"\nProcessor Frequency: " + procFreq+"GHz"+"\nRAM: " +ram+"GB"+"\nHDD: "+hdd+"GB";}
	
	/**
	*Method shows string
	*@see #toString()
	*/
	public void show(){System.out.println(this);}

}