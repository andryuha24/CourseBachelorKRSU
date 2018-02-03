
import MyLib.*;
class TestBuilding 
{
	public static void main(String[] args) 
	{

//upcasting
		Building bld[]={new Residential(4,"SMN","Sankt-Peterburg, Nevsky avenue 12","02.05.2005",12,"state",BuildingQuality.buildQulity[1]),
					new Residential(),
					new Residential(3,"Aleksandrov V.K.","Bishkek, Manasa street 20","08.06.1995",6,"private",BuildingQuality.buildQulity[2]),
					new NonResidental(5,"Microsoft Corporation","Redmond, WA 98052-7329","02.05.2005","administrative"), 
					new NonResidental(1,"Jean Marais","Paris, 41 Avenue Montaigne","10.08.1991","food service"),
					new NonResidental(4,"State","Cambridge, MA 02138, USA","08.09.1636","educational"),
				};
		
		//polimorfizm
		for(int i=0;i<bld.length;i++)bld[i].show(); 
		
		//overloading  downcasting		
		for(int i=0;i<bld.length;i++) 
			{
				if(bld[i] instanceof Residential) ((Residential)bld[i]).search(BuildingQuality.buildQulity[2],3); 

			}
			
		//downcasting
		for (int i=0;i<bld.length ;i++ ) {
			if(bld[i] instanceof Residential) System.out.println(((Residential)bld[i]).getOwnerShip());
			}
	}
}
