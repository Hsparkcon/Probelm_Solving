#include <iostream>
#include <vector>
#include <tuple>
#include <cassert>

using namespace std;

vector<int> shuffle(vector<int>& nums, int n);

int main(){
    vector<tuple<vector<int>, int , vector<int>>> testCase;

    testCase.push_back(make_tuple(vector<int>{2,5,1,3,4,7}, 3, vector<int>{2,3,5,4,1,7}));
    testCase.push_back(make_tuple(vector<int>{1,2,3,4,4,3,2,1}, 4, vector<int>{1,4,2,3,3,2,4,1}));
    testCase.push_back(make_tuple(vector<int>{1,1,2,2}, 2, vector<int>{1,2,1,2}));

    for(auto iterTestCase: testCase){
        assert(shuffle(get<0>(iterTestCase), get<1>(iterTestCase)) == get<2>(iterTestCase));
        cout << "HELLO" << endl;
    }

    system("PAUSE");

    return 0;
}

/**
 * @brief 
 * 
 * @param nums 
 * @param n 
 * @return vector<int> 
 */
vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> returnResult;
        for(int iterNums_X = 0, iterNums_Y = n; iterNums_X < n; iterNums_X++, iterNums_Y++){
            returnResult.push_back(nums[iterNums_X]);
            returnResult.push_back(nums[iterNums_Y]);
        }
        
        return returnResult;   
}