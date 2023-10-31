#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};
node *front = NULL;
node *rear = NULL;

void push(int info){
    if (rear == NULL)
    {
        rear = new node;
        rear->next = NULL;
        rear->data = info;
        front = rear;
    }
    else{
        node *ptr;
        ptr = new node;
        ptr->data = info;
        rear->next= ptr;
        ptr->next= NULL;
        rear = ptr;
    }
}

void pop(){
    node *temp;
    temp = front->next;
    cout << "The element popped is: "<<front->data <<endl;
    free(front);
    front = temp;
        
}
void disp(){
    node *temp;
    temp = front;
    cout<< "Data is: \n";
    while (temp != NULL)
    {
        cout<< temp->data<<endl;
        temp = temp->next;

    }
    
}

int main(){
    while (1)
    {
        cout << "\n1. Push an item\n2. Pop an item\n3. Display queue\n4. Exit\nYour choice ?\n";
            int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int n;
            cout<<"Enter number of elements you want to enter in queue: ";
            cin >> n;
            int data;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter the value to be pushed in queue: ";
                cin >> data;
                push(data);
            }
                break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            disp();
            break;
        }

        case 4:{
            cout << "Exiting.....\n";
            exit(0);
        }
        default:
        {
            cout<<"Invalid Choice\n";
            break;
        }
        }
    }
    return 0;
}