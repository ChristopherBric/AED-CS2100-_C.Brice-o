#ifndef LIST_H
#define LIST_H

#include "node.h"

// TODO: Implement all methods
template <typename T>
class List {
    protected:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

    public:
        List() : head(nullptr), tail(nullptr), nodes(0) {};
        ~List(){
            // TODO            
        } ;

        /*
        virtual T front() = 0;
        virtual T back() = 0;
        virtual void push_front(T) = 0;
        virtual void push_back(T) = 0;
        virtual T pop_front() = 0;
        virtual T pop_back() = 0;
        virtual T insert(T, int) = 0;
        virtual bool remove(T) = 0;
        virtual T operator[](int) = 0;
        virtual bool empty() = 0;
        virtual bool find(T) = 0;
        virtual int size() = 0;
        virtual void clear() = 0;
        virtual void sort() = 0;
        virtual bool is_sorted() = 0;
        virtual List* reverse() = 0;
        virtual void display(std::ostream& os) = 0;
        virtual string name() = 0;
        */

       T front(){
            return tail->data;
       }
       T back(){
            return head->data;
       }
       void push_front(T s_data){
            if (nodes == 0){
                head = new Node<T>(s_data, NULL, NULL);
                tail = head;
            }
            else{
                Node<T>* Temp = head;
                head = new Node(s_data, Temp, tail);

                Temp->next = head;
                tail->Temp = head;
            }
            nodes++;
       }
       void push_back(T s_data){
            Node<T>* Temp = tail;
            tail = new Node<T>(s_data, head, Temp);

            head->next = tail;
            Temp->prev = tail;
            nodes++;
       }
       T pop_front(){
            Node<T>* Temp = head->prev;
            T data = head->data;
            delete head;

            head = Temp;
            head->next = tail;
            tail->Temp = head;

            nodes--;
            return data;
       }
       T pop_back(){
            Node<T>* Temp = tail->next;
            T data = tail->data;

            delete tail;
            tail = Temp;
            tail->prev = head;
            head->next = tail;

            nodes--;
            return data;
       }
       T insert(T s_data, int X){
            Node<T>* it = tail;
            for(int var = 1; var <= nodes; var++){
                if(X == var){
                    Node<T>* Temp1 = it->prev;
                    Node<T>* Temp2 = it->next;

                    Node<T>* new_val = new Node<T>(s_data, Temp1, Temp2);

                    Temp1->next = new_val;
                    Temp2->prev = new_val;

                    nodes++;

                    return Temp2->data;
                }
                it = it->next
            }
       }
       bool remove(T s_data){
            Node<T>* it = tail;
            bool status = false;
            for(int var = 1; var <= nodes; var++){
                if(it->data == s_data){
                    Node<T>* Temp1 = it->prev;
                    Node<T>* Temp2 = it->next;
                    
                    delete it 
                    Temp1->next = Temp2;
                    Temp2->prev = Temp1;

                    nodes--;
                    it = Temp2;
                    status = true;
                }
                else{
                    it = it->next
                }
            }
            return status;
       }
       T operator[](int X){
            Node<T>* it = tail;
            T data_out;
            for(int var = 1; var <= nodes; var++){
                if(X == var){
                    data_out = it->data;
                }
                it = it->next
            }
            return data_out;
       }
       bool empty(){
           bool status;
            status = (head == nullptr && tail == nullptr) ? true : false ;
           return status:
       }
       bool find(T s_data){
            Node<T>* it = tail;
            bool status = false;
            for(int var = 1; var <= nodes; var++){
                if(s_data == it->data){
                    status = true;
                }
                it = it->next
            }
            return status;
       }
       int size(){
           return nodes;
       }
       void clear(){
            Node<T>* it = tail;
            Node<T>* temp;
            for(int var = 1; var <= nodes; var++){
                temp = it;
                delete it;
                it = temp->next
            }
            nodes = 0;
       }
       void sort(){
           //bubble sort
            Node<T>* it = tail->next;
            Node<T> prev_Node = tail;
            T temp;
            bool permut = true;
            while(permut){
                permut = false;
                for(int var = 2; var <= nodes; var++){
                    if (it->data < prev_Node->data){
                        temp = it->data;
                        it->data = prev_Node->data;
                        prev_Node->data = temp;
                        permut = true;
                    }
                }
            }
            return !permut;
       }
       bool is_sorted(){
            Node<T>* it = tail;
            T prev_data;
            bool status = true;
            for(int var = 1; var <= nodes; var++){
                if (it != tail){
                    if (prev_data > it->data){
                        status = false;
                    }
                    prev_data = it->data
                }
                else{
                    prev_data = it->data
                }
            }
            return status;
       }
       List* reverse(){
           List List_out;
           Node<T>* it = tail;
            for(int var = 1; var <= nodes; var++){
                List_out.push_front(it->data);
                it = it->next
            }
            return List_out;
           
       }
       void display(std::ostream& os){
           for(Node<T>* it = tail; it->next != tail; it = it->next){
                os << it->data << " ";
            }
            os << head->data << " ";
       }
       string name(){

       }

};

#endif