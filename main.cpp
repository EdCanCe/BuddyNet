/*Edmundo Canedo Cervantes - A01645576 */
#include <iostream>
#include "BuddyNet.h"

int main(){
    Profile perfil=Profile(0, "Edmundo", "Eddy", "hola123", "ASDADAS", 2005, 4, 14);
    Post posteo=Post(0,perfil,"Jajaja que pedo banda");


    std::cout<<screen.text.style.bold(screen.text.color.blue( posteo.getAuthor().getName() ))<<" - ";
    std::cout<<screen.text.color.blue("@"+posteo.getAuthor().getUsername())<<"\n";
    std::cout<<posteo.getText()<<"\n";
    std::cout<<screen.text.color.blue(screen.text.style.dim(posteo.getDate().toText()) )<<"\n";

    Net net;
    net.startNet();
}
