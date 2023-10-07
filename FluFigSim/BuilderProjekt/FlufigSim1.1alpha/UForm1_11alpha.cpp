//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UForm1_11alpha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UFrame1_11alpha"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    Interpoli1 = new Interpoli();
    Interpoli2 = new Interpoli();
    Interpoli3 = new Interpoli();
    Interpoli4 = new Interpoli();
    Interpoli5 = new Interpoli();
    Interpoli6 = new Interpoli();
    Interpoli_N = Interpoli1;
    Interpoli1->Aufloesungy = 1;
    Interpoli1->Kommastellen =0;
    Interpoli1->max_y = 360;
    Interpoli1->min_y = -360;
    Interpoli1->Einheity = "�/s";
    Interpoli2->Aufloesungy = 1;
    Interpoli2->Kommastellen =0;
    Interpoli2->max_y = 360;
    Interpoli2->min_y = -360;
    Interpoli2->Einheity = "�/s";
    Interpoli3->Aufloesungy = 1;
    Interpoli3->Kommastellen =0;
    Interpoli3->max_y = 360;
    Interpoli3->min_y = -360;
    Interpoli3->Einheity = "�/s";
    Interpoli4->Aufloesungy = 0.075f;
    Interpoli4->Kommastellen =2;
    Interpoli4->max_y = 20;
    Interpoli4->min_y = -20;
    Interpoli4->Einheity = "m";
    Interpoli5->Aufloesungy = 0.075f;
    Interpoli5->Kommastellen =2;
    Interpoli5->max_y = 20;
    Interpoli5->min_y = -20;
    Interpoli5->Einheity = "m";
    Interpoli6->Aufloesungy = 0.075f;
    Interpoli6->Kommastellen =2;
    Interpoli6->max_y = 20;
    Interpoli6->min_y = -20;
    Interpoli6->Einheity = "m";
    Aufloesungx = 20;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    getcwd(aktVerzeich, MAXPATH); //aktuelles Arbeitsverzeichnis merken

    SaveDialog1->FileName = "FlugFig0";
    Frame11->PaintBox1->Height = 720;
    Frame11->PaintBox1->Width = 2000;
    Frame11->Height = Form1->ClientHeight -10;
    Frame11->Width = Form1->ClientWidth -130;
    NeuKurven();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    int boxantwort = 7;
    if (flggesp == 0)
    {
        boxantwort = Application->MessageBox("Sollen die alten Kurven vorher gespeichert werden?",
                                             "Beenden", MB_YESNO);
        if(boxantwort == 6)
        {
           if (SaveDialog1->FileName == "FlugFig0")
           {
              if(SaveDialog1->Execute()==1)
              {SpeichernKurven();}
           }
           else
           { SpeichernKurven();}
        }
    }
    delete Interpoli1;
    delete Interpoli2;
    delete Interpoli3;
    delete Interpoli4;
    delete Interpoli5;
    delete Interpoli6;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{
    Interpoli_N = Interpoli1;
    Panel4->Color = clRed;
    Panel5->Color = clRed;
    AllesNeuZeichnen();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton6Click(TObject *Sender)
{
    Interpoli_N = Interpoli2;
    Panel4->Color = clYellow;
    Panel5->Color = clYellow;
    AllesNeuZeichnen();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton5Click(TObject *Sender)
{
   Interpoli_N = Interpoli3;
   Panel4->Color = clBlue;
   Panel5->Color = clBlue;
   AllesNeuZeichnen();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton7Click(TObject *Sender)
{
   Interpoli_N = Interpoli4;
   Panel4->Color = clLime;
   Panel5->Color = clLime;
   AllesNeuZeichnen();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton8Click(TObject *Sender)
{
   Interpoli_N = Interpoli5;
   Panel4->Color = clFuchsia;
   Panel5->Color = clFuchsia;
   AllesNeuZeichnen();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton9Click(TObject *Sender)
{
   Interpoli_N = Interpoli6;
   Panel4->Color = clTeal;
   Panel5->Color = clTeal;
   AllesNeuZeichnen();
}
//---------------------------------------------------------------------------
void TForm1::AllesNeuZeichnen()
{
   EditorLeerZeichnen();
   KurveNeuZeichnen(Interpoli1);
   KurveNeuZeichnen(Interpoli2);
   KurveNeuZeichnen(Interpoli3);
   KurveNeuZeichnen(Interpoli4);
   KurveNeuZeichnen(Interpoli5);
   KurveNeuZeichnen(Interpoli6);
   KurveNeuZeichnen(Interpoli_N);
   HilfsBildZeichnen(0);
   Panel4->Caption = IntToStr(Interpoli_N->LesenAnzPunkte());
   Panel5->Caption = IntToStr(Interpoli_N->LesenAnzAusgP());
}
//---------------------------------------------------------------------------
void TForm1::EditorLeerZeichnen()
{
    //Schwarzer Ramen
    Frame11->PaintBox1->Canvas->Pen->Color = clBlack;
    Frame11->PaintBox1->Canvas->Pen->Width = 2;
    Frame11->PaintBox1->Canvas->Rectangle(1, 1,Frame11->PaintBox1->Width-1, Frame11->PaintBox1->Height-1);

     //Gitter
     Frame11->PaintBox1->Canvas->Pen->Color = clGray;
     Frame11->PaintBox1->Canvas->Pen->Width = 1;
     Frame11->PaintBox1->Canvas->MoveTo(0,360);
     Frame11->PaintBox1->Canvas->LineTo(2000,360);
     Frame11->PaintBox1->Canvas->MoveTo(0,360-Interpoli_N->max_y/Interpoli_N->Aufloesungy);
     Frame11->PaintBox1->Canvas->LineTo(2000,360-Interpoli_N->max_y/Interpoli_N->Aufloesungy);
     Frame11->PaintBox1->Canvas->MoveTo(0,360-Interpoli_N->min_y/Interpoli_N->Aufloesungy);
     Frame11->PaintBox1->Canvas->LineTo(2000,360-Interpoli_N->min_y/Interpoli_N->Aufloesungy);
}
//---------------------------------------------------------------------------
void TForm1::KurveNeuZeichnen(Interpoli *interpoli)
{
       int anzausgp = 0;
       int anzeingp = 0;
       int einx,einy;

       anzeingp = interpoli->LesenAnzPunkte();
       anzausgp = interpoli->LesenAnzAusgP();

       if (interpoli == Interpoli1)
       {Frame11->PaintBox1->Canvas->Pen->Color = clRed;}
       else if (interpoli == Interpoli2)
       {Frame11->PaintBox1->Canvas->Pen->Color = clYellow;}
       else if (interpoli == Interpoli3)
       {Frame11->PaintBox1->Canvas->Pen->Color = clBlue;}
        else if (interpoli == Interpoli4)
       {Frame11->PaintBox1->Canvas->Pen->Color = clLime;}
        else if (interpoli == Interpoli5)
       {Frame11->PaintBox1->Canvas->Pen->Color = clFuchsia;}
       else if (interpoli == Interpoli6)
       {Frame11->PaintBox1->Canvas->Pen->Color = clTeal;}

       if ( anzausgp > 2)
       {
         Frame11->PaintBox1->Canvas->Pen->Width = 4;
         for (int i=0; i<anzeingp;i++)
         {
           einx = interpoli->EinpXLesen(i);
           einy = interpoli->EinpYLesen(i);
           Frame11->PaintBox1->Canvas->MoveTo(einx,einy);
           Frame11->PaintBox1->Canvas->Ellipse(einx-1,einy-1,einx+1,einy+1);
         }
         if (RadioButtonLinie->Checked == true)
         {
           Frame11->PaintBox1->Canvas->Pen->Width = 1;
           Frame11->PaintBox1->Canvas->MoveTo(interpoli->AusgPXLesen(0), interpoli->AusgPYLesen(0));
           for (int i=0; i<anzausgp;i++)
           {
             Frame11->PaintBox1->Canvas->LineTo(interpoli->AusgPXLesen(i), interpoli->AusgPYLesen(i));
           }
         }
         else if (RadioButtonPunkte->Checked == true)
         {
           Frame11->PaintBox1->Canvas->Pen->Width = 2;
           for (int i=0; i<anzausgp;i++)
           {
              einx = interpoli->AusgPXLesen(i);
              einy = interpoli->AusgPYLesen(i);
              Frame11->PaintBox1->Canvas->MoveTo(einx,einy);
              Frame11->PaintBox1->Canvas->Ellipse(einx-1,einy-1,einx+1,einy+1);
           }
         }
       }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Frame11PaintBox1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//Punkte Setzen
  if (RadioButton1->Checked == true)
   {
     Interpoli_N->NeuerPunkt(X,Y);
     AllesNeuZeichnen();
     flggesp = 0;
   }
//Punkte Schieben
   if (RadioButton2->Checked == true)
   {
     AllesNeuZeichnen();
     Frame11->PaintBox1->Canvas->Pen->Color = clLime;

     SchiebPunkt = Interpoli_N-> PunktUmCursor(X,Y);
     if (SchiebPunkt > -1)
     {
       Frame11->PaintBox1->Canvas->Ellipse(Interpoli_N->EinpXLesen(SchiebPunkt)-3,
                                     Interpoli_N->EinpYLesen(SchiebPunkt)-3,
                                     Interpoli_N->EinpXLesen(SchiebPunkt)+3,
                                     Interpoli_N->EinpYLesen(SchiebPunkt)+3);
     }
   }
//Punkte L�schen
   if (RadioButton3->Checked == true)
   {
     SchiebPunkt = Interpoli_N->PunktUmCursor(X,Y);
     if (SchiebPunkt > -1)
     {Interpoli_N->PunktLoeschen(SchiebPunkt);}
     AllesNeuZeichnen();
     flggesp = 0;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Frame11PaintBox1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
     div_t x;
     int kommafaktor = 1;
     x = div(X * Aufloesungx,1000);
     Panel2->Caption = IntToStr(x.quot) + "s " +IntToStr(x.rem) + "ms";

     ldiv_t y;
     float y_echt;
     int y_vorkomma, y_nachkomma;
     y_echt = (360-Y) * Interpoli_N->Aufloesungy;
     if (Interpoli_N->Kommastellen == 0)
     {
        y_vorkomma = y_echt;
        Panel3->Caption = IntToStr(y_vorkomma) + Interpoli_N->Einheity;
     }
     else
     {
       for (int i=0; i<Interpoli_N->Kommastellen;i++)
         {kommafaktor = kommafaktor *10;}
       y_echt = y_echt * kommafaktor;
       y = ldiv (y_echt, kommafaktor);
       y_vorkomma = y.quot;
       y_nachkomma = y.rem;
       Panel3->Caption = IntToStr(y_vorkomma) + "." + IntToStr(abs(y_nachkomma)) +Interpoli_N->Einheity;
     }

     HilfsBildZeichnen(360-Y);

     if (RadioButton2->Checked == true && SchiebPunkt > -1)
     {

       Interpoli_N->PunktVerschieben(SchiebPunkt,X,Y);
       AllesNeuZeichnen();
       flggesp = 0;
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Frame11PaintBox1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    SchiebPunkt = -1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Frame11PaintBox1Paint(TObject *Sender)
{
     AllesNeuZeichnen();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Neu1Click(TObject *Sender)
{
     int boxantwort = 7;
     if (flggesp == 0)
     {
        boxantwort = Application->MessageBox("Sollen die alten Kurven vorher gespeichert werden?",
                                             "Neue Figur", MB_YESNOCANCEL);
        if(boxantwort == 6)
        {
           if (SaveDialog1->FileName == "FlugFig0")
           {
              if(SaveDialog1->Execute()==1)
              {SpeichernKurven();}
           }
           else
           { SpeichernKurven();}
        }
     }
     if (boxantwort == 6 || boxantwort == 7)
     {
       NeuKurven();
       SaveDialog1->FileName = "FlugFig0";
     }
}
//---------------------------------------------------------------------------
void TForm1::NeuKurven(void)
{
     Interpoli *interpoli_n;
     for (int i=0; i<6; i++)
     {
       switch (i)
       {
          case 0: interpoli_n = Interpoli1;
                  break;
          case 1: interpoli_n = Interpoli2;
                  break;
          case 2: interpoli_n = Interpoli3;
                  break;
          case 3: interpoli_n = Interpoli4;
                  break;
          case 4: interpoli_n = Interpoli5;
                  break;
          case 5: interpoli_n = Interpoli6;
                  break;
       }
       interpoli_n->Initialisieren();
       interpoli_n->NeuerPunkt(0,360);
       interpoli_n->NeuerPunkt(500,360);
       interpoli_n->NeuerPunkt(1000,360);
       interpoli_n->NeuerPunkt(1500,360);
       interpoli_n->NeuerPunkt(2000,360);
     }
     AllesNeuZeichnen();
     Form1->Caption = "FluFigSim Editor []";
      Form2->Caption = "FluFifSim 3D-Animation []";
     flggesp = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Speichern1Click(TObject *Sender)
{
     if (SaveDialog1->FileName == "FlugFig0")
     {
        if(SaveDialog1->Execute()==1)
        {SpeichernKurven();}
     }
     else
     { SpeichernKurven();}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Speichern2Click(TObject *Sender)
{
    if(SaveDialog1->Execute()==1)
    {SpeichernKurven();}
}
//---------------------------------------------------------------------------
void TForm1::SpeichernKurven()
{
    TStringList *KurvStringList = new TStringList;
    try
    {
      Interpoli *interpoli_n;
      for (int i=0; i<6; i++)
      {
        switch (i)
        {       
          case 0: interpoli_n = Interpoli1;
                  KurvStringList->Add("K1");
                  break;
          case 1: interpoli_n = Interpoli2;
                  KurvStringList->Add("K2");

                  break;
          case 2: interpoli_n = Interpoli3;
                  KurvStringList->Add("K3");
                  break;
          case 3: interpoli_n = Interpoli4;
                  KurvStringList->Add("K4");
                  break;
          case 4: interpoli_n = Interpoli5;
                  KurvStringList->Add("K5");
                  break;
          case 5: interpoli_n = Interpoli6;
                  KurvStringList->Add("K6");
                  break;
        }
        KurvStringList->Add(" ");
        for(int ii=0; ii<interpoli_n->LesenAnzPunkte();ii++)
        {
           KurvStringList->Add(IntToStr(interpoli_n->EinpXLesen(ii)));
           KurvStringList->Add(IntToStr(interpoli_n->EinpYLesen(ii)));
           KurvStringList->Add(" ");
        }
        KurvStringList->Add("ende");
        KurvStringList->Add(" ");
      }
      KurvStringList->SaveToFile(SaveDialog1->FileName);
      Form1->Caption = "FluFigSim Editor [" + SaveDialog1->FileName + "]";
      Form2->Caption = "FluFigSim 3D-Animation [" + SaveDialog1->FileName + "]";
      flggesp = 1;
    }
    __finally
    {
      delete KurvStringList;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Oeffnen1Click(TObject *Sender)
{
     int boxantwort = 7;
     if (flggesp == 0)
     {
        boxantwort = Application->MessageBox("Sollen die alten Kurven vorher gespeichert werden?",
                                             "Oeffnen", MB_YESNOCANCEL);
        if(boxantwort == 6)
        {
           if (SaveDialog1->FileName == "FlugFig0")
           {
              if(SaveDialog1->Execute()==1)
              {SpeichernKurven();}
           }
           else
           { SpeichernKurven();}
        }
     }
     if (boxantwort == 6 || boxantwort == 7)
     {
       if(OpenDialog1->Execute() ==1)
       OeffnenKurven();
     }
}
//---------------------------------------------------------------------------
void TForm1::OeffnenKurven()
{
   int zaehler;
   Interpoli *interpoli_n;
   AnsiString x;
   AnsiString y;
   TStringList *KurvStringList = new TStringList;
    try
    {
      KurvStringList->LoadFromFile(OpenDialog1->FileName);

      int i;
      //for (i=0; i < 10; i++);
      for (i=0; i < KurvStringList->Count-1; i++)
      {
         if (KurvStringList->Strings[i] == "K1")
         {
            interpoli_n = Interpoli1;
            interpoli_n->Initialisieren();
         }
         else if (KurvStringList->Strings[i] == "K2")
         {
            interpoli_n = Interpoli2;
            interpoli_n->Initialisieren();
            zaehler = 0;
         }
         else if (KurvStringList->Strings[i] == "K3")
         {
            interpoli_n = Interpoli3;
            interpoli_n->Initialisieren();
            zaehler = 0;
         }
         else if (KurvStringList->Strings[i] == "K4")
         {
            interpoli_n = Interpoli4;
            interpoli_n->Initialisieren();
            zaehler = 0;
         }
         else if (KurvStringList->Strings[i] == "K5")
         {
            interpoli_n = Interpoli5;
            interpoli_n->Initialisieren();
            zaehler = 0;
         }
         else if (KurvStringList->Strings[i] == "K6")
         {
            interpoli_n = Interpoli6;
            interpoli_n->Initialisieren();
            zaehler = 0;
         }
         else if (KurvStringList->Strings[i] == " " )
         {
            zaehler = 0;
         }
         else if (KurvStringList->Strings[i] == "ende" )
         {
            zaehler = 0;
         }
         else // (KurvStringList->Strings[i] != " ")
         {
            zaehler++;
         }
         if (zaehler ==1)
         { x = KurvStringList->Strings[i];}
         else if (zaehler ==2)
         {
           y = KurvStringList->Strings[i];
           interpoli_n->NeuerPunkt(StrToInt(x),StrToInt(y));
         }
      }
      Form1->Caption = "FluFigSim Editor [" + OpenDialog1->FileName + "]";
      Form2->Caption = "FluFifSim 3D-Animation [" + OpenDialog1->FileName + "]";
      flggesp = 1;
      SaveDialog1->FileName = OpenDialog1->FileName;
    }
    __finally
    {
      delete KurvStringList;
    }
    AllesNeuZeichnen();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButtonLinieClick(TObject *Sender)
{
    AllesNeuZeichnen();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButtonPunkteClick(TObject *Sender)
{
    AllesNeuZeichnen();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Beenden1Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------
void TForm1::HilfsBildZeichnen(int pos)
{
 int richtung, richtung1;
 richtung1 = richtung;
 if (pos < -2)
 {richtung = -1;}
 else if (pos > 2)
 {richtung = 1;}
 else
 {richtung = 0;}
 if(richtung1 != richtung)
 {
   //Pfad f�r Textur-Bild (gleicherpfad wie exe-Datei)
   StrCopy (targaVerzeich,aktVerzeich);
   StrCat (targaVerzeich,"\\");
   StrCat(targaVerzeich,"Targa.jpg");
   //Targa-Bild laden
   TJPEGImage *jp = new TJPEGImage();
   jp->LoadFromFile(targaVerzeich);

   Graphics::TBitmap *Bitmap1 = new Graphics::TBitmap();
   Bitmap1->Assign(jp);

   Image1->Visible = true;

   Image1->Picture->Assign(Bitmap1);

   delete jp;
   delete Bitmap1; 

   Image1->Canvas->Pen->Width = 3;
   Image1->Canvas->Pen->Color = clNavy;
   if (Interpoli_N == Interpoli1)
   {
     Image1->Canvas->MoveTo(5,30);
     Image1->Canvas->LineTo(125,30);
     switch(richtung)
     {
       case  0:
                 break;

       case 1:   Image1->Canvas->Pen->Color = clAqua;
                 Image1->Canvas->Arc(50,40,80,100,50,40,70,100);
                 Image1->Canvas->MoveTo(47,55);
                 Image1->Canvas->LineTo(55,45);
                 Image1->Canvas->LineTo(61,55);
                 break;
       case  -1: Image1->Canvas->Pen->Color = clAqua;
                 Image1->Canvas->Arc(50,40,80,100,50,40,70,80);
                 Image1->Canvas->MoveTo(67,94);
                 Image1->Canvas->LineTo(75,90);
                 Image1->Canvas->LineTo(76,96);
                 break;
     }
   }
   else if (Interpoli_N == Interpoli2)
   {
     Image1->Canvas->MoveTo(60,68);
     Image1->Canvas->LineTo(70,70);
     switch(richtung)
     {
       case  0:
                 break;
       case 1:   Image1->Canvas->Pen->Color = clAqua;
                 Image1->Canvas->Arc(40,45,90,95,120,60,120,80);
                 Image1->Canvas->MoveTo(81,64);
                 Image1->Canvas->LineTo(90,68);
                 Image1->Canvas->LineTo(92,61);
                 break;
       case  -1: Image1->Canvas->Pen->Color = clAqua;
                 Image1->Canvas->Arc(40,45,90,95,120,60,120,80);
                 Image1->Canvas->MoveTo(81,76);
                 Image1->Canvas->LineTo(90,72);
                 Image1->Canvas->LineTo(92,79);
                 break;
     }
   }
   else if (Interpoli_N == Interpoli3)
   {
     Image1->Canvas->MoveTo(65,5);
     Image1->Canvas->LineTo(65,135);
     switch(richtung)
     {
       case  0:
                 break;
       case 1:   Image1->Canvas->Pen->Color = clAqua;
                 Image1->Canvas->Arc(40,50,100,80,40,50,100,80);
                 Image1->Canvas->MoveTo(36,58);
                 Image1->Canvas->LineTo(49,52);
                 Image1->Canvas->LineTo(48,64);
                 break;
       case  -1: Image1->Canvas->Pen->Color = clAqua;
                 Image1->Canvas->Arc(40,50,100,80,40,50,100,80);
                 Image1->Canvas->MoveTo(81,73);
                 Image1->Canvas->LineTo(93,72);
                 Image1->Canvas->LineTo(92,80);
                 break;
     }
   }
   else if (Interpoli_N == Interpoli4)
   {
      switch(richtung)
     {
       case  0:  Image1->Canvas->MoveTo(5,30);
                 Image1->Canvas->LineTo(125,30);
                 break;
       case -1:  Image1->Canvas->MoveTo(5,100);
                 Image1->Canvas->LineTo(125,100);
                 break;
       case  1:  Image1->Canvas->MoveTo(5,10);
                 Image1->Canvas->LineTo(125,10);
                 break;
     }
   }
   else if (Interpoli_N == Interpoli5)
   {
     switch(richtung)
     {
       case  0:  Image1->Canvas->MoveTo(65,5);
                 Image1->Canvas->LineTo(65,135);
                 break;
       case -1:  Image1->Canvas->MoveTo(120,5);
                 Image1->Canvas->LineTo(120,135);
                 break;
       case  1:  Image1->Canvas->MoveTo(10,5);
                 Image1->Canvas->LineTo(10,135);
                 break;
     }
   }
   else if (Interpoli_N == Interpoli6)
   {
     switch(richtung)
     {
       case  0:  Image1->Canvas->MoveTo(60,30);
                 Image1->Canvas->LineTo(70,32);
                 break;
       case -1:  Image1->Canvas->MoveTo(60,100);
                 Image1->Canvas->LineTo(70,102);
                 break;
       case  1:  Image1->Canvas->MoveTo(60,10);
                 Image1->Canvas->LineTo(70,12);
                 break;
     }
   }
 }
}
//---------------------------------------------------------------------------




