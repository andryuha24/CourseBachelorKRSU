import java.awt.*;
import javax.swing.*;
class Polygons extends JFrame
{
    Polygons()
    {
      super("Polygons");
      setSize(500,500);
      show();
    }
    public void paint(Graphics g)
    {
       super.paint(g);
       int xPoly[] = {150,250,325,375,450,275,100};
       int yPoly[] = {150,100,125,225,250,375,300};
       g.drawPolygon(xPoly,yPoly,7);
       int xPoly2[] = {100,150,175};
       int yPoly2[] = {50,120,70};
       g.drawPolygon(xPoly2,yPoly2,3);
       int xPoly3[] = {62,62,10};
       int yPoly3[] = {500,120,70};
       int xPol4[] = {160,220,325,365,370};
       int yPol4[] = {190,130,160,235,300};
       g.fillPolygon(xPoly3,yPoly3,3);
       g.setColor(Color.red);
       g.fillPolygon(xPol4,yPol4,5);

    }
    public static void main(String argv[])
    {
      Polygons application=new Polygons();
      application.setDefaultCloseOperation
      (JFrame.EXIT_ON_CLOSE);
    }
}
