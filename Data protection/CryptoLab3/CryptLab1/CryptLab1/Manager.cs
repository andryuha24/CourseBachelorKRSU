using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;
using System.IO;
using System.Windows.Forms;
using MathNet.Numerics.LinearAlgebra;
using MathNet.Numerics.LinearAlgebra.Double;

namespace CryptLab1
{
    public class Manager
    {
        public static string alphabet = "abcdefghijklmnopqrstuvwxyz";
        public static string code;
        public string Template { get; set; }
        public Dictionary<string, double> getDecode{ get { return countCode; }  }
        private  Dictionary<string, double> chast = new Dictionary<string, double>();
        private  Dictionary<string, double> countOrigin = new Dictionary<string, double>();
        private Dictionary<string, double> countCode = new Dictionary<string, double>();
        private Dictionary<string, int> neededFrequency = new Dictionary<string, int>();
        // private Matrix<double> original, Code;
        public static double[,] keyMatrix, invertKeyMatrix;


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

        private void FillFreqLetter()
        {
            chast.Add("a", 8.167); chast.Add("b", 1.492); chast.Add("c", 2.782); chast.Add("d", 4.253);
            chast.Add("e", 12.702); chast.Add("f", 2.228); chast.Add("g", 2.015); chast.Add("h", 6.094);
            chast.Add("i", 6.966); chast.Add("j", 0.153); chast.Add("k", 0.772); chast.Add("l", 4.025);
            chast.Add("m", 2.406); chast.Add("n", 6.749); chast.Add("o", 7.507); chast.Add("p", 1.929);
            chast.Add("q", 0.095); chast.Add("r", 5.987); chast.Add("s", 6.327); chast.Add("t", 9.056);
            chast.Add("u", 2.758); chast.Add("v", 0.978); chast.Add("w", 2.360); chast.Add("x", 0.150);
            chast.Add("y", 1.974); chast.Add("z", 0.074);
        }


        public static double[,] getcharMatrix(string value, int size)
        {
            double[,] result = new double[size, size];
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                {
                    result[i, j] = alphabet.IndexOf(value[i * size + j]);
                }
            return result;
        }

       /* public Matrix<double> multiplayMatix(double [,]matrixA, double[,] matrixB)
        {
            original = DenseMatrix.OfArray(matrixB);
            Code = DenseMatrix.OfArray(matrixA);
            var result = Code*original;
            return result;
        }*/

        public string getMatrixText(double[,] matrix)
        {
            StringBuilder res = new StringBuilder();
            for (int j = 0; j < matrix.GetLength(0); j++)
                for (int i = 0; i < matrix.GetLength(1); i++)
                    res.Append(alphabet[Convert.ToInt32(matrix[i, j])]);
            return res.ToString();
        }

        public static string HillEncode(string msg, string key, int size, Label label)
        {
            code = null;
            keyMatrix = getcharMatrix(key, size);
            if (checkMatrix(keyMatrix) == false)
            {
                label.Text = "Матрица не имеет обратной.\nВведите другой ключ.";
                return null;
            }
            else
            {
                label.Text = " ";
                int parts = msg.Length - msg.Length % size;
                var p = new int[size];
                var c = new int[size];
                for (int m = 0; m < parts; m+=size)
                {
                    for (int n = 0; n < size; n++)
                    {
                        c[n] = 0;
                        p[n] = alphabet.IndexOf(msg[n + m]);
                    }

                    for (int i = 0; i < size; i++)
                    {
                        for (int j = 0; j < size; j++)
                        {
                            c[i] += (p[j] * (int)keyMatrix[i, j]);
                        }
                        c[i] = c[i] % alphabet.Length;
                        code += alphabet[c[i]].ToString();
                    }
                  }
            }
            return code;   
        }

        public static bool checkMatrix(double [,] checksMatrix)
        {
            bool result = false;
            var keyM = DenseMatrix.OfArray(checksMatrix);
            int determ = Convert.ToInt32(keyM.Determinant());
            if (determ != 0 && NOD(determ, alphabet.Length) == true)
                result = true;
            else result = false;
            return result;
        }
        public  static bool NOD(int a, int b)
        {
            for (int i = 2; i < Math.Abs(a)+1; i++)
            {
                if ((a % i == 0) && (b % i == 0))
                {
                    return false;
                }
            }
            return true;
        }

        public string HillDecode(string msg, string key, int size, Label label)
        {
            string code = null;
            keyMatrix = getcharMatrix(key, size);
            double determ = 0;
            if (checkMatrix(keyMatrix) == false)
            {
                label.Text = "Матрица не имеет обратной.\nВведите другой ключ.";
                return null;
            }
            else
            {
                label.Text = " ";
                Matrix keyM = DenseMatrix.OfArray(keyMatrix);
                determ = keyM.Determinant();
                var keyInvert = keyM.Inverse();
                keyInvert *= determ;
             
                invertKeyMatrix = keyInvert.ToArray();
                double invDeterm = nfmod(determ, alphabet.Length);
                double invMultDeterm = modInverse(Convert.ToInt32(invDeterm), alphabet.Length);
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        invertKeyMatrix[i, j] = Convert.ToInt32(nfmod(invertKeyMatrix[i, j], alphabet.Length))* Convert.ToInt32(invMultDeterm);
                        invertKeyMatrix[i, j]%= alphabet.Length;
                      
                    }  
                }
                int parts = msg.Length - msg.Length % size;
                var p = new int[size];
                var c = new int[size];
                for (int m = 0; m < parts; m += size)
                {
                    for (int n = 0; n < size; n++)
                    {
                        c[n] = 0;
                        p[n] = alphabet.IndexOf(msg[n + m]);
                    }

                    for (int i = 0; i < size; i++)
                    {
                        for (int j = 0; j < size; j++)
                        {
                            c[i] += (p[j] * (int)invertKeyMatrix[i, j]);
                        }
                        c[i] %= alphabet.Length;
                        code += alphabet[c[i]].ToString();
                    }
                }
            }
            return code;
        }

        double nfmod(double a, double b)
        {
            return a - b * Math.Floor(a / b);
        }

        int modInverse(int a, int m)
        {
            int x = 0;
            a %= m;
            for (int i = 1; i < m; i++)
            {
                if ((a * i) % m == 1)
                    x = i;
            }
            return x;
        }

        public void HackHill(string input, string output, int size, Label label)
        {
           
            Dictionary<string,double> sum = new Dictionary<string, double>();
            string originCode = output;
            while ( input.Length <= output.Length)//(output.Length > Math.Pow(size, 2) + 1) &&
            {
                if (input.Length < size * size)
                {
                    MessageBox.Show("Размер участка открытого текста должен быть\nбольше или равен квадрата размера ключевой матрицы.");
                    return;
                }
                var originMatrix = getcharMatrix(input, size);

                var codeMatrix = getcharMatrix(output, size);
                /* if (checkMatrix(originMatrix) == false)
                 {
                     label.Text = "Матрица не имеет обратной.\nВведите другой ключ.";
                     return;
                 }
                 else *//*if (checkMatrix(codeMatrix) == false)
                 {
                     label.Text = "Матрица не имеет обратной.\nВведите другой ключ.";
                     return;
                 }
                 else
                 {*/

                    Matrix originM = DenseMatrix.OfArray(originMatrix);
                    Matrix codeM = DenseMatrix.OfArray(codeMatrix);
                    double determ = originM.Determinant();
                    var originInvert = originM.Inverse();
                    originInvert *= determ;
                    // (keyM.Determinant()%26)*
                    var invertOriginMatrix = originInvert.ToArray();
                    double invDeterm = nfmod(determ, alphabet.Length);
                    double invMultDeterm = modInverse(Convert.ToInt32(invDeterm), alphabet.Length);
                    if (invMultDeterm == 0)
                    {
                      MessageBox.Show("Попробуйте ввести другую пару открытого и зашифрованного текста");
                      return;
                    }
                    else
                    {
                        for (int i = 0; i < size; i++)
                        {
                            for (int j = 0; j < size; j++)
                            {
                                
                                invertOriginMatrix[i, j] = Convert.ToInt32(nfmod(invertOriginMatrix[i, j], alphabet.Length)) * Convert.ToInt32(invMultDeterm);
                                invertOriginMatrix[i, j] %= alphabet.Length;
                            }
                        }
                        Matrix inverOriginM = DenseMatrix.OfArray(invertOriginMatrix);
                        var keyM = (inverOriginM * codeM) % alphabet.Length;

                        double[,] findKeyMatrix = keyM.ToArray();
                        if (checkMatrix(findKeyMatrix) == false)
                        {
                            label.Text = "Матрица не имеет обратной.\nВведите другой ключ.";
                            output = output.Remove(0, 1);
                            continue;
                        }
                        else
                            AnalysisForLogical(findKeyMatrix, originCode, size, label, sum);

                        // MessageBox.Show(keyM.ToString());
                        //}
                        output = output.Remove(0, 1);
                    } 
            }

            if (sum.Count()==0)
                MessageBox.Show("Не найден ключ!");
            else
            {
                var showKey = sum.OrderByDescending(z => z.Value).ToDictionary(a => a, s => s).First().Value;
                MessageBox.Show(showKey.Key.ToString());
            }
                
        }

        public void AnalysisForLogical(double[,] key,string code, int block, Label templabel,  Dictionary<string, double> sum)
        {

            int l = alphabet.Length;
            chast = new Dictionary<string, double>();
            //FillTemplate();
            FillFreqLetter();
            // double[] sum = new double[25];
            string tempKey = getMatrixText(key);
            string decode = HillDecode(code, tempKey, block, templabel);
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
            double tempSum = 0;
            foreach (KeyValuePair<string, int> pair in neededFrequency)
            {
                tempSum += pair.Value * GetFrequence(pair.Key);
            }
            sum.Add(tempKey,tempSum);
        }
    }
}
