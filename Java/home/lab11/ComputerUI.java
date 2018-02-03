import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.io.*;
import java.lang.reflect.*;
class ComputerUI extends JFrame
{
  private JButton buttonShow;
  private JTextField showClass;
  private JList bd;
  private GridBagLayout gridbag ;
  private GridBagConstraints c;
  private DefaultListModel model;
  ComputerUI()
  {
	//Frame f = new Frame("My Search_Engine");
	super("My Search_Engine");
	setSize(300, 220);
	addNotify();
	addWindowListener(
			new WindowAdapter() {
				public void windowClosing(WindowEvent w)
				{System.exit(0);}
			});    
	MyGUI();
  	setVisible(true);
  	setResizable(false);
  }

  private void MyGUI()
  {
	gridbag = new GridBagLayout();
	c = new GridBagConstraints();
	model = new DefaultListModel();
	JPanel buttonPanel = new JPanel();
	
	bd = new JList(model);
	JScrollPane scrollPane = new JScrollPane(bd);
	scrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);

	
	JPanel buttonsPanel = new JPanel(gridbag);

  	setLayout(gridbag);
	c.fill = GridBagConstraints.BOTH;
	c.anchor = GridBagConstraints.PAGE_END;
	c.weightx = 1.0;
	c.weighty = 0.0;                
	c.gridwidth = 0; 
	c.gridheight = 1; 
	c.gridy = 1;    
	gridbag.setConstraints(scrollPane, c);
	c.gridwidth = 1; 
	
	c.gridy = 2;
	buttonShow=new JButton("Show");
	buttonShow.setActionCommand("Show");
	gridbag.setConstraints(buttonShow, c);


	c.gridy = 0;
	showClass = new JTextField(10);
	gridbag.setConstraints(showClass, c);

	buttonsPanel.add(scrollPane);
	buttonsPanel.add(buttonShow);
	buttonsPanel.add(showClass);


	add(buttonsPanel);
  }

  private void Buttons()
  {

	
	
	  buttonShow.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) 
      {
       	model.removeAllElements();
		Class sclass=new Computer().getClass();
		showClass.setText(sclass.toString());
		Constructor[] constructors= sclass.getConstructors();
		for(Constructor constructor:constructors)
		{
			model.addElement(constructor.getName());
		}
		Method[] methods = sclass.getMethods();
		for(Method method: methods)
		{
			model.addElement(method.getName());
		}
	  }	
    });
	 

  }
 
  public static void main(String[] argv)
  {  

    ComputerUI application = new  ComputerUI();
    application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    application.Buttons();
  }
  
}