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
        friend class Stack<T>;
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
        Node<T>* tail;
        int size=0;

    public:
        bool empty();
        T top();
        void pop();
        void push(T);
};

template <class T>
bool Stack<T>::empty(){
    return size==0;
}

template <class T>
T Stack<T>::top(){
    return head->value;
}

template <class T>
void Stack<T>::pop(){
    if(empty()) return;
    size--;
    if(size>=2){
        Node<T>* aux=head->next;
        delete head;
        head=aux;
        head->prev=0;
    }else{
        head=0;
        tail=0;
    }
    
}

template <class T>
void Stack<T>::push(T x){
    size++;
    if(size==1){
        head=new Node(x);
        tail=head;
    }else{
        Node<T>* aux=new Node(x, head, 1);
        head->prev=aux;
        head=aux;
    }
    if(size==11){ //Limits the size to ten
        Node<T>* aux=tail->prev;
        delete tail;
        tail=aux;
        tail->next=0;
        size--;
    }
}

template <class T>
class Queue{
    private:
        Node<T>* head;
        Node<T>* tail;
        int size=0;

    public:
        bool empty();
        T front();
        void push(T);
        void pop();
};

template <class T>
bool Queue<T>::empty(){
    return size==0;
}

template <class T>
T Queue<T>::front(){
    return head->value;
}

template <class T>
void Queue<T>::push(T x){
    size++;
    if(size==1){
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
    size--;
}

#endif