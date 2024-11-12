/**
 * @file Sorts.h
 * @author EdCanCe
 * @brief This file has the sorting algorithms that will be used.
 * @version 0.1
 * @date 2024-11-11
 * 
 */
#ifndef SORTS_H
#define SORTS_H

#include "Post.h"

/**
 * @class Sorts
 * 
 * @brief This class contains the methods to sort
 * vectors. 
 */
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

/**
 * @brief Sets the sorting type to 'dates'.
 * 
 */
void Sorts::setDates(){
    sortingType=false;
}

/**
 * @brief Sets the sorting type to 'votes'.
 * 
 */
void Sorts::setVotes(){
    sortingType=true;
}

/**
 * @brief Checks whether the sorting type is
 * set to 'votes' or 'dates'.
 * 
 * @return TRUE - Set to 'votes'.
 * 
 * FALSE - Set to 'dates'.
 */
bool Sorts::currentSort(){
    return sortingType;
}

/**
 * @brief Merges the 2 sorted parts of A into a single one.
 * It has a time complexity of O(n), where n=high-low.
 * 
 * @param A Original vector.
 * @param B Auxiliar vector.
 * @param low Lower pointer of the active section.
 * @param mid Middle pointer of the active section.
 * @param high Higher pointer of the active section.
 */
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

/**
 * @brief Performs the recursive part of the algorithm. Splits
 * the vector into its halves until they are only one element.
 * Then merges both halves and copies them to the original vector.
 * It has a time complexity of O(n log n).
 * 
 * @param A Original vector.
 * @param B Auxiliar vector.
 * @param low Lower pointer of the active section.
 * @param high Higher pointer of the active section.
 */
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

/**
 * @brief Copies the elements from de auxiliar vector to the original one.
 * It has a time complexity of O(n), where n=high-low.
 * 
 * @param A Original vector.
 * @param B Auxiliar vector.
 * @param low Lower pointer of the active section.
 * @param high Higher pointer of the active section.
 */
void Sorts::mergeCopy(vector<Post*>& A, vector<Post*>& B, ll low, ll high){
    for(ll i=low; i<=high; i++){
        A[i]=B[i];
    }
}

Sorts sorts; //Creates a sort object that will be used througout the classes.

#endif