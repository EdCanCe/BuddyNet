/**
 * @file Sorts.h
 * @author EdCanCe
 * @brief This file has the sorting algorithms that will be used.
 * @version 0.1
 * @date 2024-10-13
 * 
 */
#ifndef SORTS_H
#define SORTS_H

#include "Post.h"

class Sorts{
    private:
        bool sortingType=false; //Represents if it will be ordered by votes or dates. False=Dates, True=Votes.

    public:
        void setDates();
        void setVotes();
        bool currentSort();
        void mergeArray(vector<Post*>&, vector<Post*>&, ll, ll, ll);
        void mergeSplit(vector<Post*>&, vector<Post*>&, ll, ll);
        void mergeCopy(vector<Post*>&, vector<Post*>&, ll, ll);
};

void Sorts::setDates(){
    sortingType=false;
}

void Sorts::setVotes(){
    sortingType=true;
}

bool Sorts::currentSort(){
    return sortingType;
}

void Sorts::mergeArray(vector<Post*>& A, vector<Post*>& B, ll low, ll mid, ll high){
    ll fp=low, sp=mid+1;
    for(ll i=low; i<=high; i++){
        if(fp==mid+1){
            B[i]=A[sp];
            sp++;
        }else if(sp==high+1){
            B[i]=A[fp];
            fp++;
        }else if(sortingType==true){
            if(A[fp]->getVotes()<A[sp]->getVotes()){
                B[i]=A[fp];
                fp++;
            }else{
                B[i]=A[sp];
                sp++;
            }
        }else{
            if(A[fp]->getDate()<A[sp]->getDate()){
                B[i]=A[fp];
                fp++;
            }else{
                B[i]=A[sp];
                sp++;
            }
        }
    }
}

void Sorts::mergeSplit(vector<Post*>& A, vector<Post*>& B, ll low, ll high){
    if(high-low<1){
        return;
    }
    ll mid=(low+high)/2;
    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid+1, high);
    mergeArray(A, B, low, mid, high);
    mergeCopy(A,B, low, high);
}

void Sorts::mergeCopy(vector<Post*>& A, vector<Post*>& B, ll low, ll high){
    for(ll i=low; i<=high; i++){
        A[i]=B[i];
    }
}

Sorts sorts;

#endif