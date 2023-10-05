#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;
};
struct node *start;

int main()
{
    node *t, *s;
    int n;
    t = new node;
    if (t == NULL)
    {
        cout << "Overflow";
    }
    else
    {
        //CREATION of Singly Linked List
        cout << "Enter total number of node to be made: ";
        cin >> n;
        if (n<1)
        {
            cout<<"Invalid Input"<<endl;
            goto insertion;
            return 0;
        }
        
        //Initializing Linked list
        cout << "Enter the data for first node: ";
        cin >> t->info;
        t->next = NULL;
        start = t;

        // Creating n sized Linked List
        for (int i = 0; i < n-1 ; i++)
        {   
            s=new node;
            cout << "\n Enter the data for next node : " << endl;
            cin >> s->info;
            t -> next = s;
            s -> next = NULL;
            t=s;
        }
//Traversing Linked List
        node *temp;
        temp = start;
        while( temp !=NULL){
            cout<<"Data is "<<temp->info<<endl;
            temp = temp ->next;
        }
//goto statement
        insertion:
//INSERTION
// Insertion at Begining
        struct node *ptr;
        ptr = new node;
        if (ptr == NULL){
            cout << "Overflow";
        }
        if (start == NULL)
        {
            cout<< "Enter info for new node at beginning: ";
            cin >> ptr -> info;
            start = ptr;
            ptr -> next = NULL;
            n++;
        }
        else{
            cout<< "Enter info for new node at beginning: ";
            cin >> ptr -> info;
            ptr -> next = start;
            start = ptr;
            n++;
            node *temp;
            temp = start;
            while( temp !=NULL){
                cout<<"Data is "<<temp->info<<endl;
                temp = temp ->next;
            }
        }

// Insertion at the end
        struct node *ptr1;
        ptr1 = new node;
        if (ptr1==NULL){
            cout <<" Overflow"<<endl;
            return 0;
        }
        if (start == NULL){
            cout<< "Enter info for new node at the end: ";
            cin >> ptr1 -> info;
            start = ptr1;
            ptr1 -> next = NULL;
        }
        else{
            cout<< "Enter info for new node at the end: ";
            cin >> ptr1 ->info;
            struct node *temp;
            temp = start;
            while (temp->next != NULL)
            {
                cout << temp->info << endl;
                temp = temp->next;
            }
            temp->next = ptr1;
            ptr1 ->next = NULL;
            n++;
            while (temp != NULL)
            {
                cout << temp->info << endl;
                temp = temp->next;
            }
        }

// Insertion at specific location
        node *ptr2;
        ptr2 = new node;
        if (ptr2 == NULL)
        {
            cout << "Overflow"<< endl;
            return 0;
        }
        if (start ==NULL)
        {
            cout<< "Enter info for new node: ";
            cin >> ptr2 -> info;
            start = ptr2;
            ptr2 -> next = NULL;
        }
        else{
            cout<<" Enter position where you want to insert a new node : "<<endl;
            int pos,i=1;
            cin>>pos;
            if (pos > n || pos <1)
            {
                cout << "Invalid input"<< endl;

            }
            else{
                cout<< "Enter info for new node: ";
                cin >> ptr2 -> info;
                node *temp;
                temp = start;

                if (pos == 1)
                {
                    ptr2 -> next = start;
                    start = ptr2;
                    n++;
                }
                else{
                    while (i<pos-1)
                    {
                        temp = temp->next;
                        i++;
                    }
                    (*ptr2).next = temp->next;
                    temp->next = ptr2;
                    n++;
                    node *temp1;
                    temp1 = start;
                    while (temp1 != NULL)
                    {
                        cout << "Data is: ";
                        cout << temp1->info << endl;
                        temp1 = temp1->next;
                    }
                }
            }
        }

// DELETION
// Deletion at the beginning
        node *delPtr;
        delPtr =start;
        if(start==NULL){
            cout <<"List Empty";
            return 0;
        }
        else{
            cout << "Deleted first node = "<< delPtr->info << endl;
            start = delPtr->next;
            delete delPtr;
            n--;
            node *temp;
            temp = start;
            cout << "Data remaining is: "<<endl;
            while (temp !=NULL)
            {
                cout << temp->info << endl;
                temp = temp->next;
            }
        }

// Deleting last node
        node *delPtr1;
        if (start ==NULL)
        {
            cout << "Empty list" << endl;
            return 0;
        }
        else{
            node *temp;
            delPtr1 = start;
            while (delPtr1->next != NULL)
            {
                temp =  delPtr1;
                delPtr1 = delPtr1->next;
            }
            temp->next = NULL;            
            cout << "Deleted last node: "<<delPtr1->info<< endl;
            delete delPtr1;
            n--;
            node *temp1;
            temp1 = start;
            cout << "Data remaining is: "<< endl;
            while (temp1 != NULL)
            {
                cout << temp1->info<<endl;
                temp1 = temp1->next;
            }
            
        }

// Deletion at specific location
        node *delPtr2;
        int delPos;
        cout<<"Enter the position to be deleted"<<endl;
        cin>>delPos;
        if(delPos>n || delPos<1){
            cout <<"Invalid Position";
        }
        else{
            if(delPos==1){
                delPtr2 = start;
                cout<<"Deleted node info: " << delPtr2->info << endl;
                start=start->next;
                delete delPtr2;
                n--;
            }
            else{
                int i= 0;
                delPtr2 = start;
                node *temp;
                while (i < delPos-1)
                {
                    temp = delPtr2;
                    delPtr2 = delPtr2->next;
                    i++;
                }
                temp->next = delPtr2->next;
                cout << "Deleted node info:" << delPtr2->info<< endl;
                delete delPtr2;   
                n--;
                node *temp1;
                temp1 = start;
                cout << "Data remaining is: "<< endl;
                while (temp1 != NULL)
                {
                    cout << temp1->info<<endl;
                    temp1 = temp1->next;
                }
                             
            }
        }
    }
    return 0;
}