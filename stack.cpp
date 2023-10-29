#include<iostream>
using namespace std;

struct node {
    int info;
    node *next;
};

struct node *front;
struct node *rear;

int main(){
    node *t,*p, *z;
    t = new node;
    front = t;
    rear = t;
    t->info = 42;
    p = new node;
    t->next = p;
    p->info = 55;
    rear = p;
    z = new node;
    p->next = z;
    z->info = 69;
    rear = z;
    int ptr = (t->next->info);
    cout << "The value of the element is: "<< t->info << endl;
    cout << "The value of the element is: "<< ptr<< endl;
    cout << "The value of the element is: "<< z->info << endl;

    delete t,p,z;
    return 0;
}