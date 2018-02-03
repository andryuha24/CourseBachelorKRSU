class TestComputer
{

  public static void main(String[] argv)
  {  
    Computer pc[]={new Computer("i3-4005U",1.7,4,500),
	              new Computer("i5-5200U",2.7,6,1024),
				  new Computer("i7-4712MQ",3.2,8,1024),
				  new Computer("Quad-Core Intel Core i5",3.1,4,2048),
				  new Computer()};
	for (int i=0;i<pc.length;i++) pc[i].show();
		
	System.out.println("\n1. Search pc by CPU i5-5200U ");
	for(int i=0;i<pc.length;i++) if(pc[i].getProc().equals("i5-5200U")) pc[i].show();
		
	System.out.println("\n2. Search pc by Proc.Frequency: 2.7GHz ");
	for(int i=0;i<pc.length;i++) if(pc[i].getFrequency()==2.7) pc[i].show();
		
	System.out.println("\n3. Search pc by RAM: 8GB ");
	for(int i=0;i<pc.length;i++) if(pc[i].getRAM()==8) pc[i].show();
		
	System.out.println("\n4. Search pc by HDD: 2048GB ");
	for(int i=0;i<pc.length;i++) if(pc[i].getHDD()==2048) pc[i].show();
	
  }
}