/*Edmundo Canedo Cervantes - A01645576 */
#include <iostream>
#include "BuddyNet.h"

int main(){
    Profile perfil=Profile(0, "Edmundo", "Eddy", "hola123", "ASDADAS", 2005, 4, 14);
    Post posteo=Post(0,perfil,"Probando con textos largos para ver si funciona algo o la vdd no funciona nada nada nadota.");


    std::cout<<screen.centerHorizontal(screen.text.style.bold(screen.text.color.blue( posteo.getAuthor().getName())) + " - " + screen.text.color.blue("@"+posteo.getAuthor().getUsername()))<<"\n";
    std::cout<<screen.centerHorizontal(posteo.getText())<<"\n";
    std::cout<<screen.text.color.blue(screen.text.style.dim(posteo.getDate().toText()))<<"\n";

    Net net;
    net.startNet();
}
