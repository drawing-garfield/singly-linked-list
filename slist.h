/*

Header file for single linked list class library

*/
#include <string>
struct AIRPORT
{
    char    code[5];
    double   longitude;
    double   latitude;
    
};
struct NODE {
  AIRPORT value;
  NODE* next;
};

class slist {
  public :
    NODE* head;

    slist(NODE *headval);
// add(value)				//Adds a new value to the end of this list.
    void add(AIRPORT value);
// clear()					//Removes all elements from this list.
    void clear();
// equals(list)				//Returns true if the two lists contain the same elements in the same order.
    bool equals(slist list);
//get(index)				//Returns the element at the specified index in this list.
    AIRPORT get(int index);
//insert(index, value)		//Inserts the element into this list before the specified index.
    void insert(int index, AIRPORT value);
//exchg(index1, index2)		//Switches the payload data of specified indexex.
    void exchg(int index1, int index2);
//swap(index1,index2)		//Swaps node located at index1 with node at index2
    void swap(int index1, int index2);
// isEmpty()				//Returns true if this list contains no elements.
    bool isEmpty();
// mapAll(fn)				//Calls the specified function on each element of the linkedlist in ascending index order.
   // void mapAll(function fn);
// remove(index)			//Removes the element at the specified index from this list.
    void remove(int index);
// set(index, value)		//Replaces the element at the specified index in this list with a new value.
    void set(int index, AIRPORT value);
// size()					//Returns the number of elements in this list.
    int size();
// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
    slist subList(int start, int length);
// toString()				//Converts the list to a printable string representation.
    std::string toString();

};