//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "NatCubSplInt11alpha.h"
#pragma package(smart_init)

//Interpoli *Interpoli1;

const int var400 = 50;
const int var10 = 10;
void mul(int n,float a[var400][var400],float b[var400],float c[var400]);
void gussele(int n,float a[var400][var400],float b[var400],float x[var400]);
//---------------------------------------------------------------------------
Interpoli::Interpoli(void)
{
  Initialisieren();
}
//---------------------------------------------------------------------------
void Interpoli::Initialisieren(void)
{
  for (int i=0; i<50; i++)
  {
    EingPunkte[i].PosX = 0;
    EingPunkte[i].PosY = 0;
    EingPunkte[i].flgletztPnkt = false;
  }
  for (int i=0; i<50; i++)
  {
    AusgPunkte[i].PosX = 0;
    AusgPunkte[i].PosY = 0;
    AusgPunkte[i].flgletztPnkt = false;
  }
  AnzPunkte =0;
  AnzAusgP =0;
}
//---------------------------------------------------------------------------
int Interpoli::NeuerPunkt(int posx, int posy)
{
    if (AnzPunkte > 44)
    {return -1;}
    else
    {
      AnzPunkte++;
      EingPunkte[AnzPunkte-1].PosX = posx;
      EingPunkte[AnzPunkte-1].PosY = posy;
      EinPSortieren();
      BegrenzenEingP();
      if(Interpolation() == 1)
      {
        BegrenzenAusgP();
        return 1;
      }
      else
      {
        return 0;
      }
    }
}
//---------------------------------------------------------------------------
int Interpoli::PunktLoeschen (int nummer)
{
   for (int i=nummer; i<AnzPunkte-1; i++)
   {
     EingPunkte[i].PosX = EingPunkte[i+1].PosX;
     EingPunkte[i].PosY = EingPunkte[i+1].PosY;
   }
   AnzPunkte--;
   EinPSortieren();
   BegrenzenEingP();
   if(Interpolation() == 1)
   {
        BegrenzenAusgP();
        return 1;
   }
   else
   {
        return 0;
   }
}
//---------------------------------------------------------------------------
int Interpoli::PunktVerschieben(int nummer, int posx, int posy)
{
   EingPunkte[nummer].PosX = posx;
   EingPunkte[nummer].PosY = posy;
   EinPSortieren();
   BegrenzenEingP();
   if(Interpolation() == 1)
   {
        BegrenzenAusgP();
        return 1;
   }
   else
   {
        return 0;
   }
}
//---------------------------------------------------------------------------
int Interpoli::PunktUmCursor(int posx, int posy)
{
   for (int i=0; i<AnzPunkte; i++)
   {
     if ((posx-EingPunkte[i].PosX)<5 && (posx-EingPunkte[i].PosX)>-5 && posy-EingPunkte[i].PosY<5 && posy-EingPunkte[i].PosY>-5)
     {
       return i;
     }
   }
   return -1;
}
//---------------------------------------------------------------------------
int Interpoli::LesenAnzPunkte(void)
{
  return(AnzPunkte);
}
//---------------------------------------------------------------------------
int Interpoli::LesenAnzAusgP(void)
{
  return(AnzAusgP);
}
//---------------------------------------------------------------------------
int Interpoli::EinpXLesen(int nummer)
{
    return(EingPunkte[nummer].PosX);
}
//---------------------------------------------------------------------------
int Interpoli::EinpYLesen(int nummer)
{
    return(EingPunkte[nummer].PosY);
}
//---------------------------------------------------------------------------
int Interpoli::AusgPXLesen(int nummer)
{
    return(AusgPunkte[nummer].PosX);
}
//---------------------------------------------------------------------------
int Interpoli::AusgPYLesen(int nummer)
{
    return(AusgPunkte[nummer].PosY);
}
//---------------------------------------------------------------------------
void Interpoli::EinPSortieren(void)
{
     int dummy_x, dummy_y;
     EingPunkte[0].PosX =0;
     for (int i=0; i < (AnzPunkte-1); i++)
     {
       for (int ii = i; ii < (AnzPunkte); ii++)
       {
         if (EingPunkte[ii].PosX < EingPunkte[i].PosX)
         {
            dummy_x = EingPunkte[i].PosX;
            dummy_y = EingPunkte[i].PosY;

            EingPunkte[i].PosX = EingPunkte[ii].PosX;
            EingPunkte[i].PosY = EingPunkte[ii].PosY;

            EingPunkte[ii].PosX = dummy_x;
            EingPunkte[ii].PosY = dummy_y;

         }
       }
     }
}
//---------------------------------------------------------------------------
void Interpoli::BegrenzenEingP()
{
   for (int i=0; i < (AnzPunkte); i++)
   {
      if ((360 - EingPunkte[i].PosY)*Aufloesungy > max_y)
      {
         EingPunkte[i].PosY = 360 - max_y /Aufloesungy ;
      }
      else if ((360 - EingPunkte[i].PosY)*Aufloesungy < min_y)
      {
         EingPunkte[i].PosY = 360 - min_y /Aufloesungy ;
      }
   }
}
//---------------------------------------------------------------------------
void Interpoli::BegrenzenAusgP()
{
   for (int i=0; i < (AnzAusgP); i++)
   {
      if ((360 - AusgPunkte[i].PosY)*Aufloesungy > max_y)
      {
         AusgPunkte[i].PosY = 360 - max_y /Aufloesungy ;
      }
      else if ((360 - AusgPunkte[i].PosY)*Aufloesungy < min_y)
      {
         AusgPunkte[i].PosY = 360 - min_y /Aufloesungy ;
      }
   }
}
//---------------------------------------------------------------------------
int Interpoli::Interpolation(void)
{//1.1
    float xd[var400],yd[var400],fx[var400],fy[var400];
    float x[var400],y[var400],matleft[var400][var400],matright[var400][var400];
    float px[11][var400],py[11][var400];
    int m,n,txy;
    float fu1,fu2,fu3,fu4,posx1,posx2,posxmax;

    m = AnzPunkte+4;
    n=m-1;
    if (AnzPunkte > 1 || AnzPunkte < 51)
    {//2.2
                for(int i=0; i<2; i++)
                {
                  x[i]= (-50)*i -100;
                  y[i]= EingPunkte[0].PosY;
                }
                for(int i=0;i<AnzPunkte;i++)
                {//3.3
                   x[i+2] = EingPunkte[i].PosX;//+50;
                   y[i+2] = EingPunkte[i].PosY;
                }//3.2
                for(int i=0;i<2; i++)
                {
                   x[i+AnzPunkte+2]= x[AnzPunkte+1]+100*i+100;
                   y[i+AnzPunkte+2]= y[AnzPunkte+1];
                }

                for(int i=0;i<var400;i++)
                {//4.3
                  fx[i]=0;
                  fy[i]=0;
                  yd[i]=0;
                  xd[i]=0;
                  for(int j=0;j<var400;j++)
                  {//5.4
                        matright[i][j]=0;
                        matleft[i][j]=0;
                  }//5.3
                }//4.2
                for(int i=1;i<=n-1;i++)
                {//6.3
                        matleft[i][i-1]=2;
                        matleft[i][i]=8;
                        matleft[i][i+1]=2;
                        matright[i][i-1]=-6;
                        matright[i][i]=0;
                        matright[i][i+1]=6;
                }//6.2
                matleft[0][0]=4;
                matleft[0][1]=2;
                matleft[n][n-1]=2;
                matleft[n][n]=4;
                matright[0][0]=-6;
                matright[0][1]=6;
                matright[0][n]=2;
                matright[n][0]=2;
                matright[n][n-1]=-6;
                matright[n][n]=6;

                mul(n,matright,x,fx);
                mul(n,matright,y,fy);
                gussele(n,matleft,fx,xd);
                gussele(n,matleft,fy,yd);
                float u=0;
                for(int j=1;j<=n;j++)
                {//7.3
                   for(int i=0;i<=var10;i++)
                   {//8.4
                        fu1=2*u*u*u-3*u*u+1;
                        fu2=-1*2*u*u*u+3*u*u;
                        fu3=u*u*u-2*u*u+u;
                        fu4=u*u*u-u*u;
                        px[i][j]=fu1*x[j-1]+fu2*x[j]+fu3*xd[j-1]+fu4*xd[j];
                        py[i][j]=fu1*y[j-1]+fu2*y[j]+fu3*yd[j-1]+fu4*yd[j];
                        u=u+0.1;
                   }//8.3
                   u=0;
                }//7.2
                u=0;
                AnzAusgP = 0;
                AusgPunkte[AnzAusgP].PosX = EingPunkte[0].PosX;
                AusgPunkte[AnzAusgP].PosY = EingPunkte[0].PosY;
                AnzAusgP = 1;
                posxmax = 0;
                for(int j=1;j<=n;j++)
                {//9.3
                   for(int i=0;i<=var10;i++)
                   {//10.4
                     if (px[i][j]>posxmax) 
                     {posxmax = px[i][j];}
  if (j>2 && px[i][j]==posxmax && px[i][j]<=(EingPunkte[AnzPunkte-1].PosX))//+50))
                      {//11.5
                          AusgPunkte[AnzAusgP].PosX = px[i][j];//-50;
                          AusgPunkte[AnzAusgP].PosY = py[i][j];
                          AnzAusgP++;
                      }//11.4
                   }//10.3
                }//9.2
                return 1;
     }//2.1
     else {return 0;}
}//1.0
//---------------------------------------------------------------------------
//      THIS FUNCTION GAUSS ELIMINATION METHD TO SOLVE SIMULTANEOUS EQUATION
void gussele(int n,float a[var400][var400],float b[var400],float x[var400])
    {
     n=n+1;
     int i,j,k;
     float c;
     for(i=0;i<n;i++)
      {
       for(j=i+1;j<n;j++)
         {
         if(a[i][i]<a[j][i])
          {
          for(k=0;k<n;k++)
            {
             c=a[i][k];
             a[i][k]=a[j][k];
             a[j][k]=c;
            }
           c=b[i];
           b[i]=b[j];
           b[j]=c;
          }
      }
    }
 

  for(i=0;i<n;i++)
   {
    for(j=i+1;j<n;j++)
     {
      b[j]=b[j]-a[j][i]*(b[i]/a[i][i]);
       for(k=n-1;k>=0;k--)
       {
        a[j][k]=a[j][k]-a[j][i]*(a[i][k]/a[i][i]);
       }
     }
    }
  //cout<<"\n the new a matrix";
  //cout<<"\n";
     for(i=0;i<n;i++)
     {
      for (j=0;j<n;j++){}
   //cout<<"\t"<<a[i][j];
   //cout<<"\n";
     }
  //cout<<"\n the new b matrix";
  //cout<<"\n";
     for(i=0;i<n;i++)
     {
    //cout<<b[i];
    //cout<<"\n";
     }

    x[n-1]=b[n-1]/a[n-1][n-1];
     for(i=n-2;i>=0;i--)
      {
       x[i]=b[i];
       for(j=n-1;j>i;j--)
        {
         x[i]=x[i]-a[i][j]*x[j];
        }
        x[i]=x[i]/a[i][i];
      }
    //cout<<"\n the solution of the matrix";
    //cout<<"\n";
     for(i=0;i<n;i++)
     {
     //cout<<x[i];
     //cout<<"\n";
      }
 }
//---------------------------------------------------------------------------
 //THIS FUNCTION MULTIPLY TWO N x N MATRIX
 void mul(int n,float a[var400][var400],float b[var400],float c[var400] )
 {
    for(int j=0;j<=n;j++)
    {
      float sum=0;
      for(int k=0;k<=n;k++)
      {
         sum=sum+a[j][k]*b[k];
      }
      c[j]=sum;
    }
 }
//---------------------------------------------------------------------------

