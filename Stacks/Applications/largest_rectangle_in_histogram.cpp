#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int LRIH(vector <int> heights){
    int n = heights.size();
    vector <int> right_i(n,0);
    vector <int> left_i(n,0);
    stack <int> s;

    for(int i=n-1;i>=0;i--){ // Right Smallest Index
        while (s.size()>0 && heights[s.top()]>=heights[i])
        {
            s.pop();
        }
        if(s.empty()){
            right_i[i] = n;
        }
        else{
            right_i[i] = s.top();
        }
        s.push(i);
    }

    while(!s.empty()){ // Emtpy the stack
        s.pop();
    }

    for(int i=0;i<n;i++){ // Left Smallest Index
        while (s.size()>0 && heights[s.top()]>=heights[i])
        {
            s.pop();
        }
        if(s.empty()){
            left_i[i] = -1;
        }
        else{
            left_i[i] = s.top();
        }
        s.push(i);
    }
    int max_area = 0;
    for(int i=0;i<n;i++){
        int width = (right_i[i]-left_i[i]-1);
        int curr_area = heights[i]*width;
        max_area = max(max_area,curr_area);
    }

    return max_area;
}

int main(){
    vector <int> heights = {2,1,5,6,2,3};
    int ans = LRIH(heights);
    cout<<"\n The Largest Rectangle in the histogram is of "<<ans<<" area meter square."<<endl;
    return 0;
}