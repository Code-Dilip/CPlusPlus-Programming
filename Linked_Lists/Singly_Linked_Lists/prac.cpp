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

Node *insertAtFront(Node *head,int val){
    Node *newp = new Node(val);
    newp->nxt = head;
    head = newp;
    return head;
}

Node *insertAtEnd(Node *head,int val){
    Node *newp = new Node(val);
    if(head == nullptr){
        head = newp;
        return head;
    }
    Node *temp = head;
    while(temp->nxt != nullptr){
        temp = temp->nxt;
    }
    temp->nxt = newp;
    return head;
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
    head = insertAtFront(head,3);
    head = insertAtFront(head,2);
    head = insertAtFront(head,1);
    cout<<"\n The List After inserting at Front: ";
    printList(head);
    
    head = insertAtEnd(head,4);
    head = insertAtEnd(head,5);
    head = insertAtEnd(head,6);
    cout<<"\n The List After inserting at End: ";
    printList(head);
    return 0;
}