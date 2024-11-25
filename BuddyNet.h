#ifndef BUDDYNET_H
#define BUDDYNET_H

#include <iostream>
#include <fstream>
#include <cstdio>
#include "Profile.h"
#include "Post.h"
#include "Notification.h"
#include "Structures.h"
#include "Sorts.h"
#include "Screen.h"
#include "Input.h"

/**
 * @class Net
 * 
 * Contains all methods and attributes to execute
 * the program.
 */
class Net{
    private:
        vector<Profile*> profiles; //Vector that stores all the profile data
        vector<Post*> posts; //Vector that stpres all the posts data
        Profile* user; //Pointer referencing the current user
    
        void createProfile();
        void accessProfile(); 
        Profile* profileExists(vector<Profile*>&, std::string);
        Profile* profileExists(std::string);
        Post* postExists(ll);

        void home(); 
        void showPosts();
        void showPosts(Profile*);
        void orderByVotes();
        void orderByDates();
        void orderProfiles(vector<Profile*>&);
        void createPost();
        void gotoSearch();
        void showPost(Post*);
        void showProfile(Profile*);
        void gotoNotis();

        void freeMemory();
        void waitUser();

        void loadData(); 
        void storeData();

    public:
        void startNet();
};

/**
 * @brief Starts the execution of the program.
 * 
 * Shows the main menu to let the user select what they want to do.
 */
void Net::startNet(){
    //Checks the type of the system, depending on it, sets the output.
    #ifdef _WIN32 
    SetConsoleOutputCP(CP_UTF8);
    #else
    std::setlocale(LC_ALL, "");
    #endif
    
    int q; //Auxiliar variable used to store the user's input.

    loadData(); //Loads all the data that was saved.

    do{ //Loops the user's actions.
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

    storeData(); //Saves all the data, both the new one and the previous one.
    freeMemory(); //Deletes the objects created during the execution to free the memory.
}

/**
 * @brief Shows a screen to let the user create it's own
 * profile.
 * 
 */
void Net::createProfile(){
    screen.clear();

    std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.blue("BUDDY NET -> PROFILE CREATION")))<<"\n\n";
    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your desired username: "));
    std::string username=input.getRawString(input.getWord());
    while(profileExists(username) != 0){ //Checks if the username the user wants is already taken
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
    orderProfiles(profiles);
    std::cout<<"\n"<<screen.center(screen.text.color.yellow("Your profile has bean created succesfully."))<<"\n";
    std::cout<<screen.center(screen.text.color.yellow("Log in with the \"Access Profile\" option."))<<"\n\n";
    waitUser();
}

/**
 * @brief Shows a screen used for the user to log in.
 * 
 */
void Net::accessProfile(){
    screen.clear();

    std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.blue("BUDDY NET -> PROFILE ACCESS")))<<"\n\n";
    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your username: "));
    std::string username=input.getRawString(input.getWord());
    Profile* pPtr=profileExists(username);
    if(pPtr==0){ //In case the username doesn't exist, takes the user back to the main menu
        std::cout<<"\n"<<screen.center(screen.text.color.red("Username not found."))<<"\n";
        std::cout<<"\n"<<screen.center(screen.text.color.yellow("Going back to main menu."))<<"\n\n";
        waitUser();
        return;
    }

    int c=1;
    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your user's password: "));
    std::string password=input.getPassword();
    while(!pPtr->validatePassword(password) && c<3){ //In case the password doesn't match, the user has 3 attempts to try to log in
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
    home(); //Takes the user to the home menu
}

/**
 * @brief Checks if a profile exists given a username.
 * It has a time complexity of O(log n) because it uses
 * a binary search algorithm to search for it.
 * 
 * @param username The user's username.
 * @return Profile* The pointer to that user's data.
 */
Profile* Net::profileExists(std::string username){
    ll x=sorts.binarySearch(profiles, username);
    if(x==-1) return 0;
    return profiles[x];
}

/**
 * @brief Checks if a profile exists given a username.
 * It has a time complexity of O(log n) because it uses
 * a binary search algorithm to search for it.
 * 
 * @param v The vector to check if it is in.
 * @param username The user's username.
 * @return Profile* The pointer to that user's data.
 */
Profile* Net::profileExists(vector<Profile*>& v, std::string username){
    ll x=sorts.binarySearch(v, username);
    if(x==-1) return 0;
    return v[x];
}

/**
 * @brief Checks if a post exists given an ID.
 * It has a time complexity of O(n) because it uses
 * a linear search algorithm.
 * 
 * @param postID The post's ID.
 * @return Post* The pointer to that post's data.
 */
Post* Net::postExists(ll postID){
    for(ll i=0; i<posts.size(); i++){
        if(posts[i]->getId()==postID) return posts[i];
    }
    return 0;
}

/**
 * @brief Shows the screen of the home menu, lets
 * the user select what they want to do.
 * 
 */
void Net::home(){
    int q; //Auxiliar variable used to store the user's input.

    do{ //Loops the user's actions
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

    }while(q!=0); //Returns to the main menu
}

/**
 * @brief Shows a list of all the posts posted in the user's friend net.
 * Depending on the sorting type that the user chose it can
 * list them sorting them by date or votes. It's time complexity
 * is O(V'+E'+V' log(V')+n log(V')+V'), simplyfing it O(V' log(V')).
 * 
 */
void Net::showPosts(){
    screen.clear();
    std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.green("BUDDY NET -> HOME -> POSTS")))<<"\n\n\n";

    //Obtains the user's friend net and sorts it
    vector<Profile*> userNet=user->getNet();
    orderProfiles(userNet);

    //Filters posts by authors
    ll ps=posts.size();
    vector<Post*> netPosts;
    for(ll i=0; i<ps;i++){
        if(profileExists(userNet, posts[i]->getAuthor().getUsername())!=0){
            netPosts.push_back(posts[i]);
        }
    }

    ps=netPosts.size();
    if(ps==0){ //In case there are no posts to show
        std::cout<<"\n"<<screen.center(screen.text.color.red("There are no posts to show."))<<"\n";
        std::cout<<"\n"<<screen.center(screen.text.color.yellow("Going back home."))<<"\n\n";
        waitUser();
        return;
    }

    //Shows the posts
    ps--;
    for(ll i=0; i<ps; i++){
        netPosts[i]->print();
        std::cout<<"\n";
        for(int j=0; j<3; j++)std::cout<<screen.center(screen.text.style.bold(screen.text.color.green("║")))<<"\n";
    }
    netPosts[ps]->print();
    std::cout<<"\n\n";

    std::cout<<screen.center(screen.text.color.yellow("Going back home."))<<"\n\n";

    waitUser();
}

/**
 * @brief Shows all the post's a user has posted.
 * It has a time complexity of O(n).
 * 
 * @param pPtr The pointer to the profile.
 */
void Net::showPosts(Profile* pPtr){
    screen.clear();
    std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.green("POSTS FROM @"+pPtr->getUsername())))<<"\n\n\n";

    //Filters the posts by author.
    ll ps=posts.size();
    vector<Post*> userPosts;
    for(ll i=0; i<ps;i++){
        if(&posts[i]->getAuthor()==pPtr) userPosts.push_back(posts[i]);
    }

    ps=userPosts.size();
    if(ps==0){ //In case there are no posrts to show
        std::cout<<"\n"<<screen.center(screen.text.color.red("There are no posts to show."))<<"\n";
        std::cout<<"\n"<<screen.center(screen.text.color.yellow("Going back."))<<"\n\n";
        waitUser();
        return;
    }

    //Shows the posts
    ps--;
    for(ll i=0; i<ps; i++){
        userPosts[i]->print();
        std::cout<<"\n";
        for(int j=0; j<3; j++)std::cout<<screen.center(screen.text.style.bold(screen.text.color.green("║")))<<"\n";
    }
    userPosts[ps]->print();
    std::cout<<"\n\n";

    std::cout<<screen.center(screen.text.color.yellow("Going back home."))<<"\n\n";
    waitUser();
}

/**
 * @brief Sorts the posts by votes.
 * Since it uses a merge sort algorithm, it has a 
 * time complexity of O(n log(n)).
 */
void Net::orderByVotes(){
    sorts.setVotes();
    vector<Post*> v2(posts.size());
    sorts.mergeSplit(posts, v2, 0, posts.size()-1);
}

/**
 * @brief Sorts the posts by dates.
 * Since it uses a merge sort algorithm, it has a 
 * time complexity of O(n log(n)).
 */
void Net::orderByDates(){
    sorts.setDates();
    vector<Post*> v2(posts.size());
    sorts.mergeSplit(posts, v2, 0, posts.size()-1);
}

/**
 * @brief Sorts the profiles by their username.
 * Since it uses a merge sort algorithm, it has a 
 * time complexity of O(n log(n)).
 * 
 * @param v The vector to sort.
 */
void Net::orderProfiles(vector<Profile*>& v){
    vector<Profile*> v2(v.size());
    sorts.mergeSplit(v, v2, 0, v.size()-1);
}

/**
 * @brief Shows a screen to let the user create
 * a post. It has a time complexity of O(n log(n)).
 * 
 */
void Net::createPost(){
    screen.clear();
    std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.magenta("BUDDY NET -> HOME -> CREATE POST")))<<"\n\n";
    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your post: "));
    std::string text=input.getString();
    

    if(sorts.currentSort() == true){ //Means it's ordered by votes
        orderByDates();
        posts.push_back(new Post(posts.size(), *user, text));
        orderByVotes();
    }else{
        posts.push_back(new Post(posts.size(), *user, text));
    }
}

/**
 * @brief Takes the user to a certain post or
 * profile. It has a time complexity of O(n).
 * 
 */
void Net::gotoSearch(){
    screen.clear();
    std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.cyan("BUDDY NET -> HOME -> SEARCH")))<<"\n\n";
    std::cout<<"\n"<<screen.center(screen.text.style.italic(screen.text.color.green("Type \"[XX\" to go to that post. Only type the text to go to a username.")))<<"\n";
    std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type your search: "));
    std::string searchText=input.getWord();

    if(searchText[0]=='['){ //It's a post
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
        searchText=input.getRawString(searchText);
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

/**
 * @brief Shows a specific post and a menu to let 
 * the user select what they want to do.
 * 
 * @param pPtr The pointer to the post.
 */
void Net::showPost(Post* pPtr){
    int q; //Auxiliar variable used to store the user's input.

    do{ //Loops the user's actions.
        screen.clear();
        std::string aux;
        if(user->isInList(pPtr->getVotes(0))!=-1) aux=screen.text.color.red("Downvote");
        else if(user->isInList(pPtr->getVotes(1))!=-1) aux=screen.text.color.green("Upvote");
        else aux=aux=screen.text.color.white("None");;

        std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.green("POST")))<<"\n\n";
        pPtr->print();
        std::cout<<"\n\n"<<screen.center(screen.text.color.green("Current vote: "+aux))<<"\n";
        std::cout<<"\n\n";

        std::cout<<"\n"<<screen.text.color.green("1.- Upvote the post")<<"\n";
        std::cout<<"\n"<<screen.text.color.green("2.- Downvote the post")<<"\n";
        std::cout<<"\n"<<screen.text.color.green("3.- Remove my votes")<<"\n";
        std::cout<<"\n"<<screen.text.color.green("4.- Redirect to the post's author")<<"\n";
        std::cout<<"\n"<<screen.text.color.green("0.- Go back")<<"\n\n";
        std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type the number corresponding to what you want to do (0-3): "));
        q=input.getInt(0,6);

        bool x;
        switch(q){
            case 1: //Upvote the post
                x=pPtr->upvote(user);
                if(x==true){
                    std::cout<<"\n"<<screen.center(screen.text.color.green("The post was upvoted succesfully!"))<<"\n";
                    pPtr->getAuthor().getNotifications().push(new Notification("@"+user->getUsername()+" upvoted one of your posts.", 2, pPtr, user));
                }else{
                    std::cout<<"\n"<<screen.center(screen.text.color.red("The post couldn't be upvoted. Try erasing the votes."))<<"\n";
                }
                std::cout<<"\n"<<screen.center(screen.text.color.yellow("Going back."))<<"\n\n";
                waitUser();
                break;
            case 2: //Downvote the post
                x=pPtr->downvote(user);
                if(x==true){
                    std::cout<<"\n"<<screen.center(screen.text.color.green("The post was downvoted succesfully!"))<<"\n";
                    pPtr->getAuthor().getNotifications().push(new Notification("@"+user->getUsername()+" downvoted one of your posts.", 2, pPtr, user));
                }else{
                    std::cout<<"\n"<<screen.center(screen.text.color.red("The post coulnd't be downvoted. Try erasing the votes."))<<"\n";
                }
                std::cout<<"\n"<<screen.center(screen.text.color.yellow("Going back."))<<"\n\n";
                waitUser();
                break;
            case 3: //Erase the vote to a post
                x=pPtr->erasevote(user);
                if(x==true){
                    std::cout<<"\n"<<screen.center(screen.text.color.green("The votes were removed succesfully!"))<<"\n";
                }else{
                    std::cout<<"\n"<<screen.center(screen.text.color.red("There weren't any votes to erase."))<<"\n";
                }
                std::cout<<"\n"<<screen.center(screen.text.color.yellow("Going back."))<<"\n\n";
                waitUser();
                break;
            case 4: //Go to the authors profile
                showProfile(&pPtr->getAuthor());
                break;
        }

    }while(q!=0);
}

/**
 * @brief Shows a specific profile and a menu to let 
 * the user select what they want to do.
 * 
 * @param pPtr The pointer to the profile.
 */
void Net::showProfile(Profile* pPtr){
    int q; //Auxiliar variable used to store the user's input.

    do{ //Loops the user's actions.
        screen.clear();

        std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.green("PROFILE")))<<"\n\n";
        pPtr->print();
        std::cout<<"\n\n";

        bool same=pPtr==user;
        bool following=user->isInList(user->getFollows(), pPtr)!=-1;

        std::cout<<"\n"<<screen.text.color.green("1.- See this profile's posts")<<"\n";
        if(!same) std::cout<<"\n"<<screen.text.color.green("2.- " + std::string(following==true ? "Unfollow" : "Follow") + " this user")<<"\n";
        std::cout<<"\n"<<screen.text.color.green("0.- Go back")<<"\n\n";
        std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type the number corresponding to what you want to do (0-3): "));
        q=input.getInt(0,!same ? 2 : 1);

        if(following && q==2) q=3; //Depending on the following status, changes q to the corresponding value

        bool y;
        switch(q){
            case 1: //Shows all the posts the profile posted
                showPosts(pPtr);
                break;
            case 2: //Follows the profile
                y=user->addFollow(pPtr);
                if(y==true){
                    pPtr->getNotifications().push(new Notification("@"+user->getUsername()+" followed you", 1, nullptr, user));
                    std::cout<<"\n"<<screen.center(screen.text.color.green("The follow was successfull!"))<<"\n";
                }else{
                    std::cout<<"\n"<<screen.center(screen.text.color.red("You already followed this user."))<<"\n";
                }
                waitUser();
                break;
            case 3: //Unfollows the profile
                y=user->removeFollow(pPtr);
                if(y==true){
                    std::cout<<"\n"<<screen.center(screen.text.color.green("The unfollow was successfull!"))<<"\n";
                }else{
                    std::cout<<"\n"<<screen.center(screen.text.color.red("You didn't followed the user."))<<"\n";
                }
                waitUser();
                break;
        }

    }while(q!=0);
}

/**
 * @brief Shows the notifications that the user has. Shows
 * a menu to let the user decide what they want to do.
 * 
 */
void Net::gotoNotis(){
    int q; //Auxiliar variable used to store the user's input.

    do{ //Loops the user's actions.
        screen.clear();

        std::cout<<"\n\n"<<screen.center(screen.text.style.bold(screen.text.color.green("BUDDY NET -> HOME -> NOTIFICATIONS ("+input.getString(user->getNotifications().size())+")")))<<"\n\n";
        
        if(user->getNotifications().empty()){
            std::cout<<"\n"<<screen.center(screen.text.color.red("There are no notifications."))<<"\n";
            std::cout<<"\n"<<screen.center(screen.text.color.yellow("Going back to home."))<<"\n\n";
            waitUser();
            return;
        }

        user->getNotifications().top()->print();
        std::cout<<"\n\n";

        if(user->getNotifications().top()->getType()==0){ //Post comment
            std::cout<<"\n"<<screen.text.color.green("1.- Access the post")<<"\n";
            std::cout<<"\n"<<screen.text.color.green("2.- Redirect to the post's author")<<"\n";
            std::cout<<"\n"<<screen.text.color.green("3.- Mark this notification as seen")<<"\n";
            std::cout<<"\n"<<screen.text.color.green("0.- Go back")<<"\n";
            std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type the number corresponding to what you want to do (0-3): "));
            q=input.getInt(0,3);
            if(q==1) q=2;
            else if(q==2) q=1;
        }else if(user->getNotifications().top()->getType()==1){ //Profile follower
            std::cout<<"\n"<<screen.text.color.green("1.- Redirect to the follower's profile")<<"\n";
            std::cout<<"\n"<<screen.text.color.green("2.- Mark this notification as seen")<<"\n";
            std::cout<<"\n"<<screen.text.color.green("0.- Go back")<<"\n";
            std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type the number corresponding to what you want to do (0-3): "));
            q=input.getInt(0,2);
            if(q==2) q=3;
        }else{ //Liked post
            std::cout<<"\n"<<screen.text.color.green("1.- Access the post")<<"\n";
            std::cout<<"\n"<<screen.text.color.green("2.- Redirect to the liker's profile")<<"\n";
            std::cout<<"\n"<<screen.text.color.green("3.- Mark this notification as seen")<<"\n";
            std::cout<<"\n"<<screen.text.color.green("0.- Go back")<<"\n";
            std::cout<<"\n"<<screen.text.style.italic(screen.text.color.green("Type the number corresponding to what you want to do (0-3): "));
            q=input.getInt(0,3);
            if(q==1) q=2;
            else if(q==2) q=1;
        }

        bool x;
        switch(q){
            case 1: //Access profile
                showProfile(user->getNotifications().top()->getProfile());
                break;
            case 2: //Access post
                showPost(user->getNotifications().top()->getPost());
                break;
            case 3: //Next notification
                user->getNotifications().pop();
                break;
        }

    }while(q!=0);
}

/**
 * @brief Frees the memory that was used
 * throughout the program. It has a time
 * complexity of O(n).
 * 
 */
void Net::freeMemory(){
    for(Post* i:posts){
        delete i;
    }
    for(Profile* i:profiles){
        delete i;
    }
}

/**
 * @brief It waits for the user input to
 * continue the execution of the program.
 * 
 */
void Net::waitUser(){
    std::cout<<screen.center(screen.text.style.italic(screen.text.color.green("Type enter to continue.")));
    string s=input.getString();
}

/**
 * @brief Loads the data of all the actions performed
 * during previous executions. It has a time complexity
 * of O(P log(P) + C log(P) + C*k log(P) + N log(P) + N*K*C + N*K*log(P) + N + F log(P) + F*K log(P)).
 * 
 */
void Net::loadData(){
    ifstream inputFile("database.txt"); 
    string s;
    bool leftProfile=1; //Indicates if it's the first time a post is read.
    while(getline(inputFile, s)){ //Reads from the database file.
        if(s=="X") break;
        else if(s=="P"){ //Reads a profile
            std::string name, username, password, description, yearS, monthS, dayS, idS;
            int year, month, day, id;
            getline(inputFile, idS);
            getline(inputFile, name);
            getline(inputFile, username);
            getline(inputFile, password);
            getline(inputFile, description);
            getline(inputFile, yearS);
            getline(inputFile, monthS);
            getline(inputFile, dayS);
            id=input.getInt(idS);
            year=input.getInt(yearS);
            month=input.getInt(monthS);
            day=input.getInt(dayS);
            profiles.push_back(new Profile(id, name, username, password, description, year, month, day));
        }else if(s=="C"){ //Reads a post
            if(leftProfile==1){
                leftProfile=0;
                orderProfiles(profiles);
            }
            std::string idS, authorS;
            getline(inputFile, idS);
            getline(inputFile, authorS);
            ll id=input.getInt(idS);
            Profile* author=profileExists(authorS);

            std::string numVotesS, vote;
            getline(inputFile, numVotesS);
            ll numVotes=input.getInt(numVotesS);
            vector<Profile*> upvotes;
            for(ll i=0; i<numVotes; i++){
                getline(inputFile, vote);
                upvotes.push_back(profileExists(vote));
            }
            getline(inputFile, numVotesS);
            numVotes=input.getInt(numVotesS);
            vector<Profile*> downvotes;
            for(ll i=0; i<numVotes; i++){
                getline(inputFile, vote);
                downvotes.push_back(profileExists(vote));
            }

            std::string text, yearS, monthS, dayS, hourS, minuteS, secondS;
            ll year, month, day, hour, minute, second;
            getline(inputFile, text);
            getline(inputFile, yearS);
            getline(inputFile, monthS);
            getline(inputFile, dayS);
            getline(inputFile, hourS);
            getline(inputFile, minuteS);
            getline(inputFile, secondS);
            year=input.getInt(yearS);
            month=input.getInt(monthS);
            day=input.getInt(dayS);
            hour=input.getInt(hourS);
            minute=input.getInt(minuteS);
            second=input.getInt(secondS);

            posts.push_back(new Post(id, *author, upvotes, downvotes, text, year, month, day, hour, minute, second));
        }else if(s=="N"){ //Reads a notification
            std::string qS, userS;
            getline(inputFile, userS);
            getline(inputFile, qS);
            ll q=input.getInt(qS);
            Profile* curUser=profileExists(userS);
            Stack<Notification*> notis;
            for(ll i=0; i<q; i++){
                std::string text, yearS, monthS, dayS, hourS, minuteS, secondS, typeS, postS, profileS;
                ll year, month, day, hour, minute, second, type;
                getline(inputFile, text);
                getline(inputFile, yearS);
                getline(inputFile, monthS);
                getline(inputFile, dayS);
                getline(inputFile, hourS);
                getline(inputFile, minuteS);
                getline(inputFile, secondS);
                getline(inputFile, typeS);
                year=input.getInt(yearS);
                month=input.getInt(monthS);
                day=input.getInt(dayS);
                hour=input.getInt(hourS);
                minute=input.getInt(minuteS);
                second=input.getInt(secondS);
                type=input.getInt(typeS);

                getline(inputFile, postS);
                getline(inputFile, profileS);
                Post* notiPost=nullptr;
                Profile* notiProfile=nullptr;
                if(postS!="-1") notiPost=postExists(input.getInt(postS));
                if(profileS!="-1") notiProfile=profileExists(profileS);

                notis.push(new Notification(text, Date(year, month, day, hour, minute, second), type, notiPost, notiProfile));
            }
            Stack<Notification*> notiSend;
            while(!notis.empty()){
                notiSend.push(notis.top());
                notis.pop();
            }
            curUser->setNotifications(notiSend);
        }else if(s=="F"){ //Reads a follow
            std::string qS, userS;
            getline(inputFile, userS);
            getline(inputFile, qS);
            ll q=input.getInt(qS);
            Profile* curUser=profileExists(userS);
            for(ll i=0; i<q; i++){
                std::string aux;
                getline(inputFile, aux);
                curUser->addFollow(profileExists(aux));
            }
        }
    }
    inputFile.close(); 
}

/**
 * @brief It stores all the data related to profiles
 * and posts. It has a time complexity of O(n).
 * 
 */
void Net::storeData(){
    FILE *fp=freopen("database.txt", "w", stdout);

    for(auto i:profiles){ //Profiles
        cout<<"P\n";
        cout<<i->getId()<<"\n";
        cout<<i->getName()<<"\n";
        cout<<i->getUsername()<<"\n";
        cout<<i->getPassword()<<"\n";
        cout<<i->getDescription()<<"\n";
        cout<<i->getBirth().getYear()<<"\n";
        cout<<i->getBirth().getMonth()<<"\n";
        cout<<i->getBirth().getDay()<<"\n";
    }

    for(auto i:posts){ //Posts
        cout<<"C\n";
        cout<<i->getId()<<"\n";
        cout<<i->getAuthor().getUsername()<<"\n";

        ll aux=i->getVotes(1).size(); //Upvotes
        cout<<aux<<"\n";
        for(auto j:i->getVotes(1)){
            cout<<j->getUsername()<<"\n";
        }

        aux=i->getVotes(0).size(); //Downvotes
        cout<<aux<<"\n";
        for(auto j:i->getVotes(0)){
            cout<<j->getUsername()<<"\n";
        }

        cout<<i->getText()<<"\n";
        cout<<i->getDate().getYear()<<"\n";
        cout<<i->getDate().getMonth()<<"\n";
        cout<<i->getDate().getDay()<<"\n";
        cout<<i->getDate().getHour()<<"\n";
        cout<<i->getDate().getMinute()<<"\n";
        cout<<i->getDate().getSecond()<<"\n";
    }

    for(auto i:profiles){ //Notifications and follows
        cout<<"N\n";
        cout<<i->getUsername()<<"\n";
        cout<<i->getNotifications().size()<<"\n";
        while(!i->getNotifications().empty()){
            cout<<i->getNotifications().top()->toText()<<"\n";
            cout<<i->getNotifications().top()->getDate().getYear()<<"\n";
            cout<<i->getNotifications().top()->getDate().getMonth()<<"\n";
            cout<<i->getNotifications().top()->getDate().getDay()<<"\n";
            cout<<i->getNotifications().top()->getDate().getHour()<<"\n";
            cout<<i->getNotifications().top()->getDate().getMinute()<<"\n";
            cout<<i->getNotifications().top()->getDate().getSecond()<<"\n";
            cout<<i->getNotifications().top()->getType()<<"\n";
            if(i->getNotifications().top()->getPost()!=nullptr) cout<<i->getNotifications().top()->getPost()->getId()<<"\n";
            else cout<<"-1\n";
            if(i->getNotifications().top()->getProfile()!=nullptr) cout<<i->getNotifications().top()->getProfile()->getUsername()<<"\n";
            else cout<<"-1\n";
            i->getNotifications().pop();
        }

        cout<<"F\n";
        cout<<i->getUsername()<<"\n";
        cout<<i->getFollows().size()<<"\n";
        for(auto j:i->getFollows()){
            cout<<j->getUsername()<<"\n";
        }
    }

    cout<<"X";

    fclose(fp);
    #ifdef _WIN32 //Depending on the user's system selects their console as the output
    freopen("CON", "w", stdout);
    #else
    freopen("/dev/tty","w", stdout);
    #endif
}

#endif