#include <iostream>
#include <string>
#include "class_linkedlist.h"
using namespace std;

template <class u>
class hash_map{
public:
singly_linked_list<u> *arr; 
int size;
int count;
hash_map(){}
hash_map(int s){
    size = s;
    arr = new singly_linked_list<u> [s];
    count = 0;
}
void insert(u val){
    int index = hash_function(val);
    cout<<"Index ins"<<index<<endl;

    arr[index].add_to_end_of_LL(val);
}
int hash_function(int key){
return key % size;
}
void delete_from_map(u val){
    int index = hash_function(val);
    cout<<"Index del"<<index<<endl;
    arr[index].delete_by_value(val);
}
void search_map(u val){
    int index = hash_function(val);
    if(arr[index].search(val)){
        cout<<"Value found\n";
    }
    else{
        cout<<"Value not found\n";
    }
}
void show_map(){
    for(int i = 0; i<size; i++){
        arr[i].traverse_LL();
    }
}
};




int main() {
    hash_map <int> h (5);
    h.insert(100);
    h.insert(5);
    h.search_map(100);
    h.delete_from_map(100);
    h.search_map(100);
    h.arr[0].traverse_LL();
    h.insert(5);
    h.insert(10);
    h.insert(0);
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(8);
    h.insert(4);
    h.insert(9);
    h.show_map();
    h.delete_from_map(9);
    h.delete_from_map(5);
    h.delete_from_map(2);
    h.show_map();
    return 0;
}