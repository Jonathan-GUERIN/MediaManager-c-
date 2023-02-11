//
// main.cpp
// Created on 21/10/2018
//

#include "mother_multimedia.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[])
{
    std::cout << "Hello brave new world" << std::endl;

    Mother_multimedia * test = new Mother_multimedia("test1","/cal/exterieurs/jguerin-21/inf224/TP1/");
    test->display(std::cout);
    string name = test->getName();
    std::cout << name << std::endl;

    return 0;
}
