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
    Node *newp = new Node (val);
    if((*head) == nullptr){
        *head = newp;
        return ;
    }
    Node *ptr = *head;
    while(ptr->nxt!=nullptr){
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

Node *merge2Lists(Node *head1, Node *head2){
    if(head1==nullptr || head2==nullptr){
        return (head1==nullptr?head2:head1);
    }
    if(head1->data<=head2->data){
        head1->nxt = merge2Lists(head1->nxt,head2);
        return head1;
    }
    else{
        head2->nxt = merge2Lists(head1,head2->nxt);
        return head2;
    }
}

Node *mergeListsIteratively(Node *head1,Node *head2){
    Node *ptr1=head1, *ptr2=head2,*temp = new Node(-1),*result = temp;
    while (ptr1!=nullptr && ptr2!=nullptr)
    {
        if(ptr1->data<=ptr2->data){
            result->nxt = new Node(ptr1->data);
            result = result->nxt;
            ptr1 = ptr1->nxt;
        }
        else{
            result->nxt = new Node (ptr2->data);
            result = result->nxt;
            ptr2 = ptr2->nxt;
        }
    }
    while(ptr1!=nullptr){
        result->nxt = new Node(ptr1->data);
        ptr1 = ptr1->nxt;
        result = result->nxt;
    }
    while (ptr2!=nullptr)
    {
        result->nxt = new Node(ptr2->data);
        ptr2 = ptr2->nxt;
        result = result->nxt;
    }
    return temp->nxt;
}

int main(){
    Node *head1=nullptr, *head2=nullptr;
    
    insertAtEnd(&head1,0);
    insertAtEnd(&head1,2);
    insertAtEnd(&head1,4);
    insertAtEnd(&head1,7);
    cout<<"\n";
    printList(head1);
   
    insertAtEnd(&head2,1);
    insertAtEnd(&head2,3);
    insertAtEnd(&head2,5);
    insertAtEnd(&head2,9);
    cout<<"\n";
    printList(head2);

    Node *mLI = mergeListsIteratively(head1,head2);
    cout<<"\nThe merged Linked List itteratively is ";
    printList(mLI);

    Node *mLR = merge2Lists(head1,head2);
    cout<<"\nThe merged Linked List recursively is ";
    printList(mLR);
    
    return 0;
}