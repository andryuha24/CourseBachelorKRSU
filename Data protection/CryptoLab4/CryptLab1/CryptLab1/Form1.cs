using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;
using System.IO;
using System.Windows.Controls.DataVisualization.Charting;
using System.Numerics;


namespace CryptLab1
{
    public partial class Form1 : Form
    {
        Manager scrypt=new Manager();
        int numBlock = 3;
        public Form1()
        {
            InitializeComponent();
            //scrypt.FillDataGrid(dataGridView1, scrypt.GetNumberTemplate, scrypt.Template);
        }

        private void open_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
            dialog.FilterIndex = 0;
            dialog.Title = "Файл с сообщением.";
            string name = dialog.FileName;
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                 inputBox.Text = File.ReadAllText(dialog.FileName);
                
            }

        }
 
        private void decode_Click(object sender, EventArgs e)
        {
            try
            {
                outputBox.Text = "";
                scrypt.EncodeBackPack(Convert.ToInt32(keyBox.Text), inputBox.Text);
                mText.Text = scrypt.mNumber.ToString();
                xText.Text = scrypt.xNumber.ToString();
                yText.Text = scrypt.yNumber.ToString();
                List<BigInteger> EChar = scrypt.encodedChars;
                foreach(BigInteger sum in EChar)
                {
                    outputBox.Text += sum + " ";
                }
            }
            catch { MessageBox.Show("Неверно введены данные!\nИли полностью не введены все данные."); }

        }

        private void encode_Click(object sender, EventArgs e)
        {
            try
            {
                string[] stringArray = outputBox.Text.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                BigInteger[] encodeCH = stringArray.Select(x => BigInteger.Parse(x)).ToArray();
                scrypt.DecodeBackPack(encodeCH);
                decodeOutputBox.Text = " ";
                foreach (int chId in scrypt.decodedChars)
                {
                    decodeOutputBox.Text += ((char)chId).ToString();
                }

            }
            catch { MessageBox.Show("Неверно введены данные!\nИли полностью не введены все данные."); }
        }

       

        private void save_Click(object sender, EventArgs e)
        {
            if (outputBox.Text == "")
            {
                MessageBox.Show("Нет текста для записи в файл.");
                return;
            }
            SaveFileDialog dialog = new SaveFileDialog();
            dialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
            dialog.ShowDialog();
            string name = dialog.FileName;
            if (name != "")
            {
                File.WriteAllText(name, outputBox.Text);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
           
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar);
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if(checkBox1.Checked==true)
            {
                keyBox.Enabled = false;
            }
            else if(checkBox1.Checked==false)
            {
                keyBox.Enabled = true;
            }
        }
    }
}
