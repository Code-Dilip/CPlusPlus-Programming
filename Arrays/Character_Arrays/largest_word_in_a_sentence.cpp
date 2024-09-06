#include<iostream>
#include<climits>
#include<string>

using namespace std;

void largest_word(string str){
    int max_len=INT_MIN,current_len=0,n=str.size(),st_idx=0,max_st_idx=0;
    for(int i=0;i<n;i++){
        if(str[i]==' ' || str[i]=='\0'){
            if(current_len > max_len){
                max_len = current_len;
                max_st_idx = st_idx;
            }
            current_len = 0;
            st_idx = i+1;
        }
        else{
            current_len ++;
        }
    }
    cout<<"Largest word in the sentence is ";
    for(int i=0;i<max_len;i++){
        cout<<str[max_st_idx+i];
    }
    cout<<endl;
}

int main(){
    string str;
    cout<<"\nenter a sentence to find largest word in it: ";
    getline(cin,str);
    cout<<"The entered string is "<<str<<endl;

    largest_word(str);

    cout<<endl;
    return 0;
}