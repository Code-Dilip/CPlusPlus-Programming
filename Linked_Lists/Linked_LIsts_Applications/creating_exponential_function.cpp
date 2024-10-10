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
    if(*head == nullptr){
        *head = newp;
        return;
    }
    node *temp = (*head);
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newp;
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

void print(node *ptr){
    while(ptr->next != nullptr){
        cout<<"("<<ptr->coeff<<"*10^"<<ptr->expo<<") + ";
        ptr = ptr->next;
    }
    cout<<" ("<<ptr->coeff<<"10^"<<ptr->expo<<") "<<endl;
}

int main(){
    int n;
    node *head1 = nullptr;
    cout<<"\nenter the number of terms in the first polynomial function: ";
    cin>>n;
    createPolyFunc(&head1,n);
    print(head1);

    return 0;
}