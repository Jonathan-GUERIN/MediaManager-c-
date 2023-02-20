#ifndef FILM_H
#define FILM_H
#include <string>
#include <iostream>
#include "video.h"

using namespace std;

class Film : public Video
{
private:
    int * chapters = nullptr;
    unsigned int count = 0;
public:
    Film() {}
    Film(string name, string pathname, unsigned int duree,int * _chapters, unsigned int _count) : Video(name, pathname, duree) {
        //On propose de reconstruire le tableau en argumant pour éviter de ne stocker que le pointeur
        //Cela nécessite de fournir le nombre d'élémets en argument, en ne stockant pas le pointeur, on assure l'encapsulation des données

        if(_count > 0){
            this->chapters = new int[_count];
            for(unsigned int c = 0; c < _count; c++){
                this->chapters[c] = _chapters[c];
            }
        }
        this->count = _count;
    }
    ~Film() {
        delete[] chapters;
        this->chapters = nullptr;
    }

    //Les setters
    void setChapters(int * chapters, unsigned int _count) {
        delete[] this->chapters;
        if(_count > 0){
            this->chapters = new int[_count];
            for(unsigned int c = 0; c < _count; c++){
                this->chapters[c] = chapters[c];
            }
        }
        this->count = _count;
    }

    //les getters
    int * getChapters() const{
        return this->chapters;
    }
    int getChaptersNumber() const{
        return this->count;
    }

    void showChapters(ostream & who) const;


};

#endif // FILM_H
