import java.awt.*;
import javax.swing.*;
class LineRectOvals extends JFrame
{
    LineRectOvals()
    {
      super("Geometric figures");
      setSize(350,350);
      show();
    }
    public void paint(Graphics g)
    {
       super.paint(g);
      g.setColor(Color.red);
      g.drawLine(20,50,150,50);
      g.drawRoundRect(20, 140, 130, 50, 50, 50);
      g.fillRoundRect(200, 140, 130, 50, 50, 50);
      g.setColor(Color.blue);
      g.drawLine(200,50,330,50);
      g.fillRect(200,70,130,50);
      g.drawRect(20,70,130,50);
      g.setColor(Color.yellow);
      g.drawRect(20,200,130,50);
      g.drawRect(200,200,130,50);
      g.setColor(new Color(190,199,31));
      g.fillRect(200,200,130,50);
      g.setColor(new Color(255,0,255));
      g.drawOval(20,270,130,50);
      g.fillOval(200,270,130,50);

    }
    public static void main(String argv[])
    {
      LineRectOvals application=new LineRectOvals();
      application.setDefaultCloseOperation
      (JFrame.EXIT_ON_CLOSE);
    }
}
