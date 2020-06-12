#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int firstMissingPositive(vector<int>& nums);

int main(){
    vector<pair<vector<int>, int>> testCase;

    testCase.push_back(make_pair(vector<int>{1,2,0}, 3));
    testCase.push_back(make_pair(vector<int>{3,4,-1,1}, 2));
    testCase.push_back(make_pair(vector<int>{7,8,9,11,12}, 1));

    for(auto iterTestCase: testCase){
        assert(firstMissingPositive(get<0>(iterTestCase)) == get<1>(iterTestCase));
        cout << "HELLO" << endl;
    }

    system("PAUSE");

    return 0;
}


int firstMissingPositive(vector<int>& nums) {
    if(nums.empty()){
        return 1;
    }
        
    int missedPositive = 1;
    while(1){
        int diff = -1;
        for(auto checkNum: nums){
            if(checkNum > 0){
                diff = checkNum - missedPositive;
                    
                if(diff == 0){
                    break;
                }
            }
        }
            
        if(diff != 0){
            break;
        }

        missedPositive++;            

    }
    return missedPositive;
}
