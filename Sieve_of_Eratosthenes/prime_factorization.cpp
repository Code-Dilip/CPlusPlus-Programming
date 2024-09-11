#include<iostream>

using namespace std;

void prime_factors(int n){
    const int len = 1e4;
    int spf[len] = {0};
    for(int i=2;i<=n;i++){
        spf[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j){
                    spf[j] =  i;
                }
            }
        }
    }
    cout<<"Prime factors of "<<n<<" : ";
    while(n!=1){
        cout<<spf[n]<<" ";
        n /= spf[n];
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"\nenter a number to find prime factors of it: ";
    cin>>n;
    prime_factors(n);
    cout<<endl;
    return 0;
}