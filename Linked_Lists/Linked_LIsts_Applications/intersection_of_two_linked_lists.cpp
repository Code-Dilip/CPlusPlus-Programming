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

int length(node *head){
    int count = 0;
    while(head != nullptr){
        count ++;
        head = head->next;
    }
    return count;
}

void intersect(node *head1,node *head2,int pos){
    int l1 = length(head1),l2 = length(head2);
    node *ptr1,*ptr2;
    if(l1 >= l2){
        ptr1 = head1;
        ptr2 = head2;
    }
    if(l2 > l1){
        ptr1 = head2;
        ptr2 = head1;
    }
    pos --;
    while(pos-- && ptr1!=nullptr){
        ptr1 = ptr1->next; 
    }
    while(ptr2->next != nullptr){
        ptr2 = ptr2->next;
    }
    ptr2->next = ptr1;
}



void display(node *ptr){
    if(ptr == nullptr){
        cout<<"The List is Empty!"<<endl;
        return;
    }
   
    while(ptr != NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<"Null"<<endl;
}

int main(){

    cout<<endl;
    node *head1 = NULL,*head2 = NULL;
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
    intersect(head1,head2,3);
    display(head1);
    display(head2);


    cout<<endl;
    return 0;
}