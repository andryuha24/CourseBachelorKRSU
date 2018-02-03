package MyLib;

public class Building 
{
	protected int numFloors;
	protected String owner;
	protected String address;
	protected String buildYear;

	public Building()
	{
		numFloors=5;
		owner="Karlov A.K.";
		address="Moscow, Graphskii alley 14";
		buildYear="12.02.1995";
	}

	public Building(int newNumFloors, String newOwner, String newAddress,String newBuildYear)
	{
		numFloors=newNumFloors;
		owner=newOwner;
		address=newAddress;	
		buildYear=newBuildYear;
	}

	public int getFloors(){return numFloors;}
	public String getOwner(){return owner;}
	public String getAddress(){return address;}
	public String getBuildYear(){return buildYear;}

	public void setFloors(int newNumFloors){numFloors=newNumFloors;}
	public void setOwner(String newOwner){owner=newOwner;}
	public void setAddress(String newAddress){address=newAddress;}
	public void setBuildYear(String newBuildYear){buildYear=newBuildYear;}

	
	
	public String toString()
	{
		return("Building:  " + "\t" + numFloors + "\t" +owner+"\t"+address+"\t"+buildYear) ;
	}
	public void show(){System.out.println(this);}

	public void search(){}
}