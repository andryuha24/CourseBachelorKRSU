import MyLib.*;
class Residential extends Building{
	private int numRooms;
	private String typeOwnership;
	private String quality;


	public Residential()
	{
		super();
		numRooms = 2;
		typeOwnership = "Private";
		quality = BuildingQuality.buildQulity[0];

	}
	public Residential(int newNumFloors, String newOwner, String newAddress,String newBuildYear, int newRooms,String newOwnership, String newQuality)
	{
		super(newNumFloors,newOwner,newAddress,newBuildYear);
		numRooms = newRooms;
		typeOwnership = newOwnership;
		quality = newQuality; 
	}
	public int getRooms(){return numRooms;}
	public String getOwnerShip(){return typeOwnership;}
	public String getQuality(){return quality;}

	public void setRooms(int newNumRooms){numRooms=newNumRooms;}
	public void setOwnerShip(String newTOwnership){ typeOwnership=newTOwnership;}
	public void setQuality(String newQuality){quality=newQuality;}

	public void show(){System.out.println(this);}

	public String toString()
	{
		return("Building:  " + "\t" + numFloors + "\t" +owner+"\t"+address+"\t"+buildYear+"\t"+numRooms+"\t"+quality);//overriding
	}

	public void search(String finding, int kateg)
	{
		switch(kateg)
		{
			case 0:
				if(getFloors()==Integer.parseInt(finding))System.out.println(this);
			case 1:
				if(getAddress().equals(finding))System.out.println(this);
			case 2:
				if(getBuildYear().equals(finding))System.out.println(this);
			case 3:
				if(this.getQuality().equals(finding))System.out.println(this);
		}
	}
}