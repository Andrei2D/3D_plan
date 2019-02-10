#include <iostream>
#include "GraphicsFunctions.h"

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
    initwindow(600, 600, "Graphic");

    drawWithCommands(someLines);

    return 0;
}
