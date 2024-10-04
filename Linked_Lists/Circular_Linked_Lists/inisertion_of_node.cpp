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
    
    insertAtEnd(&tail,4);
    insertAtEnd(&tail,5);
    insertAtEnd(&tail,6);
    printList(tail);
    
    insertAtPos(&tail,7,1);
    insertAtPos(&tail,8,3);
    insertAtPos(&tail,9,11);
    printList(tail);

    cout<<endl;
    return 0;
}