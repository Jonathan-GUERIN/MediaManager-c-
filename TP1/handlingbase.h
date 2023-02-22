#ifndef HANDLINGBASE_H
#define HANDLINGBASE_H
#include <string>
#include <iostream>
#include "mother_multimedia.h"
#include "group.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include <map>
#include <memory>

using namespace std;

class HandlingBase
{
private:
    map<string,shared_ptr<Mother_multimedia>> allMedias;
    map<string,shared_ptr<Group>> allGroups;
public:
    HandlingBase() : allMedias(), allGroups() {}
    HandlingBase(map<string,shared_ptr<Mother_multimedia>> allMedias, map<string,shared_ptr<Group>> allGroups){
        this->allMedias = allMedias;
        this->allGroups = allGroups;
    }
    ~HandlingBase() {};

    shared_ptr<Mother_multimedia> createPhoto(string name, string pathname, unsigned int latitude, unsigned int longitude);
    shared_ptr<Mother_multimedia> createVideo(string name, string pathname, unsigned int duree);
    shared_ptr<Mother_multimedia> createFilm(string name, string pathname, unsigned int duree,int * _chapters, unsigned int _count);
    shared_ptr<Group> createGroup(string name);

    void removeMedia(string name);
    void removeGroup(string name);

    shared_ptr<Mother_multimedia> searchMedia(string name) const;
    shared_ptr<Group> searchGroup(string name) const;
    void displayMedia(string name) const;
    void displayGroup(string name) const;

    void playMedia(string name) const;
    bool processRequest(std::string const & request);
};

#endif // HANDLINGBASE_H
