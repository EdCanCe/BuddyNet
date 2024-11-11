/**
 * @file Structures.h
 * @author EdCanCe
 * @brief This file has the data structures that will be
 * used throughout the proyect.
 * @version 0.1
 * @date 2024-10-13
 * 
 */
#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <vector> //After learning how it works implement it manually
#define ll long long int
using namespace std;

template <class T> class Stack;
template <class T> class Queue;

template <class T>
class Node{
    private:
        T value;
        Node<T>* prev;
        Node<T>* next;

    public:
        Node(T);
        Node(T, Node<T>*, bool);

        friend class Stack<T>;
        friend class Queue<T>;
};

template <class T>
Node<T>::Node(T x){
    value=x;
    prev=0;
    next=0;
}

template <class T>
Node<T>::Node(T x, Node<T>* Ptr, bool typeOfPtr){
    value=x;
    if(typeOfPtr==0){
        prev=Ptr;
        next=0;   
    }else{
        prev=0;
        next=Ptr;
    }
}

template <class T>
class Stack{
    private:
        Node<T>* head;
        ll sze=0;

    public:
        bool empty();
        T top();
        void pop();
        void push(T);
        ll size();
};

template <class T>
bool Stack<T>::empty(){
    return sze==0;
}

template <class T>
T Stack<T>::top(){
    return head->value;
}

template <class T>
void Stack<T>::pop(){
    if(empty()) return;
    sze--;
    if(sze==0){
        delete head;
        head=0;
    }
    Node<T>* aux= sze>0 ? head->next : 0;
    delete head;
    head=aux;
}

template <class T>
void Stack<T>::push(T x){
    if(empty()){
        head=new Node(x);
    }else{
        Node<T>* aux=new Node(x, head, 1);
        head=aux;
    }
    sze++;
}

template <class T>
ll Stack<T>::size(){
    return sze;
}

template <class T> class Graph;

template <class T>
class Queue{
    private:
        Node<T>* head;
        Node<T>* tail;
        ll sze=0;

    public:
        bool empty();
        T front();
        void push(T);
        void pop();

    friend class Graph;
};

template <class T>
bool Queue<T>::empty(){
    return sze==0;
}

template <class T>
T Queue<T>::front(){
    return head->value;
}

template <class T>
void Queue<T>::push(T x){
    sze++;
    if(sze==1){
        head=new Node(x);
        tail=head;
    }else{
        Node<T>* aux=new Node(x, tail, 0);
        tail->next=aux;
        tail=aux;
    }
}

template <class T>
void Queue<T>::pop(){
    if(empty()) return;
    Node<T>* aux=head->next;
    delete head;
    head=aux;
    aux->prev=0;
    sze--;
}

template <class T>
class Graph{
    private:
        vector<T*> connected;

    public:
        Graph(vector<T*>);
        vector<T*> BFS();
};

template <class T>
Graph<T>::Graph(vector<T*> x){
    for(auto i:x) connected.push_back(i);
}

template <class T>
vector<T*> Graph<T>::BFS(){

}

#endif