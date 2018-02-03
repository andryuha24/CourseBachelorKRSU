import MyLib.*;
class NonResidental extends Building{
	
	private String purpose;

	public NonResidental()
	{
		super();
		purpose = "Health Service";
	}
	public NonResidental(int newNumFloors, String newOwner, String newAddress,String newBuildYear, String newPurpose)
	{
		super(newNumFloors,newOwner,newAddress,newBuildYear);
		purpose=newPurpose;
	}
	public String getPurpose(){return purpose;}
	public void setPurpose(String newPurpose){ purpose=newPurpose;}

	public void show(){System.out.println(this);}

	public String toString()
	{
		return("Building:  "+"\t"+purpose + "\t" +numFloors + "\t" +owner+"\t"+address+"\t"+buildYear) ;//overriding
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
				if(this.getPurpose().equals(finding))System.out.println(this);
		}
	}
}