//
//  Set.cpp
//  Homework1
//
//  Created by 刘豪杰 on 1/20/23.
//

#include "newSet.h"
#include "Set.h"
#include <iostream>
#include <string>

using namespace std;

newSet::newSet(){
    container = new ItemType[DEFAULT_MAX_ITEMS];
}

newSet::~newSet(){
    delete[] container;
}

newSet::newSet(int max){
    container = new ItemType[max];
    
}


bool newSet::empty(){
    if(length == 0){
        return true;
    }
    return false;
}

int newSet::size() {
    
    return length;
}

bool newSet::insert(const ItemType& value){
    if (length == 0){
        container[0]=value;
        length++;
        return true;
    }
    else{
        for (int i=0; i<length; i++){
            if (value == container[i]){
                return false;
            }
        }
        container[length] = value;
        length++;
        

        return true;
    }
    return false;
}

bool newSet::erase(const ItemType& value){
    if(length ==1){
        return false;
    }
    for (int i=0; i<length; i++){
        if(container[i] == value){
            for (int j=i; j<length; j++){
                container[i] = container[j];
            }
            length--;
            return true;
        }
    }
    
    
    return false;
}

bool newSet::contains(const ItemType &value){
    if(length==0){
        return false;
    }
    for(int i=0; i<length; i++){
        if(container[i]==value){
            return true;
        }
    }
    return false;
}

bool newSet::get(int i, ItemType& value){
    if (i<0){
        return false;
    }
    if(i>size()){
        return false;
    }
    ItemType a;
    int count;
    
    for (int j=0; j<length; j++){
        a = container[j];
        count = 0;
        for (int k=0; k<length;k++){
            if(a>container[k]){
                count++;
            }
        }
        if (count == i){
            value = a;
            return true;
        }
        
    }
    
    return false;
}


void newSet::swap(newSet &other){
    
    newSet s = other;
    for (int i=0; i<size(); i++){
        other.container[i] = container[i];
    }
    other.length = length;
    
    for (int i=0; i<s.size(); i++){
        container[i] = s.container[i];
    }
    length = s.size();

    return;
}


void newSet::read(){
    
    for (int i=0; i<length; i++){
        cout<<container[i] <<endl;
    }
    
    return;
}
