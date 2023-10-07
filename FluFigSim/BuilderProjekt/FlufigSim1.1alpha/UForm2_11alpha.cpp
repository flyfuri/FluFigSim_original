//---------------------------------------------------------------------------

#include <vcl.h>
#include <dos.h>
#pragma hdrstop

#include "UForm2_11alpha.h"
#include "UForm1_11alpha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "OpenGLPanel"
#pragma resource "*.dfm"
TForm2 *Form2;

  //Form des Schirms Initialisieren

  GLfloat sknotA[22]={0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1};
  GLfloat tknotA[12]={0,0,0,0,0,0,1,1,1,1,1,1};
  GLfloat ctlarrayA[11][6][3]=
  {0.0f,0.9f,0.0f,  0.3f,0.4f,0.78f, 0.8f,0.3f,1.1f,  1.5f,0.1f,1.73f,
   2.5f,0.05f,2.18f, 5.0f,0.0f,2.5f, 7.5f,0.05f,2.18f, 8.5f,0.1f,1.73f,
   9.2f,0.3f,1.1f, 9.7f,0.4f,0.78f,  10.0f,0.9f,0.0f,
   0.0f,1.0f,0.0f,  0.3f,0.9f,0.8f, 0.8f,0.7f,1.2f,  1.5f,0.5f,1.84f,
   2.5f,0.3f,2.28f, 5.0f,0.2f,2.6f, 7.5f,0.3f,2.28f, 8.5f,0.5f,1.84f,
   9.2f,0.7f,1.2f, 9.7f,0.9f,0.8f,  10.0f,1.0f,0.0f,
   0.0f,1.0f,0.0f,  0.3f,0.8f,0.8f, 0.8f,0.8f,1.24f,  1.5f,0.6f,1.88f,
   2.5f,0.65f,2.35f, 5.0f,0.5f,2.7f, 7.5f,0.65f,2.35f, 8.5f,0.6f,1.88f,
   9.2f,0.8f,1.24f, 9.7f,0.8f,0.8f,  10.0f,1.0f,0.0f,
   0.0f,1.0f,0.0f,  0.3f,1.0f,0.72f, 0.8f,1.0f,1.17f,  1.5f,1.0f,1.8f,
   2.5f,1.0f,2.2f, 5.0f,1.0f,2.6f, 7.5f,1.0f,2.2f, 8.5f,1.0f,1.8f,
   9.2f,1.0f,1.17f, 9.7f,1.0f,0.72f,  10.0f,1.0f,0.0f,
   0.0f,1.1f,0.0f,  0.3f,1.1f,0.6f, 0.8f,1.2f,0.9f,  1.5f,1.3f,1.56f,
   2.5f,1.45f,2.0f, 5.0f,1.5f,2.3f, 7.5f,1.45f,2.0, 8.5f,1.3f,1.56f,
   9.2f,1.2f,0.9f, 9.7f,1.1f,0.6f,  10.0f,1.1f,0.0f,
   0.0f,1.1f,0.0f,  0.3f,1.6f,0.5f, 0.8f,1.7f,0.9f,  1.5f,1.9f,1.4f,
   2.5f,1.95f,1.9f, 5.0f,2.0f,2.1f, 7.5f,1.95f,1.8f, 8.5f,1.9f,1.4f,
   9.2f,1.7f,0.3f, 9.7f,1.6f,0.5f,  10.0f,1.1f,0.0f,
   };

   //alte Schirm-Form
  /*  GLfloat ctlarrayA[11][6][3]=
  {0.0f,0.9f,0.0f,  0.3f,0.4f,0.78f, 0.8f,0.3f,1.1f,  1.5f,0.1f,1.73f,
   2.5f,0.05f,2.18f, 5.0f,0.0f,2.5f, 7.5f,0.05f,2.18f, 8.5f,0.1f,1.73f,
   9.2f,0.3f,1.1f, 9.7f,0.4f,0.78f,  10.0f,0.9f,0.0f,
   0.0f,1.0f,0.0f,  0.3f,0.9f,0.8f, 0.8f,0.7f,1.2f,  1.5f,0.5f,1.84f,
   2.5f,0.3f,2.28f, 5.0f,0.2f,2.6f, 7.5f,0.3f,2.28f, 8.5f,0.5f,1.84f,
   9.2f,0.7f,1.2f, 9.7f,0.9f,0.8f,  10.0f,1.0f,0.0f,
   0.0f,1.0f,0.0f,  0.3f,0.8f,0.8f, 0.8f,0.8f,1.24f,  1.5f,0.6f,1.88f,
   2.5f,0.65f,2.35f, 5.0f,0.5f,2.7f, 7.5f,0.65f,2.35f, 8.5f,0.6f,1.88f,
   9.2f,0.8f,1.24f, 9.7f,0.8f,0.8f,  10.0f,1.0f,0.0f,
   0.0f,1.0f,0.0f,  0.3f,1.0f,0.72f, 0.8f,1.0f,1.17f,  1.5f,1.0f,1.8f,
   2.5f,1.0f,2.2f, 5.0f,1.0f,2.6f, 7.5f,1.0f,2.2f, 8.5f,1.0f,1.8f,
   9.2f,1.0f,1.17f, 9.7f,1.0f,0.72f,  10.0f,1.0f,0.0f,
   0.0f,1.1f,0.0f,  0.3f,1.1f,0.6f, 0.8f,1.2f,0.9f,  1.5f,1.3f,1.56f,
   2.5f,1.45f,2.0f, 5.0f,1.5f,2.3f, 7.5f,1.45f,2.0, 8.5f,1.3f,1.56f,
   9.2f,1.2f,0.9f, 9.7f,1.1f,0.6f,  10.0f,1.1f,0.0f,
   0.0f,1.1f,0.0f,  0.3f,1.6f,0.5f, 0.8f,1.7f,0.9f,  1.5f,1.9f,1.4f,
   2.5f,1.95f,1.9f, 5.0f,2.0f,2.1f, 7.5f,1.95f,1.8f, 8.5f,1.9f,1.4f,
   9.2f,1.7f,0.3f, 9.7f,1.6f,0.5f,  10.0f,1.1f,0.0f,
   };  */
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
   Form2->WindowState = wsMaximized;
   Form2->BorderStyle = bsDialog;

   brBildrate = 25; //Bilder pro Sekunde
   brSpeed = 1;     //Zeitlupen-Faktor
   msppix_x = 20;   //Mili-Sekunden pro Pixel (Darstellung im Editor)

   //Pfad f�r Textur-Bild (gleicherpfad wie exe-Datei)
   StrCopy (bildVerzeich,Form1->aktVerzeich);
   StrCat (bildVerzeich,"\\");
   StrCat(bildVerzeich, "schirm.bmp");
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
   //Animations-Initialisierung beim Oeffnen des Animations-Bildschirms
   lookatflg1 = false;
   urflg1 = false;
   dauerplayflg = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::OpenGLPanel1Init(TObject *Sender)
{  //Gr�sse OpenGLPanel
   OpenGLPanel1->Top =20;
   OpenGLPanel1->Left = 130;
   OpenGLPanel1->Height = Form2->ClientHeight-20;
   OpenGLPanel1->Width = ClientWidth-140;
   // aspect (Verh�ltniss H�he/Breite der Projektion)
    double aspect;
    aspect = (OpenGLPanel1->Height == 0) ?
    (double)OpenGLPanel1->Width : (double)OpenGLPanel1->Width/
                                  (double)OpenGLPanel1->Height;
    //Bildausschnitt wahlen
    glViewport(0,0,OpenGLPanel1->Width,OpenGLPanel1->Height);
    //Projektions Volumen festlegen (Betrachtungs-Winkel, Distanzbereich)
    glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluPerspective(40,aspect,1,400.0);
    //Textur Nullen
    glMatrixMode(GL_TEXTURE);
      glLoadIdentity();
    //ModelMatrix Initialisieren
    glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glDrawBuffer(GL_BACK);
      glEnable(GL_DEPTH_TEST);

    //Hintergrundfarbe
    Background[0] = 0.71;
    Background[1] = 0.7;
    Background[2] = 1.0;
    Background[3] = 0.0;

    //Texturinitialisierung
    glEnable(GL_TEXTURE_2D);
    //Textur-Vorlage oeffnen
    Graphics::TBitmap *bitmap = new Graphics::TBitmap();
    bitmap->LoadFromFile(bildVerzeich);
    for(int i = 0; i < 512; i++)
    {
    	for(int j = 0; j < 256; j++)
        {
            bits[i][j][0]= (GLbyte)GetRValue(bitmap->Canvas->Pixels[i][j]);
            bits[i][j][1]= (GLbyte)GetGValue(bitmap->Canvas->Pixels[i][j]);
            bits[i][j][2]= (GLbyte)GetBValue(bitmap->Canvas->Pixels[i][j]);
            bits[i][j][3]= (GLbyte)255;
        }
    }
    delete bitmap;
    //Textur-Einstellungen
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 512, 256, 0, GL_RGBA, GL_UNSIGNED_BYTE, bits);


    //Licht und Schatten
    glShadeModel(GL_SMOOTH); //Schattenmodel jeder Punkt einzeln
    glEnable(GL_NORMALIZE);
    glClearDepth( 1.0 );
    //LichtEinstellungen
    GLfloat  Licht_Ambient[] = {0.2f,0.2f,0.2f,1.0f};
    GLfloat Licht_Diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat Licht_Specular[]= {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat Licht_Position[]= {500.0f, 300.0f, 1000.0f, 0.0f};
    glLightfv( GL_LIGHT0, GL_AMBIENT, Licht_Ambient);
    glLightfv( GL_LIGHT0, GL_DIFFUSE, Licht_Diffuse);
    glLightfv( GL_LIGHT0, GL_SPECULAR,Licht_Specular);
    glLightfv( GL_LIGHT0, GL_POSITION, Licht_Position);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 1.0);
    // Lichtquelle einschalten
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);

    //Material bestimmen (Eigenschaften bezueglichh Licht)
    GLfloat  Mat_Ambient[] = {0.2f,0.2f,0.2f,1.0f};
    GLfloat Mat_Diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat Mat_Specular[]= {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat Mat_Shininess[]= {0.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Mat_Ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Mat_Diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Mat_Specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, Mat_Shininess);

    //Bilschirm leer zeichenen
    glClearColor(Background[0],Background[1],Background[2],Background[3]);
}
//---------------------------------------------------------------------------

//***************************************************************************
//Bild zeichnen:
//***************************************************************************

//---------------------------------------------------------------------------
void __fastcall TForm2::OpenGLPanel1Paint(TObject *Sender)
{
   ModelZeichnen();
}
//---------------------------------------------------------------------------
void TForm2::ModelZeichnen()
{
  glClearColor(Background[0],Background[1],Background[2],Background[3]);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();                        //Matrix0 Nullen
  if (lookatflg1 == false)
  {
    glGetDoublev(GL_MODELVIEW_MATRIX, drehmatrix); //Matrix des letzten Bildes=0
    gluLookAt(0.0,0.0,50.0, 0.0,0.0,-1.0, 0.0,1.0,0.0);
    lookatflg1 = true;
  }
  glTranslatef(winxcor,winycor,winzcor);  //Kamera Verschieben
  glMultMatrixd(drehmatrix);              //Matrix0 mit gespeicherter Matrix des
                                          //letzten Bildes multiplizieren
  //Drehung nach Berechnung aus Kurve
  glTranslatef(0.0,PosiLang,0.0);
  glRotatef(SchrittLaengsa,0.0,0.0,1.0);
  glTranslatef(0.0,-PosiLang,0.0);
  glTranslatef(0.0,PosiQuer,0.0);
  glRotatef(SchrittQuera,1.0,0.0,0.0);
  glTranslatef(0.0,-PosiQuer,0.0);
  glTranslatef(PosiHocha,0.0,0.0);
  glRotatef(SchrittHocha,0.0,1.0,0.0);
  glTranslatef(-PosiHocha,0.0,0.0);

  glGetDoublev(GL_MODELVIEW_MATRIX, drehmatrix); //Matrix des Bildes speichern

  KameraKorrBerech(); //berechnen, um wieviel beim n�chsten Bild die Kamera
                      //geschoben wird
  glPushAttrib(GL_ALL_ATTRIB_BITS); //GL-Status sichern
  glPushMatrix();//Matrix Schirm und Pilot
     glPushMatrix();//Matrix Schirm
       glTranslatef(-5.0f,-2.21f,0.5f);
       glRotatef(-75,1.0f,0.0f,0.0f);
       glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
       glColor4f(1.0f,1.0f,1.0f,0.0f);

       NurbA=gluNewNurbsRenderer();     // NURBS-anfordern
       if (NurbA > 0) //Probleme bei Anforderung?
       {  //Nein, dann NURBS definieren...
          //NURBS-Eigenschaften
          gluNurbsProperty(NurbA,        // Darstellungsart
          GLU_DISPLAY_MODE,               //   der NURBS-Fl�che
          GLU_FILL );                     //  =fl�chig(Default)
          gluNurbsProperty(NurbA,        // Zeiger auf NURBS
          GLU_SAMPLING_METHOD,            // Erzeugungsmethode:
          GLU_DOMAIN_DISTANCE);           // �ber u und v Def.!
          gluNurbsProperty(NurbA,        // Zeiger auf NURBS
          GLU_U_STEP,                     // Approximation in u
          35.0F);                         // Default=100.0F
          gluNurbsProperty(NurbA,        // Zeiger auf NURBS
          GLU_V_STEP,                     // Approximation in v
          35.0F);                         // Default=100.0F

          glEnable(GL_AUTO_NORMAL);       //weil NURBS=MAPs sind!

          glBindTexture (GL_TEXTURE_2D, texture1);
          gluBeginSurface(NurbA);    //NURBS-Def.Beginn
             gluNurbsSurface(NurbA,   //das NURBS-Objekt
              (GLint)22,sknotA, //sknot_count, sknot
              (GLint)12,tknotA, //tknot_count, tknot
              (GLint) 3,  //Array Offset u
              (GLint) 33,            //Array Offset v
              &ctlarrayA[0][0][0],      //Kontrollpunktefeld
              11,              //Anz.Kontrollpunkte u
              6,              //Anz.Kontrollpunkte v
              GL_MAP2_TEXTURE_COORD_2);    //Erzeugungsmodus    */
            gluNurbsSurface(NurbA,   //das NURBS-Objekt
              (GLint)22,sknotA, //sknot_count, sknot
              (GLint)12,tknotA, //tknot_count, tknot
              (GLint) 3,  //Array Offset u
              (GLint) 33,            //Array Offset v
              &ctlarrayA[0][0][0],      //Kontrollpunktefeld
              11,              //Anz.Kontrollpunkte u
              6,              //Anz.Kontrollpunkte v
              GL_MAP2_NORMAL);    //Erzeugungsmodus
            gluNurbsSurface(NurbA,   //das NURBS-Objekt
              (GLint)22,sknotA, //sknot_count, sknot
              (GLint)12,tknotA, //tknot_count, tknot
              (GLint) 3,  //Array Offset u
              (GLint) 33,            //Array Offset v
              &ctlarrayA[0][0][0],      //Kontrollpunktefeld
              11,              //Anz.Kontrollpunkte u
              6,              //Anz.Kontrollpunkte v
              GL_MAP2_VERTEX_3);    //Erzeugungsmodus
            gluEndSurface(NurbA);      //NURBS-Def. Ende
        gluDeleteNurbsRenderer(NurbA); //NURBS-Speicher freig.
      }


  glPopMatrix(); //Schirm
  glPopAttrib();

  //Pilot
  glPushMatrix();//Pilot
    glTranslatef(0.0,-7.25,0.0);
    glRotatef(-35,1.0,0.0,0.0);
    glScalef(0.5,1.0,0.3);
    glColor4f(0.0,0.0,0.2,0.0);
    GLUquadricObj*	q = gluNewQuadric();
    gluQuadricDrawStyle(q, GLU_FILL);
    gluQuadricNormals(q, GLU_SMOOTH);
    gluSphere(q, 0.5, 12, 7);
    gluDeleteQuadric(q);
  glPopMatrix();//Pilot

  //Laengsachse
  if (CheckBoxLang->Checked == true)
  {
    glPushMatrix;//Laengsachse
      glTranslatef(0.0,PosiLang,0.0);
      glBegin(GL_LINES);
        glColor4f(0.0,1.0,0.0,0.0);
        glVertex3d(0.0, 0.0, -20.0);
        glVertex3d(0.0, 0.0, 20.0);
      glEnd();
    glPopMatrix;//Laengsachse
  }

  //Querachse
  if (CheckBoxQuer->Checked == true)
  {
    glPushMatrix;//Querachse
      glTranslatef(0.0,PosiQuer,0.0);
      glBegin(GL_LINES);
        glColor4f(1.0,0.0,0.0,0.0);
        glVertex3d(-20.0, 0.0, 0.0);
        glVertex3d(20.0, 0.0, 0.0);
      glEnd();
    glPopMatrix;//Querachse
  }

  //Hochachse
  if (CheckBoxHoch->Checked == true)
  {
    glPushMatrix;//Hochachse
      glTranslatef(PosiHocha,0.0,0.0);
      glBegin(GL_LINES);
        glColor4f(0.0,0.0,1.0,0.0);
        glVertex3d(0.0, -20.0, 0.0);
        glVertex3d(0.0, 20.0, 0.0);
      glEnd();
    glPopMatrix;//Hochachse
  }
  glPopMatrix();//Schirm und Pilot

  glPushMatrix();
    glLoadIdentity();
    gluLookAt(0.0,0.0,50.0, 0.0,0.0,-1.0, 0.0,1.0,0.0);
    glBegin(GL_LINES);
        glColor4f(0.0,0.0,1.0,0.0);
        glVertex3d(0.0,0.02,48.0);
        glVertex3d(0.0,-0.02,48.0);
    glEnd();
    glBegin(GL_LINES);
        glColor4f(0.0,0.0,1.0,0.0);
        glVertex3d(-0.02,0.0,48.0);
        glVertex3d(0.02,0.0,48.0);
    glEnd();
  glPopMatrix();

  SchrittQuera = 0.0f;
  SchrittLaengsa = 0.0f;
  SchrittHocha = 0.0f;
}
//---------------------------------------------------------------------------

//***************************************************************************
//Bild-Timer, Bewegung aus Kurve und aus Zeitlupenfaktor berechnen:
//***************************************************************************

//---------------------------------------------------------------------------
void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
   //Timer1->Enabled = false;
   BewegungBerechnen();
   OpenGLPanel1->Repaint();
   if (zeitms!=0 || dauerplayflg == true)
   {Timer1->Enabled = true;
   }
}
//---------------------------------------------------------------------------
void TForm2::BewegungBerechnen()
{
    if (playflg == false)
    {
      SchrittQuera = 0.0f;
      SchrittHocha = 0.0f;
      SchrittLaengsa = 0.0f;
      PosiQuer = 0.0f;
      PosiLang = 0.0f;
      PosiHocha = 0.0f;
    }
    else
    {
      if (brSpeed == 1)  //wenn Echtzeit
      {
        BewegungAusKurve(); //Bewegung f�r n�chstes Bild aus Kurve holen
        PosiQuer = PosiQuer1;
        PosiLang = PosiLang1;
        PosiHocha = PosiHocha1;
        SchrittQuera = SchrittQuera1;
        SchrittLaengsa = SchrittLaengsa1;
        SchrittHocha = SchrittHocha1;
      }
      else //bei 2-10facher Zeitlupe wird jedes Bild in 2-10 Bilder aufgeteilt
      {
        brZeitLpInd++;
        if(brZeitLpInd ==1)
        {BewegungAusKurve();}
        SchrittQuera = SchrittQuera1/brSpeed;
        SchrittLaengsa = SchrittLaengsa1/brSpeed;
        SchrittHocha = SchrittHocha1/brSpeed;
        PosiQuer = PosiQuer1;
        PosiLang = PosiLang1;
        PosiHocha = PosiHocha1;
        if(brZeitLpInd >= brSpeed)
        {brZeitLpInd = 0;}
      }
    }
}
//---------------------------------------------------------------------------
void TForm2::BewegungAusKurve()
{
   Interpoli *interpoli_n;
   int aind = 0;
   float bewegung;
   int aind1 = 0;
   int aind2 = 0;
   int aind3 = 0;
   int aind4 = 0;
   int aind5 = 0;
   int aind6 = 0;
   int x1, x2, y1, y2;
   float y;

   for (int i=0; i<6;i++)
   {
           switch (i)
           {
             case 0: interpoli_n = Form1->Interpoli1;
                     aind = aind1;
                     bewegung = SchrittQuera1;
                     break;
             case 1: interpoli_n = Form1->Interpoli2;
                     aind = aind2;
                     bewegung = SchrittLaengsa1;
                     break;
             case 2: interpoli_n = Form1->Interpoli3;
                     aind = aind3;
                     bewegung = SchrittHocha1;
                     break;
             case 3: interpoli_n = Form1->Interpoli4;
                     aind = aind4;
                     bewegung = PosiQuer1;
                     break;
             case 4: interpoli_n = Form1->Interpoli5;
                     aind = aind5;
                     bewegung = PosiHocha1;
                     break;
             case 5: interpoli_n = Form1->Interpoli6;
                     aind = aind6;
                     bewegung = PosiLang1;
                     break;
           }
           while ((interpoli_n->AusgPXLesen(aind) * msppix_x > zeitms)
                   && (aind != 0))
             {aind--;}
           while (interpoli_n->AusgPXLesen(aind) * msppix_x < zeitms
                  && interpoli_n->LesenAnzAusgP() > aind )
             {aind++;}
           if(interpoli_n->AusgPXLesen(aind) * msppix_x == zeitms
             || aind ==0)
             {bewegung =(360-interpoli_n->AusgPYLesen(aind));}
           else
           {
             x1 = interpoli_n->AusgPXLesen(aind-1) * msppix_x;
             y1 = interpoli_n->AusgPYLesen(aind-1);
             x2 = interpoli_n->AusgPXLesen(aind) * msppix_x;
             y2 = interpoli_n->AusgPYLesen(aind);

             if (x1 == x2 || y1 == y2)
             {bewegung = 360-y1;}
             else
             {
               y = ((y2-y1)/(x2-x1)) * (zeitms-x1) +y1;
               bewegung = 360-y;
             }
           }
           if (bewegung < 4 && bewegung > -4)
           {bewegung = 0;}
           switch (i)
           {
             case 0: aind1 = aind;
                     SchrittQuera1 = bewegung/brBildrate *(-1)
                                     * Form1->Interpoli1->Aufloesungy ;
                     break;
             case 1: aind2 = aind;
                     SchrittLaengsa1 = bewegung/brBildrate *(-1)
                                        * Form1->Interpoli2->Aufloesungy ;
                     break;
             case 2: aind3 = aind;
                     SchrittHocha1 = bewegung/brBildrate *(-1)
                                      * Form1->Interpoli3->Aufloesungy ;
                     break;
             case 3: aind4 = aind;
                     PosiQuer1 = bewegung
                                   * Form1->Interpoli4->Aufloesungy;
                     break;
             case 4: aind5 = aind;
                     PosiHocha1 = bewegung *(-1)
                                   * Form1->Interpoli5->Aufloesungy;
                     break;
             case 5: aind6 = aind;
                     PosiLang1 = bewegung 
                                   * Form1->Interpoli6->Aufloesungy;
                     break;
           }
   }
   zeitms = zeitms+1000/brBildrate;
   div_t tsim;
   tsim = div(zeitms,1000);
   LabelSimSek->Caption = IntToStr(tsim.quot);
   LabelSimMili->Caption = IntToStr(tsim.rem);
   if (zeitms > 2000 * msppix_x)
   {
     zeitms =0;
     if (dauerplayflg == true)
      {AnimGrundpos();}
     else
      {AnimStop();}
   }
}

//---------------------------------------------------------------------------

//***************************************************************************
//Zurueck zum Editor,Play,Stop,Pause,Animationseinstellungen:
//***************************************************************************
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonEditorClick(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonPlayClick(TObject *Sender)
{
  if (playflg == false)
  {
    AnimPlay();
    dauerplayflg = false;
  }
  else
  {
    AnimPause();
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonDauerPlayClick(TObject *Sender)
{

  if (playflg == false)
  {
    AnimPlay();
    dauerplayflg = true;
  }
  else
  {
    AnimPause();
  }
}
//---------------------------------------------------------------------------
void TForm2::AnimPlay()
{
   ButtonPlay->Caption = "Pause";
   ButtonDauerPlay->Caption = "Pause";
   playflg = true;
   ScrollBarBildrate->Enabled = false;
   ButtonStop->Enabled = true;
   brZeitLpInd = 0;
   Timer1->Enabled = true;
   //zeitms =0;
}
//---------------------------------------------------------------------------
void TForm2::AnimPause()
{
   ButtonPlay->Caption = "Play";
   ButtonDauerPlay->Caption = "Dauerplay";
   playflg = false;
   ButtonStop->Enabled = true;
   ScrollBarSpeed->Enabled = true;
   ScrollBarBildrate->Enabled = true;
   Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonStopClick(TObject *Sender)
{
   dauerplayflg = false;
   AnimStop();
}
//---------------------------------------------------------------------------
void TForm2::AnimStop()
{
   ButtonPlay->Caption = "Play";
   ButtonDauerPlay->Caption = "Dauerplay";
   playflg = false;
   ButtonStop->Enabled = false;
   ScrollBarBildrate->Enabled = true;
   Timer1->Enabled = false;
   zeitms =0;
   SchrittQuera =0.0f;
   SchrittHocha = 0.0f;
   SchrittLaengsa =0.0f;
   PosiQuer = 0.0f;
   PosiHocha = 0.0f;
   PosiLang = 0.0f;
   lookatflg1 = false;
   urflg1 = false;
}
//---------------------------------------------------------------------------
void TForm2::AnimGrundpos()
{
   Timer1->Enabled = false;
   zeitms =0;
   SchrittQuera =0.0f;
   SchrittHocha = 0.0f;
   SchrittLaengsa =0.0f;
   PosiQuer = 0.0f;
   PosiHocha = 0.0f;
   PosiLang = 0.0f;
   lookatflg1 = false;
   urflg1 = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ScrollBarSpeedChange(TObject *Sender)
{
    brSpeed = ScrollBarSpeed->Position;
    LabelSpeed->Caption = IntToStr(brSpeed);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ScrollBarBildrateChange(TObject *Sender)
{
   brBildrate = ScrollBarBildrate->Position;
   LabelBldrate->Caption = IntToStr(brBildrate);
   Timer1->Interval = 1000/ScrollBarBildrate->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
    AnimStop();
}
//---------------------------------------------------------------------------

//***************************************************************************
//Berechnen der Kamera-Korrektur:
//***************************************************************************

//---------------------------------------------------------------------------
void TForm2::KameraKorrBerech()
{
    glGetIntegerv(GL_VIEWPORT,viewport);
    glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
    glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);
    gluProject(0.0f,0.0f,0.0f,mvmatrix,projmatrix,
                 viewport, &winx, &winy, &winz);

    winx2 = winx1;
    winx1 = (winx - OpenGLPanel1->Width/2);
    winy2 = winy1;
    winy1 = (winy - OpenGLPanel1->Height/2);
    winz2 = winz1;
    winz1 = winz;
    winspeedx = winx1-winx2;

    if (RadioButtonKamMan->Checked == true)
    {
       winxcor = winxcorm;
       winycor = winycorm;
       winzcor = winzcorm;
    }
    else
    { //x
      if (fabs(winx1) > OpenGLPanel1->Width * 0.4f)
       {winxcor = winx1/(-100);}
      else if (fabs(winx1) < OpenGLPanel1->Width * 0.1f)
       {winxcor = 0;}
      //y
      if (fabs(winy1) > OpenGLPanel1->Height * 0.4f)
       {winycor = winy1/(-100);}
      else if (fabs(winy1) < OpenGLPanel1->Height * 0.1f)
       {winycor = 0;}
      //z 
      winzcor = 0;
    }
}
//---------------------------------------------------------------------------

//***************************************************************************
//Manuelle Kammeraf�hrung:
//***************************************************************************

void __fastcall TForm2::RadioButtonKamManClick(TObject *Sender)
{
   GroupBoxKam->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButtonKamAutClick(TObject *Sender)
{
   GroupBoxKam->Visible = false;
}
//-------------------------------------------------------------------------
void __fastcall TForm2::ButtonUPMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   winycorm--;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonUPMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   winycorm = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonDownMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   winycorm++;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonDownMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   winycorm = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonLeftMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   winxcorm++;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonLeftMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    winxcorm = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonRightMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    winxcorm--;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonRightMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
     winxcorm = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonZoomInMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
     winzcorm++;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonZoomInMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
      winzcorm = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonZoomOutMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
      winzcorm--;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonZoomOutMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
      winzcorm = 0;
}
//---------------------------------------------------------------------------



