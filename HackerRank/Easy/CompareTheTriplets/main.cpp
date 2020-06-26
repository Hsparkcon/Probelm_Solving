#include <iostream>
#include <vector>

using namespace std;

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    vector<int> result {0, 0};
    int lenRates = a.size();

    for(int iterRate = 0; iterRate < lenRates; iterRate++){
        if(a[iterRate] > b[iterRate]){
            result[0]++;
        }else if (a[iterRate] < b[iterRate]){
            result[1]++;
        }else{
            // do nothing
        }

    }

    return result;
}



int main()
{

    tuple<vector<int>, vector<int>, vector<int>> testCase(vector<int>{17, 28, 30}, vector<int>{99, 16, 8}, vector<int>{2, 1});

    cout << "Expected: ";
    for(auto expected : get<2>(testCase)){
        cout << expected << ' ';
    }
    cout << endl;

     vector<int> result = compareTriplets(get<0>(testCase), get<1>(testCase));
    cout << "Output: ";
    for(auto checkResult : result){
        cout << checkResult << ' ';
    }
    cout << endl;

    return 0;
}