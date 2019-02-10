#ifndef aux_fun

#define aux_fun

float map(float my_val, float its_lwr, float its_upr, float wan_lwr, float wan_upr)
{
    float unit = (wan_upr - wan_lwr) / (its_upr - its_lwr);

    return unit * (my_val - its_lwr) + wan_lwr;
}


#endif // aux_fun

