//Week 1 - Pointers 2

#include<iostream>
using namespace std;

struct List{
    float data;

};

struct Node{
    public:
        //private:
        float data;
        Node* next;
        //public:
        Node(float data, Node* next){
            this->data = data;
            this->next = next;
            //data = _data;
            //next = _next;    
        }
};


int calc_size_of_pointer(int *arr){
    int arr_size;
    // ...
    return arr_size;
}


int main(){
    // En un array se puede almacenar informacion de forma estatica
    int marray[100];
    int *arr = new int[100];

    cout << "size: " << calc_size_of_pointer(arr);
    cout << "addr: " << &arr[100] << endl;
    cout << "int pointed size: " << sizeof(*(arr+1000)) << endl; // ????
    cout << "size: " << sizeof(*arr)/sizeof(int) << endl;



    // En una lista, vectores, list, etc. se puede almacenar informacion de forma dinamica

    Node mnode(1,NULL);
    Node mnode2(4,&mnode);
    Node mnode3(6,&mnode2);
    
    Node *it;
    for(it = &mnode3; it != NULL; it = it=it->next){
        cout << it->data << " ";
    }
    cout << endl;

    /*
    List mlist;
    mlist.data = 4;

    List mlist2;
    mlist2.data = 5;
    */

    return 0;
}