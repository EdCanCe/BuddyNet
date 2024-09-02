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
        void loop();
    
        void createProfile();
        void accessProfile(); //Check password -> Local variables about user change??

        void showFeed(); //Change order, access to a post, create a post, quit
        void orderByVotes();
        void orderByDates();
        void accessPost(); //Takes to a menu to upvote or downvote and in a future comment

        void upvotePost();
        void downvotePost();

        void loadData();
        void storeData();

        //checar en pet vet: si en las clases de no tanta importancia dentro de otras clases se creaban con NEW o se creaban directamente

    public:
        void startNet();
};

void startNet(){
    screen.clear();
    
}

#endif