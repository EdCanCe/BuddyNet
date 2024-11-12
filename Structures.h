/**
 * @file Structures.h
 * @author EdCanCe
 * @brief This file has the data structures that will be
 * used throughout the proyect.
 * @version 0.1
 * @date 2024-11-11
 * 
 */
#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <vector>
#include "Profile.h"
#define ll long long int
using namespace std;

class Profile; //Forward declaration
template <class T> class Stack; //Forward declaration
template <class T> class Queue; //Forward declaration

/**
 * @class Node
 * 
 * @brief This class has the nodes that will be used for
 * linear structures.
 */
template <class T>
class Node{
    //Declaration of private attributes
    private:
        T value; //The value of the node
        Node<T>* prev; //The previous node
        Node<T>* next; //The next node

    //Declaration of public methods
    public:
        Node(T);
        Node(T, Node<T>*, bool);

        friend class Stack<T>;
        friend class Queue<T>;
};

/**
 * @brief Construct a new blank Node with
 * a value.
 * 
 * @param x The value of the node.  
 */
template <class T>
Node<T>::Node(T x){
    value=x;
    prev=0;
    next=0;
}

/**
 * @brief Construct a new Node with all of it's data.
 * 
 * @param x The value of the node.
 * @param Ptr The pointer to a previous or next node.
 * @param typeOfPtr Indicates if the pointer is previous(0) or next(1).
 */
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

/**
 * @class Stack
 * 
 * @brief This class controls the nodes in the structure.
 */
template <class T>
class Stack{
    private:
        Node<T>* head; //The starting node of the stack
        ll sze=0; //The current size of the node

    public:
        bool empty();
        T top();
        void pop();
        void push(T);
        ll size();
};

/**
 * @brief Checks if the stack is empty.
 * 
 * @return TRUE - The stack is empty.
 * 
 * FALSE - The stack has at least one element.
 */
template <class T>
bool Stack<T>::empty(){
    return sze==0;
}

/**
 * @brief Returns the last element that was inserted.
 * It has a time complexity of O(1).
 * 
 * @return T - The top of the stack.
 */
template <class T>
T Stack<T>::top(){
    return head->value;
}

/**
 * @brief Removes the last element that was inserted.
 * It has a time complexity of O(1).
 * 
 */
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

/**
 * @brief Adds a new element to the stack.
 * It has a time complexity of O(1).
 * 
 * @param x The element to add.
 */
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

/**
 * @brief Returns the current size of the stack.
 * 
 * @return ll - The size of the stack. 
 */
template <class T>
ll Stack<T>::size(){
    return sze;
}

/**
 * @class Queue
 * 
 * @brief This class controls the nodes in the structure.
 */
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
};

/**
 * @brief Checks if the queue is empty.
 * 
 * @return TRUE - The queue is empty.
 * 
 * FALSE - The queue has at least one element.
 */
template <class T>
bool Queue<T>::empty(){
    return sze==0;
}

/**
 * @brief Returns the first element that was inserted.
 * It has a time complexity of O(1).
 * 
 * @return T - The front of the queue.
 */
template <class T>
T Queue<T>::front(){
    return head->value;
}

/**
 * @brief Adds a new element to the queue.
 * It has a time complexity of O(1).
 * 
 * @param x The element to add.
 */
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

/**
 * @brief Removes the first element that was inserted.
 * It has a time complexity of O(1).
 * 
 */
template <class T>
void Queue<T>::pop(){
    if(empty()) return;
    if(sze>1){
        Node<T>* aux=head->next;
        delete head;
        head=aux;
        aux->prev=0;
    }else{
        delete head;
        head=0;
        tail=head;
    }
    sze--;
}

#endif