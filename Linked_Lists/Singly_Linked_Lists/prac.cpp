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
    Node *ptr = *head;
    while(ptr->nxt != nullptr){
        ptr = ptr->nxt;
    }
    ptr->nxt = newp;
}

void printList(Node *head){
    Node *temp = head;
    while(temp->nxt!=nullptr){
        cout<<temp->data<<" -> ";
        temp = temp->nxt;
    }
    cout<<temp->data;
}

void insertAtPos(Node **head,int val,int pos){
    Node *newp = new Node(val);
    if(head == nullptr){
        *head = newp;
        return ;
    }
    int count = 1;
    Node *ptr = *head;
    while(count<pos-1 && ptr->nxt!=nullptr){
        ptr = ptr->nxt;
        count ++;
    }
    newp->nxt = ptr->nxt;
    ptr->nxt = newp;
}

void deleteAtFront(Node **head){
    if(head == nullptr){
        cout<<"The List is Empty!"<<endl;
        return ;
    }
    Node *del = *head;
    *head = (*head)->nxt;
    delete del;
}

void deleteAtEnd(Node **head){
    if(head == nullptr){
        cout<<"The List is Empty!"<<endl;
        return ;
    }
    Node *temp = *head;
    while (temp->nxt->nxt != nullptr)
    {
        temp = temp->nxt;
    }
    delete temp->nxt;
    temp->nxt = nullptr;
}

void deleteAtPos(Node **head,int pos){
    if(head == nullptr){
        cout<<"The List is Empty!"<<endl;
    }
    Node *temp = *head, *del;
    int count = 1;
    while(count<pos-1 && temp->nxt!=nullptr){
        temp = temp->nxt;
        count ++;
    }
    del = temp->nxt;
    temp->nxt = del->nxt;
    delete del;
}

int main(){
    Node *head = nullptr;
    insertAtFront(&head,3);
    insertAtFront(&head,2);
    insertAtFront(&head,1);
    cout<<"\n";
    printList(head);
    
    insertAtEnd(&head,4);
    insertAtEnd(&head,5);
    insertAtEnd(&head,6);
    cout<<"\n";
    printList(head);

    insertAtPos(&head,7,6);
    insertAtPos(&head,8,4);
    insertAtPos(&head,9,1);
    cout<<"\n";
    printList(head);

    deleteAtFront(&head);
    cout<<"\n";
    printList(head);

    deleteAtEnd(&head);
    cout<<"\n";
    printList(head);

    deleteAtPos(&head,3);
    cout<<"\n";
    printList(head);

    return 0;
}