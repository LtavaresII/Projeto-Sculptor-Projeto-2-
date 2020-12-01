#include "interpretador.h"
#include "figurageometrica.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

int main()
{
    Sculptor *s1;

    Interpretador parser;

    vector<FiguraGeometrica*> figs;

    figs = parser.parse("");

    s1 = new Sculptor(parser.getX(), parser.getY(), parser.getZ());

    for(size_t i=0; i<figs.size();i++){
        std::cout<< "draw\n";
        figs[i]->draw(*s1);
    }

    s1->limpaVoxels();

    s1->writeOFF((string)"");
    for(size_t i=0; i<figs.size();i++){
        delete figs[i];
    }
    delete s1;
    return 0;
}
