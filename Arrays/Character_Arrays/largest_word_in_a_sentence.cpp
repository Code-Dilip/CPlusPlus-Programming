#include<iostream>
#include<climits>
using namespace std;

void print_char_array(char str[]){
    int i=0;
    while(str[i] != '\0'){
        cout<<str[i];
        i++;
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"\nenter the size of the sentence: ";
    cin>>n;
    char str[n+1];

    cout<<"enter the sentence: ";
    cin.getline(str,n+1);
    cin.ignore();

    cout<<endl;

    int max_length = INT_MIN,curr_legth = 0;
    for(int i=0;i<n;i++){
        if(str[i]==' ' || str[i]=='\0'){
            max_length = max(max_length,curr_legth);
            curr_legth = 0;
        }
        else{
            curr_legth ++;
        }
    }

    cout<<"Length of the largest word is "<<max_length<<" ."<<endl;

    cout<<endl;
    return 0;
}