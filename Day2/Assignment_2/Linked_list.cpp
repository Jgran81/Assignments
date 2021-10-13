/* Implement a single (forward) linked list for integers, your application should be able to:
• Add items to the end of the list
• Remove items from the front the list
• Print the list in the correct order */

#include <iostream>

typedef struct Node {
    int data;           //Datatype of int stored in struct
    struct Node *next;
}Node_t;                //Datatype of type Node_t

Node_t *findLast(Node_t *LinkedList) {  //Returning an adress?
    if (LinkedList == nullptr) {        //If we are at the last place at the list(nullptr) return that adress?
        return LinkedList;
    }
    Node_t *current = LinkedList;       //Setting the current adress to the first item in list
     while (current->next != nullptr) { //While the next item on list is not nullptr, keep going
        current = current->next;        //Set current to next item on list
    }
    return current;                     //Return current adress when the next is a nullptr
}

void add(Node_t *LinkedList, int value) {   //Will not return anything. Takes in adress of LinkedList and int value
    // 1) find the last item
    // 2)create a new node
    // 3) assign & link
    
    if (LinkedList == nullptr) {
                                        //If there are no values in the list = nullptr:
        LinkedList = new Node;        //Allocate new dynamic memory slot
                                       //Add int value to struct data value in heap
        LinkedList->next = nullptr;     //Set next item in list to nullptr
        LinkedList-> data = value;                                //Will always pick this statement! => LinkedList = nullptr
        //std::cout<<LinkedList->data<<std::endl; 
    }               // Data is not stored in list, not in dynamic mem?
    else {
        Node_t  *newNode = new Node_t,              //Creating a pointer for new dynamic memory slot for a new node
                *lastNode = findLast(LinkedList);   //Creating a pointer to last node before nullptr
        newNode->next = nullptr;                    //Setting the next node to nullptr
        newNode->data = value;                      //Setting the current node data value with the value from arg
        lastNode->next = newNode;                   //Setting the created node after the lastNode
    }
}

//Removes front of linked list
Node_t *remove(Node_t *LinkedList) {    //Will return adress. Takes in adress of LinkedList
    if (LinkedList == nullptr) {        //If we have an empty list, return LinkedList
        return LinkedList;
    }
    // 1) find the head of next and set as new head
    // 2) delete head
    Node_t *next = LinkedList->next;    //Sets ptr to next item in list 
    delete LinkedList;                  //Deletes first item in list
    return next;                        //Returns the next item(first item), previously the next item was the second item
}
//
void print(Node_t *LinkedList) {
    // 1)loop over the list
    // 2) print things
    
    //if (LinkedList == nullptr) return;
    
    while(LinkedList != nullptr) {
        std::cout<<"print"<<std::endl;
        std::cout << LinkedList->data << std::endl; 
        LinkedList = LinkedList->next;       
    }
}

int main () { //int argc, char ** argv

    Node_t * MY_LINKED_LIST;
    
    add (MY_LINKED_LIST, 12);
    
   /*  add (MY_LINKED_LIST, 152);
    add (MY_LINKED_LIST, 1232);
    add (MY_LINKED_LIST, 121);
    add (MY_LINKED_LIST, 182);
    add (MY_LINKED_LIST, 132);
    add (MY_LINKED_LIST, 127);
    add (MY_LINKED_LIST, 1211);
    add (MY_LINKED_LIST, 1233); 
    print(MY_LINKED_LIST);
    std::cout<<MY_LINKED_LIST<<std::endl;*/
    std::cout<<MY_LINKED_LIST->data<<std::endl;
    std::cout<<MY_LINKED_LIST->next<<std::endl;
    //std::cout<<"Happy endings"<<std::endl;
    
    return 0;
}