#include<iostream>

using namespace std;

int countPath(int s,int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count = 0;
    for(int i=1;i<=6;i++){
        count += countPath(s+i,e);
    }
    return count;
}

int main(){
    int s,e;
    cout<<"\nenter the starting position: ";
    cin>>s;
    cout<<"enter the ending position: ";
    cin>>e;
    cout<<"The total number of paths to reach from "<<s<<" to "<<e<<" is "<<countPath(s,e)<<endl;
    cout<<endl;
    return 0;
}