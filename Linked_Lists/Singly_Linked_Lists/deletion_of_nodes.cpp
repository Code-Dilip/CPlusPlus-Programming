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
    if(pos == 1){
        insertAtHead(head,val);
        return ;
    }
    node *newp = new node(val);
    if(*head == nullptr){
        *head = newp;
        return ;
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

void deleteAtHead(node **head){
    if(*head == nullptr){
        cout<<"Empty!"<<endl;
        return ;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
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
    if(pos == 1){
        deleteAtHead(head);
        return ;
    }
    if(*head == nullptr){
        cout<<"Empty!"<<endl;
        return ;
    }
    node *temp = *head,*del_node;
    pos --;
    while(pos > 1 && temp->next != nullptr){
        temp = temp->next;
        pos --;
    }
    if(temp->next == nullptr){
        deleteAtEnd(head);
        return ;
    }
    del_node = temp->next;
    temp->next = temp->next->next;
    free(del_node);
}

void display(node *ptr){
    if(ptr == nullptr){
        cout<<"\nThe List is Empty!"<<endl;
    }
   
    while(ptr != NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<"Null"<<endl;
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

    cout<<endl;
    insertAtPos(&head,13,1);
    insertAtPos(&head,9,2);
    display(head);
    insertAtPos(&head,10,6);
    display(head);
    insertAtPos(&head,11,12);
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
    deleteAtPos(&head,15);
    display(head);

    cout<<endl;
    return 0;
}