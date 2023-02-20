#ifndef GROUP_H
#define GROUP_H
#include <string>
#include <iostream>
#include <list>
#include <memory>
#include "mother_multimedia.h"

using namespace std;

class Group : public list<shared_ptr<Mother_multimedia>>
{
private:
    string groupName = "";
public:
    Group() : list<shared_ptr<Mother_multimedia>>() {}
    Group(string name) {
        this->groupName = name;
    }
    ~Group() {cout << "Goodbye Lenin " << groupName << endl;}

    string getName() const{return groupName;}

    void showGroup(ostream & who) const;
};

#endif // GROUP_H
