#include<iostream>
using namespace std;

void print_character_array(char str[]){
    int i=0;
    while(str[i] != '\0'){
        cout<<str[i];
        i++;
    }
    cout<<endl;
}

bool check_palindrome(char str[],int n){
    for(int i=0;i<n;i++){
        if(str[i]!=str[n-1-i]){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout<<"\nenter the size of the word: ";
    cin>>n;
    char str[n+1];
    cout<<"enter the word: ";
    cin>>str;

    cout<<"\nThe word is ";
    print_character_array(str);

    if(check_palindrome(str,n)){
        cout<<"entered word is palindrome!"<<endl;
    }
    else{
        cout<<"entered word is not palindrome!"<<endl;
    }

    cout<<endl;
    return 0;
}