import java.awt.*;
import javax.swing.*;
import java.awt.geom.*;
import java.awt.image.BufferedImage;
class Shapes extends JFrame
{
    Shapes()
    {
      super("Polygons");
      setSize(500,200);
      show();
    }
    public void paint(Graphics g)
    {
      super.paint(g);
      Graphics2D ga = (Graphics2D) g;
      ga.setPaint(new GradientPaint(5,30,Color.blue,35,100,Color.yellow,true));
      ga.fill(new Ellipse2D.Double(10,60,65,100));
      BasicStroke с = new BasicStroke(3);
      ga.setStroke(new BasicStroke(10));
      ga.setPaint(Color.red);
      ga.drawRect(100,70,50,100);
      //#3
      BufferedImage bufferedImage = new BufferedImage(8, 8, BufferedImage.TYPE_INT_RGB);
      Graphics2D g2 = bufferedImage.createGraphics();
      g2.setColor(Color.yellow);
      g2.drawRect(0, 0, 7, 7);
      g2.setColor(Color.blue);
      g2.fillRect(1, 1, 3, 3);
      g2.setColor(Color.red);
      g2.fillRect(4, 4, 3, 3);
      Rectangle2D rect = new Rectangle2D.Double(5, 5, 8, 8);
      ga.setPaint(new TexturePaint(bufferedImage, rect));
      g.fillRoundRect(180, 70, 100, 100, 50, 50);
      //#4
      ga.setStroke(new BasicStroke(4));
      ga.setPaint(Color.white);
      ga.draw(new Arc2D.Double(300, 70, 100, 100, 0, 270, Arc2D.PIE));
      ga.setPaint(Color.green);
      g.drawLine(460, 50, 400, 150);
      ga.setStroke(new BasicStroke(4.0f,                    
                           BasicStroke.CAP_SQUARE,    
                           BasicStroke.JOIN_MITER,    
                           10.0f,                     
                           new float[] {20.0f,20.0f}, 
                           0.0f));
      ga.setPaint(Color.yellow);
      g.drawLine(400, 50, 480, 150);


    }
    public static void main(String argv[])
    {
      Shapes application=new Shapes();
      application.setDefaultCloseOperation
      (JFrame.EXIT_ON_CLOSE);
    }
}
