/*Edmundo Canedo Cervantes - A01645576 */
#include <iostream>
#define fore(i, l, r) for (long long i = (l); i < (r); i++)
#define rfc "\033[31;1m"
#define gfc "\033[32;1m"
#define yfc "\033[33;1m"
#define bfc "\033[34;1m"
#define pfc "\033[35;1m"
#define cfc "\033[36;1m"
#define nfc "\033[0m"

#include "Screen.h"

int main(){
    Screen screen;
    screen.clear();
    int width=screen.getWidth(), extra=width%2;
    int height=screen.getHeight();
    fore(i,0,height/2){
        fore(j,0,width/2-1+extra){
            std::cout<<" ";
        }
        std::cout<<"#"<<"\n"; //█
    }
    fore(i,0,width/2-1+extra){
        std::cout<<"#"; //▀
    }
    std::cout<<rfc<<"#"<<nfc;
    fore(i,0,width/2){
        std::cout<<"#"; //▀
    }
    fore(i,2,height/2){
        fore(j,0,width/2-1+extra){
            std::cout<<" ";
        }
        std::cout<<"#"<<"\n"; //█
    }
    std::cin>>width;
    std::cout<<"\a";
}
