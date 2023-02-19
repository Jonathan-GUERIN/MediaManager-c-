#ifndef PHOTO_H
#define PHOTO_H
#include <string>
#include <iostream>
#include "mother_multimedia.h"

using namespace std;

class Photo : public Mother_multimedia
{
private:
    unsigned int latitude = 0;
    unsigned int longitude = 0;
public:
    Photo(){}
    Photo(string name, string pathname, unsigned int latitude, unsigned int longitude) : Mother_multimedia(name, pathname){
        this->latitude = latitude,
                this->longitude = longitude;}
    ~Photo() {}

    void setLatitude(unsigned int latitude){this->latitude = latitude;}
    void setLongitude(unsigned int longitude){this->longitude = longitude;}
    unsigned int getLatitude() const{return this->latitude;}
    unsigned int getLongitude() const{return this->longitude;}
    void display(ostream & who) const{who << this->getLatitude() << " " << this->getLongitude() << endl;}
    void play() const override {
        string str = "imagej " + getPathname() + " &";
        system(str.data());
        //system(("imagej "+path+" &").data());}
    };
};

#endif // PHOTO_H
