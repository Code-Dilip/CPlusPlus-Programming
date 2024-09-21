#include<iostream>
#include<vector>

using namespace std;

int main(){
    cout<<endl;
    vector<int>v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    for(int i=0;i<v.size();i++){ // iterate using for loop
        cout<<v[i]<<" ";
    }
    cout<<endl;

    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
 
    for(auto element:v){   // iterate using auto keyword
        cout<<element<<" ";
    }
    cout<<endl;

    v.pop_back();
    v.pop_back();
    for(auto element:v){   // iterate using auto keyword
        cout<<element<<" ";
    }
    cout<<endl;

    vector<int>v2(2,10);
    for(auto element:v2){
        cout<<element<<" ";
    }
    cout<<endl;

    swap(v,v2);
    cout<<endl;
    for(auto element:v){
        cout<<element<<" ";
    }
    cout<<endl;

    for(auto element:v2){
        cout<<element<<" ";
    }
    cout<<endl;


    return 0;
}