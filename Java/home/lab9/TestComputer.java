import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
class TestComputer extends JFrame
{
  private JButton buttonAdd, buttonDel, buttonSearch, buttonShow;
  private JTextField textCPU, textFreq, textRAM, textHDD, textSearch;
  private JRadioButton  chCPU, chFreq, chRAM, chHDD;
  private ArrayList<Computer> list;
  private JList bd;
  private GridBagLayout gridbag ;
  private GridBagConstraints c;
  private DefaultListModel model;
  boolean isItTrue = false;
  TestComputer()
  {
	//Frame f = new Frame("My Search_Engine");
	super("My Search_Engine");
	setSize(550, 300);
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
	list = new ArrayList<Computer>(); 
 	list.add(new Computer("i3-4005U",1.7,4,500));
	list.add(new Computer("i5-5200U",2.7,6,1024));
	list.add(new Computer("i5-5200U",2.7,6,1024));
	list.add(new Computer());
	bd = new JList(model);
	JScrollPane scrollPane = new JScrollPane(bd);
	scrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);

	for(Computer pc:list)
	{
		model.addElement(pc.toString());
	}
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
	
	c.gridy = 4;
	buttonShow=new JButton("Show");
	buttonShow.setActionCommand("Show");
	gridbag.setConstraints(buttonShow, c);

	buttonDel=new JButton("Delete");
	buttonDel.setActionCommand("delete");
	gridbag.setConstraints(buttonDel, c);
	
	buttonsPanel.add(scrollPane);
	buttonsPanel.add(buttonShow);
	buttonsPanel.add(buttonDel);

	ButtonGroup bg=new ButtonGroup();  
 
	chCPU= new JRadioButton ("CPU");
	chFreq= new JRadioButton ("Frequency");
	chRAM= new JRadioButton ("RAM");
	chHDD= new JRadioButton ("HDD");
	bg.add(chCPU);	bg.add(chFreq);	bg.add(chRAM);	bg.add(chHDD);
	JPanel searchPanel = new JPanel(gridbag);
    c.anchor = GridBagConstraints.NORTH;
    c.weighty = 1;
	c.gridy = 1;
	gridbag.setConstraints(chCPU, c);
	gridbag.setConstraints(chFreq, c);
	gridbag.setConstraints(chRAM, c);
	gridbag.setConstraints(chHDD, c);
	
	c.gridy = 3;
	textCPU = new JTextField(10);
	textFreq = new JTextField(10);
	textRAM = new JTextField(10);
	textHDD = new JTextField(10);

	buttonAdd=new JButton("Add");
	buttonAdd.setActionCommand("add");
	gridbag.setConstraints(buttonAdd, c);

	gridbag.setConstraints(textCPU, c);
	gridbag.setConstraints(textFreq, c);
	gridbag.setConstraints(textRAM, c);
	gridbag.setConstraints(textHDD, c);

	buttonsPanel.add(buttonAdd);
	buttonsPanel.add(textCPU);
	buttonsPanel.add(textFreq);
	buttonsPanel.add(textRAM);
	buttonsPanel.add(textHDD);

	buttonsPanel.add(chCPU);
	buttonsPanel.add(chFreq);
	buttonsPanel.add(chRAM);
	buttonsPanel.add(chHDD);

	c.gridy = 2;
	buttonSearch=new JButton("Search");
	textSearch = new JTextField();
	textSearch.setMaximumSize( textSearch.getPreferredSize() );
	buttonSearch.setActionCommand("search");
	gridbag.setConstraints(buttonSearch, c);
	

	buttonsPanel.add(buttonSearch);
	c.gridwidth = GridBagConstraints.REMAINDER;

	gridbag.setConstraints(textSearch, c);
	buttonsPanel.add(textSearch);


	add(buttonsPanel);
  }

  private void Buttons()
  {

	 buttonDel.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        if (model.getSize() > 0)
        {
          System.out.println(bd.getSelectedIndex());
          list.remove(bd.getSelectedIndex());
          model.removeElementAt(bd.getSelectedIndex());
          buttonShow.doClick();
        }

      }
    });
	 buttonAdd.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        if(textCPU.getText().equals("")&&textFreq.getText().equals("")&&textRAM.getText().equals("")&&textHDD.getText().equals(""))
		{
			model.removeAllElements();
			list.add(new Computer());
			buttonShow.doClick();
		}
		else  if(!textCPU.getText().equals("")&&!textFreq.getText().equals("")&&!textRAM.getText().equals("")&&!textHDD.getText().equals(""))
		{
			String cpu = textCPU.getText();
			double fq = Double.parseDouble(textFreq.getText());
			int ram = Integer.parseInt(textRAM.getText());
			int hdd = Integer.parseInt(textHDD.getText());
			list.add(new Computer(cpu,fq,ram,hdd));
			buttonShow.doClick();
		}
		else
			model.addElement("Input more data!");
      }
    });
	  buttonShow.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) 
      {
       	model.removeAllElements();
       	for(Computer pc:list)
		{
			model.addElement(pc.toString());
		}
	  }	
    });
	  buttonSearch.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) 
      {
       	if (chCPU.isSelected())
        {
			model.removeAllElements();
			for(Computer pc:list)
			{
				if(textSearch.getText().equals(pc.getProc()))
				{
					
					model.addElement(pc.toString());
				}
			}
		 }
		 else if (chFreq.isSelected()) 
		 {
		 	model.removeAllElements();
			for(Computer pc:list)
			{
				if(Double.parseDouble(textSearch.getText())==pc.getFrequency())
				{
					
					model.addElement(pc.toString());
				}
			}
		 }
		 else if(chRAM.isSelected())
		 {
		 	model.removeAllElements();
			for(Computer pc:list)
			{
				if(Integer.parseInt(textSearch.getText())==pc.getRAM())
				{
					
					model.addElement(pc.toString());
				}
			}
		 }
		 else if(chHDD.isSelected())
		 {
		 	model.removeAllElements();
			for(Computer pc:list)
			{
				if(Integer.parseInt(textSearch.getText())==pc.getHDD())
				{
					
					model.addElement(pc.toString());
				}
			}
		 }
	  }	
    });

  }
 
  public static void main(String[] argv)
  {  

    TestComputer application = new  TestComputer();
    application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    application.Buttons();
  }
  
}