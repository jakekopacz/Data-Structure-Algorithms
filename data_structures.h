#include <string>


// NODES FOR LINKED LIST & QUEUE
#ifndef _NODE_
#define _NODE_

template<class T>
class Node{

    public:

        T data;
        Node<T>* next;

        Node() {
            this->data = NULL;
            this->next = NULL;

        }

        Node(T data) {
            this->data = data;
            this->next = nullptr;
        }

        Node(T data, Node<T>* next) {
            this->data = data;
            this->next = next;
        }

        ~Node() {
            if(this->next != nullptr){
                delete this->next;
            }
        }
};
#endif


#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

template<class T>
class LinkedList {

    private:
        Node<T>* head;
        unsigned int size;

    public:

        LinkedList() {
            this->head = nullptr;
        }

        LinkedList(T data) {
            this->head = new Node(data);
            this->size = 1;
        }

        ~LinkedList(){
            delete this->head;
        }

        void push_front(T data){
            Node<T>* tmp = this->head;
            this->head = new Node(data, tmp);
            this->size++;
        }

        void push_back(T data) {
            
                    if (this->head == nullptr) {
                        push_front(data);
                        return;
                    }

                    Node<T>* tmp = this->head;

                    while(tmp->next != nullptr){
                        tmp = tmp->next;
                    }

                    tmp->next = new Node(data);
                    this->size++;
        }

        void insert(T data, int idx) {

            if (idx >= size) {
                push_back(data);
                return;
            }
            else if (idx == 0) {
                push_front(data);
                return;
            }

            
            Node<T>* tmp = this->head;

            int i = 0;
            while (tmp != nullptr && i < (idx - 1)) {
                tmp = tmp->next;
                i++;
            }

            tmp->next = new Node(data, tmp->next);

            this->size++;
        }

        void remove(T data) {

            Node<T>* tmp = this->head;
            Node<T>* prv = nullptr;

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

        bool contains(T data) {

            Node<T>* tmp = this->head;

            while (tmp != nullptr) {

                if (tmp->data == data) {
                    return true;
                }
                tmp = tmp->next;
            }

            return false;
        }

        int get_size() {
            return this->size;
        }

};
#endif

#ifndef _QUEUE_H_
#define _QUEUE_H_

template<class T>
class Queue{

    private:

        Node<T>* head;
        Node<T>* tail;
        unsigned int size;

        void base(T data) {
            this->head = new Node(data);
            this->tail = this->head;
            this->size = 1;
        }

    public:

        Queue() {
            this->head = nullptr;
            this->tail = nullptr;
            this->size = 0;
        }

        Queue(T data) { base(data); }

        ~Queue() { delete this->head; }

        void enqueue(int data) {

            if (this->size == 0) {
                base(data);
                return;
            }
            this->tail->next = new Node(data);
            this->tail = this->tail->next;
            size++;
        }

        void dequeue() {

            if (this->size == 0) {
                return;
            }
            else if (this->size == 1) {
                delete this->head;
                this->head = nullptr;
                this->tail = nullptr;
                this->size = 0;
                return;
            }

            Node<T>* tmp = this->head;
            this->head = this->head->next;
            tmp->next = nullptr;
            delete tmp;
            this->size--;

            if (this->size == 0) {
                this->tail = nullptr;
            }
        }

        T peak() {
            return this->head->data;
        }

        int get_size() { return this->size; }

        std::string to_string() {
            std::string stringified;
            Node<T>* tmp = this->head;

            while(tmp != nullptr){
                stringified += std::to_string(tmp->data) + " ";
                tmp = tmp->next;
            }

            return stringified;
        }
};
#endif

#ifndef _PRIORITY_NODE_H_
#define _PRIORITY_NODE_H_

template<class T>
class PriorityNode {
    private:
        T data;
        int priority;
        PriorityNode<T>* next;

        friend class PriorityQueue;
    public:
        PriorityNode() {
            this->data = NULL;
            this->next = nullptr;
        }

        PriorityNode(T data, int priority) {
            this->data = data;
            this->priority = priority;
            this->next = nullptr;
        }

        PriorityNode(T data, int priority, PriorityNode* next) {
            this->data = data;
            this->priority = priority;
            this->next = next;
        }

        ~PriorityNode() {
            if(this->next != nullptr){
                delete this->next;
            }
        }
};
#endif

#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

template<class T>
class PriorityQueue {
    private:
        PriorityNode<T>* head;
        PriorityNode<T>* tail;
        unsigned int size;
        void base(T data, int pr)  {
            this->head = new PriorityNode(data, pr);
            this->tail = this->head;
            this->size = 1;
        }

    public:
        PriorityQueue() {

            this->head = nullptr;
            this->tail = nullptr;
            this->size = 0;
        }

        PriorityQueue(T data, int priority) { base(data, pr); }

        ~PriorityQueue() { delete this->head; }

        void enqueue(T data, int pr) {

            PriorityNode* tmp;
            if (this->size == 0) {
                base(data, pr);
                return;
            }
            else if (this->tail->priority <= pr) {
                this->tail->next = new PriorityNode(data, pr);
                this->tail = this->tail->next;
                this->size++;
                return;
            }
            else if (this->head->priority > pr) {
                tmp = this->head;
                this->head = new PriorityNode(data, pr, tmp);
                this->size++;
                return;
            }

            tmp = this->head;
            while(tmp != nullptr && tmp->next->priority <= pr) {
                tmp = tmp->next;
            }

            tmp->next = new PriorityNode(data, pr, tmp->next);
            this->size++;

        }

        void dequeue() {

            if (this->size == 0) {
                return;
            }
            else if (this->size == 1) {
                delete this->head;
                this->head = nullptr;
                this->tail = nullptr;
                this->size = 0;
                return;
            }

            PriorityNode* tmp = this->head;
            this->head = this->head->next;
            tmp->next = nullptr;
            delete tmp;
            this->size--;
        }

        T peak() {
            return this->head->data;
        }

        int get_size() { return this->size; }

};
#endif