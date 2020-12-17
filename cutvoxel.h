#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"

class CutVoxel : public FiguraGeometrica{
    int x, y, z;
public:
    CutVoxel(int mx, int my, int mz);
    ~CutVoxel();
    void draw(Sculptor &s);
};

#endif // CUTVOXEL_H

