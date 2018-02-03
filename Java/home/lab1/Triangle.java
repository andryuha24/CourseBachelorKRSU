import java.util.*;
import java.math.*;
class Triangle
{
 private double a,b;
 Triangle()
 {
  a=4;
  b=7;
 }
 Triangle(double a, double b)
 { 
  this.a=a;
  this.b=b;
 }
  double getHypotenyze(){ return Math.sqrt(a*a+b*b);}
  double getAngleAlfa(){ return Math.toDegrees(Math.atan(a/b));}     //grad
  double getAngeBetta(){ return 90-getAngleAlfa();}          //
  double getSquare(){ return (0.5*a*b);}
  double getPerimeter(){ return a+b+getHypotenyze();}
  
 public static void main (String[] arg)
 {
  
  Triangle t1=new Triangle(Double.parseDouble(arg[0]), Double.parseDouble(arg[1]));
  System.out.printf("Hypotenyze=%6.2f\n",t1.getHypotenyze());
  System.out.printf("Square=%f\n",t1.getSquare());
  System.out.printf("Perimeter=%f\n",t1.getPerimeter());
  System.out.printf("AnglesAlfa=%f\n", t1.getAngleAlfa());
  System.out.printf("AnglesBetta=%f\n",t1.getAngeBetta());
 }
}