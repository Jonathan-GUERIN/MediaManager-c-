#ifndef MOTHER_MULTIMEDIA_H
#define MOTHER_MULTIMEDIA_H
#include <string>
#include <iostream>

using namespace std;

class Mother_multimedia
{
private:
    string name;
    string pathname;
public:
    Mother_multimedia();
    Mother_multimedia(string name, string pathname);
    ~Mother_multimedia();

    void setName(string name);
    void setPathname(string pathname);
    string getName() const;
    string getPathname() const;
    void display(ostream & who) const;
};

#endif // MOTHER_MULTIMEDIA_H
