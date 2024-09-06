#include<iostream>
#include<string>

using namespace std;

void sort(string str){
    int n=str.size();
    for(int i=1;i<n;i++){
        int j=i-1;
        char current_ele = str[i];
        while(j>=0 && current_ele < str[j]){
            str[j+1] = str[j];
            j--;
        }
        str[j+1] = current_ele;
    }
    cout<<"\nThe sorted string is "<<str<<" ."<<endl;
}

int main(){
    string str;
    cout<<"\nenter the string: ";
    getline(cin,str);
    sort(str);
    cout<<endl;
    return 0;
}