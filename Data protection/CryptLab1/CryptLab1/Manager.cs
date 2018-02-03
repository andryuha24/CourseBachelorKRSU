using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;
using System.IO;
using System.Windows.Forms;

namespace CryptLab1
{
    class Manager
    {
        public static string alphabet = "abcdefghijklmnopqrstuvwxyz";
        public static string newMonoAlphabet = "tjnpzysqarvlwxkdhbgiuomcfe";
        public string code;
        public string Template { get; set; }
        private  Dictionary<string, double> chast = new Dictionary<string, double>();
        private  Dictionary<string, double> countOrigin = new Dictionary<string, double>();
        private Dictionary<string, double> countCode = new Dictionary<string, double>();
        private  Dictionary<string, int> neededFrequency = new Dictionary<string, int>();
        public void FillDataGrid(DataGridView datagrid, Func<string, double> func, string input)
        {
            datagrid.Rows.Clear();
            for (int i = 1; i < newMonoAlphabet.Length+1; i++)
            {
                int index = datagrid.Rows.Add();
                DataGridViewRow row = datagrid.Rows[index];
                row.Cells[0].Value = i;
                row.Cells[1].Value = alphabet[i-1].ToString();
                row.Cells[2].Value = Convert.ToDouble(func(alphabet[i-1].ToString())/input.Length);

            }
            datagrid.Sort(datagrid.Columns[2], ListSortDirection.Descending);
            for (int i = 0; i < newMonoAlphabet.Length; i++)
            {
                var row = datagrid.Rows[i];
                row.Cells[0].Value = i + 1;   
            }
        }

        //private void FillFreqLetter()
        //{
        //    chast.Add("a", 8.167); chast.Add("b", 1.492); chast.Add("c", 2.782); chast.Add("d", 4.253);
        //    chast.Add("e", 12.702); chast.Add("f", 2.228); chast.Add("g", 2.015); chast.Add("h", 6.094);
        //    chast.Add("i", 6.966); chast.Add("j", 0.153); chast.Add("k", 0.772); chast.Add("l", 4.025);
        //    chast.Add("m", 2.406); chast.Add("n", 6.749); chast.Add("o", 7.507); chast.Add("p", 1.929);
        //    chast.Add("q", 0.095); chast.Add("r", 5.987); chast.Add("s", 6.327); chast.Add("t", 9.056);
        //    chast.Add("u", 2.758); chast.Add("v", 0.978); chast.Add("w", 2.360); chast.Add("x", 0.150);
        //    chast.Add("y", 1.974); chast.Add("z", 0.074);

        //}
        public double GetFrequence(string letter)
        {
            if (alphabet.Contains(letter) == false) return 0.0;
            return chast[letter];
        }

        public double GetNumberTemplate(string letter)
        {
            if (alphabet.Contains(letter) == false) return 0;
            return chast[letter];
        }
        public void FillTemplate()
        {
            chast = new Dictionary<string, double>();
            using (StreamReader sr = new StreamReader("TEMP.txt"))
            {
                Template = sr.ReadToEnd();
                sr.Close();
            }

            foreach (char t in alphabet)
            {
                chast.Add(t.ToString(), 0);
            }

            foreach (char t in Template)
            {
                if (alphabet.Contains(t.ToString()))
                    chast[t.ToString()]++;
            }
        }

        public void FindKeyCeazer( string output)
        {
            int key = 0;
            int l = alphabet.Length;
            double[] sum = new double[25];
          //  FillTemplate();
            //chast = new Dictionary<string, double>();
           // FillFreqLetter();
            string newOutput = output.ToLower();
            for (int i = 0; i < 25; i++)
            {

                string decode = DeCaezar(i+1, newOutput);
          
                neededFrequency = new Dictionary<string, int>();
                foreach (char t in alphabet)
                {
                    neededFrequency.Add(t.ToString(), 0);
                }

                foreach (char t in decode)
                {
                    if (alphabet.Contains(t.ToString()))
                        neededFrequency[t.ToString()]++;
                }
                foreach (KeyValuePair<string, int> pair in neededFrequency)
                {
                   
                    sum[i] += pair.Value*GetFrequence(pair.Key);
                }
            }
          
            double max = sum[0];
            for (int i = 0; i < sum.Length; i++)
            {
                if (sum[i] > max)
                {
                    max = sum[i];
                    key = i+1;
                }
            }
            MessageBox.Show("Найденный ключ: "+ key.ToString());
        }


        public double GetNumberOrigin(string letter)
        {
            if (alphabet.Contains(letter) == false) return 0;
            return countOrigin[letter];
        }
        public double GetNumberCode(string letter)
        {
            if (alphabet.Contains(letter) == false) return 0;
            return countCode[letter];
        }

        public void FillCount(string input)
        {
            countCode = new Dictionary<string, double>();
            countOrigin = new Dictionary<string, double>();
            foreach (char t in alphabet)
            {
                countCode.Add(t.ToString(), 0);
                countOrigin.Add(t.ToString(), 0);
            }

            foreach (char t in code)
            {
                if (alphabet.Contains(t.ToString()))
                    countCode[t.ToString()]++;
            }
            
            foreach (char t in input)
            {
                if (alphabet.Contains(t.ToString()))
                     countOrigin[t.ToString()]++;
            }
        }
        public  void MonoAlphabetEncode(string input)
        {
            code = "";
            foreach (char t in input)
            {
                if (alphabet.Contains(t.ToString()) == false)
                {
                    code += t.ToString();
                }
                else
                {
                    int pos = alphabet.IndexOf(t);
                    code += newMonoAlphabet[pos].ToString();
                }
            }

        }
        public  string MonoAlphabetDecode(string input)
        {

            string origin = "";
            if (string.IsNullOrEmpty(code)) return "";
            foreach (char t in code)
            {
                if (alphabet.Contains(t.ToString()) == false)
                {
                    origin += t.ToString();
                }
                else
                {
                    int pos = newMonoAlphabet.IndexOf(t);
                    origin += alphabet[pos].ToString();
                }
            }
            return origin;
        }

        public void Caezar(int key, string input)
        {
            code = "";
            foreach (char t in input)
            {
                if (alphabet.Contains(t.ToString()) == false)
                {
                    code += t.ToString();
                }
                else
                {
                    int pos = alphabet.IndexOf(t);
                    pos += key;
                    code += alphabet[pos % alphabet.Length].ToString();
                }
            }
        }

        public string DeCaezar(int key, string input)
        {
            string origin = "";
            if (string.IsNullOrEmpty(input)) return "";
            foreach (char t in input)
            {
                if (alphabet.Contains(t.ToString()) == false)
                {
                    origin += t.ToString();
                }
                else
                {
                    int pos = alphabet.IndexOf(t);
                    pos -= key;
                    origin += alphabet[(pos + alphabet.Length) % alphabet.Length].ToString();
                }
            }
            return origin;
        }

        public void Tritemius(string keyword, string input)
        {
            code = "";
            List<int> keyPos = new List<int>();
            int i;
            for (i = 0; i < keyword.Length; i++)
            {
                keyPos.Add(alphabet.IndexOf(keyword[i]));
            }

            for (i = 0; i < input.Length; i++)
            {
                if (alphabet.Contains(input[i].ToString()) == false)
                {
                    code += input[i].ToString();
                }
                else
                {
                    int offset = keyPos[i % keyword.Length];
                    int pos = alphabet.IndexOf(input[i]);
                    pos += offset;
                    code += alphabet[pos % alphabet.Length].ToString();
                }
            }
        }

        public string DeTritemius(string keyword)
        {
            string origin = "";
            if (string.IsNullOrEmpty(code)) return "";

            List<int> keyPos = new List<int>();
            int i;
            for (i = 0; i < keyword.Length; i++)
            {
                keyPos.Add(alphabet.IndexOf(keyword[i]));
            }

            for (i = 0; i < code.Length; i++)
            {
                if (alphabet.Contains(code[i].ToString()) == false)
                {
                    origin += code[i].ToString();
                }
                else
                {
                    int offset = keyPos[i % keyword.Length];
                    int pos = alphabet.IndexOf(code[i]);
                    pos -= offset;
                    origin += alphabet[(pos + alphabet.Length) % alphabet.Length].ToString();
                }
            }
            return origin;
        }
    }
}
