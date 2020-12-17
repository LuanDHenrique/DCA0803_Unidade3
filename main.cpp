#include "sculptor.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "interpretador.h"
#include "figurageometrica.h"
#include "putbox.h"
#include "cutbox.h"
#include "putellipsoid.h"
#include "putsphere.h"
#include "putvoxel.h"
#include "cutellipsoid.h"
#include "cutsphere.h"
#include "cutvoxel.h"

using namespace std;

int main(){

    Sculptor *s1;

    Interpretador parser;

    vector<FiguraGeometrica*> figura;
    figura=parser.parse((char*)"C:/Users/Luan Henrique/Desktop/teste.txt");

    s1=new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());

    for(size_t i=0; i<figura.size(); i++){
        figura[i]->draw(*s1);
    }

    s1->limpaVoxels();

    s1->writeOFF((char*)"C:/Users/Luan Henrique/Desktop/projeto3.off");
    for(size_t i=0; i<figura.size(); i++){
        delete figura[i];
    }
    delete s1;
    cout << "Deu certo!" << endl;
    return 0;
}
