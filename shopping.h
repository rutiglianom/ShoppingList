// Rutigliano, Matthew
// shopping.h
// 4/24/20

// Description: The ShoppingList class has all the attributes necessary
// to create a shopping list queue. Each list entry contains a name, price,
// and item category. The entries are stored in a circular dynamic array,
// the size of which is doubled upon running out of space. The list can be
// parsed for the price of a specific item, printed, and a new list can be
// created holding all the items of a certain category. Dequeueing an item
// simply prints that the item was purchased.

// Assumptions: None

// Sources: Dr. Kong's "formatting.txt"

#include <iostream>
#include <cstring>
using namespace std;

#ifndef SHOPPING_H
#define SHOPPING_H

class ShoppingList {
  private:
    
    // Item structure
    struct Item {
      string name;
      double price;
      string category;
    };
    
    // Dynamic Array
    Item *queue = nullptr;
    
    // Front of array, number of entries and size
    int front;
    int numItems;
    int size;
    
    // Default initial size
    const int DEF_SIZE = 4;
    
    void resize();
    // Function for doubling size of array
    // Pre: Dynamic array has been allocated
    // Post: Size of array is doubled
    
  public:
  
    ShoppingList();
    // Default Constructor
    // Pre: None
    // Post: ShoppingList is initialized
    
    ShoppingList(const ShoppingList &s);
    // Copy Constructor
    // Pre: Initial ShoppingList has been initialized
    // Post: Second ShoppingList is initialized, identical to the first
    
    ShoppingList& operator=(const ShoppingList &rhs);
    // Overloaded Assignment Operator
    // Pre: Two ShoppingLists are initialized
    // post: First ShoppingList is identical to the second
    
    ~ShoppingList();
    // Destructor
    // Pre: ShoppingList has been initialized
    // Post: Dynamic array is deallocated
    
    void enqueue(string name, double price, string category);
    // Adds item to list, calling resize if list is full
    // Pre: ShoppingList has been initialized
    // Post: Specified item is now at the back of the queue
    
    void enqueue(Item temp);
    // Overloaded enqueue function for queuing Item struct
    // Pre: ShoppingList and Item have been initialized
    // Post: Specified item is now at the back of the queue
    
    void dequeue();
    // Item at front of queue is printed and removed
    // Pre: ShoppingList has been initialized, at least one item has been queued
    // Post: Front of the queue is behind the item, marking it for rewrite
    
    int getSize();
    // Returns size of queue
    // Pre: ShoppingList has been initialized
    // Post: Length of queue has been returned
    
    double getPrice(string name);
    // Searches queue for specified item, returning its price
    // Pre: ShoppingList has been initialized
    // Post: Price of item has been returned
    
    void printList();
    // Prints queue from front to back
    // Pre: ShoppingList has been initialized
    // Post: Contents of queue have been printed
    
    void createList(ShoppingList& s2, string categ);
    // Copies items of category categ to s2
    // Pre: Two ShoppingLists have been initialized
    // Post: s2 now holds items of category categ
    
};

#endif // SHOPPING_H