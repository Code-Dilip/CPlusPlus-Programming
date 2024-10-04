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

int length(node *tail){
    int count = 0;
    node *head = (tail)->next;
    do{
        head = head->next;
        count ++;
    }while(head != tail->next);
    return count;
}

void insertAtHead(node **tail,int val){
    node *newp = new node(val);
    if(*tail == nullptr){
        *tail = newp;
        newp->next  = *tail;
        return ;
    }
    newp->next = (*tail)->next;
    (*tail)->next = newp;
}

void insertAtEnd(node **tail,int val){
    node *newp = new node(val);
    if(*tail == nullptr){
        *tail = newp;
        newp->next = *tail;
        return ;
    }
    newp->next = (*tail)->next;
    (*tail)->next = newp;
    *tail = newp;
}

void insertAtPos(node **tail,int val,int pos){
    node *temp = *tail;
    if(pos == 1){
        insertAtHead(tail,val);
        return ;
    }
    if(pos >= length(temp)){
        insertAtEnd(tail,val);
        return ;
    }
    node *newp = new node(val);
    if(*tail == nullptr){
        *tail = newp;
        newp->next = *tail;
        return ;
    }
    pos --;
    node *head = (*tail)->next;
    while(pos > 1){
        head = head->next;
        pos --;
    }
    newp->next = head->next;
    head->next = newp;
    if(head == *tail){
        *tail = (*tail)->next;
    }
}

void deleteAtHead(node **tail){
    if(*tail == nullptr){
        cout<<"Empty!"<<endl;
        return ;
    }
    node *head = (*tail)->next;
    (*tail)->next = head->next;
    free(head);
    head = nullptr;
}

void deleteAtEnd(node **tail){
    if(*tail == nullptr){
        cout<<"Empty!"<<endl;
        return ;
    }
    node *head = (*tail)->next;
    while(head->next != (*tail)){
        head = head->next;
    }
    head->next = (*tail)->next;
    free(*tail);
    *tail = head;
}

void deleteAtPos(node **tail,int pos){
    if(pos == 1){
        deleteAtHead(tail);
        return ;
    }
    node *temp = *tail;
    if(pos >= length(temp)){
        deleteAtEnd(tail);
        return ;
    }
    pos --;
    node *head = (*tail)->next;
    while(pos > 1){
        head = head->next ;
        pos --;
    }
    node *freePtr = head->next;
    head->next = head->next->next;
    free(freePtr);
    freePtr = nullptr;
}

void printList(node *tail){
    node *head = tail->next;
    do{
        cout<<(head->data)<<"->";
        head = head->next;
    }while(head != tail->next);
    cout<<"NULL"<<endl;
}

int main(){
    cout<<endl;
    node *tail = nullptr;
    insertAtHead(&tail,3);
    insertAtHead(&tail,2);
    insertAtHead(&tail,1);
    printList(tail);
    cout<<endl;
    
    insertAtEnd(&tail,4);
    insertAtEnd(&tail,5);
    insertAtEnd(&tail,6);
    printList(tail);
    cout<<endl;
    
    insertAtPos(&tail,7,1);
    insertAtPos(&tail,8,3);
    printList(tail);
    insertAtPos(&tail,9,11);
    printList(tail);
    cout<<endl;

    deleteAtHead(&tail);
    printList(tail);
    deleteAtHead(&tail);
    printList(tail);
    cout<<endl;

    deleteAtEnd(&tail);
    deleteAtEnd(&tail);
    printList(tail);
    cout<<endl;

    deleteAtPos(&tail,1);
    printList(tail);
    deleteAtPos(&tail,3);
    printList(tail);
    deleteAtPos(&tail,10);
    printList(tail);

    cout<<endl;
    return 0;
}