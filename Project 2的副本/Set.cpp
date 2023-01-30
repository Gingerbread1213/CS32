#include "Set.h"
#include <iostream>
#include <cstdlib>


Set::Set()
 : m_size(0)
{
    head = nullptr;
    tail = nullptr;
}

Set::~Set()
{
    if (head == nullptr){
        return;
    }
    
    while (tail!=head) {
        Node* preNode = new Node;
        preNode = tail->frontNode;
        delete tail;
        m_size--;
        tail = preNode;
    }
    delete head;
}

Set::Set(const Set& other): m_size(other.m_size)
{
    int n_size = other.m_size;
    
    
    if (other.m_size == 0) {
        // if other is empty, set this to empty and return
        head = nullptr;
        tail = nullptr;
        
        return;
    }
    
    // Save head
    head = new Node;
    head -> frontNode = nullptr;
    
    // save all of the value into the node and link it to the new node. Except for tail.
    Node* finalNode = head;
    Node* copyNode = other.head;
    while (n_size!=1) {
        finalNode->value=copyNode->value;
        Node* makeNew = new Node;
        finalNode->afterNode = makeNew;
        makeNew->frontNode = finalNode;
        copyNode = copyNode->afterNode;
        finalNode = makeNew;
        n_size--;
    }
    
    // Save tail
    finalNode->value=other.tail->value;
    finalNode->afterNode =nullptr;
    tail = finalNode;
    
}

Set& Set::operator=(const Set& rhs) {
   
    if (this != &rhs) {
        Set temp(rhs);
        swap(temp);
    }

    return *this;
}

bool Set::empty() const{

    return (m_size==0);
}

int Set::size() const{
    return m_size;
}

bool Set::insert(const ItemType& value){
    if(m_size == 0){
        Node* makeNew = new Node;
        makeNew->value = value;
        makeNew->frontNode=nullptr;
        makeNew->afterNode=nullptr;
        
        head=makeNew;
        tail=makeNew;
        
        m_size++;
        return true;
    }
    
    if(contains(value)){
        return false;
    }
    
    Node* newNode = new Node;
    newNode->value = value;
    newNode->frontNode=tail;
    newNode->afterNode=nullptr;
    tail->afterNode = newNode;
    tail=newNode;
    m_size++;
    
    
    return true;
}

bool Set::erase(const ItemType& value){
    
    // First make sure that value is inside the list. If not, return false.
    // Find the address of the that node.
    // link the node in front of that node to the node after that node.
    // erase it by delete.
    
    if(!contains(value)){
        return false;
    }
    
    // erase the node if it is the tail
    if(value == tail->value){
        Node* breakNode = tail->frontNode;
        breakNode->afterNode = nullptr;
        delete tail;
        tail = breakNode;
    }
    
    // erase the node if it is the head
    if(value == head->value){
        Node* breakNode = tail->afterNode;
        breakNode->frontNode = nullptr;
        delete head;
        head = breakNode;
    }
    
    
    Node *breakNode = new Node;
    breakNode = head->afterNode;
    int n_size = m_size;
    
    for (int i=1; i<=n_size ;i++){
        
        if(breakNode->value == value){
            Node* save = breakNode->afterNode;
            save->frontNode = breakNode->frontNode;
            save = breakNode->frontNode;
            save->afterNode = breakNode->afterNode;
            
            breakNode->afterNode=nullptr;
            breakNode->frontNode=nullptr;
            
            delete breakNode;
            m_size--;
            return true;
            
        }
        breakNode = breakNode->afterNode;
    }

    return false;

}

bool Set::contains(const ItemType& value) const{
    
    int n_size=m_size;
    Node *test = new Node;
    test = head;
    
    //check if the value is already inside
    while (n_size!=0) {
        if(value == test->value){
            return true;
        }
        if(test->afterNode==nullptr){
            n_size--;
        }
        else{
            test=test->afterNode;
            n_size--;
        }
    }
    
    return false;
}


bool Set::get(int pos, ItemType& value) const{
    
    Node* testNode = head;
    int count =0;
    for(int i=0; i<m_size;i++){
        Node* m_testNode = head;
        for (int j=0;j<m_size;j++){
            if(m_testNode->value < testNode->value){
                count++;
            }
            if(m_testNode!=tail){
                m_testNode = m_testNode->afterNode;
            }
        }
        if(count == pos){
            value = testNode->value;
            return true;
        }else{
            count = 0;
        }
        if(testNode!=tail){
            testNode = testNode->afterNode;
        }
        
    }
    
    return false;
}

void Set::swap(Set& other){
    
    // to swap the Set, we need to swap the size of both set.
    // And swap the elements that contain in both sets.
    // because we can find the body of a list by finding it's head and tail.
    // we can only swap the head and tail between both set.
    
    int newSize = m_size;
    m_size = other.m_size;
    other.m_size = newSize;
    
    //swaps the tails
    Node* t_tail = tail;
    tail = other.tail;
    other.tail = t_tail;

    // swaps the heads
    Node* t_head = head;
    head = other.head;
    other.head = t_head;
    
    return;
}

void unite(const Set& s1, const Set& s2, Set& result) {
    
    // insert all of the element in s1 into result
    for (int i = 0; i < s1.size(); i++) {
        ItemType a;
        s1.get(i, a);
        result.insert(a);
    }
    
    // insert all of the element in s2 into result
    for (int i = 0; i < s2.size(); i++) {
        ItemType a;
        s2.get(i, a);
        result.insert(a);
    }
}

void butNot(const Set& s1, const Set& s2, Set& result){
    
    for (int i=0; i<s2.size(); i++){
        
        ItemType a;
        s2.get(i, a);
        for(int j=0; j<s1.size();j++){
            ItemType b;
            s1.get(j, b);
            if(a==b){
                result.insert(a);
            }
            
        }
    }
    
    return;
}


