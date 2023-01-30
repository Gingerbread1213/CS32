#include <string>

#ifndef SET_INCLUDED
#define SET_INCLUDED
  // Later in the course, we'll see that templates provide a much nicer
  // way of enabling us to have Sets of different types.  For now,
  // we'll use a type alias.

using ItemType = std::string;


class Set
{
  public:
    Set();
      // Create an empty set with the given capacity.
    ~Set();
    Set(const Set& other);
    bool empty() const;  // Return true if the set is empty, otherwise false.
    int size() const;    // Return the number of items in the set.
    bool insert(const ItemType& value);
    bool erase(const ItemType& value);
    bool contains(const ItemType& value) const;
    bool get(int pos, ItemType& value) const;
    void swap(Set& other);
    
    Set& operator=(const Set& rhs);
    
  private:
    
    struct Node{
        
        ItemType value;
        Node* frontNode;
        Node* afterNode;
        
    };
    
    int       m_size;
    Node* head;
    Node* tail;

      // At any time, the elements of m_data indexed from 0 to m_size-1
      // are in use and are stored in increasing order.

};

void unite(const Set& s1, const Set& s2, Set& result);
void butNot(const Set& s1, const Set& s2, Set& result);

#endif // NEWSET_INCLUDED


// First of all, we need have the structure down for linked list. Where:
// All linked list have a head that let us can find it from the memory.
// Also a tail that tells us where does it end.
// All linked list are build based on node, which is the basic element of the linked list.
    // All nodes need to contain 3 elements:
        // address of the previous node
        // address of the node after
        // value that are inside the node
    // Therefore, we need have two pointers inside the array.
    // and a private class or struct, node, need to be build inside the header file.
 
