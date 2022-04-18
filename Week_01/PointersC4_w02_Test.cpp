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
            this->id = id;
        }
        void print(){
            cout << "Value: " << this->data << ", Dir.:" << &this->data << ", Next Dir.:" << this->next <<endl;
        }

};

struct List{
    Node *HEAD;
    Node *root;
    Node *NEXT;
    int count = 0;
    public:
        List(){};
        void append(int data){
            if(count == 0){
                NEXT = new Node(0,0,NULL);
                HEAD = new Node(data, count, NEXT);
                root = HEAD;
            }
            else {
                HEAD = NEXT;
                NEXT = new Node(0,0,NULL);

                HEAD->data = data;
                HEAD->id = count;
                HEAD->next = NEXT;
            }
            count++;
            HEAD->print();
        }
        Node* rootDirec(){
            return root;
        }
        int size(){
            return count;
        }
        int value(int idx){
            int out;
            Node *it = root;
            for(int X = 0; X < count; X ++){
                if(it->id == idx){
                    out = it->data;
                }
                it = it->next;
            }
            return out;
        }
        void  remove(int idx){
            Node *it = root;
            Node *nbrPrev;
            if(idx < count){
                for(int X = 0; X < count; X ++){
                    if (idx == 0){
                        nbrPrev = it;
                        it = it->next;
                        root = it;
                        delete nbrPrev;
                    }
                    else if(it->id == idx - 1){
                        nbrPrev = it;
                        it = it->next;
                    }
                    else if (it->id == idx){
                        nbrPrev->next = it->next;
                        nbrPrev = it;
                        it = it->next;
                        delete nbrPrev;
                    }
                    else{
                        it = it->next;
                    }
                }
                count --;
                it = root;
                for(int X = 0; X < count; X ++){
                    it->id = X;
                    it = it->next;
                }
            }
            
        }

        /*void remove(int idx){
            Node *it;
            for(it = HEAD; it != NULL; it=it->next){
                if(it->id == idx){
                    cout << it->data << " ";
                    delete it;
                    break;
                }
            }
            count = count - 1;
        }*/
};

// OVERLOAD
//https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170

ostream& operator<<(ostream& os, List& list){
    Node *it = list.root;
    for(int X = 0; X < list.count; X ++){
        os << it->data << " ";
        it=it->next;
    }
    return os;
}


int main(){
    List lst;
    lst.append(2); //0
    lst.append(4); //1
    lst.append(8); //2
    lst.append(16); //3
    lst.append(32); //4

    cout << "Root Dirc.: " << lst.rootDirec() << endl;
    cout << "Size: " << lst.size() << endl;
    cout << lst << endl;
    cout << "value (0): " << lst.value(0) << endl;
    cout << "value (1): " << lst.value(1) << endl;
    cout << "value (2): " << lst.value(2) << endl;
    cout << "value (3): " << lst.value(3) << endl;
    cout << "value (4): " << lst.value(4) << endl;
    cout << "value (5): " << lst.value(5) << endl;

    cout << lst << endl;
    lst.remove(4);
    cout << lst << " Remove [4]" << endl;
    lst.remove(4);
    cout << lst << " Remove [4]" << endl;
    lst.remove(1);
    cout << lst << " Remove [1]" << endl;
    lst.remove(1);
    cout << lst << " Remove [1]" << endl;
    //lst.print();

    return 0;
}