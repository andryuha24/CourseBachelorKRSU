import java.applet.*;
import java.awt.event.*;
import java.awt.*;

public class MyApplet extends Applet 
{
   private TextArea txtArea; TextField textT, textA, textN, textB;
   private Button buttonShow;

	public void init()
	{
		txtArea = new TextArea(6,20);
		txtArea.setEditable(false);

		GridBagLayout gridbag = new GridBagLayout();
		GridBagConstraints c = new GridBagConstraints();

		Panel buttonsPanel = new Panel(gridbag);

		setLayout(gridbag);
		c.fill = GridBagConstraints.BOTH;
		c.anchor = GridBagConstraints.PAGE_END;
		c.weightx = 1.0;
		c.weighty = 0.0;                
		c.gridwidth = 0; 
		c.gridheight = 1; 
		c.gridy = 0;    

		c.gridwidth = 1; 
		Label label1 = new Label("Function:  t1=(1/a^3)*(ln(x)+(2*b/x)-b^2/(2*x^2));");
		gridbag.setConstraints(label1, c);

		c.gridy = 6;
		buttonShow=new Button("Calculate");
		Label label6 = new Label();
		buttonShow.setActionCommand("Calculate");
		
		gridbag.setConstraints(label6, c);
		gridbag.setConstraints(buttonShow, c);
		
		c.gridy = 7;
		Label label8 = new Label("   x(i)        f(x)");
		gridbag.setConstraints(label8, c);

		c.gridy = 8;
		Label label7 = new Label();
		gridbag.setConstraints(label7, c);
		

		gridbag.setConstraints(txtArea, c);
		c.gridy = 2;
		Label label2 = new Label("Parametr a: ");
		textA = new TextField(10);
		gridbag.setConstraints(label2, c);
		gridbag.setConstraints(textA, c);

		c.gridy = 3;
		Label label3 = new Label("Parametr b: ");
		textB = new TextField(10);
		gridbag.setConstraints(label3, c);
		gridbag.setConstraints(textB, c);

		c.gridy = 4;
		Label label4 = new Label("Delta t ");
		 textT = new TextField(10);
		gridbag.setConstraints(label4, c);
		gridbag.setConstraints(textT, c);

		c.gridy = 5;
		Label label5 = new Label("Number of point: ");
		textN = new TextField(10);
		gridbag.setConstraints(label5, c);
		gridbag.setConstraints(textN, c);

		buttonsPanel.add(label1);
		buttonsPanel.add(label6);
		buttonsPanel.add(buttonShow);
		buttonsPanel.add(label8);
		buttonsPanel.add(label2);
		buttonsPanel.add(textA);
		buttonsPanel.add(label3);
		buttonsPanel.add(textB);
		buttonsPanel.add(label4);
		buttonsPanel.add(textT);
		buttonsPanel.add(label5);
		buttonsPanel.add(textN);
		//buttonsPanel.add(label9);
		buttonsPanel.add(txtArea);

		add(buttonsPanel);
	
		

		Buttons();
	}


	private void Buttons()
	{
		buttonShow.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) 
			{
				txtArea.setText("");
				try
				{
					double a = Double.parseDouble(textA.getText());
					double b = Double.parseDouble(textB.getText());
					int n = Integer.parseInt(textN.getText());
					double h = Double.parseDouble(textT.getText());
					t1(a, b, n, h);
				}
				catch(IllegalArgumentException exp){txtArea.setText(exp.toString());}
			
			}	
		});
	}


	public void t1(double a, double b, int N, double h)
	{
		
		double t1=0, i=0, x=0;
		while(i<N)
		{
			x+=h;
			t1=(1/Math.pow(a,3))*(Math.log(x)+(2*b/x)-Math.pow(b,2)/(2*Math.pow(x,2)));
			txtArea.append(String.format("%.2f", x)+"\t"+String.format("%.3f", t1)+"\n");
			i++;
		}
		
	} 
}