import java.util.*;

public class MyOuter
{
	private String month;

	public MyOuter()
	{
		month = MONTH.month[5];
	}
	public MyOuter(String month)
	{
		this.month=month;
	}
	public String getMonth(){return month;}
	public void setMonth(String month){this.month=month;}
	static class MyInner 
	{
        public MyInner(){};
        public void getOuterMonth(MyOuter obj) 
        {
              System.out.println(obj.month);  
        }
    }
    public static MyInner createInner()
    {
    	return new MyInner();
    }


}