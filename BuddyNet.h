#ifndef BUDDYNET_H
#define BUDDYNET_H

#include <iostream>
#include "Screen.h"
#include "Profile.h"
#include "Post.h"
#include "Input.h"
#include "Database.h"
#include "Structures.h"

class Net{
    private:
        vector<Profile*> profiles;
        vector<Post*> posts;
        vector<Post*> postsIndex; //To access the posts with their ID;

        void loop();
    
        void createProfile();
        void accessProfile(); //Check password -> Local variables about user change??

        void showFeed(); //Change order, access to a post, create a post, quit
        void orderByVotes();
        void orderByDates();
        void accessPost(); //Takes to a menu to upvote or downvote and in a future comment

        void upvotePost();
        void downvotePost();

        void freeMemory();

        void testData();

        /*void loadData(); - Future Implementation
        void storeData();*/

        //checar en pet vet: si en las clases de no tanta importancia dentro de otras clases se creaban con NEW o se creaban directamente

    public:
        void startNet();
};

void Net::startNet(){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #else
    std::setlocale(LC_ALL, "");
    #endif
    
    
    int q;

    testData();

    do{
        screen.clear();
        std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.green("BUDDY NET")))<<"\n\n";
        std::cout<<"\n"<<screen.text.color.green("1.- Create Profile")<<"\n";
        std::cout<<"\n"<<screen.text.color.green("2.- Access Profile")<<"\n";
        std::cout<<"\n"<<screen.text.color.green("0.- Exit")<<"\n\n";
        std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type the number corresponding to what you want to do (0-2): "));
        q=input.getInt(0,2);
        switch(q){
            case 1: //Create profile
                break;
            case 2: //Acces profile
                break;
        }

    }while(q!=0);
    std::cout<<"\n\n"<<screen.center(screen.text.style.blinking(screen.text.color.yellow("Exiting...")))<<"\n\n\n";
    freeMemory();
}

void Net::freeMemory(){
    for(Post* i:posts){
        delete i;
    }
    for(Profile* i:profiles){
        delete i;
    }
}

void Net::testData(){
    profiles.push_back(new Profile(0, "Edmundo Canedo Cervantes", "EdCanCe", "contrasena", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer nec odio. Praesent libero. Sed cursus ante dapibus diam.", 2000, 1, 1));

    profiles.push_back(new Profile(1, "Juan Perez", "JotaPe", "contrasena", "Proin fermentum leo vel orci porta non. Ut tristique est sit amet arcu aliquam, in aliquam purus bibendum. Sed ut perspiciatis unde omnis.", 2000, 1, 1));

    profiles.push_back(new Profile(2, "Ana Martinez", "AnaLaQueTieneLana", "contrasena", "Sed nisi. Nulla quis sem at nibh elementum imperdiet. Duis sagittis ipsum. Praesent mauris. Fusce nec tellus sed augue semper auctor.", 1995, 6, 15));

    posts.push_back(new Post(0, *profiles[0], -12,  "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));
    posts.push_back(new Post(1, *profiles[1], 5, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));
    posts.push_back(new Post(2, *profiles[2], -3, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));
    posts.push_back(new Post(3, *profiles[0], 10, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));
    posts.push_back(new Post(4, *profiles[1], -8, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));
    posts.push_back(new Post(5, *profiles[2], 16, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));
    posts.push_back(new Post(6, *profiles[0], -20, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));
    posts.push_back(new Post(7, *profiles[1], 4, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));
    posts.push_back(new Post(8, *profiles[2], 11, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));
    posts.push_back(new Post(9, *profiles[0], 7, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));

    postsIndex=posts;

}

#endif