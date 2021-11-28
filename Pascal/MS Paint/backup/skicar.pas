unit skicar;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls,
  Buttons, ComCtrls;

type

  { TForm4 }

  TForm4 = class(TForm)
    Cervena: TSpeedButton;
    Cierna: TSpeedButton;
    Biela: TSpeedButton;
    Fialova: TSpeedButton;
    Hneda: TSpeedButton;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Modra: TSpeedButton;
    Ceruza: TSpeedButton;
    Guma: TSpeedButton;
    Line: TSpeedButton;
    Obdlznik: TSpeedButton;
    Elipsa: TSpeedButton;
    ObdlznikPlny: TSpeedButton;
    ElipsaPlna: TSpeedButton;
    Zelena: TSpeedButton;
    Ruzova: TSpeedButton;
    Oranzova: TSpeedButton;
    Zlta: TSpeedButton;
    Stetec: TSpeedButton;
    SpeedButton2: TSpeedButton;
    Image1: TImage;
    Hrubka: TTrackBar;
    procedure BielaClick(Sender: TObject);
    procedure CeruzaClick(Sender: TObject);
    procedure CervenaClick(Sender: TObject);
    procedure CiernaClick(Sender: TObject);
    procedure ElipsaClick(Sender: TObject);
    procedure ElipsaPlnaClick(Sender: TObject);
    procedure FialovaClick(Sender: TObject);
    procedure GumaClick(Sender: TObject);
    procedure HnedaClick(Sender: TObject);
    procedure Image1MouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure Image1MouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer
      );
    procedure Image1MouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure LineClick(Sender: TObject);
    procedure ModraClick(Sender: TObject);
    procedure ObdlznikClick(Sender: TObject);
    procedure ObdlznikPlnyClick(Sender: TObject);
    procedure OranzovaClick(Sender: TObject);
    procedure RuzovaClick(Sender: TObject);
    procedure ZelenaClick(Sender: TObject);
    procedure ZltaClick(Sender: TObject);
    procedure SpeedButton2Click(Sender: TObject);
    procedure StetecClick(Sender: TObject);
  private

  public

  end;

var
  Form4: TForm4;
  nastroj: char='s';
  x1, y1: integer;

implementation

{$R *.lfm}

{ TForm4 }

procedure TForm4.Image1MouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
begin
     Image1.Canvas.Pen.Width:=0;
     if (Shift=[ssLeft]) and (nastroj='s') then Image1.canvas.Ellipse(X-Hrubka.Position,Y-Hrubka.Position,X+Hrubka.Position,Y+Hrubka.Position);
     if (Shift=[ssLeft]) and (nastroj='c') then Image1.Canvas.Rectangle(X-Hrubka.Position,Y-Hrubka.Position,X+Hrubka.Position,Y+Hrubka.Position);
end;

procedure TForm4.Image1MouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
     x1:=x;
     y1:=y;
end;

procedure TForm4.Image1MouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
     if nastroj='l' then Image1.Canvas.Line(x1, y1, x, y)
     else if (nastroj='e') or (nastroj='g') then Image1.Canvas.Ellipse(x1,y1,x,y)
     else if (nastroj='o') or (nastroj='k') then Image1.Canvas.Rectangle(x1,y1,x,y);
end;

procedure TForm4.LineClick(Sender: TObject);
begin
     nastroj:='l'
end;

procedure TForm4.ObdlznikClick(Sender: TObject);
begin
     nastroj:='o';
     Image1.Canvas.Brush.Style:=bsClear;
end;

procedure TForm4.ObdlznikPlnyClick(Sender: TObject);
begin
     nastroj:='k';
     Image1.Canvas.Brush.Style:=bsSolid;
end;

procedure TForm4.ElipsaClick(Sender: TObject);
begin
     nastroj:='e';
     Image1.Canvas.Brush.Style:=bsClear;
end;

procedure TForm4.ElipsaPlnaClick(Sender: TObject);
begin
     nastroj:='g';
     Image1.Canvas.Brush.Style:=bsSolid;
end;

procedure TForm4.SpeedButton2Click(Sender: TObject);
begin
  Image1.Canvas.Brush.Color:=clWhite;
  Image1.Canvas.Rectangle(0,0,992,596);
  Image1.Canvas.Brush.Color:=clBlack;
end;

procedure TForm4.StetecClick(Sender: TObject);
begin
     nastroj := 's';
     Image1.Canvas.Pen.Color:=clBlack;
     Image1.Canvas.Brush.Color:=clBlack;
end;

procedure TForm4.CeruzaClick(Sender: TObject);
begin
     nastroj := 'c';
     Image1.Canvas.Pen.Color:=clBlack;
     Image1.Canvas.Brush.Color:=clBlack;
end;

procedure TForm4.BielaClick(Sender: TObject);
begin
     Image1.Canvas.Pen.Color:=clWhite;
     Image1.Canvas.Brush.Color:=clWhite;
end;

procedure TForm4.CervenaClick(Sender: TObject);
begin
     Image1.Canvas.Pen.Color:=clRed;
     Image1.Canvas.Brush.Color:=clRed;
end;

procedure TForm4.CiernaClick(Sender: TObject);
begin
     Image1.Canvas.Pen.Color:=clBlack;
     Image1.Canvas.Brush.Color:=clBlack;
end;

procedure TForm4.FialovaClick(Sender: TObject);
begin
     Image1.Canvas.Pen.Color:=clPurple;
     Image1.Canvas.Brush.Color:=clPurple;
end;

procedure TForm4.ModraClick(Sender: TObject);
begin
     Image1.Canvas.Pen.Color:=clBlue;
     Image1.Canvas.Brush.Color:=clBlue;
end;

procedure TForm4.OranzovaClick(Sender: TObject);
begin
     Image1.Canvas.Pen.Color:=26367;
     Image1.Canvas.Brush.Color:=26367;
end;

procedure TForm4.RuzovaClick(Sender: TObject);
begin
     Image1.Canvas.Pen.Color:=10256382;
     Image1.Canvas.Brush.Color:=10256382;
end;

procedure TForm4.ZelenaClick(Sender: TObject);
begin
     Image1.Canvas.Pen.Color:=clGreen;
     Image1.Canvas.Brush.Color:=clGreen;
end;

procedure TForm4.ZltaClick(Sender: TObject);
begin
     Image1.Canvas.Pen.Color:=clYellow;
     Image1.Canvas.Brush.Color:=clYellow;
end;

procedure TForm4.GumaClick(Sender: TObject);
begin
     Image1.Canvas.Pen.Color:=clWhite;
     Image1.Canvas.Brush.Color:=clWhite;
end;

procedure TForm4.HnedaClick(Sender: TObject);
begin
     Image1.Canvas.Pen.Color:=2047065;
     Image1.Canvas.Brush.Color:=2047065;
end;

end.

