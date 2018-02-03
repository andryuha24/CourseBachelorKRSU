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


namespace CryptLab1
{
    public partial class Form1 : Form
    {
        public Manager scrypt=new Manager();
        int numBlock = 3;
        public Form1()
        {
            InitializeComponent();
            CreateTables();
            scrypt.FillTemplate();
            //scrypt.FillDataGrid(dataGridView1, scrypt.GetNumberTemplate, scrypt.Template);
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
            dialog.Filter = "txt files (*.txt)|*.txt|rtf files(*.*)|*.rtf";
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
            //try
            //{
                string input = inputBox.Text;
                input = input.ToLower();
            //input = input.Replace(Environment.NewLine, " ");
               input = Regex.Replace(input, @"[^a-z]", "");
             // input = input.Replace("\n", "");
                string key = keyBox.Text.ToLower();
                if (Math.Sqrt(key.Length) % 1 == 0 && key.Length < 17) numBlock = Convert.ToInt32(Math.Sqrt(key.Length));
                else
                {
                    MessageBox.Show("Введите другой ключ!\nДлина ключа должна быть квадратом целого числа.\nДлина ключа: 1<key< 17");
                    return;
                }

                    if (inputBox.Text != "")
                    {
                        if (input.Length % 2 != 0) input += 'x';
                        var result = Manager.HillEncode(input, key, numBlock, label2);
                        /* if (result == null) { return; }
                         else
                         {*/
                        DataTable dt = new DataTable();
                        for (int i = 0; i < numBlock; i++)
                        {
                            dt.Columns.Add(i.ToString(), typeof(string));
                        }
                        for (int i = 0; i < numBlock; i++)
                        {
                            DataRow dr = dt.NewRow();
                            for (int j = 0; j < numBlock; j++)
                            {
                                dr[j.ToString()] = Manager.keyMatrix[i, j];
                            }
                            dt.Rows.Add(dr);
                        }
                        dataGridView4.DataSource = dt;
                        dataGridView4.Update();
                        outputBox.Text = result;
                        scrypt.FillCount(input);
                        scrypt.FillDataGrid(dataGridView2, scrypt.GetNumberOrigin, input);
                        scrypt.FillDataGrid(dataGridView3, scrypt.GetNumberCode, outputBox.Text);
                    }
                    else
                        MessageBox.Show("Введите исходный текст!");
                //}
             
            //}
            //catch(Exception ex) { MessageBox.Show("Неверно введены данные!\nИли полностью не введены все данные." + ex.Message); }

        }

        public string encodeFunction(string NewOutput)
        {
            string output = NewOutput;
            string result;
            output = output.ToLower();
            string key = keyBox.Text.ToLower();
            if (Math.Sqrt(key.Length) % 1 == 0 && key.Length < 17) numBlock = Convert.ToInt32(Math.Sqrt(key.Length));
            else
            {
                MessageBox.Show("Введите другой ключ!\nДлина ключа должна быть квадратом целого числа.\nДлина ключа: 1<key< 17");
                return null;
            }

            if (output == "") { throw new ArgumentNullException("outputBox", "Введите текст для расшифрования!"); }// { return; }
            else
            {
                result = scrypt.HillDecode(output, key, numBlock, label2);
                DataTable dt = new DataTable();
                for (int i = 0; i < numBlock; i++)
                {
                    dt.Columns.Add(i.ToString(), typeof(string));
                }
                for (int i = 0; i < numBlock; i++)
                {
                    DataRow dr = dt.NewRow();
                    for (int j = 0; j < numBlock; j++)
                    {
                        dr[j.ToString()] = Manager.invertKeyMatrix[i, j];
                    }
                    dt.Rows.Add(dr);
                }
                dataGridView4.DataSource = dt;
                dataGridView4.Update();
                //result;
            }
            return result;
        }
        private void encode_Click(object sender, EventArgs e)
        {
            try
            {
                inputBox.Text = encodeFunction(outputBox.Text);
               // else MessageBox.Show("Введите текст для расшифрования!");
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

        private void hack_Click(object sender, EventArgs e)
        {
            try
            {
                string output = hackOutputBox.Text;
                string input = hackInputBox.Text;
                int sizeBlock = Convert.ToInt32(textBox1.Text);
                output = output.ToLower();
                input = input.ToLower();
                scrypt.HackHill(input, output, sizeBlock, label2);
            }
            catch
            {
                MessageBox.Show("Неверно введены данные!\nИли полностью не введены все данные.");
            }

        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar);
            validateInputKey(e.KeyChar);


        }
       public void validateInputKey(char c)
        {
            if (!char.IsDigit(c) && !char.IsControl(c))
            {
                throw new ArgumentException("e.KeyChar", "Введите только числовое значение!");
                // MessageBox.Show("Введите только числовое значение!");
            }
        }
    }
}
