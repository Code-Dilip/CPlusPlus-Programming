#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int val){
        data = val;
        next = nullptr;
    }
};

void insertAtHead(node **head,int val){
    node *newp = new node(val);
    newp->next = *head;
    *head = newp;
}

void insertAtEnd(node **head,int val){
    node *newp = new node(val);
    if(*head == nullptr){
        *head = newp;
        return;
    }
    node *temp = *head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newp;
}

void display(node *ptr){
    if(ptr == nullptr){
        cout<<"\nEmpty List! "<<endl;
        return;
    }
    cout<<ptr->data;
    ptr = ptr->next;
    while(ptr!=nullptr){
        cout<<"->"<<ptr->data;
        ptr = ptr->next;
    }
    cout<<endl;
}

int search(node *ptr,int key){
    if(ptr == nullptr){
        return -1;
    }
    int count = 0;
    while(ptr!=nullptr){
        count ++;
        if(ptr->data == key){
            return count;
        }
        ptr = ptr->next;
    }
    return -1;
}

int main(){

    cout<<endl;
    node *head = NULL;
    insertAtHead(&head,1);
    insertAtHead(&head,2);
    insertAtHead(&head,3);
    insertAtHead(&head,4);
    insertAtHead(&head,5);
    insertAtEnd(&head,6);
    insertAtEnd(&head,7);
    insertAtEnd(&head,8);
    display(head);
    cout<<search(head,5)<<endl;
    cout<<search(head,8)<<endl;
    cout<<search(head,9)<<endl;

    cout<<endl;
    return 0;
}