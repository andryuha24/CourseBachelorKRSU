namespace CryptLab1
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.inputBox = new System.Windows.Forms.RichTextBox();
            this.open = new System.Windows.Forms.Button();
            this.decode = new System.Windows.Forms.Button();
            this.encode = new System.Windows.Forms.Button();
            this.save = new System.Windows.Forms.Button();
            this.keyBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.outputBox = new System.Windows.Forms.RichTextBox();
            this.decodeOutputBox = new System.Windows.Forms.RichTextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.mText = new System.Windows.Forms.Label();
            this.xText = new System.Windows.Forms.Label();
            this.yText = new System.Windows.Forms.Label();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // inputBox
            // 
            this.inputBox.Location = new System.Drawing.Point(12, 34);
            this.inputBox.Name = "inputBox";
            this.inputBox.Size = new System.Drawing.Size(310, 91);
            this.inputBox.TabIndex = 3;
            this.inputBox.Text = "";
            // 
            // open
            // 
            this.open.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.open.Location = new System.Drawing.Point(331, 8);
            this.open.Name = "open";
            this.open.Size = new System.Drawing.Size(176, 35);
            this.open.TabIndex = 5;
            this.open.Text = "Открыть";
            this.open.UseVisualStyleBackColor = true;
            this.open.Click += new System.EventHandler(this.open_Click);
            // 
            // decode
            // 
            this.decode.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.decode.Location = new System.Drawing.Point(331, 49);
            this.decode.Name = "decode";
            this.decode.Size = new System.Drawing.Size(176, 35);
            this.decode.TabIndex = 6;
            this.decode.Text = "Зашифровать";
            this.decode.UseVisualStyleBackColor = true;
            this.decode.Click += new System.EventHandler(this.decode_Click);
            // 
            // encode
            // 
            this.encode.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.encode.Location = new System.Drawing.Point(331, 90);
            this.encode.Name = "encode";
            this.encode.Size = new System.Drawing.Size(176, 35);
            this.encode.TabIndex = 7;
            this.encode.Text = "Расшифровать";
            this.encode.UseVisualStyleBackColor = true;
            this.encode.Click += new System.EventHandler(this.encode_Click);
            // 
            // save
            // 
            this.save.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.save.Location = new System.Drawing.Point(331, 131);
            this.save.Name = "save";
            this.save.Size = new System.Drawing.Size(176, 35);
            this.save.TabIndex = 8;
            this.save.Text = "Сохранить";
            this.save.UseVisualStyleBackColor = true;
            this.save.Click += new System.EventHandler(this.save_Click);
            // 
            // keyBox
            // 
            this.keyBox.Enabled = false;
            this.keyBox.Location = new System.Drawing.Point(220, 9);
            this.keyBox.Multiline = true;
            this.keyBox.Name = "keyBox";
            this.keyBox.Size = new System.Drawing.Size(81, 20);
            this.keyBox.TabIndex = 10;
            this.keyBox.Text = "100";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(13, 8);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(201, 17);
            this.label1.TabIndex = 11;
            this.label1.Text = "Длинна последовательности";
            // 
            // outputBox
            // 
            this.outputBox.Location = new System.Drawing.Point(12, 139);
            this.outputBox.Name = "outputBox";
            this.outputBox.Size = new System.Drawing.Size(310, 85);
            this.outputBox.TabIndex = 16;
            this.outputBox.Text = "";
            // 
            // decodeOutputBox
            // 
            this.decodeOutputBox.Location = new System.Drawing.Point(12, 239);
            this.decodeOutputBox.Name = "decodeOutputBox";
            this.decodeOutputBox.Size = new System.Drawing.Size(310, 85);
            this.decodeOutputBox.TabIndex = 17;
            this.decodeOutputBox.Text = "";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(328, 189);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(31, 17);
            this.label2.TabIndex = 18;
            this.label2.Text = "m =";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(328, 221);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(26, 17);
            this.label3.TabIndex = 19;
            this.label3.Text = "x =";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(328, 252);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(27, 17);
            this.label4.TabIndex = 20;
            this.label4.Text = "y =";
            // 
            // mText
            // 
            this.mText.AutoSize = true;
            this.mText.Location = new System.Drawing.Point(355, 189);
            this.mText.Name = "mText";
            this.mText.Size = new System.Drawing.Size(49, 13);
            this.mText.TabIndex = 21;
            this.mText.Text = "_______";
            // 
            // xText
            // 
            this.xText.AutoSize = true;
            this.xText.Location = new System.Drawing.Point(355, 223);
            this.xText.Name = "xText";
            this.xText.Size = new System.Drawing.Size(49, 13);
            this.xText.TabIndex = 22;
            this.xText.Text = "_______";
            // 
            // yText
            // 
            this.yText.AutoSize = true;
            this.yText.Location = new System.Drawing.Point(355, 256);
            this.yText.Name = "yText";
            this.yText.Size = new System.Drawing.Size(49, 13);
            this.yText.TabIndex = 23;
            this.yText.Text = "_______";
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Checked = true;
            this.checkBox1.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox1.Location = new System.Drawing.Point(307, 12);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(15, 14);
            this.checkBox1.TabIndex = 24;
            this.checkBox1.UseVisualStyleBackColor = true;
            this.checkBox1.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(558, 335);
            this.Controls.Add(this.checkBox1);
            this.Controls.Add(this.yText);
            this.Controls.Add(this.xText);
            this.Controls.Add(this.mText);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.decodeOutputBox);
            this.Controls.Add(this.outputBox);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.keyBox);
            this.Controls.Add(this.save);
            this.Controls.Add(this.encode);
            this.Controls.Add(this.decode);
            this.Controls.Add(this.open);
            this.Controls.Add(this.inputBox);
            this.Name = "Form1";
            this.Text = "Лабораторная №3";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.RichTextBox inputBox;
        private System.Windows.Forms.Button open;
        private System.Windows.Forms.Button decode;
        private System.Windows.Forms.Button encode;
        private System.Windows.Forms.Button save;
        private System.Windows.Forms.TextBox keyBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.RichTextBox outputBox;
        private System.Windows.Forms.RichTextBox decodeOutputBox;
        private System.Windows.Forms.Label mText;
        private System.Windows.Forms.Label xText;
        private System.Windows.Forms.Label yText;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.CheckBox checkBox1;
    }
}

