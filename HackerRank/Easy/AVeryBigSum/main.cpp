#include <iostream>
#include <vector>

using namespace std;

long aVeryBigSum(vector<long> & ar) {
    long tempResult = 0;

    for(auto getSum : ar){
        tempResult += getSum;
    }
    
    return tempResult;
}

int main()
{
    pair<vector<long>, long> testcase (vector<long>{1000000001, 1000000002, 1000000003, 1000000004, 1000000005}, 5000000015);

    cout << "Expected: " << aVeryBigSum(testcase.first) << " Output: " << testcase.second << endl;

    return 0;
}