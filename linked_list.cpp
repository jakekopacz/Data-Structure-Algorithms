#include "linked_list.h"
#include <iostream>


LinkedList::LinkedList(){

    this->head = nullptr;
}


LinkedList::LinkedList(int data){
    this->head = new Node(data);
    this->size = 1;
}


LinkedList::LinkedList(std::vector<int> vec){

    int i = vec.size() - 1;

    this->head = new Node(vec.at(i));
    this->size = 1;
    i--;

    for ( ; i >= 0; i--) {
        push_front(vec.at(i));
    }
}

LinkedList::~LinkedList(){

    delete this->head;
}


void LinkedList::push_front(int data){

    Node* tmp = this->head;
    head = new Node(data, tmp);
    size++;

}

void LinkedList::push_back(int data){
    
    if (this->head == nullptr) {
        push_front(data);
        return;
    }

    Node* tmp = this->head;

    while(tmp->next != nullptr){
        tmp = tmp->next;
    }

    tmp->next = new Node(data);
    size++;
}

void LinkedList::insert(int data, int idx){

    if (idx >= size) {
        push_back(data);
        return;
    }
    else if (idx == 0) {
        push_front(data);
        return;
    }

    
    Node* tmp = this->head;

    int i = 0;
    while (tmp != nullptr && i < (idx - 1)) {
        tmp = tmp->next;
        i++;
    }

    tmp->next = new Node(data, tmp->next);

    size++;
}

void LinkedList::remove(int data){

    Node* tmp = this->head;
    Node* prv = nullptr;

    if (this->head->data == data) {
        this->head = this->head->next;
        tmp->next = nullptr;
        delete tmp;
        return;
    }


    while (tmp != nullptr && tmp->data != data) {
        prv = tmp;
        tmp = tmp->next;
    }

    if (tmp == nullptr) {
        return;
    }

    prv->next = tmp->next;
    tmp->next = nullptr;

    delete tmp;

    size--;
}


bool LinkedList::contains(int data){

    Node* tmp = this->head;

    while (tmp != nullptr) {

        if (tmp->data == data) {
            return true;
        }
        tmp = tmp->next;
    }

    return false;
}


int LinkedList::get_size(){
    return this->size;
}

// O(n)
std::string LinkedList::to_string(){
    std::string stringified;
    Node* tmp = this->head;

    while(tmp != nullptr){
        stringified += std::to_string(tmp->data) + " ";
        tmp = tmp->next;
    }

    return stringified;
}