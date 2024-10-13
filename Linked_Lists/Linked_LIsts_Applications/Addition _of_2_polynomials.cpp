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

void polyAdd(node **head1,node **head2,node **head3){
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
        node *ptr1 = *head1,*ptr2 = *head2;
        while(ptr1!=nullptr && ptr2!=nullptr){
            if(ptr1->expo == ptr2->expo){
                insertTerm(head3,ptr1->coeff+ptr2->coeff,ptr1->expo);
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else if(ptr1->expo > ptr2->expo){
                insertTerm(head3,ptr1->coeff,ptr1->expo);
                ptr1 = ptr1->next;
            }
            else{
                insertTerm(head3,ptr2->coeff,ptr2->expo);
                ptr2 = ptr2->next;
            }
        }
        while(ptr1 != nullptr){
            insertTerm(head3,ptr1->coeff,ptr1->expo);
            ptr1 = ptr1->next;
        }
        while(ptr2!=nullptr){
            insertTerm(head3,ptr2->coeff,ptr2->expo);
            ptr2 = ptr2->next;
        }
    }
}

void print(node *ptr){
    while(ptr->next != nullptr){
        cout<<"("<<ptr->coeff<<"*10^"<<ptr->expo<<") + ";
        ptr = ptr->next;
    }
    cout<<" ("<<ptr->coeff<<"*10^"<<ptr->expo<<") ";
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
    
    polyAdd(&head1,&head2,&head3);
    cout<<"\n";
    print(head1);
    cout<<" + ";
    print(head2);
    cout<<" = ";
    print(head3);
    cout<<endl;

    return 0;
}