#include <iostream>
using namespace std;

struct Node{
    public:
        int data;
        Node *prev;
        Node *next;

        Node(int data, Node *prev, Node *next){
            this->data = data;
            this->prev = prev;
            this->next = next;
        }

        // D E B U G 
        void print(){cout << "Value: " << this->data << ", Dir.:" << &this->data << ", Prev Dir.:" << this->prev<< ", Next Dir.:" << this->next <<endl;}
};

struct List{
    Node *HEAD;
    Node *ROOT;
    Node *PREV;
    int countList = 0;
    public:
        List(){};

        void append(int data){
            if (countList == 0){
                HEAD = new Node(data, NULL, NULL);
                ROOT = HEAD;
            }
            else{
                PREV = HEAD;
                HEAD = new Node(data, PREV, ROOT);

                PREV->next = HEAD;
                ROOT->prev = HEAD;
            }
            countList++;

            // D E B U G 
            HEAD->print();
        }

        void addfront(int data){
            PREV = ROOT;
            ROOT = new Node(data, HEAD, PREV);

            HEAD->next = ROOT;
            PREV->prev = ROOT;
            countList++;

            // D E B U G 
            ROOT->print();
        }

        void pop(){
            PREV = HEAD->prev;
            delete HEAD;

            HEAD = PREV;
            HEAD->next = ROOT;
            ROOT->prev = HEAD;

            // D E B U G 
            HEAD->print();
        }
};
ostream& operator<<(ostream& os, List& list){
    for(Node *it = list.ROOT; it->next != list.ROOT; it = it->next){
        os << it->data << " ";
    }
    os << list.HEAD->data << " ";
    return os;
}

int main(){

    List lst;
    cout << ">>  A P P E N D  <<" << endl;
    lst.append(0); //0
    lst.append(1); //1
    lst.append(2); //2
    lst.append(3); //3
    lst.append(4); //4
    cout << lst << endl;

    cout << ">>  A D D F R O N T  <<" << endl;
    lst.addfront(5);
    lst.addfront(6);
    lst.addfront(7);
    lst.addfront(8);
    cout << lst << endl;

    cout << ">>  P O P  <<" << endl;
    lst.pop();
    lst.pop();
    lst.pop();
    cout << lst << endl;

    return 0;
}