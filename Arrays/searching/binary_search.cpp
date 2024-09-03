#include<iostream>
using namespace std;

void input_arr(int arr[],int n){
    cout<<"enter the elements in array!"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
}

void output_arr(int arr[],int n){
    cout<<"[ ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"] ."<<endl;
}

void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int current = arr[i];
        int j = i-1;
        while(arr[j]>current && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

int binary_search(int arr[],int n,int key){
    int start=0,end=n-1,mid;
    while(start<=end){
        mid = (start+end)/2;
        if(key == arr[mid]){
            return mid;
        }
        else if(key < arr[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}


int main(){
    int n,key,ind;
    cout<<"\nenter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<endl;
    
    input_arr(arr,n);
    insertion_sort(arr,n);

    char ws='y';
    while(ws=='y' || ws=='Y'){
        cout<<"enter the search element: ";
        cin>>key;
        ind = binary_search(arr,n,key);

        if(ind == -1){
           cout<<"The search element "<<key<<" is not present in the array! "<<endl;
        }
        else{
            cout<<"The search element "<<key<<" is at index "<<ind<<" !"<<endl;
        }
        cout<<"Want to search more elements? (press y/n) :";
        cin>>ws;
        cout<<endl;
    }

    return 0;
}