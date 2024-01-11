#include "fdf.h"

int	gradient(int startcolor, int endcolor, int len, int pix)
{
	double increment[3];
	int new[3];
	int newcolor;

	increment[0] = ((R(endcolor)) - (R(startcolor))) / len;
    increment[1] = ((G(endcolor)) - (G(startcolor))) / len;
    increment[2] = ((B(endcolor)) - (B(startcolor))) / len;

    new[0] = (R(startcolor)) + pix * increment[0];
    new[1] = (G(startcolor)) + pix * increment[1];
    new[2] = (B(startcolor)) + pix * increment[2];

    newcolor = RGB(new[0], new[1], new[2]);

    return (newcolor);
}
