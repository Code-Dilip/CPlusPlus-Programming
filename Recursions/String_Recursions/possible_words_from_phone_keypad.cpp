#include<iostream>
#include<string>

using namespace std;

string keyPadArray[] = {"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void printPossibleWords(string str,string ans){
    if(!str.length()){
        cout<<ans<<endl;
        return;
    }
    char ch = str[0];
    string word = keyPadArray[ch-'0'];
    for(int i=0;i<word.length();i++){
        printPossibleWords(str.substr(1),ans+word[i]);
    }
}

int main(){
    cout<<endl;
    printPossibleWords("23","");
    cout<<endl;
    return 0;
}