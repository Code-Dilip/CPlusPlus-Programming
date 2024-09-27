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
        return ;
    }
    node *temp = *head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newp;
}

void insertAtPos(node **head,int val,int pos){
    node *newp = new node(val);
    if(*head == nullptr || pos == 1){
        *head = newp;
    }
    node *temp = *head;
    pos --;
    while(pos>1 && temp->next != nullptr){
        temp = temp->next;
        pos --;
    }
    newp->next = temp->next;
    temp->next = newp;
}

void display(node *ptr){
    if(ptr == nullptr){
        cout<<"\nThe List is Empty!"<<endl;
    }
    cout<<ptr->data;
    ptr = ptr->next;
    while(ptr != NULL){
        cout<<"->"<<ptr->data;
        ptr = ptr->next;
    }
    cout<<endl;
}

int main(){
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

    insertAtPos(&head,9,2);
    display(head);
    insertAtPos(&head,10,6);
    display(head);
    insertAtPos(&head,11,12);
    display(head);

    cout<<endl;
    return 0;
}