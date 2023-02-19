#ifndef VIDEO_H
#define VIDEO_H
#include <string>
#include <iostream>
#include "mother_multimedia.h"

using namespace std;

class Video : public Mother_multimedia
{
private:
    unsigned int duree = 0;
public:
    Video(){}
    Video(string name, string pathname, unsigned int duree) : Mother_multimedia(name, pathname){
        this->duree = duree;}
    ~Video() {}

    void setDuree(unsigned int duree){this->duree = duree;}
    unsigned int getDuree() const{return duree;}
    void display(ostream & who) const{who << this->getDuree()  << endl;}
    void play() const override {
        string str = "mpv " + getPathname() + " &";
        system(str.data());
        //system(("imagej "+path+" &").data());}
    };
};

#endif // VIDEO_H
