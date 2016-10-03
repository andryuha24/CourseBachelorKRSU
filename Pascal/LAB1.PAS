Program MyGraph;
{$R-}
{Theme:'Plotting functions y=a*sin(x*x)+b*x
                                  y=a*tg(x)+b'}
{Author: Zhulin Andrey}
{Date:14.03.2013}
uses Graph, Crt;
var
   xMax,yMax,col,code,i,y1,iChoose:integer;
   s:string;
   x,y,a1,b1,c,a,b,y3:extended;
   ch:char;

 {Inicialization of Graph rejime}
procedure GraphInit;
var
  grDriver: integer;
  grMode: integer;
  ErrCode: integer;
begin
    grDriver := Detect;
    InitGraph(grDriver, grMode,'C:\langs\bp\bgi\');
    ErrCode := GraphResult;
    if ErrCode <> grOk then
      begin
         Writeln('Graphics error:', GraphErrorMsg(ErrCode));
         repeat until KeyPressed;
          Halt;
      end;
      xMax:=GetMaxX;
      yMax:=GetMaxY;
end;

{General frame}
procedure Maket;
  begin
   SetBkColor(0);
   SetLineStyle(0,0,3);
   SetColor(14);
   Rectangle(0,0,xMax,yMax);{General Frame}
   Line((xMax div 3)-30,0,(xMax div 3)-30,438);{Vertical line}
   Line(0,438,xMax,438);{Bottom Gorizontal line}
 {Table}
   Rectangle(6,8,177,280);{Border table}
   Line(57,10,57,280);{Line between X and Y}
   Line(117,10,117,280);{Line between Y and Y1}
   Line(7,36,177,36);{Horizontal line under the X and Y}
 {Function and there difinition}
   Rectangle(8,288,175,430);
   SetLineStyle(0,0,0);
   SetColor(11);
   OutTextXY(35,297,'y=a*sin(x*x)+b*x');
   OutTextXY(50,364,'y1=a*tg(x)+b');
   SetColor(2);
   OutTextXY(30,316,'a=');
   OutTextXY(30,338,'b=');
   OutTextXY(30,382,'a=');
   OutTextXY(30,404,'b=');
   SetColor(14);
   Rectangle(50,313,155,328);
   Rectangle(50,335,155,350);
   Rectangle(50,378,155,393);
   Rectangle(50,400,155,415);
 {Name of table function}
   SetLineStyle(0,0,3);
   SetTextStyle(8,0,2);
   SetColor(11);
   OutTextXY(22,8,'x');
   OutTextXY(80,8,'y');
   OutTextXY(130,8,'y1');
 {Filling of x}
   SetTextStyle(0,0,0);
   for i:=-100 to 100  do
     begin
      y1:=150+i;
      if (i mod 10)=0 then
        begin
         x:=i/10;
         STR(x:2:1,s);
         case round(x) of {alignment of x}
          -9..-1:OutTextXY(18,y1,s);
             -10:OutTextXY(10,y1,s);
            0..9:OutTextXY(25,y1,s);
              10:OutTextXY(16,y1,s);
         end;
        end;
     end;
  end;

{Coordinate plane}
procedure DrawKoordinata;
  begin
   SetLineStyle(0,0,0);
   SetColor(8);
  {Grid}
   for i:=1 to 21 do
     begin
      Line(xMax-430+(20*i),yMax-475,xMax-430+(20*i),yMax-66);
      Line(xMax-415,YMax-490+(20*i),xMax-8,yMax-490+(20*i));
     end;
   SetLineStyle(0,0,3);
   SetColor(1);
   Rectangle(xMax-415,yMax-475,xMax-5,yMax-65);{Border of coordinate plane}
   SetLineStyle(0,0,0);
   SetColor(14);
  {Coordinate axis}
   Line(xMax-210,yMax-470,XMax-210,yMax-70);
   Line(xMax-410,yMax-270,xMax-10,yMax-270);
  {Direction of axis}
   Line(xMax-210,yMax-470,xMax-215,yMax-455);
   Line(xMax-210,yMax-470,xMax-205,yMax-455);
   Line(xMax-10,yMax-270,xMax-25,yMax-275);
   Line(xMax-10,yMax-270,xMax-25,yMax-265);
  {Digitizing of coordinate axis}
   SetColor(2);

{Number of horizontal}
   for i:=-10 to 10 do
     begin
      STR(i,s);
       case i of
          0..9:OutTextXY(xMax-212+(20*i),yMax-60,s);
        -9..-1:OutTextXY(xMax-220+(20*i),yMax-60,s);
            10:OutTextXY(xMax-210+(19*i),yMax-60,s);
           -10:OutTextXY(xMax-225+(20*i),yMax-60,s);
       end;
     end;
  {Number of vertical}
   for i:=-10 to 10 do
     begin
      STR(i*10,s);
      case i of
        -9..-1:OutTextXY(xMax-442,yMax-270+(-20*i),s);
           -10:OutTextXY(xMax-450,yMax-272+(-20*i),s);
             0:OutTextXY(xMax-425,yMax-272+(-20*i),s);
          1..9:OutTextXY(xMax-434,yMax-272+(-20*i),s);
            10:OutTextXY(xMax-442,yMax-272+(-20*i),s);
      end;
     end;
   SetTextStyle(8,0,4);
   OutTextXY(610,207,'x');
   OutTextXY((xMax div 3)*2-25,0,'y');
  end;
{Draw Graphic}
procedure DrawGraphic;
 begin
  if col<15 then col:=col+1 {Changes color graphics}
            else col:=1;
  SetTextStyle(0,0,0);
  x:=-100;
  repeat
   SetViewPort(xMax-415,yMax-473,xMax-5,yMax-67,ClipOn);{Sets the current 
                                                                  viewport}
   y:=a*sin(x*x)+b*x;
   y3:=a1*(sin(x)/cos(x))+b1;
   PutPixel(round(x*20)+(xMax-434),round(-y*2)+(yMax-276),col+4);{Draw  
                                                                  Graphic}
   PutPixel(round(x*20)+(xMax-434),round(-y3*2)+(yMax-276),col);
   SetViewPort(0,0,xMax,yMax,ClipOn);{returns the viewport to the start   
                                                                 position}
   x:=x+0.001;{increment of the argument}
  until x>=100;
 end;

{Buttons}
procedure Buttons(iChoose:integer);
 begin
  SetTextStyle(0,0,0);
  
For i:=0 to 3 do
    begin
     SetFillStyle(1,7);
     Bar(8+i*100,445,100+i*100,yMax-6);{External layer buttons}
     SetFillStyle(1,15);
     Bar(12+i*100,449,96+i*100,yMax-10);{Interal layer buttons}
    end;
  SetFillStyle(1, 2);
 {Choose buttons}
  case iChoose of
      0: Bar(12,449,96,yMax-10);
      1: Bar(112,449,196,yMax-10);
      2: Bar(212,449,296,yMax-10);
      3: Bar(312,449,396,yMax-10);
  end;
  SetLineStyle(0,0,0);
  Setcolor(1);
 {Effect  3D of buttons}
  For i:=0 to 3 do
    begin
     Rectangle(8+i*100,445,100+i*100,yMax-6);{External circuit}
     Rectangle(12+i*100,449,96+i*100,yMax-10);{Interal circuit}
     Line(8+i*100,445,12+i*100,449);
     Line(8+i*100,yMax-6,12+i*100,yMax-10);
     Line(100+i*100,445,96+i*100,449);
     Line(100+i*100,yMax-6,96+i*100,yMax-10);
    end;
 {Name buttons}
  SetColor(4);
  OutTextXY(40,456,'N');
  OutTextXY(138,456,'D');
  OutTextXY(238,456,'C');
  OutTextXY(342,456,'E');
  SetColor(1);
  OutTextXY(48,456,'ew');
  OutTextXY(146,456,'raw');
  OutTextXY(245,456,'lear');
  OutTextXY(350,456,'nd');
 end;

{Clear coordinate plane}
procedure Clear;
 begin
  SetViewPort(xMax-415,yMax-475,xMax-5,yMax-65,ClipOn);
  ClearViewPort;
  SetViewPort(0,0,xMax,yMax,ClipOn);
  DrawKoordinata;{After clearing again draw coordinate plane }
 end;

{Input Data}
procedure InputData(x,y,x2,y2:integer);
 begin
  s:='';
  SetColor(1);
  repeat
   ch:=ReadKey;
   
case ch of
     '0'..'9': if Length(s)<=5 then
                 begin
                  s:=s+ch;
                  OutTextXY(xMax-x,yMax-y,s);
                  Val(s,c,code);
                 end;
     '-': if Length(s)=0 then
            begin
             s:=s+ch;
             OutTextXY(xMax-x,yMax-y,s);
             Val(s,c,code);
            end;
     '.':  if  s[1]='-' then
             begin
              if Length(s)>=2 then
                begin
                 s:=s+ch;
                 OutTextXY(xMax-x,yMax-y,s);
                 Val(s,c,code);
                end;
             end
            else
             if (Length(s)>=1) then
               begin
                s:=s+ch;
                OutTextXY(xMax-x,yMax-y,s);
                Val(s,c,code);
               end;
      #8:  begin {#8 = "<-Backspace"}
            Delete(s,Length(s),1);
            Bar(xMax-x,yMax-y,xMax-x2,yMax-y2);
            OutTextXY(xMax-x,yMax-y,s);
            Val(s,c,code);
           end;
   end;
  until ch=#13;
  if (Length(s)=0) or (s='0') then
    begin
     s:='0.0';{If the line is empty, it is assigned 0.0}
     OutTextXY(xMax-x,yMax-y,s);
     Val(s,c,code);
    end;
 end;

{Filling in the values of the function}
procedure OutputNewData;
  begin
    SetColor(14);
    SetLineStyle(0,0,3);
    SetFillStyle(1,0);
    Bar(59,39,175,276);
    Line(117,10,117,280);
    x:=-10;
    repeat
     Setcolor(11);
     
     i:=i+1;
     y:=a*sin(x*x)+b*x;
     STR(y:5:2,s);
     case round(y) of {Vyravnivanie chisel}
             0..9:OutTextXY(75,10+(10*i),s);
           10..99:OutTextXY(75,10+(10*i),s);
        100..1000:OutTextXY(67,10+(10*i),s);
           -9..-1:OutTextXY(75,10+(10*i),s);
         -99..-10:OutTextXY(67,10+(10*i),s);
      -1000..-100:OutTextXY(59,10+(10*i),s);
     end;
     y3:=a1*(sin(x)/cos(x))+b1;
     STR(y3:5:2,s);
     case round(y3) of {Vyravnivanie chisel}
             0..9:OutTextXY(134,10+(10*i),s);
           10..99:OutTextXY(134,10+(10*i),s);
        100..1000:OutTextXY(126,10+(10*i),s);
           -9..-1:OutTextXY(134,10+(10*i),s);
         -99..-10:OutTextXY(126,10+(10*i),s);
      -1000..-100:OutTextXY(119,10+(10*i),s);
     end;
     x:=x+1;
    until x>=11;
  end;

{Opens a window for input of data}
procedure NewData;
  var
     p:pointer;
     size:longint;
  begin
   size:=ImageSize(xMax div 3,yMax-460,(xMax div 3)*2,yMax-100);
   GetMem(p,size);
   GetImage(xMax div 3,yMax-460,(xMax div 3)*2,yMax-100,p^);
   SetFillStyle(1,2);
   Bar((xMax div 3)+5,yMax-300,(xMax div 3)*2,YMax-160);{Window of input 
                                                                     data}
   SetColor(1);
   OutTextXY(xMax-409,yMax-295,'Func y=a*sin(x*x)+b*x');
   OutTextXY(xMax-409,yMax-230,'Func y1=a*tg(x)+b');
   OutTextXY(xMax-414,yMax-275,' a=');
   OutTextXY(xMax-414,yMax-250,' b=');
   OutTextXY(xMax-414,yMax-210,' a=');
   OutTextXY(xMax-414,yMax-185,' b=');
   SetColor(4);
   Rectangle(xMax-389,yMax-280,xMax-229,yMax-265);{Input "a"}
   SetColor(9);
   Rectangle(xMax-389,yMax-255,xMax-229,yMax-240);{Input "b"}
   Rectangle(xMax-389,yMax-215,xMax-229,yMax-200);{Input "a1"}
   Rectangle(xMax-389,yMax-190,xMax-229,yMax-175);{Input "b1"}
   InputData(386,276,320,267);
   a:=c;
   SetColor(9);
   Rectangle(xMax-389,yMax-280,xMax-229,yMax-265);{Input "a"}
   SetColor(4);
   Rectangle(xMax-389,yMax-255,xMax-229,yMax-240);{Input "b"}
   InputData(386,251,320,244);
   b:=c;
   SetColor(9);
   Rectangle(xMax-389,yMax-255,xMax-229,yMax-240);{Input "b"}
   SetColor(4);
   Rectangle(xMax-389,yMax-215,xMax-229,yMax-200);{Input "a1"}
   InputData(386,211,320,206);
   a1:=c;
   SetColor(9);
   Rectangle(xMax-389,yMax-215,xMax-229,yMax-200);{Input "a1"}
   SetColor(4);
   Rectangle(xMax-389,yMax-190,xMax-229,yMax-175);{Input "b1"}
   InputData(386,186,320,180);
   b1:=c;
   SetColor(1);
   Rectangle(xMax-389,yMax-190,xMax-229,yMax-175);{Pole vvoda "b1"}

   PutImage(xmax div 3,yMax-460,p^,NormalPut);{Close a window for input of 
                                                                      data}
   SetColor(1);
   OutPutNewData;
   SetColor(9);
   STR(a:3:3,s);
   SetFillStyle(1,0);
   Bar(51,314,154,327);
   OutTextXY(54,317,s);{a output}
   STR(b:3:3,s);
   Bar(51,336,154,349);
   OutTextXY(54,339,s);{b output}
   STR(a1:3:3,s);
   Bar(51,379,154,392);
   OutTextXY(54,382,s);{a1 output}
   STR(b1:3:3,s);
   Bar(51,401,154,414);
   OutTextXY(54,404,s);{B1 output}
  end;

{Management buttons}
procedure Choose;
 begin
  repeat
   ch:=ReadKey;
   if ch<>#0 then
     case ch of
       'N','n': begin
                 iChoose:=6400;
                 NewData;
                end;
       'D','d': begin
                 iChoose:=6401;
                 DrawGraphic;
                end;
       'C','c': begin
                 iChoose:=6402;
                 Clear;
                end;
       'E','e': iChoose:=6403;
           
#13: case iChoose mod 4 of
                   0: NewData;
                   1: DrawGraphic;
                   2: Clear;
                   3: Halt;
                end;
     end
   else
     begin
      ch:=ReadKey;
      case ch of
       #75:iChoose:=iChoose-1;
       #77:iChoose:=iChoose+1;
      end;
     end;
   
Buttons(iChoose mod 4);
   Delay(10);
  until (ch=#27) or (Upcase(ch) = 'E');
 end;

Begin
 GraphInit;{Inicialization of Graph rejime}
 Maket;{General frame}
 DrawKoordinata;{Coordinate plane}
 Buttons(iChoose mod 4);{Buttons}
 iChoose:=6400;
 Choose;{Management buttons}
 CloseGraph;
End.
