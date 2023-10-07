//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("FluFigSim11alpha.res");
USEFORM("UForm1_11alpha.cpp", Form1);
USEUNIT("NatCubSplInt11alpha.cpp");
USEFORM("UFrame1_11alpha.cpp", Frame1); /* TFrame: File Type */
USEFORM("UForm2_11alpha.cpp", Form2);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(TForm2), &Form2);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
