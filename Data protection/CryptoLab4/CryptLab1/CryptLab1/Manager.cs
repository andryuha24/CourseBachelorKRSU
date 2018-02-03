using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;
using System.IO;
using System.Windows.Forms;
using System.Numerics;

namespace CryptLab1
{
    class Manager
    {
        public BigInteger mod, xNumber, yNumber, sum, mNumber;
        public List<BigInteger> encodedChars = new List<BigInteger>();
        public List<int> decodedChars;
        private BigInteger[] a;
        public static BigInteger NOD(BigInteger a, BigInteger b)
        {
            if (b == 0) return a;
            else return NOD(b, a % b);
        }

        public static BigInteger CountSum(BigInteger[] array, int index)
        {
            BigInteger result = 0;
            for (int i = 0; i < index; i++)
                result += array[i];
            return result;
        }

        public static BigInteger[] generateSequence(int n)
        {
            BigInteger[] key = new BigInteger[n];
            key[0] = 1;
            key[1] = 4;
            for (int i = 2; i < n; i++)
            {
                key[i] = CountSum(key, i) + 1;
                if (key[i] % key[i - 1] == 0) key[i]++;
            }
            return key;
        }

        public BigInteger[] getB_Sequence(BigInteger[] a, BigInteger x, BigInteger m)
        {
            BigInteger[] result = new BigInteger[a.Length];
            for (int i = 0; i < a.Length; i++)
                result[i] = a[i] * x % m;
            return result;
        }


        public void iterative_egcd(BigInteger a, BigInteger b, ref BigInteger x, ref BigInteger y, ref BigInteger d)
        {
            BigInteger q, r, x1, x2, y1, y2;
            if (b == 0)
            {
                d = a; x = 1; y = 0;
                return;
            }
            x2 = 1; x1 = 0; y2 = 0; y1 = 1;
            while (b > 0)
            {
                q = a / b;
                r = a - q * b;
                x = x2 - q * x1;
                y = y2 - q * y1;
                a = b;
                b = r;
                x2 = x1;
                x1 = x;
                y2 = y1;
                y1 = y;
            }
            d = a; x = x2; y = y2;
        }
        public BigInteger modInverse(BigInteger a, BigInteger m)
        {
            BigInteger d = 0, x = 0, y = 0;
            iterative_egcd(a, m, ref x, ref y, ref d);
            if (d == 1) return x;
            return 0;
        }

        private string createFillMassNull(int n)
        {
            char[] nulls = new char[n];
            for (int i = 0; i < nulls.Length; i++) nulls[i] = '0';
            string nullsString = new string(nulls);
            return nullsString;
        }

        public string[] getBinFromText(string text, int sizeBlock)
        {
            byte[] bytes = Encoding.Default.GetBytes(text);
            string[] binaryText = new string[bytes.Length];
            string temp;
            for(int i=0; i<binaryText.Length;i++)
            {
                temp = Convert.ToString(bytes[i], 2);
                binaryText[i] = createFillMassNull(sizeBlock - temp.Length) + temp;
            }
            return binaryText;
        }

        public void EncodeBackPack(int blockSize, string msg)
        {
            mod = 0; xNumber = 0;
            yNumber = 0; sum = 0;
            mNumber = 0;
            Random rnd = new Random();
            a = generateSequence(blockSize);
            sum = CountSum(a, blockSize);
            mNumber = sum + 3;
            BigInteger yNew = 0;
            while (mod != 1)
            {
                xNumber = rnd.Next(int.MaxValue);
                if (xNumber > mNumber - 3) continue;
                if (NOD(mNumber, xNumber) !=1) continue;
                yNumber = modInverse(xNumber, mNumber);
                mod = xNumber * yNumber % mNumber;
            }
            var bKey = getB_Sequence(a, xNumber, mNumber);
            var binText = getBinFromText(msg, blockSize);

            
            encodedChars.Clear();
            foreach(string chars in binText)
            {
                BigInteger sum_CE = 0;
                for (int i=0; i<chars.Length;i++)
                {
                    int chBinId = (int)(char.GetNumericValue(chars[i]));
                    sum_CE += chBinId * bKey[i];
                }
                encodedChars.Add(sum_CE);
            }
        }
        public int findMax_NotMore(BigInteger n, BigInteger[] a)
        {
            string binMsg;
            BigInteger noMoreMax = 0;
            char[] BitMsg = new char[a.Length];
            for (int i = 0; i < BitMsg.Length; i++) BitMsg[i] = '0';

            for (int i = 0; i < a.Length; i++)
            {
                if(n>=a[i])
                {
                    BitMsg[i] = '1';
                    n = n - a[i];
                    
                }
                  
                else
                {
                    BitMsg[i] = '0';
                }
            }
       
            binMsg = new string(BitMsg);
            binMsg = binMsg.Substring(0,8);
            char[] arr = binMsg.ToCharArray();
            Array.Reverse(arr);
            string newMsg = new string(arr);
            int charId = Convert.ToInt32(newMsg, 2);
            return charId;
        }

        public void DecodeBackPack(BigInteger[] encodedChars)
        {
            BigInteger temp, delta=1;
            decodedChars = new List<int>();
            // decodedChars.Clear();
            BigInteger[] reversA = new BigInteger[a.Length];
            Array.Copy(a, reversA, a.Length);
           // reversA = a;
            Array.Reverse(reversA);
            foreach (BigInteger ch in encodedChars)
            {
                temp = ch* yNumber% mNumber;
                decodedChars.Add(findMax_NotMore(temp, reversA));
               
            }
        }
    }
}
