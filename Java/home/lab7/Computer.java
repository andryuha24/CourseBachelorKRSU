import MyLib.*;
import java.util.*;
public class Computer
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
	
	public Computer(String procType,double procFreq, int ram, int hdd) throws MyException
	{
	  	setProc(procType);
	  	setFrequency(procFreq);
	  	setRAM(ram);
	  	setHDD(hdd);
	}
	
	public String getProc(){return procType;}
	public double getFrequency(){return procFreq;}
	public int getRAM(){return ram;}
	public int getHDD(){return hdd;}

	
	public void setProc(String procType) //throws IllegalArgumentException
	{
		if (procType == null || procType == "") 
			throw new IllegalArgumentException("Название процессора недолжно быть пустым.");
		this.procType=procType;
	}
	public void setFrequency(double procFreq) throws IllegalArgumentException
	{
		if(procFreq==0)
			throw new IllegalArgumentException("Значение частоты недолжно быть равным нулю");
		this.procFreq=procFreq;
	}

	public void setRAM(int ram) throws MyException
	{
		if(ram>32)
			throw new MyException("Значение параметра ram должно быть меньше 32");
		this.ram=ram;
	}


	public void setHDD(int hdd) throws IllegalArgumentException
	{
		if(hdd<=0)
			throw new IllegalArgumentException("Объем жесткого диска должен быть больше нуля.");
		this.hdd=hdd;
	}
	
	public String toString()
	{return "\nCPU: "+procType+"\nProcessor Frequency: " + procFreq+"GHz"+"\nRAM: " +ram+"GB"+"\nHDD: "+hdd+"GB";}

	void show(){System.out.println(this);}

}