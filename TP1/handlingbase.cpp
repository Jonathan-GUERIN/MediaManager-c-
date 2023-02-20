#include "handlingbase.h"
#include <iostream>

using namespace std;

shared_ptr<Mother_multimedia> HandlingBase::createPhoto(string name, string pathname, unsigned int latitude, unsigned int longitude){
    shared_ptr<Photo> photo(new Photo(name, pathname, latitude, longitude));
    allMedias[name] = photo;
    return allMedias[name];
}

shared_ptr<Mother_multimedia> HandlingBase::createVideo(string name, string pathname, unsigned int duree){
    shared_ptr<Video> video(new Video(name, pathname, duree));
    allMedias[name] = video;
    return allMedias[name];
}

shared_ptr<Mother_multimedia> HandlingBase::createFilm(string name, string pathname, unsigned int duree,int * _chapters, unsigned int _count){
    shared_ptr<Film> film(new Film(name, pathname, duree, _chapters, _count));
    allMedias[name] = film;
    return allMedias[name];
}

shared_ptr<Group> HandlingBase::createGroup(string name){
    shared_ptr<Group> group(new Group(name));
    allGroups[name] = group;
    return allGroups[name];
}


void HandlingBase::removeMedia(string name){
    shared_ptr<Mother_multimedia> media = searchMedia(name);
    if(media != nullptr){
        allMedias.erase(name);
    }
}

void HandlingBase::removeGroup(string name){
    shared_ptr<Group> group = searchGroup(name);
    if(group != nullptr){
        allGroups.erase(name);
    }
}


shared_ptr<Mother_multimedia> HandlingBase::searchMedia(string name) const{
    auto iterator = allMedias.find(name);
    if(iterator != allMedias.end()){
        return iterator->second;
    }
    cerr << name << ": media not found" << endl;
    return nullptr;
}

shared_ptr<Group> HandlingBase::searchGroup(string name) const{
    auto iterator = allGroups.find(name);
    if(iterator != allGroups.end()){
        return iterator->second;
    }
    cerr << name << ": group not found" << endl;
    return nullptr;
}

void HandlingBase::displayMedia(string name) const{
    shared_ptr<Mother_multimedia> media = searchMedia(name);
    if(media != nullptr){
        media->display(cout);
    }
    cout << name << ": media not found" << endl;
}

void HandlingBase::displayGroup(string name) const{
    shared_ptr<Group> group = searchGroup(name);
    if(group != nullptr){
        group->showGroup(cout);
    }
    cout << name << ": group not found" << endl;
}


void HandlingBase::playMedia(string name) const{
    shared_ptr<Mother_multimedia> media = searchMedia(name);
    if(media != nullptr){
        media->play();
    }
    cout << name << ": media not found" << endl;
}
