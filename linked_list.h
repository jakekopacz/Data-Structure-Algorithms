#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include "node.h"
#include <vector>
#include <string>

class LinkedList{
    private:
        Node* head;
        unsigned int size;

    public:
        LinkedList(); // this->head = nullptr;
        LinkedList(int data);
        LinkedList(std::vector<int> vec);
        ~LinkedList();

        void push_front(int data);
        void push_back(int data);
        void insert(int data, int idx); // For any `idx` > `size`, append the value
        void remove(int data);
        bool contains(int 
        );
        int get_size();
        std::string to_string();
};
#endif
