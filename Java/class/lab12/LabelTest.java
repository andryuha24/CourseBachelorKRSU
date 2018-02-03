import java.awt.*;
import javax.swing.*;
class LabelTest extends JFrame
{
    private JLabel label1, label2,label3;
    LabelTest()
    {
      super("JLabel demonstation");
      Container container=getContentPane();
      container.setLayout(new FlowLayout());
      Icon icon = new ImageIcon("1.png");
      label1 = new JLabel("Label with text and image", icon, JLabel.RIGHT);
      label2 = new JLabel("Label with text and image");
      label3 = new JLabel("Label with text and image", icon, JLabel.CENTER);
      label3.setVerticalTextPosition(JLabel.BOTTOM);
      label3.setHorizontalTextPosition(JLabel.CENTER);
      container.add(label2);
      container.add(label1);
      container.add(label3);
      setSize(275,170);
      setVisible(true);
 
    }
    public static void main(String argv[])
    {
      LabelTest application=new LabelTest();
      application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
