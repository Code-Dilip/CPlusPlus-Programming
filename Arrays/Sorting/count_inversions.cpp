#include<iostream>

using namespace std;

void input_arr(int arr[],int n){
    cout<<"\nenter the array elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
}

void print_arr(int arr[],int n){
    cout<<"\n[ ";
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
    cout<<" ]"<<endl;
}

int merge(int arr[],int l,int mid,int r){
    int inv = 0;

    int n1 = mid-l+1;
    int n2 = r-mid;
    int a[n1],b[n2];

    for(int i=0;i<n1;i++){
        a[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i] = arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            arr[k] = a[i];
            i++;
            k++;
        }
        else{
            inv += n1 - i;
            arr[k] = b[j];
            j++;
            k++;
        }
    }
    
    while(i<n1){
        arr[k] = a[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = b[j];
        j++;
        k++;
    }

    return inv;
}

int count_inversions(int arr[],int l,int r){
    int inv = 0;
    if(l<r){
        int mid = (l+r)/2;
        
        inv += count_inversions(arr,l,mid);
        inv += count_inversions(arr,mid+1,r);

        inv += merge(arr,l,mid,r);
    }
    return inv;
}

int main(){
    int n;
    cout<<"\nenter the size of the array: ";
    cin>>n;
    int arr[n];
    input_arr(arr,n);
    cout<<"\nThe array is ";
    print_arr(arr,n);
    
    cout<<"\nThe number of inversions in the array is "<<count_inversions(arr,0,n-1)<<" ."<<endl;
    cout<<endl;

    return 0;
}