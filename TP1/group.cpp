#include "group.h"

using namespace std;

void Group::showGroup(ostream & who) const{
    who << "Group " << getName() << endl;
    for(auto & it : *this){
        if(it){
            it->display(who);
        }
    }
}

