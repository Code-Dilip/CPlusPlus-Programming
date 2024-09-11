#include<iostream>

using namespace std;

void primeSieve(int n){
    const int len = 1e3;
    int prime[len] = {0};
    for(int i=2;i<n;i++){
        if(!prime[i]){
            for(int j=i*i;j<n;j+=i){
                prime[j] = 1;
            }
        }
    }
    cout<<"The range of prime numbers till "<<n<<" are [ ";
    for(int i=2;i<n;i++){
        if(!prime[i]){
            cout<<i<<" ";
        }
    }
    cout<<"]"<<endl;
}

int main(){
    int n;
    cout<<endl;
    cout<<"enter a number: ";
    cin>>n;
    primeSieve(n);
    cout<<endl;
    return 0;
}