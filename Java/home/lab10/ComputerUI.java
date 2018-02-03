import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.io.*;
class ComputerUI extends JFrame
{
  private JButton buttonShow;
  private JList bd;
  private GridBagLayout gridbag ;
  private GridBagConstraints c;
  private DefaultListModel model;
  ComputerUI()
  {
	//Frame f = new Frame("My Search_Engine");
	super("My Search_Engine");
	setSize(300, 200);
	addNotify();
	addWindowListener(
			new WindowAdapter() {
				public void windowClosing(WindowEvent w)
				{System.exit(0);}
			});    
	MyGUI();
  	setVisible(true);
  	setResizable(true);
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
	gridbag.setConstraints(scrollPane, c);
	c.gridwidth = 1; 
	
	c.gridy = 1;
	buttonShow=new JButton("Show");
	buttonShow.setActionCommand("Show");
	gridbag.setConstraints(buttonShow, c);

	buttonsPanel.add(scrollPane);
	buttonsPanel.add(buttonShow);

	add(buttonsPanel);
  }

  private void Buttons()
  {

	
	
	  buttonShow.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) 
      {
       	model.removeAllElements();
		try 
		{ 
		 JFileChooser fileopen = new JFileChooser();             
            int ret = fileopen.showDialog(null, "Open");                
            if (ret == JFileChooser.APPROVE_OPTION) {
                File file = fileopen.getSelectedFile();

				FileInputStream fileIn = new FileInputStream(file);
				ObjectInputStream in = new ObjectInputStream(fileIn);
				ArrayList<Computer> Computers = (ArrayList<Computer>) in.readObject();
				in.close();
				fileIn.close();
				//System.out.println("Deserialized object:");
				for(Computer pcs : Computers)
				{
					model.addElement(pcs.getProc().toString());
				}
				//System.out.println(Computer);
            }
		
		} 
		catch (Exception exp) {System.out.println("Exception in deserialization: " + exp); }   
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