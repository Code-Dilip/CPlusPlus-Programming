#include<iostream>
#include<string>
#include<climits>

using namespace std;

int main(){
    string str;
    cout<<"\nenter a string: ";
    getline(cin,str);
    cout<<"\nThe entered string is "<<str<<endl;

    int max_f = INT_MIN,freq[26],n;
    char ans ='a';
    n = str.size();
    
    for(int i=0;i<26;i++){
        freq[i] = 0;
    }
    for(int i=0;i<n;i++){
        freq[str[i]-'a'] ++;
    }
    for(int i=0;i<26;i++){
        if(freq[i]>max_f){
            max_f = freq[i];
            ans = i+'a';
        }
    }

    cout<<"\ncharacter '"<<ans<<"' is repeated more number times in the string i.e "<<max_f<<" times."<<endl;

    cout<<endl;
    return 0;
}