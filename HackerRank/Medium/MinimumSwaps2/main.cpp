#include <iostream>
#include <vector>

using namespace std;

int minimumSwaps(vector<int> & arr) {
    int countNumSwap = 0;
    for(int picker1 = 0; picker1 < arr.size(); picker1++){
        int targetVal = picker1 + 1;
        if(arr[picker1] != targetVal){
            for(int picker2 = picker1 + 1; picker2 < arr.size(); picker2++){
                if(arr[picker2] == targetVal){
                    swap(arr[picker1], arr[picker2]);
                    countNumSwap++;
                    break;
                }
            }
        }
    }
    return countNumSwap;
}

int main()
{
    vector<pair<vector<int>, int>> testCase;
    testCase.push_back(make_pair(vector<int>{4, 3, 2, 1}, 3));
    testCase.push_back(make_pair(vector<int>{2, 3, 4, 1, 5}, 3));
    testCase.push_back(make_pair(vector<int>{1, 3, 5, 2, 4, 6, 7}, 3));
    testCase.push_back(make_pair(vector<int>{1, 2, 3, 4, 4, 6, 7}, 0));

    for(auto checkResult: testCase){
        cout << "Expected: " << checkResult.second << " Output: " << minimumSwaps(checkResult.first) << endl;
    }
    return 0;
}