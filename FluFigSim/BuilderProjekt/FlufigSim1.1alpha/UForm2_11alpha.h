//---------------------------------------------------------------------------

#ifndef UForm2_11alphaH
#define UForm2_11alphaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "OpenGLPanel.h"
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "NatCubSplInt11alpha.h"
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
        TOpenGLPanel *OpenGLPanel1;
        TTimer *Timer1;
        TScrollBar *ScrollBarSpeed;
        TScrollBar *ScrollBarBildrate;
        TButton *ButtonPlay;
        TButton *ButtonStop;
        TLabel *LabelZeitlupe;
        TLabel *LabelBldpsek;
        TLabel *LabelSpeed;
        TLabel *LabelBldrate;
        TButton *ButtonDauerPlay;
        TGroupBox *GroupBoxSimZeit;
        TLabel *LabelSimSek;
        TLabel *LabelSimMili;
        TLabel *LabelDPunkt1;
        TGroupBox *GroupBoxEchtz;
        TLabel *LabelEchtMili;
        TLabel *LabelDPunkt2;
        TLabel *LabelEchtSek;
        TGroupBox *GroupBox1;
        TCheckBox *CheckBoxHoch;
        TCheckBox *CheckBoxLang;
        TCheckBox *CheckBoxQuer;
        TGroupBox *GroupBoxKamF;
        TRadioButton *RadioButtonKamAut;
        TRadioButton *RadioButtonKamMan;
        TGroupBox *GroupBoxKam;
        TButton *ButtonUP;
        TButton *ButtonRight;
        TButton *ButtonLeft;
        TButton *ButtonDown;
        TButton *ButtonZoomIn;
        TButton *ButtonZoomOut;
        TButton *ButtonEditor;
        void __fastcall OpenGLPanel1Init(TObject *Sender);
        void __fastcall OpenGLPanel1Paint(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall ButtonPlayClick(TObject *Sender);
        void __fastcall ButtonStopClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ScrollBarSpeedChange(TObject *Sender);
        void __fastcall ScrollBarBildrateChange(TObject *Sender);
        void __fastcall ButtonDauerPlayClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall RadioButtonKamManClick(TObject *Sender);
        void __fastcall RadioButtonKamAutClick(TObject *Sender);
        void __fastcall ButtonUPMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ButtonUPMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ButtonDownMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ButtonDownMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ButtonLeftMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ButtonLeftMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ButtonRightMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ButtonRightMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ButtonZoomInMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ButtonZoomInMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ButtonZoomOutMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ButtonZoomOutMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ButtonEditorClick(TObject *Sender);
private: 
         // ModelZeichnen
         GLfloat   Background[4];  //Hintergrundfarbe
         GLubyte bits[512][256][4];//Speicher für SchirmTextur
         GLuint texture1;          //Textur für Schirm
         GLUnurbsObj* NurbA;       //Form des Schirms
         char bildVerzeich[MAXPATH];
         //Bewegungsvariabeln
         GLdouble drehmatrix[16]; //Matrix fuer momentane Orientierung
         GLfloat   SchrittQuera, SchrittHocha, SchrittLaengsa; //Drehwerte nach Zeitlupe
         float   SchrittQuera1, SchrittHocha1, SchrittLaengsa1;//Drehwerte aus Kurve
         GLfloat   PosiQuer, PosiLang, PosiHocha; // Effektiv gezeichnete Achsen--Position
         float  PosiQuer1, PosiLang1, PosiHocha1; //Achsen-Position aud Kurve

         //Bild-Timer, Bewegung aus Kurve und aus Zeitlupenfaktor berechnen:
         int brBildrate, brSpeed, brZeitLpInd, msppix_x;
         int zeitms;
         bool lookatflg1, urflg1;
         void BewegungBerechnen();
         void BewegungAusKurve();

         //Play,Stop,Pause,Animationseinstellungen:
         bool dauerplayflg, playflg;
         void AnimPlay();
         void AnimPause();
         void AnimStop();
         void AnimGrundpos();
         void ModelZeichnen();

         //Berechnen der Kamera-Korrektur:
         GLint viewport[4];
         GLdouble mvmatrix[16], projmatrix[16];
         GLdouble winx, winy, winz;
         GLdouble winx1, winy1, winz1, winx2, winy2,winz2;
         GLdouble winspeedx, winspeedy, winspeedz;
         GLdouble winxcor, winycor, winzcor, winxcorm, winycorm, winzcorm;
         void KameraKorrBerech();

public:		// Anwender-Deklarationen
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
