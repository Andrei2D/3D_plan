#include <iostream>
#include <vector>
#include "GraphicsFunctions.h"
#include "aux_fun.h"

using namespace std;

int x_scale_unit = 10;
int y_scale_unit = 10;

int x_orig_unit = 10;
int y_orig_unit = 10;

void controlGraph (int ch)
{
    switch(ch)
    {
        ///Arrow keys
    case('5'):
        Punct::addAtOrigin(0, (-1)*y_orig_unit);
        break;

    case('1'):
        Punct::addAtOrigin(x_orig_unit *(-1),0);
        break;

    case('2'):
        Punct::addAtOrigin(0, y_orig_unit);
        break;

    case('3'):
        Punct::addAtOrigin(x_orig_unit, 0);
        break;
            // end of arrow keys
        ///Left side modifier
    case('7'):
        Punct::addToScale(x_scale_unit, y_scale_unit);
        break;

    case('4'):
        Punct::addToScale((-1)*x_scale_unit, (-1)*y_scale_unit);
        break;
            //end left modifier
        ///Right side modifier
    case('9'):

        break;

    case('6'):

        break;
            //end right side
        ///Aux s commands
    case('8'):

        break;

    case('0'):

        break;

    case(32):
        closegraph();
        break;

    default:
        break;
    }
}

void drawWithCommands ( void(*drawSome)(void) )
{
    int ch = 1;

    while(ch != 32)
    {
        cleardevice();
        drawSome();

        ch = getch();
        controlGraph(ch);
        if(ch == 32) break;
    }
}

void someLines()
{
    Punct P(0,0), S(10,10), D(10,0),C(0,10);
    drawLine(P,S);
    drawLine(S,D);
    drawLine(D,C);
    drawLine(C,P);

}

int main()
{
    /*
    initwindow(600, 600, "Graphic");
    drawWithCommands(someLines);
    */
    vector<float> my_val, rez;
    float its_lwr, its_upr;
    float wan_lwr, wan_upr;

    int howMany = 1, rt = 1;
    cout<<"How many? ";
    cin>>howMany;



    while(howMany)
    {
        if(rt)
        {
            cout<<"Value's interval: ";
            cin>>its_lwr>>its_upr;

            cout<<"Desired interval: ";
            cin>>wan_lwr>>wan_upr;
        }

        my_val.resize(howMany);
        rez.resize(howMany);

        cout<<"Value: ";
        for(int i=0; i< howMany; i++)
        {
        cin>>my_val[i];
        rez[i] = map(my_val[i],its_lwr,its_upr,wan_lwr,wan_upr);
        }

        cout<<"[\t";
        for(int i=0; i< howMany; i++)
            cout<<my_val[i]<<"\t";
        cout<<"]\n[\t";
        for(int i=0; i< howMany; i++)
            cout<<rez[i]<<"\t";
        cout<<"]\n";

        cout<<"Reset? ";
        cin>>rt;

        cout<<"How many? ";
        cin>>howMany;
    }

    return 0;
}
