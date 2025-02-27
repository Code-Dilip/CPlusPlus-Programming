#include<iostream>
#include<vector>
using namespace std;


int trap_rainwate(vector<int> heights){
    int n = heights.size();
    vector<int> left_max(n,0);
    vector<int> right_max(n,0);

    left_max[0] = heights[0];
    right_max[n-1] = heights[n-1];

    for(int i=1;i<n;i++){
        left_max[i] = max(left_max[i-1],heights[i]);
    }

    for(int i=n-2;i>=0;i--){
        right_max[i] = max(right_max[i+1],heights[i]);
    }

    int rain_trapped = 0;
    for(int i=0;i<n;i++){
        rain_trapped += min(left_max[i],right_max[i])-heights[i];
    }
    return rain_trapped;
}

int main(){
    vector<int> heights = {4,2,0,3,2,5};
    cout<<trap_rainwate(heights)<<endl;
    return 0;
}