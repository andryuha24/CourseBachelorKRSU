import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class TextFieldTest extends JFrame
{
    private JTextField textField1, textField2, textField3;
    private JPasswordField passwordField;
    TextFieldTest()
    {
      super("Test of JtextField&JPasswordField");
      Container container=getContentPane();
      container.setLayout(new FlowLayout());
      textField1 = new JTextField(10);
      container.add(textField1);
      textField2 = new JTextField("Input text");
      container.add(textField2);
      textField3 = new JTextField("Uneditable text field",20);
      textField3.setEditable(false);
      container.add(textField3);
      passwordField = new JPasswordField("Hello world!");
      container.add(passwordField);
      TextFieldHandler handler = new TextFieldHandler();
      textField1.addActionListener(handler);
      textField2.addActionListener(handler);
      textField3.addActionListener(handler);
      passwordField.addActionListener(handler);
      setSize(350,120);
      setVisible(true);
    }

    public static void main(String argv[])
    {
      TextFieldTest application=new TextFieldTest();
      application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    private class TextFieldHandler implements ActionListener
    {
      public void actionPerformed(ActionEvent event)
      {
        String string="";
        if(event.getSource()==textField1) string="textField1:"+event.getActionCommand();
        if(event.getSource()==textField2) string="textField2:"+event.getActionCommand();
        if(event.getSource()==textField3) string="textField3:"+event.getActionCommand();
        if(event.getSource()==passwordField) 
        { 
          JPasswordField pwd=(JPasswordField)event.getSource();
          string="paswordField:"+ new String(passwordField.getPassword());
        } 
        JOptionPane.showMessageDialog(null,string);
      }
    }

}

