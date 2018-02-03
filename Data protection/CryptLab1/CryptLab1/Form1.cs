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

namespace CryptLab1
{
    public partial class Form1 : Form
    {
        Manager scrypt=new Manager();
        public Form1()
        {
            InitializeComponent();
            CreateTables();
            scrypt.FillTemplate();
            scrypt.FillDataGrid(dataGridView1, scrypt.GetNumberTemplate, scrypt.Template);
        }
        private void CreateTables()
        {
            dataGridView2.Columns[0].Width = 25;
            dataGridView2.Columns[1].Width = 42;
            dataGridView2.Columns[2].Width = 50;

            dataGridView3.Columns[0].Width = 25;
            dataGridView3.Columns[1].Width = 42;
            dataGridView3.Columns[2].Width = 50;
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
                string input = inputBox.Text;
                input = input.ToLower();
                string output = " ";

                if (radioButton2.Checked == true)
                {

                    int key = Convert.ToInt32(keyBox.Text);
                    scrypt.Caezar(key, input);

                    output = scrypt.code;
                }
                else if (radioButton1.Checked == true)
                {
                    
                    scrypt.MonoAlphabetEncode(input);

                    output = scrypt.code;
                }
                else if (radioButton3.Checked == true)
                {
                    string key = keyBox.Text;
                    if (key != "")
                    {
                        scrypt.Tritemius(key, input);

                        output = scrypt.code;
                    }
                    else
                        MessageBox.Show("Введите ключ!");
                }

                outputBox.Text = output;
                if (inputBox.Text != "")
                {
                 
                    scrypt.FillCount(input);
                    scrypt.FillDataGrid(dataGridView2, scrypt.GetNumberOrigin, input);
                    scrypt.FillDataGrid(dataGridView3, scrypt.GetNumberCode, output);
                }
                else
                    MessageBox.Show("Введите данные!");
            }
          catch { MessageBox.Show("Неверно введены данные!"); }
           
        }

        private void encode_Click(object sender, EventArgs e)
        {
            try
            {
                string input = outputBox.Text.ToLower();
                string output = "";
                if (radioButton1.Checked == true)
                {
                     output = scrypt.MonoAlphabetDecode(input);
                }
                else if (radioButton2.Checked == true)
                {
                    int key = Convert.ToInt32(keyBox.Text);
                    output = scrypt.DeCaezar(key, input);
                }
                else if (radioButton3.Checked == true)
                {
                    if (keyBox.Text != ""&&outputBox.Text!="") output = scrypt.DeTritemius(keyBox.Text);
                    else MessageBox.Show("Введит данные!");
                }
                outputBox.Text = output;
            }
            catch { MessageBox.Show("Неверно введены данные!"); }
        }

        private void FindKey_Click(object sender, EventArgs e)
        {
            string output = outputBox.Text;
            scrypt.FindKeyCeazer(output);

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

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            keyBox.Enabled = true;
            FindKey.Enabled = true;
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            keyBox.Enabled = false;
            FindKey.Enabled = false;
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            keyBox.Enabled = true;
            FindKey.Enabled = false;
        }
    }
}
