#ifndef BUDDYNET_H
#define BUDDYNET_H

#include <iostream>
#include "Screen.h"
#include "Profile.h"
#include "Post.h"
#include "Input.h"
#include "Sorts.h"
#include "Notification.h"
#include "Structures.h"

class Net{
    private:

        vector<Profile*> profiles;
        vector<Post*> posts;
        Profile* user;
    
        void createProfile();
        void accessProfile(); 
        Profile* profileExists(std::string);
        Post* postExists(ll);

        void home(); 
        void showPosts(); // <- Falta añadir menú que muestre si se ven todos o solo de los últimos 3 días, verificar que solo salgan posts de los usuarios a dos de distancia
        void orderByVotes();
        void orderByDates();
        void createPost();
        void gotoSearch(); //NO SE HA HECHO LA FUNCIÓN
        void showPost(Post*); //Takes to a menu to upvote, downvote and comment - Furue implementation
        void showProfile(Profile*); //NO SE HA HECHO LA FUNCIÓN
        void upvotePost();
        void downvotePost();
        void gotoNotis();

        void freeMemory();
        void waitUser();

        void testData();

        void loadData(); 
        void storeData();

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

    loadData();
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
    storeData();
    freeMemory();
}

void Net::createProfile(){
    screen.clear();

    std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.blue("Profile creation")))<<"\n\n";
    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your desired username: "));
    std::string username=input.getRawString(input.getWord());
    while(profileExists(username) != 0){
        std::cout<<screen.text.color.red("That username already exists.\n")+screen.text.style.italic(screen.text.color.green("Please type a different one: "));
        username=input.getRawString(input.getWord());
    }

    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your full name: "));
    std::string name=input.getString();

    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your user's password: "));
    std::string password=input.getPassword();

    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your user's description: "));
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
    std::string username=input.getRawString(input.getWord());
    Profile* pPtr=profileExists(username);
    if(pPtr==0){
        std::cout<<"\n"<<screen.center(screen.text.color.red("Username not found."))<<"\n";
        std::cout<<"\n"<<screen.center(screen.text.color.yellow("Going back to main menu."))<<"\n\n";
        waitUser();
        return;
    }

    int c=1;
    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your user's password: "));
    std::string password=input.getPassword();
    while(!pPtr->validatePassword(password) && c<3){
        std::cout<<screen.text.color.red("Not the correct passowrd. Attempt No. "+input.getString(c)+" of 3.\n")+screen.text.style.italic(screen.text.color.green("Please try again: "));
        password=input.getPassword();
        c++;
    }
    if(!pPtr->validatePassword(password)){
        std::cout<<screen.text.color.red("Not the correct passowrd. Attempt No. "+input.getString(c)+" of 3.\n");
        std::cout<<"\n"<<screen.center(screen.text.color.red("Too many attempts."))<<"\n";
        std::cout<<"\n"<<screen.center(screen.text.color.yellow("Going back to main menu."))<<"\n\n";
        waitUser();
        return;
    }

    user=pPtr;
    home();
}

Profile* Net::profileExists(std::string username){ //Complexity O(n)
    for(ll i=0; i<profiles.size(); i++){
        if(profiles[i]->getUsername()==username) return profiles[i];
    }
    return 0;
}

Post* Net::postExists(ll postID){
    std::cout<<screen.text.color.red("AAAAA "+input.getString(postID)+" AAAAA");
    for(ll i=0; i<posts.size(); i++){
        if(posts[i]->getId()==postID) return posts[i];
    }
    return 0;
}

void Net::home(){
    int q;

    do{
        screen.clear();

        std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.magenta("BUDDY NET -> HOME")))<<"\n\n";
        std::cout<<"\n"<<screen.text.color.green("1.- See Posts")<<"\n";
        std::cout<<"\n"<<screen.text.color.green("2.- Order posts")<<"\n";
        std::cout<<"\n"<<screen.text.color.green("3.- Create post")<<"\n";
        std::cout<<"\n"<<screen.text.color.green("4.- Go to the search section")<<"\n";
        std::cout<<"\n"<<screen.text.color.green("5.- View notifications")<<"\n";
        std::cout<<"\n"<<screen.text.color.green("0.- Go back")<<"\n\n";
        std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type the number corresponding to what you want to do (0-5): "));
        q=input.getInt(0,5);

        switch(q){
            case 1: //See posts
                showPosts();
                break;
            case 2: //Order posts
                screen.clear();
                int x;
                std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.magenta("Order by:")))<<"\n\n";
                std::cout<<"\n"<<screen.text.color.green("1.- Date" + (sorts.currentSort() == false ? screen.text.style.italic(" -> Current order") : "" ))<<"\n";
                std::cout<<"\n"<<screen.text.color.green("2.- Votes" + (sorts.currentSort() == true ? screen.text.style.italic(" -> Current order") : ""))<<"\n";
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
            case 3:
                createPost();
                break;
            case 4:
                gotoSearch();
                break;
            case 5:
                gotoNotis();
                break;
        }

    }while(q!=0);
}

void Net::showPosts(){
    screen.clear();
    std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.green("BUDDY NET -> POSTS")))<<"\n\n\n";

    ll ps=posts.size();
    if(ps==0){
        std::cout<<"\n"<<screen.center(screen.text.color.red("There are no posts to show."))<<"\n";
        std::cout<<"\n"<<screen.center(screen.text.color.yellow("Going back home."))<<"\n\n";
        waitUser();
        return;
    }

    ps--;
    for(ll i=0; i<ps; i++){
        posts[i]->print();
        std::cout<<"\n";
        for(int j=0; j<3; j++)std::cout<<screen.center(screen.text.style.bold(screen.text.color.green("║")))<<"\n";
    }
    posts[ps]->print();
    std::cout<<"\n\n";

    std::cout<<screen.center(screen.text.color.yellow("Going back home."))<<"\n\n";
    waitUser();
}

void Net::orderByVotes(){ //Merge Sort - Complexity O(n log n)
    sorts.setVotes();
    vector<Post*> v2(posts.size());
    sorts.mergeSplit(posts, v2, 0, posts.size()-1);
}

void Net::orderByDates(){ //Merge Sort - Complexity O(n log n)
    sorts.setDates();
    vector<Post*> v2(posts.size());
    sorts.mergeSplit(posts, v2, 0, posts.size()-1);
}

void Net::createPost(){
    screen.clear();
    std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.magenta("Post creation")))<<"\n\n";
    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your post: "));
    std::string text=input.getString();
    posts.push_back(new Post(posts.size(), *user, text));

    if(sorts.currentSort() == true){ //Means it's ordered by votes
        orderByVotes();
    }
}

void Net::gotoSearch(){
    screen.clear();
    std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.cyan("Search")))<<"\n\n";
    std::cout<<"\n"<<screen.center(screen.text.style.italic(screen.text.color.green("Type \"[XX\" to go to that post. Only type the text to go to a username.")))<<"\n";
    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your search: "));
    std::string searchText=input.getWord();

    if(searchText[0]=='['){ //It's a post
        //Añadir algo que confirme que sea número
        searchText=input.getRawString(searchText);
        Post* pPtr=postExists(input.getInt(searchText));
        if(pPtr==0){ //Post doesn't exist
            std::cout<<"\n"<<screen.center(screen.text.color.red("Post not found."))<<"\n";
            std::cout<<"\n"<<screen.center(screen.text.color.yellow("Going back to main menu."))<<"\n\n";
            waitUser();
            return;
        }else{ //Post does exist
            showPost(pPtr);
        }
    }else{ //It's a user
        Profile* pPtr=profileExists(searchText);
        if(pPtr==0){ //User doesn't exist
            std::cout<<"\n"<<screen.center(screen.text.color.red("Username not found."))<<"\n";
            std::cout<<"\n"<<screen.center(screen.text.color.yellow("Going back to main menu."))<<"\n\n";
            waitUser();
            return;
        }else{ //User does exist
            showProfile(pPtr);
        }
    }
}

void Net::showPost(Post* pPtr){
    int q;

    do{
        screen.clear();

        std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.green("Post")))<<"\n\n";
        pPtr->print();
        std::cout<<"\n\n";

        std::cout<<"\n"<<screen.text.color.green("1.- Upvote the post")<<"\n";
        std::cout<<"\n"<<screen.text.color.green("2.- Downvote the post")<<"\n";
        std::cout<<"\n"<<screen.text.color.green("3.- Redirect to the post's author")<<"\n";
        std::cout<<"\n"<<screen.text.color.green("4.- Comment this post")<<"\n";
        std::cout<<"\n"<<screen.text.color.green("5.- See this post's comments")<<"\n";
        std::cout<<"\n"<<screen.text.color.green("0.- Go back")<<"\n\n";
        std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type the number corresponding to what you want to do (0-3): "));
        q=input.getInt(0,5);

        bool x;
        switch(q){
            case 1:
                x=pPtr->upvote(user);
                if(x==true){
                    std::cout<<"\n"<<screen.center(screen.text.color.green("The post was upvoted succesfully!"))<<"\n";
                }else{
                    std::cout<<"\n"<<screen.center(screen.text.color.red("The post coulnd't be upvoted."))<<"\n";
                }
                std::cout<<screen.center(screen.text.color.yellow("Going back home."))<<"\n\n";
                waitUser();
                return;
                break;
            case 2: //Order posts
                x=pPtr->downvote(user);
                if(x==true){
                    std::cout<<"\n"<<screen.center(screen.text.color.green("The post was downvoted succesfully!"))<<"\n";
                }else{
                    std::cout<<"\n"<<screen.center(screen.text.color.red("The post coulnd't be downvoted."))<<"\n";
                }
                std::cout<<screen.center(screen.text.color.yellow("Going back home."))<<"\n\n";
                waitUser();
                return;
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        }

    }while(q!=0);
}

void Net::showProfile(Profile* pPtr){
    
}

void Net::gotoNotis(){
    
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

void Net::loadData(){

}

void Net::storeData(){
    FILE *fp=freopen("database.txt", "w", stdout);

    for(int i=0; i<profiles.size(); i++){
        
    }

    fclose(fp);
    #ifdef _WIN32
    freopen("CON", "w", stdout);
    #else
    freopen("/dev/tty","w", stdout);
    #endif
}

void Net::testData(){
    profiles.push_back(new Profile(0, "Edmundo Canedo Cervantes", "edcance", "contrasena", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer nec odio. Praesent libero. Sed cursus ante dapibus diam.", 2000, 1, 1));

    profiles.push_back(new Profile(1, "Juan Perez", "jotape", "contrasena", "Proin fermentum leo vel orci porta non. Ut tristique est sit amet arcu aliquam, in aliquam purus bibendum. Sed ut perspiciatis unde omnis.", 2000, 1, 1));

    profiles.push_back(new Profile(2, "Ana Martinez", "analaquetienelana", "contrasena", "Sed nisi. Nulla quis sem at nibh elementum imperdiet. Duis sagittis ipsum. Praesent mauris. Fusce nec tellus sed augue semper auctor.", 1995, 6, 15));

    vector<long long int> v={0, 1, 2}, v2={};
    posts.push_back(new Post(0, *profiles[0],  "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));
    posts.push_back(new Post(1, *profiles[1], "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));
    
    posts.push_back(new Post(2, *profiles[2], v, v2, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));
    posts.push_back(new Post(3, *profiles[0], v2, v, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));

    v={0,1};
    posts.push_back(new Post(4, *profiles[1], v, v2, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));
    posts.push_back(new Post(5, *profiles[2], v2, v, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));

    v2={2};
    posts.push_back(new Post(6, *profiles[0], v, v2, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));
    posts.push_back(new Post(7, *profiles[1], v2, v, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum. Sed sit amet eros ut urna luctus cursus."));
}

#endif
