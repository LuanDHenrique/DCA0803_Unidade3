#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <math.h>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx=_nx; ny=_ny; nz=_nz;
    v=new Voxel **[nx];
    for(int xs=0; xs<nx; xs++){
        v[xs]=new Voxel *[ny];
    }

    for(int xs=0; xs<nx; xs++){
        for(int ys=0; ys<ny; ys++){
            v[xs][ys]=new Voxel [nz];
        }
    }

    for(int xs=0; xs<nx; xs++){
        for(int ys=0; ys<ny; ys++){
            for(int zs=0; zs>nz; zs++){
                v[xs][ys][zs].isOn=false;
                v[xs][ys][zs].r=r;
                v[xs][ys][zs].g=g;
                v[xs][ys][zs].b=b;
                v[xs][ys][zs].a=a;
            }
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
Sculptor::~Sculptor(){
    int ax=nx;
    int ay=ny;

    for(int as=0; as<ax; as++){
        for(int as=0; as<ay; ay++){
            delete[] v[as][ay];
        }
    }
    for(int as=0; as<ax; as++){
        delete[] v[as];
    }
    delete[] v;
}
//----------------------------------------------------------------------------------------------------------------------
void troca(int x, int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}
//----------------------------------------------------------------------------------------------------------------------
void Sculptor::setColor(float r, float g, float b, float a){
    this->r=r;  this->g=g;   this->b=b;    this->a=a;
}
//----------------------------------------------------------------------------------------------------------------------
void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn=false;
}
//----------------------------------------------------------------------------------------------------------------------
void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn=true;
    v[x][y][z].r=r;
    v[x][y][z].g=g;
    v[x][y][z].b=b;
    v[x][y][z].a=a;
}
//----------------------------------------------------------------------------------------------------------------------


void Sculptor::writeOFF(char *filename)
{
    int i=0, j=0, k=0, cont=0, total=0, temp;
    putVoxel(i,j,k);
    ofstream arq;

    for(i = 0; i<nz; i++){
        for(j = 0; j<ny; j++){
            for(k = 0; k<nx; k++){
                if(v[i][j][k].isOn == true){
                    total++;
                }
            }
        }
    }
    int vertices=total*8, faces=total*6;
    arq.open(filename);
    arq<<"OFF"<<endl;
    arq<<vertices<<" "<<faces<<" 0"<<endl;

    for(i = 0; i<nz; i++){
        for(j = 0; j<ny; j++){
            for(k = 0; k<nx; k++){
                if(v[i][j][k].isOn == true){
                    arq<<i-0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                    arq<<i-0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                    arq<<i+0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                    arq<<i+0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                    arq<<i-0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                    arq<<i-0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                    arq<<i+0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                    arq<<i+0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;                }
            }
        }
    }

    for(i = 0; i<nz; i++){
        for(j = 0; j<nx; j++){
            for(k = 0; k<ny; k++){
                if(v[i][j][k].isOn == true){
                   int temp=cont*8;
                    arq<<"4 "<<temp<< " "<< temp+3<<" "<< temp+2 <<" "<< temp+1;
                    arq<<" "<< v[i][j][k].r <<" "<< v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    arq<<"4 "<< temp+4<< " "<< temp +5<<" "<< temp+6 <<" "<< temp+7;
                    arq<<" "<< v[i][j][k].r <<" "<< v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    arq<<"4 "<< temp<< " " << temp+1<<" "<< temp+5 <<" "<< temp+4;
                    arq<<" "<< v[i][j][k].r <<" "<< v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    arq<<"4 "<< temp<< " " << temp+4<<" "<< temp+7 <<" "<< temp+3;
                    arq<<" "<< v[i][j][k].r <<" "<< v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    arq<<"4 "<< temp+3<<" " << temp+7<<" "<< temp+6 <<" "<< temp+2;
                    arq<<" "<< v[i][j][k].r << " "<< v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    arq<<"4 "<< temp+1 <<" "<< temp +2<<" "<< temp+6 <<" "<< temp+5;
                    arq<<" "<<v[i][j][k].r << " "<< v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    cont++;
                }
            }
        }
    }arq.close();
}

void Sculptor::limpaVoxels(void){
  queue<int> q;
  int x, y, z;
  int lx,ly,lz;
  for(x=1; x<nx-1; x++){
    for(y=1; y<ny-1; y++){
      for(z=1; z<nz-1; z++){
        if((v[x][y][z].isOn == true) &&
           (v[x+1][y][z].isOn == true) &&
           (v[x-1][y][z].isOn == true) &&
           (v[x][y+1][z].isOn == true) &&
           (v[x][y-1][z].isOn == true) &&
           (v[x][y][z+1].isOn == true) &&
           (v[x][y][z-1].isOn == true)){
          q.push(x);
          q.push(y);
          q.push(z);
        }
      }
    }
  }
  while(!q.empty()){
    lx=q.front(); q.pop();
    ly=q.front(); q.pop();
    lz=q.front(); q.pop();
    v[lx][ly][lz].isOn = false;
  }
}
