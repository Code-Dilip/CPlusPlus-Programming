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

void reverseList(node **head){
    node *curr = *head,*prev = nullptr,*next = nullptr;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
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
    insertAtHead(&head,3);
    insertAtHead(&head,2);
    insertAtHead(&head,1);
    display(head);

    cout<<endl;
    insertAtEnd(&head,4);
    insertAtEnd(&head,5);
    insertAtEnd(&head,6);
    display(head);

    cout<<endl;
    insertAtPos(&head,0,1);
    display(head);
    insertAtPos(&head,7,5);
    display(head);
    insertAtPos(&head,8,10);
    display(head);
    
    cout<<endl;
    deleteAtHead(&head);
    display(head);
    
    cout<<endl;
    deleteAtEnd(&head);
    display(head);

    cout<<endl;
    deleteAtPos(&head,1);
    display(head);
    deleteAtPos(&head,5);
    display(head);
    deleteAtPos(&head,10);
    display(head);

    cout<<endl;
    reverseList(&head);
    display(head);
    
    cout<<endl;
    return 0;
}