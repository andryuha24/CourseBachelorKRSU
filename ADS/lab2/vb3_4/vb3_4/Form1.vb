
Imports System.Math

Public Class Form1
    Dim x, y, y1, y2 As Single
    Dim a, b, c, c1, eps As Single
    Dim my2pen As New Pen(Color.Black)
    Dim drawFont As New Font("Arial", 7)
    Dim drawBrush As New SolidBrush(Color.Black)

    Dim n As Integer
    Private Sub Button2_Click(ByVal sender As Object, ByVal e As EventArgs) Handles Button2.Click
        Me.Close()
    End Sub

    Private Sub Sistemacoord()
        Dim g As Graphics = PictureBox1.CreateGraphics
        Dim MyPen As New Pen(Color.Black) 'Создание пера 
        Dim i As Integer
        g.Clear(Color.SkyBlue)
        MyPen.Width = 1 'Толщина пера 
        g.DrawLine(MyPen, 0, 206, 412, 206) 'Ось Х 
        g.DrawLine(MyPen, 412, 206, 397, 202) : g.DrawLine(MyPen, 412, 206, 397, 210)

        g.DrawLine(MyPen, 206, 0, 206, 412) 'Ось Y
        g.DrawLine(MyPen, 206, 0, 202, 15) : g.DrawLine(MyPen, 206, 0, 210, 15)

        MyPen.DashStyle = Drawing2D.DashStyle.DashDot
        For i = 0 To 25
            g.DrawLine(MyPen, 20 * i - 14, 0, 20 * i - 14, 412)
            g.DrawLine(MyPen, 0, 26 + 20 * i, 412, 26 + 20 * i)
        Next
        
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
  
        Dim i As Integer
        Dim g As Graphics = PictureBox1.CreateGraphics
        Sistemacoord()
        g.TranslateTransform(206, 206)

        For i = -9 To 9 Step 1
            g.DrawString(i, drawFont, drawBrush, i * 20, 0)
            g.DrawString(i, drawFont, drawBrush, 0, -i * 20)
        Next
        g.ScaleTransform(1, -1)
        For x = -206 To 206 Step 0.001
            y = f(x)
            If y < 100 Then g.DrawEllipse(my2pen, x * 20, y * 20, 1, 1)
        Next x



    End Sub
    Function f(ByVal x As Single)
        f = (1 / 3) * (x ^ 3 - 2) ^ 2 - 1
    End Function

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        Try
            Dim g As Graphics = PictureBox1.CreateGraphics
            Dim MyPen As New Pen(Color.Red) 'Создание пера 
            g.TranslateTransform(206, 206)
            g.ScaleTransform(1, -1)
            a = TextBox1.Text
            b = TextBox2.Text
            eps = TextBox3.Text
            a = Convert.ToSingle(TextBox1.Text)
            b = Convert.ToSingle(TextBox2.Text)
            g.DrawLine(MyPen, a * 20, -206, a * 20, 206)
            g.DrawLine(MyPen, b * 20, -206, b * 20, 206)
            y1 = f(a)


            n = 0
            If f(a) * f(b) <= 0 Then
                Do While (Math.Abs(b - a) > eps)
                    c = (a + b) / 2
                    y2 = f(c)
                    If (y1 * y2 < 0) Then
                        b = c
                    Else
                        a = c
                        y1 = y2
                    End If

                    n += 1
                Loop
                c1 = (a + b) / 2
                TextBox4.Text = c1
                TextBox5.Text = Round(f(c1), 8)
                TextBox6.Text = n


            Else
                TextBox4.Text = "Решений нет"
            End If
           

        Catch When (TextBox3.Text < 0)
            MsgBox(" eps < 0")
        Catch When Not IsNumeric(TextBox1.Text)
            MsgBox("Введите число!")
        Catch When Not IsNumeric(TextBox2.Text)
            MsgBox("Введите число!")
        Catch When Not IsNumeric(TextBox3.Text)
            MsgBox("Введите число!")
        End Try
    End Sub

End Class
