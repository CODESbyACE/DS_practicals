#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;
};
node *top = NULL;

void push(int num)
{
    node *ptr;
    ptr = new node;
    ptr->info = num;
    ptr->next = top;
    top = ptr;
}
void pop()
{
    if (top == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "The popped element is: " << top->info << endl;
        top = top->next;
    }
}
void disp()
{
    node *temp = top;
    cout << "Stack is: \n";
    while (temp != NULL)
    {
        cout << temp->info << "\n";
        temp = temp->next;
    }
}

int main()
{
    while (1)
    {
        cout << "\n1. Push an item\n2. Pop an item\n3. Display Stack\n4. Exit\nYour choice ?\n";
            int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter the value to be pushed in stack: ";
            cin >> data;
            push(data);
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