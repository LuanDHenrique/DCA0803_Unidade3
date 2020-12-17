#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "sculptor.h"
#include "figurageometrica.h"


class CutEllipsoid : public FiguraGeometrica{
   int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    ~CutEllipsoid();
    void draw(Sculptor &s);
};

#endif // CUTELLIPSOID_H
