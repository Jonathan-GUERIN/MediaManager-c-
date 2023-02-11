#include "mother_multimedia.h"
#include <iostream>
#include <string>

using namespace std;

Mother_multimedia::Mother_multimedia()
{
    this->name = "NoName";
    this->pathname = "Unknown";
}

Mother_multimedia::Mother_multimedia(string _name, string _pathname)
{
    this->name = _name;
    this->pathname = _pathname;
}

void Mother_multimedia::display(ostream & who) const{
    who << this->getName() << " " << this->getPathname() << endl;
}

string Mother_multimedia::getName() const{
    return name;
}

string Mother_multimedia::getPathname() const{
    return pathname;
}

void Mother_multimedia::setName(string name){
    this->name = name;
}

void Mother_multimedia::setPathname(string pathname){
    this->pathname = pathname;
}
