#ifndef CLASS_LINKEDLIST_H
#define CLASS_LINKEDLIST_H
#include <iostream>
using namespace std;
template<class t>
class Node{
    public:
    t data;
    Node<t>* next;
    Node(){
        data = 0;
        next = NULL;
    }
    Node(t data){
        this->data = data;
        next = NULL;
    }
    ~Node(){
        delete [] next;
        next = 0;
    }
};
template <class s>
class singly_linked_list{
    public:
    Node<s>* head;
    Node<s>* tail;
    singly_linked_list(){
        head = NULL;
        tail = NULL;
    }
    singly_linked_list(s data){
        head->data = data;
        head->next = NULL;
        tail = head;
    }
    singly_linked_list(Node<s>* &n){
        head = n;
        tail = head;
    }
    void add_to_end_of_LL(s data){
        if(head==NULL){
            //No nodes are exisiting before
            head = new Node<s>;
            head->data = data;
            head->next = NULL;
            tail = head;
            return;
        }
        Node<s>* temp = new Node<s>;
        temp->data = data;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
    void add_to_start_of_LL(s data){
        cout<<"At start\n";
        if(head==NULL){
            head = new Node<s>;
            head->data = data;
            head->next = NULL;
            tail = head;
            return;
        }
        Node<s>* temp = new Node<s>;
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    void delete_last_node_aka_tail(){   
 
        //Updating new tail
        Node<s> * traverse = new Node<s>;
        traverse = head;
        while(traverse->next != tail){
            traverse = traverse->next;
        }
        delete tail;
        tail = NULL;
        tail = traverse;
        tail->next = NULL;

    }
    void delete_from_head(){
        Node<s>* temp = head;
        temp = head->next;
        head = temp;
    }
    void delete_by_value(s data){
            bool found = false;
            if(head->data == data){
                delete_from_head();
                return;  
            }
            if(tail->data == data){
                delete_last_node_aka_tail();
                return;
            }
            Node<s>* access_previous = head; //This will access one node before the node that is going to be deleted
            while (access_previous->next->data != data)
            { 
                access_previous = access_previous->next;
            }
            Node<s>* access_deleteing = access_previous->next;
            Node<s>* access_ahead = access_deleteing->next;
            access_previous->next = access_ahead;
    }
    void delete_by_index(int index){
        if(index==1){
            delete_from_head();
            return;
        }
        Node<s>* temp = head;  //This will access 1 node before the node being deleted
        Node<s>* delete_node = head;   //This will access the node being deleted
        int counter = 1;
        while(counter != index-1){
            temp = temp->next;
            counter++;
        }
        if(temp->next->next == NULL){
            //Delete from tail
            delete_last_node_aka_tail();
            return;
        }
        delete_node = temp->next;
        temp->next = delete_node->next;
        delete_node = NULL;
        delete delete_node;

        
    }
    void update_node_value(s previous_value , s new_value){
        Node<s>* temp = head;
        bool found = false;
        while(temp != NULL){
            if(temp->data == previous_value){
                temp->data = new_value;
                found = true;
                return;
            }
            else{
                temp = temp->next;
            }
        }
        if(!found){
            cout<<"No such value found\n";
        }
    }
    void traverse_LL(){
        Node<s>* traverse = new Node<s>;
        traverse = head;
        while(traverse != NULL){
            cout<<traverse->data<<" ";
            traverse = traverse->next;
        }
        cout<<endl;
    }
    bool search(s key){
        Node<s>* temp = new Node<s>;
        traverse_LL();
        temp = head;
        while(temp != NULL){
            if(temp->data == key){
                return true;
            }
            temp = temp->next;
        }
                return false;
    }
    ~singly_linked_list(){
        delete head;
        head = NULL;
        delete tail;
        tail = NULL;
    }
};
#endif