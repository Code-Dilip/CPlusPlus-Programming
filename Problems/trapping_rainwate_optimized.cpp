#include<iostream>
#include<vector>
using namespace std;

int trapped_water(vector<int> heights){
    int n = heights.size();

    int water_trapped = 0;
    int l=0,r=n-1;
    int l_max = 0,r_max = 0;
    
    while(l<r){
        l_max = max(l_max,heights[l]);
        r_max = max(r_max,heights[r]);

        if(l_max<r_max){
            water_trapped += (l_max-heights[l]);
            l++;
        }
        else{
            water_trapped += (r_max-heights[r]);
            r--;
        }
    }
    return water_trapped;
}

int main(){
    vector<int> heights = {4,2,0,3,2,5};
    cout<<trapped_water(heights)<<endl;
    return 0;
}