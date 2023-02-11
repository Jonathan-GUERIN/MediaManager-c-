#ifndef PHOTO_H
#define PHOTO_H
#include <string>
#include <iostream>

using namespace std;

class Photo
{
private:
    unsigned int latitude{};
    unsigned int longitude{};
public:
    Photo(){
        this->latitude = 0;
        this->longitude = 0;
    }
    Photo(unsigned int latitude, unsigned int longitude){
        this->latitude = latitude,
                this->longitude = longitude;}
    ~Photo();

    void setLatitude(unsigned int latitude){this->latitude = latitude;}
    void setLongitude(unsigned int longitude){this->longitude = longitude;}
    unsigned int getLatitude() const{return this->latitude;}
    unsigned int getLongitude() const{return this->longitude;}
    void display(ostream & who) const{who << this->getLatitude() << " " << this->getLongitude() << endl;}
};

#endif // PHOTO_H
