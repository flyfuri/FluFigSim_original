//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("MDI_Demo.res");
USEFORM("MDI_Main.cpp", Main_Form);
USEFORM("MDI_Child.cpp", Child);
USEFORM("MDI_About.cpp", About);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->CreateForm(__classid(TMain_Form), &Main_Form);
        Application->CreateForm(__classid(TChild), &Child);
        Application->CreateForm(__classid(TAbout), &About);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
