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
        byte[] textBits { get; set; }
        private int NumColor { get; set; }
        public Form1()
        {
            InitializeComponent();
            
        }
        private void openFile<T>(string Filter, string Title, T output)
        {
            OpenFileDialog dialog = new OpenFileDialog();
   
            dialog.Filter = Filter;
            dialog.FilterIndex = 0;

            dialog.Title = Title;
            string name = dialog.FileName;
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                if (output is RichTextBox)
                    inputBox.Text = File.ReadAllText(dialog.FileName);
                else if (output is PictureBox)
                    pictureBox1.Image = Image.FromFile(dialog.FileName);
            }
        }

        private void saveFile<T>(string Filter, string Title, T output)
        {
            Bitmap image=null;
            if (output is RichTextBox)
            {
                if (outputBox.Text == "")
                {
                    MessageBox.Show("Нет текста для записи в файл.");
                    return;
                }
            }
            else if (output is PictureBox) image = new Bitmap(pictureBox1.Image);
            
            SaveFileDialog dialog = new SaveFileDialog();
            dialog.Filter = Filter;
            dialog.Title = Title;
            dialog.ShowDialog();
            string name = dialog.FileName;
            if (name != "")
            {
                if (output is RichTextBox)
                    File.WriteAllText(name, outputBox.Text);
                else if (output is PictureBox)
                    image.Save(dialog.FileName);
            }
        }

        private void decode_Click(object sender, EventArgs e)
        {
            try
            {
                if (inputBox.Text == "")
                {
                    MessageBox.Show("Введите текст!");
                    return;
                }
                textBits = scrypt.textToBits(inputBox.Text);
                PrintBinary(textBits, outputBox);
            }
            catch { MessageBox.Show("Неверно введены данные!\nИли полностью не введены все данные."); }

        }

        private void encode_Click(object sender, EventArgs e)
        {
            try
            {
                PrintBinary(textBits, outputBox);
                string text = scrypt.bitsToText(textBits);
                decodeOutputBox.Text = text;
            }
            catch { MessageBox.Show("Неверно введены данные!\nИли полностью не введены все данные."); }
        }

        private void PrintBinary(byte[] bits, RichTextBox rtb)
        {
            StringBuilder sc = new StringBuilder();
            foreach (byte b in bits) sc.Append(b);
            rtb.Text = sc.ToString();
        }

        private void текстToolStripMenuItem_Click(object sender, EventArgs e)
        {
            openFile("txt files (*.txt)|*.txt|All files (*.*)|*.*", "Файл с сообщением.", inputBox);
        }

        private void изображениеToolStripMenuItem_Click(object sender, EventArgs e)
        {
            openFile("bmp files (*.bmp)|*.bmp|All files (*.*)|*.*", "Файл с изображением.", pictureBox1);
        }

        private void текстToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            saveFile("txt files (*.txt)|*.txt|All files (*.*)|*.*", "Сохранить файл с сообщением.", decodeOutputBox);
        }

        private void изображениеToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            saveFile("bmp files (*.bmp)|*.bmp|All files (*.*)|*.*", "Сохранить изображение", pictureBox1);
        }

        private void выходToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void chckCombination()
        {
            if (chkRed.Checked == true && chkGreen.Checked == false && chkBlue.Checked == false) NumColor = 1;
            else if (chkGreen.Checked == true && chkRed.Checked == false && chkBlue.Checked == false) NumColor = 2;
            else if (chkBlue.Checked == true && chkGreen.Checked == false && chkRed.Checked == false) NumColor = 3;
            else if (chkRed.Checked == true && chkGreen.Checked == true && chkBlue.Checked == false) NumColor = 12;
            else if (chkRed.Checked == true && chkBlue.Checked == true && chkGreen.Checked == false) NumColor = 13;
            else if (chkGreen.Checked == true && chkBlue.Checked == true && chkRed.Checked == false) NumColor = 23;
            else if (chkRed.Checked == true && chkGreen.Checked == true && chkBlue.Checked == true) NumColor = 33;
            else { MessageBox.Show("Выберите в какие цвета записывать информацию!"); return; }
           // return NumColor;
        }

        private void writeButt_Click(object sender, EventArgs e)
        {
            int bits = comboBox1.SelectedIndex + 1;
            chckCombination();
            try
            {
                Bitmap image = new Bitmap(pictureBox1.Image);
                image = scrypt.HideMessage(textBits, image, bits,NumColor);
                pictureBox1.Image = image;
                MessageBox.Show("Текст спрятан в изображении");
            }
            catch { MessageBox.Show("Не возможно спрятать текст!"); };
        }

        private void readButt_Click(object sender, EventArgs e)
        {
            int bits = comboBox1.SelectedIndex + 1;
            chckCombination();
            try
            {
                Bitmap img = new Bitmap(pictureBox1.Image);
                textBits = scrypt.ExtractMessage(img, bits, NumColor);
                PrintBinary(textBits, outputBox);
            }
            catch { MessageBox.Show("Не возможно прочитать текст!"); }
         
        }
    }
}
