#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *nxt;
    Node(int val){
        data = val;
        nxt = nullptr;
    }
};

void insertAtFront(Node **head,int val){
    Node *newp = new Node(val);
    newp->nxt = *head;
    *head = newp;
}

void insertAtEnd(Node **head,int val){
    Node *newp = new Node(val);
    if(head == nullptr){
        *head = newp;
        return ;
    }
    Node *temp = *head;
    while(temp->nxt != nullptr){
        temp = temp->nxt;
    }
    temp->nxt = newp;
}

void insertAtPos(Node **head,int val,int pos){
    Node *newp = new Node(val);
    if(head == nullptr){
        *head = newp;
        return ;
    }
    Node *temp = *head;
    int count = 1;
    while(count<pos-1 && temp->nxt!=nullptr){
        temp = temp->nxt;
        count++;
    }
    newp->nxt = temp->nxt;
    temp->nxt = newp;
}

void deleteAtFront(Node **head){
    if(head == nullptr){
        cout<<"The List is Empty!";
        return ;
    }
    Node *temp = *head;
    *head = (*head)->nxt;
    delete temp;
}

void deleterAtEnd(Node **head){
    if(head == nullptr){
        cout<<"The List is Empty!";
    }
    Node *temp = *head;
    while(temp->nxt->nxt != nullptr){
        temp = temp->nxt;
    }
    delete temp->nxt;
    temp->nxt = nullptr;
}

void deleteAtPos(Node **head,int pos){
    if(head == nullptr){
        cout<<"The List is Empty!";
        return ;
    }
    Node *temp = *head;
    Node *del;
    int count = 1;
    while(count < pos-1 && temp->nxt != nullptr){
        temp = temp->nxt;
        count ++;
    }
    del = temp->nxt;
    temp->nxt = del->nxt;
    delete del;
}

void printList(Node *head){
    Node *ptr = head;
    while(ptr->nxt != nullptr){
        cout<<ptr->data<<" -> ";
        ptr = ptr->nxt;
    }
    cout<<ptr->data;
}

int main(){
    Node *head = nullptr;
    insertAtFront(&head,3);
    insertAtFront(&head,2);
    insertAtFront(&head,1);
    cout<<"\n The List After inserting at Front: ";
    printList(head);

    insertAtEnd(&head,4);
    insertAtEnd(&head,5);
    insertAtEnd(&head,6);
    cout<<"\n The List After inserting at End: ";
    printList(head);

    insertAtPos(&head,7,6);
    insertAtPos(&head,8,2);
    cout<<"\n The List After inserting at certain Positions is ";
    printList(head);

    deleteAtFront(&head);
    cout<<"\n The list After deleting at first is ";
    printList(head);

    deleterAtEnd(&head);
    cout<<"\n The list After deleting at End is ";
    printList(head);

    deleteAtPos(&head,2);
    cout<<"\n The list After deleting at Certain Pos is ";
    printList(head);

    return 0;
}