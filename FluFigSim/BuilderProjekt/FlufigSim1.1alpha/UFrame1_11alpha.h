//---------------------------------------------------------------------------


#ifndef UFrame1_11alphaH
#define UFrame1_11alphaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrame1 : public TFrame
{
__published:	// Von der IDE verwaltete Komponenten
        TPaintBox *PaintBox1;
private:	// Anwender-Deklarationen
public:		// Anwender-Deklarationen
        __fastcall TFrame1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame1 *Frame1;
//---------------------------------------------------------------------------
#endif
