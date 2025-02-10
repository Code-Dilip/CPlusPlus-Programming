#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node *prev;
    node *next;
    node(int val){
        prev = nullptr;
        data = val;
        next = nullptr;
    }
};

void insertAtHead(node **head,int val){
    node *newp = new node(val);
    if(*head == nullptr){
        *head = newp;
        return ;
    }
    newp->next = *head;
    (*head)->prev = newp;
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
    newp->prev = temp;
}

void insertAtPos(node **head,int val,int pos){
    if(pos == 1){
        insertAtHead(head,val);
        return;
    }
    node *newp = new node(val);
    if(*head == nullptr){
        *head = newp;
        return ;
    }
    pos --;
    node *temp = *head;
    while(pos > 1 && temp->next != nullptr){
        temp = temp->next;
        pos --;
    }
    newp->next = temp->next;
    newp->prev = temp;
    if(temp->next != nullptr){
        temp->next->prev = newp;
    }
    temp->next = newp;
}

void deleteAtHead(node **head){
    if(*head == nullptr){
        cout<<"Empty!"<<endl;
        return ;
    }
    node *temp = *head;
    if((*head)->next != nullptr){
        (*head)->next->prev = nullptr;
    }
    *head = (*head)->next;
    temp->next = nullptr;
    free(temp);
    temp = nullptr;
}

void deleteAtEnd(node **head){
    if(*head == nullptr){
        cout<<"Empty!"<<endl;
        return ;
    }
    node *temp = *head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
}

void deleteAtPos(node **head,int pos){
    if(*head == nullptr){
        cout<<"Empty!"<<endl;
        return ;
    }
    if(pos == 1){
        deleteAtHead(head);
        return ;
    }
    node *temp = *head;
    while(pos>1 && temp->next!=nullptr){
        temp = temp->next;
        pos --;
    }
    temp->prev->next = temp->next;
    if(temp->next != nullptr){
        temp->next->prev = temp->prev;
    }
}

node *reverseKNodes(node *head,int k){
    node *temp = head;
    int count = 0;
    while(count < k){
        if(temp==nullptr){
            return head;
        }
        temp = temp->next;
        count ++;
    }
    node *prevNode = reverseKNodes(temp,k);
    temp = head;
    node *nxt;
    count = 0;
    while(count < k){
        nxt = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = nxt;
        count ++;
    }
    head = prevNode;
    return head;
}

void display(node *head){
    while(head!=nullptr){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node *head = nullptr;
    insertAtEnd(&head,1);
    insertAtEnd(&head,2);
    insertAtEnd(&head,3);
    insertAtEnd(&head,4);
    insertAtEnd(&head,5);
 
    display(head);
    cout<<endl;

    head = reverseKNodes(head,2);
    display(head);
    cout<<endl;
}