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
        public string code;
        public string Template { get; set; }
        public Dictionary<string, double> getDecode{ get { return countCode; }  }
        private  Dictionary<string, double> chast = new Dictionary<string, double>();
        private  Dictionary<string, double> countOrigin = new Dictionary<string, double>();
        private Dictionary<string, double> countCode = new Dictionary<string, double>();
        public static char[,] vigineerMatrix = new char[alphabet.Length, alphabet.Length];
        private static int N = 5;
        //public StringBuilder matrix = new StringBuilder();
       // private static char[,] matrixPL;
        //public string Matrix(string m)
        //{
        //   return m;

        //}
        public void FillDataGrid(DataGridView datagrid, Func<string, double> func, string input)
        {
            datagrid.Rows.Clear();
            for (int i = 1; i < alphabet.Length+1; i++)
            {
                int index = datagrid.Rows.Add();
                DataGridViewRow row = datagrid.Rows[index];
                row.Cells[0].Value = i;
                row.Cells[1].Value = alphabet[i-1].ToString();
                row.Cells[2].Value = Convert.ToDouble(func(alphabet[i-1].ToString())/input.Length);

            }
            datagrid.Sort(datagrid.Columns[2], ListSortDirection.Descending);
            for (int i = 0; i < alphabet.Length; i++)
            {
                var row = datagrid.Rows[i];
                row.Cells[0].Value = i + 1;   
            }
        }

        public static void generateVigineerMatrix()
        {
            int index = 0;
            for (int i = 0; i < alphabet.Length; i++)
            {
                for (int j = 0; j < alphabet.Length; j++)
                {
                    vigineerMatrix[i, j] = alphabet[(index + j) % alphabet.Length];
                }
                index++;
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

        public void Vigineer(string input, string keyword)
        {
            generateVigineerMatrix();
            code = "";
            List<int> keyPos = new List<int>();
            for (int i = 0; i < keyword.Length; i++)
            {
                keyPos.Add(alphabet.IndexOf(keyword[i]));
            }
            for (int i = 0; i < input.Length; i++)
            {
                if (alphabet.Contains(input[i].ToString()) == false)
                {
                    code += input[i].ToString();
                }
                else
                {
                    int row = keyPos[i % keyword.Length];
                    int column = alphabet.IndexOf(input[i]);
                    code += vigineerMatrix[row, column].ToString();
                }

            }

        }
        public string VigineerDecode(string input, string keyword)
        {
            string origin = "";
            if (string.IsNullOrEmpty(code)) return "";
            List<int> keyPos = new List<int>();
            for (int i = 0; i < keyword.Length; i++)
            {
                keyPos.Add(alphabet.IndexOf(keyword[i]));
            }
            for (int i = 0; i < input.Length; i++)
            {
                if (alphabet.Contains(code[i].ToString()) == false)
                {
                    origin += code[i].ToString();
                }
                else
                {
                    int row = keyPos[i % keyword.Length];
                    for (int j = 0; j < alphabet.Length; j++)
                        if (vigineerMatrix[row, j] == input[i])
                        {
                            origin += alphabet[j];
                            break;
                        }
                }

            }
            return origin;
        }

        //private string FillMatrix(string key)
        //{
        //    matrixPL = new char[N, N];
        //    string restAbc = alphabet;
        //    for (int i = 0; i < key.Length; i++)
        //    {
        //        matrixPL[i / N, i % N] = key[i];
        //        restAbc = restAbc.Replace(key[i].ToString(), "");
        //    }
        //    for (int i = 0; i < restAbc.Length; i++)
        //    {
        //        matrixPL[(i + key.Length) / N, (i + key.Length) % N] = restAbc[i];
        //    }
        //    return key + restAbc;
        //}

        public void Playfair(string input, string key)
        {
            code = "";
            StringBuilder result = new StringBuilder();
            StringBuilder matrix = new StringBuilder();
            StringBuilder inp = new StringBuilder(input);
            //добавляем в нашу матрицу символы из ключа
            for (int i = 0; i < key.Length; i++)
                if (key[i] != ' ' && !matrix.ToString().Contains(key[i].ToString()))
                    matrix.Append(key[i]);

            //и оставшиеся символы из алфавита
            for (int i = key.Length; i < 25; i++)
            {
                for (int j = 0; j < alphabet.Length; j++)
                {
                    if (alphabet[j] == 'q' || alphabet[j] == ' ') continue;
                    if (!matrix.ToString().Contains(alphabet[j].ToString()))
                    {
                        matrix.Append(alphabet[j]);
                    }
                }
            }
            //если в строке нечетное количество символов, добавляем x		
            if (inp.Length % 2 != 0) inp.Append('x');
            //шифруем пары
            //наш символ-разделитель 'x'		
            int length = inp.Length - 1;
            for (int i = 0; i < length; i += 2)
            {
                //#1
                if (inp[i] == inp[i + 1]) { inp.Insert(i + 1, 'x'); length++; }
                //получаем номера строк и столбцов символов нашей биграммы
                int firstKeyRow = getRow(inp[i], matrix.ToString());
                int firstKeyColumn = getColumn(inp[i], matrix.ToString());
                int secondKeyRow = getRow(inp[i + 1], matrix.ToString());
                int secondKeyColumn = getColumn(inp[i + 1], matrix.ToString());
                //#2 если символы находятся в одной строке
                if (firstKeyRow == secondKeyRow)
                {
                    result.Append(matrix[firstKeyRow * 5 + (firstKeyColumn + 1) % 5]);
                    result.Append(matrix[secondKeyRow * 5 + (secondKeyColumn + 1) % 5]);
                    continue;
                }
                //#3 если символы находятся в одном столбце
                if (firstKeyColumn == secondKeyColumn)
                {
                    result.Append(matrix[(firstKeyRow + 1) % 5 * 5 + firstKeyColumn]);
                    result.Append(matrix[(secondKeyRow + 1) % 5 * 5 + secondKeyColumn]);
                    continue;
                }
                else
                {
                    //#4 случай когда ни столбцы, ни строки не совпадают
                    result.Append(matrix[firstKeyRow * 5 + secondKeyColumn]);
                    result.Append(matrix[secondKeyRow * 5 + firstKeyColumn]);
                }
            }
           // PlayfairMessage = result.ToString();
            code = result.ToString();
        }

        public static int getRow(char a, string s)
        {
            int findRow = 0;
            findRow = s.IndexOf(a) / 5;
            return findRow;
        }
        public static int getColumn(char a, string s)
        {
            int findCol = 0;
            findCol = s.IndexOf(a) % 5;
            return findCol;
        }
    }
}
