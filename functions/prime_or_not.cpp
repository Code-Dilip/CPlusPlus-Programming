#include<iostream>
#include<cmath>
using namespace std;

void is_prime(int num){
    int flag = 0;
    for(int i=2;i<sqrt(num);i++){
        if(!(num%i)){
            flag = 1;
            break;
        }
    }
    if(flag){
        cout<<num<<" is Non-Prime no.! "<<endl;
    }
    else{
        cout<<num<<" is Prime no.! "<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    is_prime(n);
    cout<<endl;
    return 0;
}