#include<iostream>
using namespace std;

void input_arr(int arr[],int n){
    cout<<"enter the elements!"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
}

void print_array(int arr[],int n){
    cout<<" [ ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]."<<endl;
}

int linear_search(int arr[],int n,int key){
   for(int i=0;i<n;i++){
    if(arr[i] == key){
        return i;
    }
   } 
   return -1;
}

int main(){
    int n,key,ind;
    cout<<"\nenter the size of the array: ";
    cin>>n;
    cout<<endl;

    int arr[n];
    input_arr(arr,n);
    cout<<"enter the search element: ";
    cin>>key;

    ind = linear_search(arr,n,key);
    if(ind == -1){
        cout<<"The search element "<<key<<" is not present in the array!"<<endl;
    }
    else{
        cout<<"The search element "<<key<<" is at index "<<ind<<" ."<<endl;
    }

    return 0;
}