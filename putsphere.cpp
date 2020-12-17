#include "putsphere.h"
#include <math.h>

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a){
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->radius=radius;
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;
}

PutSphere::~PutSphere(){}


void PutSphere::draw(Sculptor &s){
for(int i=0; i<2*xcenter; i++){
    for(int j=0; j<2*ycenter; j++){
        for(int k=0; k<2*zcenter; k++){
            if((pow((i-xcenter),2)+pow((j-ycenter),2)+pow((k-zcenter),2))<=pow(radius,2)){
                s.putVoxel(i, j, k);
                }
            }
        }
    }
}
