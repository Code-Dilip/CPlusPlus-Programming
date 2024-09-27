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

void mergeList(node *head1,node *head2,node **head3){
    node *ptr1 = head1,*ptr2 = head2,*ptr3 = *head3;
    while(ptr1!=nullptr && ptr2!=nullptr){
        if(ptr1->data <= ptr2->data){
            insertAtEnd(head3,ptr1->data);
            ptr1 = ptr1->next;
        }
        else{
            insertAtEnd(head3,ptr2->data);
            ptr2 = ptr2->next;
        }
    }
    while(ptr1 != nullptr){
        insertAtEnd(head3,ptr1->data);
        ptr1 = ptr1->next;
    }
    while(ptr2 != nullptr){
        insertAtEnd(head3,ptr2->data);
        ptr2 = ptr2->next;
    }
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
    node *head1 = NULL,*head2 = NULL,*head3 = NULL;
    insertAtEnd(&head1,1);
    insertAtEnd(&head1,3);
    insertAtEnd(&head1,5);
    insertAtEnd(&head1,8);
    insertAtEnd(&head1,10);
    display(head1);
    
    cout<<endl;
    insertAtEnd(&head2,2);
    insertAtEnd(&head2,4);
    insertAtEnd(&head2,9);
    display(head2);
    
    cout<<endl;
    mergeList(head1,head2,&head3);
    display(head3);

    cout<<endl;
    return 0;
}