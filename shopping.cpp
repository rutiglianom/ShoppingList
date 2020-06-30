// Rutigliano, Matthew
// shopping.cpp
// 4/24/20

// Description: Implimentation of ShoppingList class

// Assumptions: None

// Sources: Dr. Kong's "formatting.txt"

#include "shopping.h"

// Default Constructor
ShoppingList::ShoppingList(){
  front = 0;
  numItems = 0;
  size = DEF_SIZE;
  queue = new Item[size];
}

// Copy Constructor
ShoppingList::ShoppingList(const ShoppingList &s){
  front = s.front;
  numItems = s.numItems;
  size = s.size;
  queue = new Item[size];
  if (numItems != 0){
    for(int i = 0; i < numItems; i++){
      queue[(front+i)%(size)] = s.queue[(front+i)%(size)];
    }
  }
}

// Overloaded Assignment Operator
ShoppingList& ShoppingList::operator=(const ShoppingList &obj){
  if (this != &obj){
    // Copy parameters
    front = obj.front;
    numItems = obj.numItems;
    size = obj.size;
    
    // Copy queue
    delete [] queue;
    queue = new Item[size];
    if (numItems != 0){
      for(int i = 0; i < numItems; i++){
        queue[(front+i)%(size)] = obj.queue[(front+i)%(size)];
      } 
    }
  }
  return *this;
}

// Destructor
ShoppingList::~ShoppingList(){
  delete [] queue;
}

// enqueue
void ShoppingList::enqueue(string name, double price, string category){
  // Resize array
  if (numItems == size){
    resize();
  }
  
  // Create item
  Item temp;
  temp.name = name;
  temp.price = price;
  temp.category = category;
  
  // Enqueue item
  queue[(front + numItems) % size] = temp;
  numItems++;
}

// Overloaded enqueue
void ShoppingList::enqueue(Item obj){
  // Resize array
  if (numItems == size){
    resize();
  }
  
  // Enqueue item
  queue[(front + numItems) % size] = obj;
  numItems++;
}

// resize
void ShoppingList::resize(){
  // Size is doubled
  int newSize = size * 2;
  Item *tmp = new Item[newSize];
  
  // Contents are copied to new array, with the front being index 0
  for (int i = 0; i < numItems; i++){
    tmp[i] = queue[(front+i)%size];
  }
  size = newSize;
  front = 0;
  delete [] queue;
  queue = tmp;
  cout << "Capacity doubled to " << size << endl;
}

// dequeue
void ShoppingList::dequeue(){
  if (numItems == 0){
    cout << "List is empty!" << endl;
  }
  else {
    cout << "Bought " + queue[front].name << endl;
    // Front is incremented, marking the spot for rewrite
    front++;
    numItems--;
  }
}

// getSize
int ShoppingList::getSize(){
  return numItems;
}

// getPrice
double ShoppingList::getPrice(string name){
  double price = 0;
  // Searching queue for name
  for(int i = 0; i < numItems; i++){
    if (queue[(front+i)%(size)].name == name){
      price = queue[(front+i)%(size)].price;
    }
  }
  return price;
}

// printList
void ShoppingList::printList(){
  Item *ptr = nullptr;
  for(int i = 0; i < numItems; i++){
    ptr = &queue[(front+i)%(size)];
    cout << i+1 << ". " + ptr->name + " - $" << ptr->price 
      << " - " + ptr->category << endl;
  }
}

// createList
void ShoppingList::createList(ShoppingList& s2, string categ){
  // Searching queue for items with category categ
  for(int i = 0; i < numItems; i++){
    if (queue[(front+i)%(size)].category == categ){
      // Queueing them in s2
      s2.enqueue(queue[(front+i)%(size)]);
    }
  }
}