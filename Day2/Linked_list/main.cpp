#include <iostream>
#include <vector>


struct Node{
    int value;
    struct Node *next;
};

class LinkedList{
    Node *head;
    Node *tail;

public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    //Creating a new Node and setting its next to 0
    //Setting first value... can I skip this? overload constructor with no input?
    void createNode(const int value){
        Node *temp = new Node;
        temp->value = value;
        temp->next = nullptr;

        //If nothing exists in the list, head is 0: set head and tail to temp
        if (head == nullptr){
            head = temp;
            tail = temp;
        }
        //Set temp after tail and set tail to temp.
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    //Temp Node current is created and set to head.
    //As long as current is not pointing to 0, print the value and set current to next node
    void printList(){
        Node *current = head;

        while (current != nullptr){
            std::cout << current->value << " -> ";
            current = current->next;
        }
        std::cout << tail->next << std::endl;
        
    }
    //Create a new node at head
    //Set its value
    //Set its next to head
    //Set head to the new node
    void insertAtStart(const int value){
        if (head == nullptr){
            this->createNode(value);
        }
        else{
            Node *new_node;
            new_node = new Node;

            new_node->value = value;
            new_node->next = head;

            head = new_node;
        }
    }
    //Create new node at end
    //Set new nodes value
    //Set its next to nullptr
    //Set tail pointing to the new node
    //Set tail to new node
    void insertAtEnd(const int value){
        if (head == nullptr){
            this->createNode(value);
        }
        else{
            Node *new_node;
            new_node = new Node;

            new_node->value = value;
            new_node->next = nullptr;

            tail->next = new_node;
            tail = new_node;
        }
    }

    void insertNodeAtPosition(const int pos, const int value){
        Node *pre = new Node;
        Node *current = new Node;
        Node *temp = new Node;
        current = head;

        for(auto i = 1; i<pos; i++){
            pre = current;
            current = current->next;
        }
        temp->value = value;
        pre->next = temp;
        temp->next = current;
    }
    void pop(){
        Node *temp = new Node;
        temp = head;
        head = head->next;
        delete temp;
    }
    void popBack(){
        Node *temp = head;
        Node *new_last;

        while (temp->next != nullptr){
            new_last = temp;
            temp = temp->next;
        }

        new_last->next = nullptr;
        tail = new_last;
        delete temp;
        

    }
    //Iterate to the value
    //Check where the value is, start middle or end
    //Move head, tail or re-connect values
    void removeValue(const int value){
        Node *temp = head;
        Node *pre = head;
        Node *after = temp->next;

        while(temp->value != value){
            pre = temp;
            temp = temp->next;
            after = temp->next;
        }
        if (head == temp){
            head = after;
            delete temp;
        }
        if (temp->next == nullptr){
            pre->next = nullptr;
            tail = pre;
            delete temp;
        }
        else{
            pre->next = after;
            delete temp;
        }
    }
    void insertSortedAndNoDuplicates(const int value){
        //check for value
        //pre, current and after
        //if current value is smaller and after value is bigger
        //break if value already exist
        //create new node if needed
        if (head == nullptr){
            this->createNode(value);
        }
        else{
            Node *current = head;
            Node *pre = head;
            Node *after = current->next;

            // 1, 3, 5, 7, 8   <-6
            if (head->value > value){
                this->insertAtStart(value);
            }
            else if (tail->value < value){
                this->insertAtEnd(value);
            }
            else if (current->next != nullptr){
                while(after != nullptr){
                    if (after == nullptr){
                        this->insertAtEnd(value);
                        break;
                    }
                    else if (after->value == value || current->value == value){
                        break;
                    }
                    else if (after->value > value){
                        Node *new_node = new Node;
                        new_node->value = value;
                        current->next = new_node;
                        new_node->next = after;
                        break;
                    }
                    pre = current;
                    current = current->next;
                    after = current->next;
                }
            }
            else {
                if (current->value < value){
                    this->insertAtEnd(value);
                }
                else if (current->value > value){
                    this->insertAtStart(value);
                }
            }
        }
    }
    
    //Sorting a vector
    std::vector<int>returnSortedVectorWithoutDuplicates(std::vector<int>&_vec){
        for(auto i=0; i<_vec.size(); i++){
            this->insertSortedAndNoDuplicates(_vec[i]);
        }
        _vec.clear();
        Node *current = head;
        while(current != nullptr){
            _vec.push_back(current->value);
            current = current->next;
        }

        return _vec;
    }
};
//Add item if it is not already in list. 
//Sorting the list by value. Sorting when adding

int main(){

    LinkedList list;

    std::vector<int> vec = {112, 894, 8, 2, 3, 3, 9, 1, 55, 1, 3, 7, 6, 5, 4, 3};

    
    list.returnSortedVectorWithoutDuplicates(vec);

    for(auto i=0; i<vec.size(); i++){
        std::cout << vec[i] << std::endl;
    } 

    
    //list.printList();

    return 0;
}