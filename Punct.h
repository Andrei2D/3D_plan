#ifndef PUNCT_H

#define PUNCT_H

#include <iostream>
#include <fstream>
#include <vector>

#define RIGHT_POINT_POZ -1
#define LEFT_POINT_POZ 1
#define STRAIGHT_POINT_POZ 0

#define XSCALE_DEF 40
#define YSCALE_DEF 40
#define XRELAT_DEF 300
#define YRELAT_DEF 400

using namespace std;


class Punct
{
protected:
    float x,y;
    static float Xscale, Yscale;
    static int Xrelat, Yrelat;

public:
    Punct (float xx=0, float yy=0)
    {
    x=xx;
    y=yy;
    }

    float getx () { return x; }
    float gety () { return y; }

    int getGhX () { return Xrelat + x*Xscale; }
    int getGhY () { return Yrelat - y*Yscale; }

    void set(float xx, float yy) {x=xx;y=yy;}

    static bool setRelativeOrigin(int Xpixel, int Ypixel)
    {
        Xrelat = Xpixel;
        Yrelat = Ypixel;
        return 0;
    }

    static void setScale (float newScaleX = -1, float newScaleY = -1)
    {
        if(newScaleX > 0) Xscale = newScaleX;
        if(newScaleY > 0) Yscale = newScaleY;
    }

    static float getXscale() {return Xscale;}
    static float getYscale() {return Yscale;}

    static void setScaleRelative (int DimensionX, int DimensionY, int howManyPointsOnX, int howManyPointsOnY)
    {
        Xscale = DimensionX / howManyPointsOnX;
        Yscale = DimensionY / howManyPointsOnY;
    }

    static void addToScale (int x, int y)
    {
        Xscale += x;
        Yscale += y;
    }

    static void addAtOrigin (int x, int y)
    {
        Xrelat += x;
        Yrelat += y;
    }


        ///OPERATION RELATED METHODS

    int operator=(const Punct& P)
    {
        if(this == &P) return 0;
        x=P.x;
        y=P.y;
        return 1;
    }

    Punct operator+ (Punct P)
    {
        Punct rez(x+P.x, y+P.y);
        return rez;
    }

    Punct operator* (float scalar)
    {
        Punct rez(x * scalar, y * scalar);
        return rez;
    }

    Punct operator- (Punct P)
    {
        Punct rez(x,y);
        rez = rez + P*(-1);
        return rez;
    }


    bool operator< (Punct P)
    {
        if(x<P.x) return 1;
        if(x==P.x && y<P.y) return 1;
        return 0;
    }

    bool operator== (Punct P)
    {
        if(x == P.x && y == P.y) return 1;
        return 0;
    }

    bool operator!= (Punct P)
    {
        return !(operator==(P));
    }


    static float Determinant(Punct P, Punct Q, Punct R)
    {
        float positive = Q.x * R.y + R.x * P.y + P.x * Q.y;
        float negative = Q.x * P.y + P.x * R.y + R.x * Q.y;
        return positive - negative;
    }

    static int Position (Punct BASE, Punct TIP, Punct POINT)
    {
        float det = Determinant(BASE, TIP, POINT);
        if (det < 0) return RIGHT_POINT_POZ;
        if (det > 0) return LEFT_POINT_POZ;
        return STRAIGHT_POINT_POZ;
    }

        ///FRIEND FUNCTIONS

friend char formaGeom (int* vir, vector<Punct>& P);
friend ifstream& operator>> (ifstream& f, Punct& p);
friend ostream& operator<< (ostream& out, Punct& p);
};

float Punct::Xscale = XSCALE_DEF;
float Punct::Yscale = YSCALE_DEF;
int Punct::Xrelat = XRELAT_DEF;
int Punct::Yrelat = YRELAT_DEF;

ifstream& operator>> (ifstream& f, Punct& p)
{
    f>>p.x>>p.y;
    return f;
}

ostream& operator<< (ostream& out, Punct& p)
{
    out<<"("<<p.x<<" "<<p.y<<")";
    return out;
}




#endif // PUNCT_H
