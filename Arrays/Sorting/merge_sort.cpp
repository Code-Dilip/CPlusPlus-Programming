#include<iostream>
#include<vector>

using namespace std;

void input_arr(int arr[],int n){
  cout<<"\nenter the array elements!\n";
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<endl;
}

void print_arr(int arr[],int n){
  cout<<"[";
  for(int i=0;i<n;i++){
    cout<<" "<<arr[i];
  }
  cout<<" ]\n";
}

void merge(int arr[],int l,int mid,int r){
  int n1 = mid-l+1;
  int n2 = r-mid;
  int a[n1],b[n2];

  for(int i=0;i<n1;i++){
    a[i] = arr[l+i];
  }
  for(int j=0;j<n2;j++){
    b[j] = arr[mid+1+j];
  }

  int i=0,j=0,k=l;
  while(i<n1 && j<n2){
    if(a[i]<b[j]){
      arr[k] = a[i];
      i++;
      k++;
    }
    else{
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

}

void mergeSort(int arr[],int l,int r){
  if(l<r){
    int mid = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);

    merge(arr,l,mid,r);
  }
}

int main(){
  int n;
  cout<<"\nenter the size of the array: ";
  cin>>n;
  int arr[n];

  input_arr(arr,n);
  cout<<"The array before sorting is ";
  print_arr(arr,n);
  mergeSort(arr,0,n-1);
  cout<<"The array after sorting is ";
  print_arr(arr,n);
  cout<<endl;
  return 0;
}