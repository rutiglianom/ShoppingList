// Rutigliano, Matthew
// pa1.cpp
// 4/24/20

// Description: Testbench program for the ShoppingList class. A list of items
// in "items.txt" is scanned in and queued into a shopping list. All of the
// class functions are then tested, with special attention being paid to the
// circular dynamic array. 

// Assumptions: "items.txt" should be formatted name,price,category

// Sources: Dr. Kong's "formatting.txt"
//          Dr. Kong's "items.txt"

#include <iostream>
#include <fstream>
#include "shopping.h"

using namespace std;

int main(){
  
  // Set cout to print two decimal places
  cout << fixed;
  cout.precision(2);
  
  ShoppingList s1;
  ShoppingList s2;
  
  string filename = "items.txt";
  
  // Scanning list into s1
  string data[3];
  ifstream infile;
  infile.open(filename);
  if (infile){
    while(!infile.eof()){
      getline(infile, data[0], ',');
      getline(infile, data[1], ',');
      getline(infile, data[2]);
      if (data[0] != ""){   // Avoids whitespace
        s1.enqueue(data[0], stod(data[1]), data[2]);
      }
    }
  } else {
    cout << "Error reading file." << endl;
  }
  infile.close();
  
  // Testing printList
  cout << "Printing s1:" << endl;
  s1.printList();
  
  // Testing Dequeue and Dynamic Memory
  s1.dequeue();
  s1.dequeue();
  s1.dequeue();
  s1.enqueue("Mechanical pencils", 4.20, "School supplies");
  s1.enqueue("Paper", 3.99, "School supplies");
  s1.enqueue("7-up", 1.00, "food");
  s1.enqueue("Bepis", 1.00, "food");
  s1.enqueue("Calculator", 10000.00, "School supplies");
  s1.enqueue("Grapes", 5.00, "food");
  cout << "Printing s1" << endl;
  s1.printList();
  
  // Testing createList
  cout << "Copying food items to s2" << endl;
  s1.createList(s2, "food");
  cout << "Printing s2" << endl;
  s2.printList();
  
  // Testing Copy Constructor
  ShoppingList s3 = s2;
  cout << "Printing s3 - should be identical to s2" << endl;
  s3.printList();
  
  // Testing Overloaded Assignment Operator
  s3 = s1;
  cout << "Printing s3 - should be identical to s1" << endl;
  s3.printList();
  
  // Testing getPrice
  cout << "Price of milk: " << s3.getPrice("milk") << endl;
  
  // Testing getSize
  int s3Size = s3.getSize();
  cout << "Length of s3: " << s3Size << endl;
  cout << "Dequeueing size + 1 times to test emptiness" << endl;
  for(int i = 0; i < s3Size + 1; i++){
    s3.dequeue();
  }
  
  // Exiting
  cout << "Exiting program" << endl;
  return 0;
}