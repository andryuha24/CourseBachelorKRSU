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
        Manager scrypt=new Manager();
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
                string key = keyBox.Text.ToLower();


                if (key != "")
                {
                    scrypt.Playfair(input, key);
                    output = scrypt.code;
                }
                else
                    MessageBox.Show("Введите ключ!");
                }
                else if (radioButton1.Checked == true)
                {
                    string key = keyBox.Text.ToLower();

                    if (key != "")
                    {
                        scrypt.Vigineer(input, key);
                        output = scrypt.code;
                    }
                    else
                        MessageBox.Show("Введите ключ!");
                    }
                    else if (radioButton3.Checked == true)
                    {
                        string key = keyBox.Text.ToLower();
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
            //try
            //{
                string input = outputBox.Text.ToLower();
                //input = Regex.Replace(input, @"[^a-z]", "");
                string output = "";
                if (radioButton1.Checked == true)
                {
                     string key = keyBox.Text.ToLower();
                     if (key != "" && outputBox.Text != "")
                        output = scrypt.VigineerDecode(input, key);
                     else MessageBox.Show("Введит данные!");
                }
                else if (radioButton3.Checked == true)
                {
                    string key = keyBox.Text.ToLower();
                    if (key != "" && outputBox.Text!="") output = scrypt.DeTritemius(key);
                    else MessageBox.Show("Введит данные!");
                }
                outputBox.Text = output;
            //}
          //  catch { MessageBox.Show("Неверно введены данные!"); }
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

        private void drawGraph_Click(object sender, EventArgs e)
        {
            if (outputBox.Text != "")
            {
                if (radioButton1.Checked == true) LoadChartData(scrypt.getDecode, 0);
                else if (radioButton2.Checked == true) LoadChartData(scrypt.getDecode, 1);
                else if (radioButton3.Checked == true) LoadChartData(scrypt.getDecode, 2);

            }
            else { MessageBox.Show("Введите данные!"); }
              
        }



        private void LoadChartData(Dictionary<string, double> d, int index)
        {
            try
            {
                if (chart1.Series[index] != null)
                {
                    chart1.Series[index].Points.Clear();
                    //MessageBox.Show("удален!");
                }
                List<double> list = new List<double>();
                d = (from entry in d orderby entry.Value descending select entry).ToDictionary(pair => pair.Key, pair => pair.Value);
                int i = 0;
                chart1.ChartAreas[0].AxisX.Interval = 1;
                while (i < dataGridView3.Rows.Count)
                {
                    var skip = dataGridView3.Rows[i].Cells[0].Value;
                    var date = dataGridView3.Rows[i].Cells[2].Value;
                    chart1.Series[index].Points.AddXY(Convert.ToDouble(skip), Convert.ToDouble(date));
                    i++;
                }
            }
            catch { }

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            chart1.Titles.Add("Статистика кодирования");
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            dataGridView2.Rows.Clear();
            dataGridView3.Rows.Clear();
            //keyBox.Enabled = true;
            encode.Enabled = true;
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            dataGridView2.Rows.Clear();
            dataGridView3.Rows.Clear();
            //keyBox.Enabled = true;
            encode.Enabled = true;
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            dataGridView2.Rows.Clear();
            dataGridView3.Rows.Clear();
           // keyBox.Enabled = false;
            encode.Enabled = false;
        }
    }
}
