#include "slist.h"
#include <string>
#include <sstream>
/*
Class Library File
*/


// Constructor
slist::slist(NODE *headval) {
   head = headval;
  
}
// Destructor

// add(value)				//Adds a new value to the end of this list.
void slist::add(AIRPORT value) {
  NODE node;
  node.value = value;
  node.next = 0;
  NODE* current = head;
  while (current->next != 0) {
    current = current->next;
  } 
  current->next = &node;
}
// clear()					//Removes all elements from this list.
void slist::clear() {
  NODE* current = head;
  while (current != 0) {
    current = current->next;
    delete current;
  }
}
// equals(list)				//Returns true if the two lists contain the same elements in the same order.
bool slist::equals(slist list) {
  NODE* current1 = head;
  NODE* current2 = list.head;
  
  while (current1 != 0) {
    current1 = current1->next;
    current2  = current2->next;
    if (current1->value.code != current2->value.code) {
      return false;
    }
  }
  return true;
}
//get(index)				//Returns the element at the specified index in this list.
AIRPORT slist::get(int index) {
  NODE* current = head;
  current = current->next;
  for (int i = 0; i < index; i++) {
    current = current->next;
  }
  return current->value;
}

//insert(index, value)		//Inserts the element into this list before the specified index.
void slist::insert(int index, AIRPORT value) {
  NODE* current = head;
  NODE newnode;
  newnode.value = value;
  current = current->next;
  for (int i = 0; i < index; i++) {
    current = current->next;
  }
  newnode.next = current->next;
  current->next = &newnode;
}
//exchg(index1, index2)		//Switches the payload data of specified indexex.
void slist::exchg(int index1, int index2) {
  NODE* current = head;
  AIRPORT node1;
  AIRPORT node2;
  current = current->next;
  for (int i = 0; i < index2; i++) {
    if (i == index1) {
      node1 = current->value;
    }
    current = current->next;
  }
  node2 = current->value;
  NODE* current1 = head;
  current1= current1->next;
  for (int i = 0; i < index1; i++) {
      current1= current1->next;
  }
  current1->value = node2;
  NODE* current2 = head;
  current2= current2->next;
  for (int i = 0; i < index1; i++) {
      current2= current2->next;
  }
  current2->value = node1;
}

//swap(index1,index2)		//Swaps node located at index1 with node at index2
void slist::swap(int index1, int index2) {
  NODE* current = head;
  AIRPORT node1;
  AIRPORT node2;
  current = current->next;
  for (int i = 0; i < index2; i++) {
    if (i == index1) {
      node1 = current->value;
    }
    current = current->next;
  }
  node2 = current->value;
  NODE* current1 = head;
  current1= current1->next;
  for (int i = 0; i < index1; i++) {
      current1= current1->next;
  }
  current1->value = node2;
  NODE* current2 = head;
  current2= current2->next;
  for (int i = 0; i < index1; i++) {
      current2= current2->next;
  }
  current2->value = node1;
}
// isEmpty()				//Returns true if this list contains no elements.
bool slist::isEmpty() {
  NODE* current = head;
  return current == 0;
}
// remove(index)			//Removes the element at the specified index from this list.
void slist::remove(int index) {
  NODE* current = head;
  current = current->next;
  for (int i = 0; i < index+1; i++) {
    current = current->next;
  }
  //NODE next = *current;
  NODE* current1 = head;
  for (int i = 0; i < index-1; i++) {
    current1 = current1->next;
  }
  current1->next = current;
}

// set(index, value)		//Replaces the element at the specified index in this list with a new value.
void slist::set(int index, AIRPORT value) {
  NODE newnode ;
  newnode.value = value;
  NODE* current = head;
  current = current->next;
  for (int i = 0; i < index+1; i++) {
    current = current->next;
  }
  newnode.next = current;
  NODE* current1 = head;
  for (int i = 0; i < index-1; i++) {
    current1 = current1->next;
  }
  current1->next = &newnode;
}
// size()					//Returns the number of elements in this list.
int slist::size() {
  NODE node;
  NODE* current = head;
  int count = 0;
  while (current != 0) {
    current = current->next;
    count++;
  }
  return count;
}
// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.

// toString()				//Converts the listt to a printable string representation. 

// MAKE LOOK GOOD *********
std::string slist::toString() {
  std::string printable;
  std::stringstream item;
  int index = 0;
  NODE* current = head;
  while (current->next != 0) {
    //item << index << current->value.code << " long " << current->value.longitude << " lat " << current->value.latitude  ;
    current = current->next;
    index++;
  }
  //printable = item.str();
  printable = "";
  return printable;
}