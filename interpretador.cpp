#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "interpretador.h"
#include "putbox.h"
#include "putellipsoid.h"
#include "putsphere.h"
#include "putvoxel.h"
#include "cutbox.h"
#include "cutellipsoid.h"
#include "cutsphere.h"
#include "cutvoxel.h"



using namespace std;

Interpretador::Interpretador(){}

int Interpretador::getDimx(){
    return dimx;
}
int Interpretador::getDimy(){
    return dimy;
}
int Interpretador::getDimz(){
    return dimz;
}

vector<FiguraGeometrica*> Interpretador::parse(string filename){
    vector <FiguraGeometrica*> figura;
    ifstream fin;
    stringstream ss;
    string s, token;

    fin.open(filename.c_str());

    if(!fin.is_open()){
        cout << "ERRO NO INTERPRETADOR" << endl;
        exit(0);
    }

    while(fin.good()){

        getline(fin, s);
        if(fin.good()){

            ss.clear();
            ss.str(s);
            ss >> token;

            if(ss.good()){

                if(token.compare("dim") == 0){
                    ss >> dimx >> dimy >> dimz;
                }

                else if(token.compare("putvoxel") == 0){
                    int x0, y0, z0;
                    ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                    figura.push_back(new PutVoxel(x0, y0, z0, r, b, g, a));
                }
                else if(token.compare("cutvoxel") == 0){
                    int x0, y0, z0;
                    ss >> x0 >> y0 >> z0;
                    figura.push_back(new CutVoxel(x0, y0, z0));
                }
                else if(token.compare("putbox") == 0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figura.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, b, g, a));
                }
                else if(token.compare("cutbox") == 0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figura.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
                }
                else if(token.compare("putsphere") == 0){
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                    figura.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, b, g, a));
                }
                else if(token.compare("cutsphere") == 0){
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius;
                    figura.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));
            }
                else if(token.compare("putellipsoid") == 0){
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                    figura.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, b, g, a));
            }
                else if(token.compare("cutellipsoid") == 0){
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
                    figura.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
                }
            }
        }
    }
    return(figura);
}

