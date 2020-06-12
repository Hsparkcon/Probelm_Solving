#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int maxProduct(vector<int>& nums);

int main(){
    vector<pair<vector<int>, int>> testCase;

    testCase.push_back(make_pair(vector<int>{3,4,5,2}, 12));
    testCase.push_back(make_pair(vector<int>{1,5,4,5}, 16));
    testCase.push_back(make_pair(vector<int>{3,7}, 12));

    for(auto iterTestCase: testCase){
        assert(maxProduct(get<0>(iterTestCase)) == get<1>(iterTestCase));
        cout << "HELLO" << endl;
    }

    system("PAUSE");

    return 0;
}



int maxProduct(vector<int>& nums){

    sort(nums.begin(), nums.end());
    
    return (nums[nums.size()-1]-1) * (nums[nums.size()-2]-1);        
}