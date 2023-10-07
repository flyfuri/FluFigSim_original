//---------------------------------------------------------------------------

#ifndef NatCubSplInt11alphaH
#define NatCubSplInt11alphaH
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <math.h>
//---------------------------------------------------------------------------
class Interpoli
{
private:	// Anwender-Deklarationen
                int AnzPunkte;
                int AnzAusgP;
                struct EINGSTRUCT{ int PosX;
                                   int PosY;
                                   bool flgletztPnkt;
                                 };
                EINGSTRUCT EingPunkte[50];
                struct AUSGSTRUCT { float PosX;
                                    float PosY;
                                    bool flgletztPnkt;
                                 };
                AUSGSTRUCT AusgPunkte[510];
                void EinPSortieren();
                void BegrenzenEingP();
                void BegrenzenAusgP();
protected:      int Interpolation(void);



public:		// Anwender-Deklarationen
                float Aufloesungy;
                int Kommastellen;
                float max_y;
                float min_y;
                float abstand_y;
                String Einheity;
                Interpoli(); //Constructor
                void Initialisieren(void);
                int LesenAnzPunkte(void);
                int LesenAnzAusgP(void);
                int NeuerPunkt(int posx, int posy);
                int PunktLoeschen (int nummer);
                int PunktVerschieben(int nummer, int posx, int posy);
                int PunktUmCursor(int posx, int posy);
                int EinpXLesen(int nummer);
                int EinpYLesen(int nummer);
                int AusgPXLesen(int nummer);
                int AusgPYLesen(int nummer);

};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
