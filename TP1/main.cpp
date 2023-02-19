//
// main.cpp
// Created on 21/10/2018
//

#include "mother_multimedia.h"
#include "photo.h"
#include "video.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char* argv[])
{
    std::cout << "Hello brave new world" << std::endl;

    //Mother_multimedia * test = new Mother_multimedia("test1","/cal/exterieurs/jguerin-21/inf224/TP1/");
    //test->display(std::cout);
    //string name = test->getName();
    //std::cout << name << std::endl;

    Photo * photo = new Photo("test_photo","/cal/exterieurs/jguerin-21/inf224/TP1/lena.tif",5,5);
    photo->display(std::cout);
    //photo->play();
    //delete photo;

    Video * video = new Video("test_video","/cal/exterieurs/jguerin-21/inf224/TP1/sample.webm",2);
    video->display(std::cout);
    //video->play();
    //delete video;

    // On ne peut plus instancier la classe mère car elle est devenue virtuelle suite à l'ajout d'une méthode abstraite à celle-ci.

    Mother_multimedia ** objects = new Mother_multimedia *[2];
    objects[0] = photo;
    objects[1] = video;

    for(unsigned int i=0; i < 2; ++i){
        objects[i]->display(std::cout);
        objects[i]->play();
    }

    //Question 5
    //Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?
    //on peut traiter ces objects de la même manière dans le tableau grâce au polymorphisme des classes, une photo est à la fois une Photo et une Mother_multimedia.
    //Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?
    //Il faut impérativement préciser que la méthode utilisée sera virtual dans la classe mère (puis override dans la classe fille).
    //Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.
    //Le tableau est composé de Mother_multimedia et doit contenir des pointeurs de ces objets, si l'on stockait les objets directement il seraient stockés dans la pile (mémoirme automatique)
    // En Java, on ne peut en revanche que faire des tableaux de pointeurs pour les objets, en C++ on peut faire des tableaux de type de base et d'objets.

    return 0;
}
