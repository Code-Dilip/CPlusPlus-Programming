#include<iostream>

using namespace std;

void input_arr(int *arr,int n){
    cout<<"\nenter the array elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>*(arr+i);
    }
    cout<<endl;
}

void print_arr(int *arr,int n){
    cout<<"\nThe array is [";
    for(int i=0;i<n;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<"] ."<<endl;
}

int first_occ(int *arr,int n,int i,int key){
    if(i==n){
        return -1;
    }
    if(*(arr+i)==key){
        return i;
    }
    return first_occ(arr,n,i+1,key);
}

int last_occ(int *arr,int n,int i,int key){
    if(i==n){
        return -1;
    }
    int rest_arr = last_occ(arr,n,i+1,key);
    if(rest_arr != -1){
        return rest_arr;
    }
    if(*(arr+i)==key){
        return i;
    }
    return -1;
}


int main(){
    int n;
    cout<<"\nenter the size of the array: ";
    cin>>n;
    int arr[n],key,pos;
    input_arr(arr,n);
    print_arr(arr,n);

    cout<<"\nenter the search element: ";
    cin>>key;
    pos = first_occ(arr,n,0,key);
    
    if(pos!=-1){
        cout<<"The first occurance of "<<key<<" in the array is at index "<<pos<<" ."<<endl;
    }
    else{
        cout<<"The search element "<<key<<" is not present in the array!"<<endl;
    }

    pos = last_occ(arr,n,0,key);
    if(pos!=-1){
        cout<<"The last occurance of "<<key<<" in the array is at index "<<pos<<" ."<<endl;
    }
    else{
        cout<<"The search element "<<key<<" is not present in the array!"<<endl;
    }

    cout<<endl;
    return 0;
}