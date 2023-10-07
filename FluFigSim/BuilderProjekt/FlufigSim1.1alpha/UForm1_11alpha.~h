//---------------------------------------------------------------------------

#ifndef UForm1_11alphaH
#define UForm1_11alphaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "NatCubSplInt11alpha.h"
#include <jpeg.hpp>
#include "dir.h"
#include "UForm2_11alpha.h"
#include <Dialogs.hpp>
#include <Menus.hpp>
#include "UFrame1_11alpha.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
        TGroupBox *GroupBox1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TPanel *Panel2;
        TPanel *Panel3;
        TLabel *Label1;
        TLabel *Label2;
        TPanel *Panel4;
        TPanel *Panel5;
        TLabel *Label3;
        TLabel *Label4;
        TGroupBox *GroupBox2;
        TRadioButton *RadioButton4;
        TRadioButton *RadioButton5;
        TRadioButton *RadioButton6;
        TRadioButton *RadioButton7;
        TFrame1 *Frame11;
        TMainMenu *MainMenu1;
        TMenuItem *Datei1;
        TMenuItem *Neu1;
        TMenuItem *Oeffnen1;
        TMenuItem *Speichern1;
        TMenuItem *Speichern2;
        TMenuItem *Beenden1;
        TSaveDialog *SaveDialog1;
        TOpenDialog *OpenDialog1;
        TRadioButton *RadioButton8;
        TButton *Button1;
        TGroupBox *GroupBox3;
        TRadioButton *RadioButtonLinie;
        TRadioButton *RadioButtonPunkte;
        TImage *Image1;
        TRadioButton *RadioButton9;
        void __fastcall Frame11PaintBox1MouseDown(TObject *Sender,
        TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Frame11PaintBox1MouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall Frame11PaintBox1MouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Frame11PaintBox1Paint(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Neu1Click(TObject *Sender);
        void __fastcall RadioButton4Click(TObject *Sender);
        void __fastcall RadioButton6Click(TObject *Sender);
        void __fastcall RadioButton5Click(TObject *Sender);
        void __fastcall Speichern1Click(TObject *Sender);
        void __fastcall Speichern2Click(TObject *Sender);
        void __fastcall Oeffnen1Click(TObject *Sender);
        void __fastcall RadioButton7Click(TObject *Sender);
        void __fastcall RadioButton8Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall RadioButtonLinieClick(TObject *Sender);
        void __fastcall RadioButtonPunkteClick(TObject *Sender);
        void __fastcall Beenden1Click(TObject *Sender);
        void __fastcall RadioButton9Click(TObject *Sender);
private:	// Anwender-Deklarationen

        Interpoli *Interpoli_N;       //Zeiger auf ausgewähltes Kurven-Objekt
        int SchiebPunkt, Aufloesungx;
        bool flggesp;
        void NeuKurven(void);
        void SpeichernKurven(void);
        void OeffnenKurven(void);
        void EditorLeerZeichnen();
        void KurveNeuZeichnen(Interpoli *interpoli);
        void AllesNeuZeichnen();
        void HilfsBildZeichnen(int pos);
public:		// Anwender-Deklarationen
        __fastcall TForm1(TComponent* Owner);
        Interpoli *Interpoli1;
        Interpoli *Interpoli2;
        Interpoli *Interpoli3;
        Interpoli *Interpoli4;
        Interpoli *Interpoli5;
        Interpoli *Interpoli6;
        char aktVerzeich[MAXPATH];
        char targaVerzeich[MAXPATH];
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
