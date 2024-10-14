#include<iostream>

using namespace std;

class node{
    public:
    float coeff;
    int expo;
    node *next;

    public:
    node(float val1,int val2){
        coeff = val1;
        expo = val2;
        next = nullptr;
    }
};

void insertTerm(node **head,float coeff,int expo){
    node *newp = new node(coeff,expo);
    if(newp == nullptr){
        cout<<"Memory cannot be allocated further!"<<endl;
        return;
    }
    if(*head == nullptr || expo > (*head)->expo){
        newp->next = (*head);
        *head = newp;
        return;
    }
    else{
        node *temp = (*head);
        while(temp->next != nullptr && temp->next->expo >  expo){
            temp = temp->next;
        }
        newp->next = temp->next;
        temp->next = newp;
    }
}

void createPolyFunc(node **head,int n){
    cout<<"\n";
    for(int i=0;i<n;i++){
        float coeff;
        int expo;
        cout<<"enter the coefficient of "<<i+1<<" term: ";
        cin>>coeff;
        cout<<"enter the exponent of "<<i+1<<" term: ";
        cin>>expo;
        insertTerm(head,coeff,expo);
    }
}

void simplifyProduct(node **head3){
    node *ptr = *head3;
    node *toDelete;
    while(ptr->next!=nullptr){
        if(ptr->expo==ptr->next->expo){
            ptr->coeff = ptr->coeff + ptr->next->coeff;
            toDelete = ptr->next;
            ptr->next = ptr->next->next;
            free(toDelete);
        }
        else{
            ptr = ptr->next;
        }
    }
}

void polyMul(node **head1,node **head2,node **head3){
    if(*head1 == nullptr && *head2 == nullptr){
        return ;
    }
    else if(*head1 == nullptr){
        *head3 = *head2;
        return;
    }
    else if(*head2 == nullptr){
        *head3 = *head1;
        return ;
    }
    else{
        node *ptr1 = *head1 ,*ptr2 ;
        while(ptr1 != nullptr){
            ptr2 = *head2;
            while(ptr2 != nullptr){
                insertTerm(head3,(ptr1->coeff*ptr2->coeff),(ptr1->expo+ptr2->expo));
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
        simplifyProduct(head3);
    }
}

void print(node *ptr){
    while(ptr->next != nullptr){
        cout<<"("<<ptr->coeff<<"*x^"<<ptr->expo<<") + ";
        ptr = ptr->next;
    }
    cout<<" ("<<ptr->coeff<<"*x^"<<ptr->expo<<") ";
}

int main(){
    int n;
    node *head1 = nullptr,*head2 = nullptr,*head3 = nullptr;
    cout<<"\nenter the number of terms in the first polynomial function: ";
    cin>>n;
    createPolyFunc(&head1,n);
    print(head1);
    cout<<endl;

    cout<<"\nenter the number of terms in the second polynomial function: ";
    cin>>n;
    createPolyFunc(&head2,n);
    print(head2);
    cout<<endl;
    
    polyMul(&head1,&head2,&head3);
    cout<<"\n";
    print(head1);
    cout<<" * ";
    print(head2);
    cout<<" = ";
    print(head3);
    cout<<endl;

    return 0;
}