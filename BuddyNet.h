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
        Profile* user;
    
        void createProfile();
        void accessProfile(); //Check password -> Local variables about user change??
        int searchProfile(std::string);

        void home(); //Change order, access to a post, create a post, quit
        void showPosts();
        void orderByVotes();
        void orderByDates();
        void accessPost(); //Takes to a menu to upvote or downvote and in a future comment

        void upvotePost();
        void downvotePost();

        void freeMemory();
        void waitUser();

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
                createProfile();
                break;
            case 2: //Access profile
                accessProfile();
                break;
        }

    }while(q!=0);

    std::cout<<"\n\n"<<screen.center(screen.text.style.blinking(screen.text.color.yellow("Exiting...")))<<"\n\n\n";
    freeMemory();
}

void Net::createProfile(){
    screen.clear();

    std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.blue("Profile creation")))<<"\n\n";
    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your desired username: "));
    std::string username=input.getWord();
    while(searchProfile(username)>=0){
        std::cout<<screen.text.color.red("That username already exists.\n")+screen.text.style.italic(screen.text.color.green("Please type a different one: "));
        username=input.getWord();
    }

    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your full name: "));
    std::string name=input.getString();

    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your user's password: "));
    std::string password=input.getPassword();

    std::cout<<screen.text.style.italic(screen.text.color.green("Type your user's description: "));
    std::string description=input.getString();

    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your year of birth: "));
    int year=input.getInt(1950, 2050);

    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your month of birth: "));
    int month=input.getInt(1,12);

    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your day of birth: "));
    int day=input.getInt(1,31);

    profiles.push_back(new Profile(profiles.size(), name, username, password, description, year, month, day));
    std::cout<<"\n"<<screen.center(screen.text.color.yellow("Your profile has bean created succesfully."))<<"\n";
    std::cout<<screen.center(screen.text.color.yellow("Log in with the \"Access Profile\" option."))<<"\n\n";
    waitUser();
}

void Net::accessProfile(){
    screen.clear();

    std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.blue("Profile Access")))<<"\n\n";
    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your username: "));
    std::string username=input.getWord();
    int i=searchProfile(username);
    if(i==-1){
        std::cout<<"\n"<<screen.center(screen.text.color.red("Username not found."))<<"\n";
        std::cout<<"\n"<<screen.center(screen.text.color.yellow("Going back to main menu."))<<"\n\n";
        waitUser();
        return;
    }

    int c=1;
    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your user's password: "));
    std::string password=input.getPassword();
    while(!profiles[i]->validatePassword(password) && c<3){
        std::cout<<screen.text.color.red("Not the correct passowrd. Attempt No. "+input.getString(c)+" of 3.\n")+screen.text.style.italic(screen.text.color.green("Please try again: "));
        password=input.getPassword();
        c++;
    }
    if(!profiles[i]->validatePassword(password)){
        std::cout<<screen.text.color.red("Not the correct passowrd. Attempt No. "+input.getString(c)+" of 3.\n");
        std::cout<<"\n"<<screen.center(screen.text.color.red("Too many attempts."))<<"\n";
        std::cout<<"\n"<<screen.center(screen.text.color.yellow("Going back to main menu."))<<"\n\n";
        waitUser();
        return;
    }

    user=profiles[i];
    home();
}

int Net::searchProfile(std::string username){ //Complexity O(n)
    for(ll i=0; i<profiles.size(); i++){
        if(profiles[i]->getUsername()==username) return i;
    }
    return -1;
}

void Net::home(){
    int q;

    do{
        screen.clear();

        std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.magenta("BUDDY NET -> HOME")))<<"\n\n";
        std::cout<<"\n"<<screen.text.color.magenta("1.- See Posts")<<"\n";
        std::cout<<"\n"<<screen.text.color.magenta("2.- Order posts")<<"\n";
        std::cout<<"\n"<<screen.text.color.magenta("0.- Go back")<<"\n\n";
        std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type the number corresponding to what you want to do (0-2): "));
        q=input.getInt(0,2);

        switch(q){
            case 1: //See posts
                showPosts();
                break;
            case 2: //Order posts
                screen.clear();
                int x;
                std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.magenta("Order by:")))<<"\n\n";
                std::cout<<"\n"<<screen.text.color.magenta("1.- Date")<<"\n";
                std::cout<<"\n"<<screen.text.color.magenta("2.- Votes")<<"\n";
                std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type the number corresponding to what you want to select (1-2): "));
                x=input.getInt(1,2);
                switch(x){
                    case 1:
                        orderByDates();
                        break;
                    case 2:
                        orderByVotes();
                        break;
                }
                break;
        }

    }while(q!=0);
}

void Net::showPosts(){

}

void Net::orderByVotes(){

}

void Net::orderByDates(){

}

void Net::freeMemory(){
    for(Post* i:posts){
        delete i;
    }
    for(Profile* i:profiles){
        delete i;
    }
}

void Net::waitUser(){
    std::cout<<screen.center(screen.text.style.italic(screen.text.color.green("Type enter to continue.")));
    string s=input.getString();
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