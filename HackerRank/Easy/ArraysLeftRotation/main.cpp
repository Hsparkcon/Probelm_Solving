#include <iostream>
#include <vector>

using namespace std;

vector<int> rotLeft(vector<int> &a, int d) {
    int sizeArr = a.size();

    vector<int> rotatedArr(sizeArr);
    for(int i = 0; i < sizeArr; i++){
        int newIndex = i - d;
        if(newIndex < 0){
            newIndex += sizeArr;
        }
        rotatedArr[newIndex] = a[i];
    }
    return rotatedArr;
}

int main()
{
    pair<vector<int>, vector<int>> testcase (vector<int>{1, 2, 3, 4, 5}, vector<int>{5, 1, 2, 3, 4});

    cout << "Expected: ";
    for(auto expected: testcase.second){
        cout << expected << ' ';
    }
    cout << endl;

    auto result = rotLeft(testcase.first, testcase.first.size());
    cout << "Output: ";
    for(auto checkResult: result){
        cout << checkResult << ' ';
    }
    cout << endl;

    return 0;
}