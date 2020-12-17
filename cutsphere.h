#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "sculptor.h"
#include "figurageometrica.h"


class CutSphere: public FiguraGeometrica{
    int xcenter, ycenter, zcenter, radius;
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    ~CutSphere();
    void draw(Sculptor &s);
};

#endif // CUTSPHERE_H

