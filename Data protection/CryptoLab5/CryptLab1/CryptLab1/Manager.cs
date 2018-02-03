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
using System.Collections;
using System.Drawing;

namespace CryptLab1
{
    class Manager
    {
        #region Convertor
        //степени 2-ки
        private byte[] binaries = { 128, 64, 32, 16, 8, 4, 2, 1 };
        //текст в биты
        public byte[] textToBits(string text)
        {
            byte[] result = new byte[text.Length * 8];
            byte[] b = Encoding.Default.GetBytes(text);
            for (int i = 0; i < text.Length; i++)
            {
                byte n = b[i];
                for (int j = 0; j < 8; j++)
                {
                    if (n >= binaries[j])
                    {
                        n -= binaries[j];
                        result[i * 8 + j] = 1;
                    }
                    else { result[i * 8 + j] = 0; }
                }
            }
            return result;
        }
        //байт в биты
        public byte[] byteToBits(byte b)
        {
            byte[] result = new byte[8];
            for (int j = 0; j < 8; j++)
            {
                if (b >= binaries[j])
                {
                    b -= binaries[j];
                    result[j] = 1;
                }
                else { result[j] = 0; }
            }
            return result;
        }
        //биты в байт
        public byte bitsToByte(byte[] bits)
        {
            int b = 0;
            for (int j = 0; j < 8; j++)
                b += bits[j] * binaries[j];
            return (byte)b;
        }
        public string bitsToText(byte[] binary)
        {
            int blocks = binary.Length / 8;
            byte[] b = new byte[blocks];
            for (int i = 0; i < blocks; i++)
            {
                int n = 0;
                for (int j = 0; j < 8; j++)
                    n += binary[i * 8 + j] * binaries[j];
                if (n == 0) n = 32;
                b[i] = (byte)n;
            }
            string result = Encoding.Default.GetString(b);
            return result;
        }
        //получить определенные биты из сообщения начиная с позиции index и количеством count
        public byte[] GetBits(byte[] message, int index, int count)
        {
            if (index + count > message.Length)
            {
                count = message.Length - index;
                if (count <= 0) return null;
            }
            byte[] result = new byte[count];
            for (int i = 0; i < count; i++)
                result[i] = message[index + i];
            return result;
        }
        #endregion
        #region Hider
        public int Length { get; set; }
        public int colPix;
        //записать сообщение в картинку
        public Bitmap HideMessage(byte[] message, Bitmap image, int bitsPerByte, int numColor)
        {
            var bmp = new Bitmap(image);
            int index = 0;
            Length = message.Length;
            int thousands = Length / 1000;
            int hundreds = (Length - thousands * 1000) / 100;
            int decs = Length % 100;
            //в последний пиксель картинки пишем размер сообщения
            Color p = Color.FromArgb(thousands, hundreds, decs);
            bmp.SetPixel(bmp.Width - 1, bmp.Height - 1, p);
            colPix = 0;
            for (int y = 0; y < bmp.Height; y++)
            {
                for (int x = 0; x < bmp.Width; x++)
                {
                    Color pixel = bmp.GetPixel(x, y);
                    colPix++;
                    byte red = pixel.R; byte green = pixel.G; byte blue = pixel.B;
                    CombinationColor(numColor, ref red, ref green, ref blue, bitsPerByte, ref index, ref message);
                    Color newPixel = Color.FromArgb(red, green, blue);
                    bmp.SetPixel(x, y, newPixel);

                    if (index >= message.Length) return bmp;
                }

            }
            return bmp;
        }

        private void CombinationColor(int numColor, ref byte red, ref byte green, ref byte blue, int bitsPerByte, ref int index, ref byte[] message)
        {
            if (numColor == 33)
            {
                red = WriteByte(red, GetBits(message, index, bitsPerByte));
                index += bitsPerByte;
                green = WriteByte(green, GetBits(message, index, bitsPerByte));
                index += bitsPerByte;
                blue = WriteByte(blue, GetBits(message, index, bitsPerByte));
                index += bitsPerByte;
            }
            else if (numColor == 12)
            {
                red = WriteByte(red, GetBits(message, index, bitsPerByte));
                index += bitsPerByte;
                green = WriteByte(green, GetBits(message, index, bitsPerByte));
                index += bitsPerByte;
            }
            else if (numColor == 13)
            {
                red = WriteByte(red, GetBits(message, index, bitsPerByte));
                index += bitsPerByte;
                blue = WriteByte(blue, GetBits(message, index, bitsPerByte));
                index += bitsPerByte;
            }
            else if (numColor == 23)
            {
                green = WriteByte(green, GetBits(message, index, bitsPerByte));
                index += bitsPerByte;
                blue = WriteByte(blue, GetBits(message, index, bitsPerByte));
                index += bitsPerByte;
            }
            else if (numColor == 1)
            {
                red = WriteByte(red, GetBits(message, index, bitsPerByte));
                index += bitsPerByte;
            }
            else if (numColor == 2)
            {
                green = WriteByte(green, GetBits(message, index, bitsPerByte));
                index += bitsPerByte;
            }
            else if (numColor == 3)
            {
                blue = WriteByte(blue, GetBits(message, index, bitsPerByte));
                index += bitsPerByte;
            }
        }

        //заменить биты в цвете
        private byte WriteByte(byte b, byte[] message)
        {
            if (message == null) return b;
            var pixel = byteToBits(b);
            for (int i = 0; i < message.Length; i++)
                pixel[7 - i] = message[message.Length - 1 - i];
            return bitsToByte(pixel);
        }
        #endregion
        #region Extracter
        public byte[] ExtractMessage(Bitmap image, int bitsPerByte, int numColor)
        {
            var bmp = new Bitmap(image);
            //считываем размер изображения
            Color p = bmp.GetPixel(bmp.Width - 1, bmp.Height - 1);
            Length = p.R * 1000 + p.G * 100 + p.B;

            byte[] bits = new byte[Length];
            int index = 0;
            for (int y = 0; y < bmp.Height; y++)
            {
                for (int x = 0; x < bmp.Width; x++)
                {
                    Color pixel = bmp.GetPixel(x, y);
                    GetPixelMessage(ref bits, pixel, bitsPerByte, index, numColor);
                    //index += 3 * bitsPerByte;
                    index += numColors(numColor) * bitsPerByte;// =colColor*bitsPerByte
                    if (index > Length) return bits;
                }
            }
            return bits;
        }
        private void GetPixelMessage(ref byte[] message, Color pixel, int bits, int index, int nColor)
        {
            //byte[] rgb = { pixel.R, pixel.G, pixel.B };
            byte[] rgb = chckCombination(nColor, pixel);
            for (int i = 0; i < rgb.Length; i++)
            {
                byte[] pixelBits = GetValues(rgb[i], bits);
                for (int j = 0; j < bits; j++)
                {
                    if (index == message.Length) return;
                    message[index++] = pixelBits[j];
                }
            }
        }
        private byte[] GetValues(byte message, int bits)
        {
            byte[] result = new byte[bits];
            var bitVal = byteToBits(message);
            for (int i = 0; i < bits; i++)
                result[bits - 1 - i] = bitVal[7 - i];
            return result;
        }

        private byte[] chckCombination(int col, Color mPixel)
        {
            byte[] rgb=null;
           
            if (col == 1)
            {
                byte[] temp= { mPixel.R};
                rgb = temp;
            }
            else if (col == 2)
            {
                byte[] temp = { mPixel.G };
                rgb = temp;
            }
            else if (col == 3)
            {
                byte[] temp = { mPixel.B };
                rgb = temp;
            }
            else if (col == 12)
            {
                byte[] temp = { mPixel.R, mPixel.G};
                rgb = temp;
            }
            else if (col == 13)
            {
                byte[] temp = { mPixel.R, mPixel.B };
                rgb = temp;
            }
            else if (col == 23)
            {
                byte[] temp = { mPixel.G, mPixel.B };
                rgb = temp;
            }
            else if (col == 33)
            {
                byte[] temp = { mPixel.R,mPixel.G,mPixel.B};
                rgb = temp;
            }
            return rgb;
            // return NumColor;
        }
        private int numColors(int n)
        {
            int num = 0;
            if (n == 1){ num = 1;}
            else if (n == 2){num = 1;}
            else if (n == 3){num = 1;}
            else if (n == 12){num = 2;}
            else if (n == 13){num = 2; }
            else if (n == 23){ num = 2; }
            else if (n == 33) {num = 3;}
            return num;
        }
        #endregion
    }
}