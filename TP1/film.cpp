#include "film.h"

using namespace std;

void Film::showChapters(ostream & who) const{
    for(unsigned int i = 0; i < count; i++){
        who << "chapter " << i << " : " << chapters[i] << "\n";
    }
    who << endl;
}
