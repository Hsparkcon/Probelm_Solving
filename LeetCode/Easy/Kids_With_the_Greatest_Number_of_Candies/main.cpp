#include <iostream>
#include <vector>
#include <tuple>
#include <cassert>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies);

int main(){
    vector<tuple<vector<int>, int , vector<bool>>> testCase;

    testCase.push_back(make_tuple(vector<int>{2,3,5,1,3}, 3, vector<bool>{true,true,true,false,true}));
    testCase.push_back(make_tuple(vector<int>{4,2,1,1,2}, 1, vector<bool>{true,false,false,false,false}));
    testCase.push_back(make_tuple(vector<int>{12,1,12}, 10, vector<bool>{true,false,true}));

    for(auto iterTestCase: testCase){
        assert(kidsWithCandies(get<0>(iterTestCase), get<1>(iterTestCase)) == get<2>(iterTestCase));
        cout << "HELLO" << endl;
    }

    system("PAUSE");

    return 0;
}


/**
 * @brief 
 * 
 * @param candies 
 * @param extraCandies 
 * @return vector<bool> 
 */
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxBeforeExtra = 0;
        for(auto checkCandies: candies){
            maxBeforeExtra = checkCandies > maxBeforeExtra ? checkCandies : maxBeforeExtra;
        }
        int minNumToMax = maxBeforeExtra - extraCandies;
        
        vector<bool> returnResult(candies.size());
        for(int iterCandies = 0; iterCandies < candies.size(); iterCandies++ ){
            returnResult[iterCandies] = candies[iterCandies] >= minNumToMax ? true : false;
        }
        
        return returnResult;
    }