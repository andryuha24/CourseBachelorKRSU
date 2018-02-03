import java.awt.*;
import javax.swing.*;
class ShowColors extends JFrame
{
    ShowColors()
    {
      super("Using Color and Font");
      setSize(550,180);
      show();
    }
    public void paint(Graphics g)
    {
       super.paint(g);
      
      g.setColor(Color.red);
      g.fillRect(20,50,100,20);
      g.drawString("Tekuschee znachenie RGB: "+g.getColor()+" ",140,65);
      g.setColor(Color.green);
      g.fillRect(20,80,100,20);
      g.drawString("Tekuschee znachenie RGB: "+g.getColor()+" ",140,95);
      g.setColor(Color.blue);
      g.fillRect(20,110,100,20);
      g.drawString("Tekuschee znachenie RGB: "+g.getColor()+" ",140,125);
      g.setColor(new Color(255,0,255));
      g.fillRect(20,140,100,20);
      g.drawString("Tekuschee znachenie RGB: "+g.getColor()+" ",140,155);
      //Дописать
    }
    public static void main(String argv[])
    {
      ShowColors application=new ShowColors();
      application.setDefaultCloseOperation
      (JFrame.EXIT_ON_CLOSE);
    }
}
