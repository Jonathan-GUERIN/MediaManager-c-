#ifndef VIDEO_H
#define VIDEO_H
#include <string>
#include <iostream>

using namespace std;

class Video
{
private:
    unsigned int duree{};
public:
    Video(){
        this->duree = 0;
    }
    Video(unsigned int duree){
        this->duree = duree;}
    ~Video();

    void setDuree(unsigned int duree){this->duree = duree;}
    unsigned int getDuree() const{return duree;}
    void display(ostream & who) const{who << this->getDuree()  << endl;}
};

#endif // VIDEO_H
