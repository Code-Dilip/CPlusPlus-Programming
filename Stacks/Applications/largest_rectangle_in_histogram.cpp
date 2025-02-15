#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int LRIH(vector <int> arr){
    int ans = 0;
    vector <int> right_arr(arr.size(),0);
    vector <int> left_arr(arr.size(),0);
    stack <int> s;

    for(int i=arr.size();i>=0;i--){
        while(s.size()>0 && arr[s.top()]>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            right_arr[i] = arr.size();
        }
        else{
            right_arr[i] = s.top();
        }
        s.push(i);
    }

    while (!s.empty())
    {
        s.pop();
    }

    for(int i=0;i<arr.size();i++){
        while (s.size()>0 && arr[s.top()]>=arr[i])
        {
            s.pop();
        }
    if(s.empty()){
        left_arr[i] = -1;
    }
    else{
        left_arr[i] = s.top();
    }
    s.push(i);
    }
    
    for(int i=0;i<arr.size();i++){
        int height = arr[i];
        int width = right_arr[i]-left_arr[i]-1;
        int curr_ans = height * width; 
        ans = max(ans,curr_ans);
    }
    return ans;
}

int main(){
    vector <int> heights = {2,1,5,6,2,3};
    int ans = LRIH(heights);
    cout<<"\n The Largest Rectangle in the histogram is of "<<ans<<" area meter square."<<endl;
    return 0;
}