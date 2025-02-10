#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node *prev;
    node *next;
    node *child;
    node(int val){
        prev = nullptr;
        data = val;
        next = nullptr;
        child = nullptr;
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

void display(node *head){
    while(head!=nullptr){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

node *Flatten(node *head){
    if(head == nullptr){
        return head;
    }
    node *curr = head,*nxt=nullptr;
    while(curr!=nullptr){
        if(curr->child!=nullptr){
            nxt = curr->next;
            curr->next = Flatten(curr->child);
            (curr->next)->prev = curr;
            curr->child = nullptr;

            while(curr->next!=nullptr){
                curr = curr->next;
            }
            if(nxt!=nullptr){
                curr->next = nxt;
                nxt->prev = curr;
            }
        }
        curr = curr->next;
    }
    return head;
}

int main(){
    
    node *head1 = nullptr,*head2 = nullptr,*head3 = nullptr;
    insertAtEnd(&head1,1);
    insertAtEnd(&head1,2);
    insertAtEnd(&head1,3);
    insertAtEnd(&head1,4);
    insertAtEnd(&head1,5);
    display(head1);
    cout<<endl;

    insertAtEnd(&head2,6);
    insertAtEnd(&head2,7);
    insertAtEnd(&head2,8);
    display(head2);
    cout<<endl;

    insertAtEnd(&head3,9);
    insertAtEnd(&head3,10);
    display(head3);
    cout<<endl;

    node *temp = head1;
    temp = (temp->next)->next;
    temp->child = head2;

    temp = head2;
    temp = temp->next;
    temp->child = head3;

    node *head4 = Flatten(head1);
    cout<<"The Flattened list is ";
    display(head4);
    cout<<endl;

    return 0;
}