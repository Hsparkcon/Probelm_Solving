#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int requiredJumpNum(vector<int>& nums);

int main(){
    vector<pair<vector<int>, int>> testCase;

    testCase.push_back(make_pair(vector<int>{2,3,1,1,4}, 2));
    testCase.push_back(make_pair(vector<int>{1,1,1,1,1}, 4));
    testCase.push_back(make_pair(vector<int>{3,2,1}, 1));
    testCase.push_back(make_pair(vector<int>{10,9,8,7,6,5,4,3,2,1,1,0}, 2));

    int trackTestCase = 1;
    for(auto iterTestCase: testCase){
        cout << "Test Case - " << trackTestCase << endl;
        assert(requiredJumpNum(get<0>(iterTestCase)) == get<1>(iterTestCase));
        trackTestCase++;
    }

    system("PAUSE");

    return 0;
}



/**
 * @brief 
 * 
 * @param nums 
 * @return int 
 */
int requiredJumpNum(vector<int>& nums) {
    int requiredDis = nums.size();
    if(requiredDis <= 1){
        return 0;
    }
    if(requiredDis == 2 || nums[0] >= requiredDis - 1){
        return 1;
    }
        
    int requiredJump = 1; int jumpedDis = 0;
    int currPos = 0;
    int nextJump_MAX = nums[0];
    while(jumpedDis < requiredDis){
        int jumpMax = INT_MIN;
        for(int searchNextP = jumpedDis+1; searchNextP <= nextJump_MAX; searchNextP++){
            if(jumpMax < nums[searchNextP] + searchNextP){
                jumpMax = nums[searchNextP] + searchNextP;
                currPos = searchNextP;
            }
        }
            
        nextJump_MAX = jumpMax;
            
        if(nextJump_MAX >= requiredDis - 1){
            requiredJump++;
            break;
        }

        requiredJump++;
        jumpedDis = currPos - 1;
    }
    return requiredJump;
}
