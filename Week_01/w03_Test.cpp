#include <iostream>
using namespace std;

struct Node{
    public:
        int data;
        Node *next;
        int id;

        Node(int data, int id, Node *next){
            this->data = data;
            this->id = id;
            this->next = next;
        }
};

struct List{
    Node *HEAD;
    Node *ROOT;
    int countList = 0;
    public:
        List(){};
        void append(int data){
            if (countList == 0){
                HEAD = new Node(data, countList, NULL);
                ROOT = HEAD;
            }
            else{
                HEAD = new Node(data, countList, HEAD);
            }
            countList ++;
        }

        void addfront(int data){
            Node *temp;
            temp = new Node(data, 0, NULL);
            ROOT->next = temp;
            ROOT = temp;
            countList ++;

            // E R R O R +++++
            Node *it; 
            it = HEAD;
            for(int X_s = countList; X_s > 0; X_s--){
                it->id = X_s;
                it = it->next;
            }
            // E R R O R +++++
        }

        void pop(){
            Node *temp;
            temp = HEAD->next;
            delete HEAD;
            HEAD = temp;
            countList --;
        }
};

ostream& operator<<(ostream& os, List& list){
    Node *it = list.HEAD;
    for(int X = list.countList; X > 0; X--){
        os << it->data << " ";
        it=it->next;
    }
    return os;
}

int main(){
    List lst;
    lst.append(2);
    lst.append(4);
    lst.append(8);
    lst.append(16);
    lst.append(32);

    cout <<"start:  " << lst << endl;

    lst.addfront(123);
    cout <<"addfront:   " << lst << endl;
    lst.addfront(987);
    cout <<"addfront:   " << lst << endl;

    lst.pop();
    cout <<"pop:        " << lst << endl;
    lst.pop();
    cout <<"pop:        " << lst << endl;

    return 0;
}