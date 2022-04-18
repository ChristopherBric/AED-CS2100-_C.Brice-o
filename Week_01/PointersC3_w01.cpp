//Week 1 - Pointers 3

#include<iostream>
using namespace std;

struct Node{
    public:
        //private:
        int data;
        Node* next;
        int id;
        //public:
        Node(int data, int id, Node* next){
            this->data = data;
            this->next = next;
            //this->id++;  
            this->id - id;
        }
        //void append(int data){}
        void print(){
            cout << "data: " << this->data << ", dir:" << &this->data << ", next:" << this->next <<endl;
        }

};

/*
    HEAD = root = (,NULL) -> () -> ()
    
    >> append(4)

    root = (,NULL) -> HEAD = (4,next)

    Node node(7,NULL);
    int a = 7
*/

struct List{
    Node *HEAD;
    Node *root;
    int count = 0;
    public:
        List(){};
        void append(int data){
            if(count == 0){
                HEAD = new Node(data, count, NULL);
                root = HEAD;
                //HEAD->next = NULL;
                //HEAD->data = 0;
                //HEAD->print();  
            }
            else {
                HEAD = new Node(data, count, HEAD);
            }
            count++;
            HEAD->print();
        }
        int size(){
            return count;
        }
        void print(){
            Node *it;
            for(it = HEAD;; it=it->next){
                if(it == HEAD){
                    cout << it->data << " ";
                    break;
                }
            }
            cout << endl;
        }
        void remove(int idx){
            Node *it;
            for(it = HEAD; it != NULL; it=it->next){
                if(it->id == idx){
                    cout << it->data << " ";
                    delete it;
                    break;
                }
            }
            //delete
            count = count - 1;
        }
};

// OVERLOAD
//https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170

ostream& operator<<(ostream& os, List& list){
    Node *HEAD = list.HEAD;
    Node *it;
        for(it = HEAD; it != NULL; it = it=it->next){
            os << it->data << " ";
        }
    return os;
}

//Tarea SIZE y Remove


int main(){
    List l;
    l.append(2);
    l.append(4);
    l.append(8);
    l.append(16);
    l.append(32);

    l.print();
    //cout << l << endl;

    cout << l << endl;

    return 0;
}