//
// main.cpp
// Created on 21/10/2018
//

#include "mother_multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "handlingbase.h"
#include "tcpserver.h"
#include <iostream>
#include <string>
#include <memory>
#define VERSION2

using namespace std;
#ifdef VERSION1
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
        //objects[i]->play();
    }

    //Question 5
    //Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?
    //on peut traiter ces objects de la même manière dans le tableau grâce au polymorphisme des classes, une photo est à la fois une Photo et une Mother_multimedia.
    //Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?
    //Il faut impérativement préciser que la méthode utilisée sera virtual dans la classe mère (puis override dans la classe fille).
    //Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.
    //Le tableau est composé de Mother_multimedia et doit contenir des pointeurs de ces objets, si l'on stockait les objets directement il seraient stockés dans la pile (mémoirme automatique)
    // En Java, on ne peut en revanche que faire des tableaux de pointeurs pour les objets, en C++ on peut faire des tableaux de type de base et d'objets.

    int * chap = new int[2];
    Film * film = new Film("test_video","/cal/exterieurs/jguerin-21/inf224/TP1/sample.webm",2,chap,2);
    film->showChapters(std::cout);

    //Question 8 et 9
    //Group * group = new Group("test_group");
    shared_ptr<Photo> photo2(new Photo("test_photo2", "/cal/exterieurs/jguerin-21/inf224/TP1/lena.tif", 5, 5));
    shared_ptr<Video> video2(new Video("test_video2", "/cal/exterieurs/jguerin-21/inf224/TP1/sample.webm", 2));
    shared_ptr<Film> film2(new Film("test_film2", "/cal/exterieurs/jguerin-21/inf224/TP1/sample.webm", 2, chap, 2));
    shared_ptr<Group> group1(new Group("Test group 1"));
    group1->push_back(photo2);
    group1->push_back(video2);
    group1->push_back(film2);

    //printing elements
    for (auto & it : * group1)
    {
        it->display(cout);
    }

    //p.reset() makes the smart pointer points to nowhere
    group1.reset();
    if (group1.use_count() != 0) {cout << "reset n'a pas marché" << endl;}
    else {cout << "le reset a fonctionné" << endl; }

    //Question 10
    HandlingBase * base = new HandlingBase();
    base->createPhoto("test_photo2", "/cal/exterieurs/jguerin-21/inf224/TP1/lena.tif", 5, 5);
    base->createVideo("test_video2", "/cal/exterieurs/jguerin-21/inf224/TP1/sample.webm", 2);
    base->createFilm("test_film2", "/cal/exterieurs/jguerin-21/inf224/TP1/sample.webm", 2, chap, 2);
    base->createGroup("Test group 1");

    base->displayMedia("test_photo2");
    base->playMedia("test_photo2");
    base->removeMedia("test_video2");
    base->displayMedia("test_video2");
    base->displayGroup("Test group 1");

    //Les méthodes précédentes permettent d'assurer la cohérence de la base de données car quand on crée un objet on l'ajoute à la table adéquate.
    //Par contre, ce ne sera pas le cas si on crée un objet directement avec new (il n'appartiendra à aucune table).
    //Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ?
    //Il suffit d'interdire l'accès à new en mettant le constructeur de ces objets dans la classe friend au lieu de public,
    //il faut ensuite faire attention à bien indiquer les méthodes qui appellent ce constructeurs comme étant friend.

    return 0;
}
#endif

#ifdef VERSION2

const int PORT = 3331;

int main(int argc, const char* argv[])
{
    HandlingBase * base = new HandlingBase();
    cout << "Partie serveur issue de server.cpp";
    // cree le TCPServer
    auto * server = new TCPServer([&base](std::string const &request, std::string &response) {
            //std::function< bool(std::string const& request, std::string& response) >;
            //TCPServer(Callback const &callback)
            // the request sent by the client to the server
            std::cout << "request: " << request << std::endl;

            // the response that the server sends back to the client
            //response = "RECEIVED: " + request;
            //response = "0here";

            // return false would close the connection with the client
            base->processRequest(request);
            return true;
    });


    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;
    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
      std::cerr << "Could not start Server on port " << PORT << std::endl;
      return 1;
    }

    return 0;
}
#endif
