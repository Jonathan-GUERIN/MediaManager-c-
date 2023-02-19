#ifndef MOTHER_MULTIMEDIA_H
#define MOTHER_MULTIMEDIA_H
#include <string>
#include <iostream>

using namespace std;

class Mother_multimedia
{
private:
    string name = "";
    string pathname = "";
public:
    Mother_multimedia();
    Mother_multimedia(string name, string pathname);
    virtual ~Mother_multimedia() {}

    void setName(string name);
    void setPathname(string pathname);
    string getName() const;
    string getPathname() const;
    void display(ostream & who) const;
    virtual void play() const = 0;
    /*
     * la méthode play est abstraite (virtuelle) car l'implémentation est différente selon l'objet
     */
};

#endif // MOTHER_MULTIMEDIA_H
