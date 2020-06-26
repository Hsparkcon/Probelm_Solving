#include <iostream>
#include <vector>

using namespace std;

int simpleArraySum(const vector<int> & ar) {

     int tempSum = 0;
    for(auto iterAr: ar){
        tempSum += iterAr;
    }

    return tempSum;

}

int main()
{
    pair<vector<int>, int> testcase (vector<int>{1,2,4,10,11}, 31);

    cout << "Expected: " << simpleArraySum(testcase.first) << " Output: " << testcase.second << endl;

    return 0;
}