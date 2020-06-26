#include <iostream>
#include <vector>

using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries) {
    /*
        Optimized Algorithm
            O(n) for time complexity
            O(1) for space complexity

        Idea behind the algorithm
            It simply denotes where 'k' filling starts - 'a' and ends - 'b',
                instead of filling entire range with 'k'.
            By denoting arr[a-1] = k and arr[b] = -k, 
                the array will be filled with values 
                that denote where each 'k' value starts and end.
            During the summation,
                'k' val with overlapped range will be added whereas 
                'k' val with non-overalpped will be substracted.
            Therefore, MAX val during summaiton will be the answer.

        Example
            5 3
            1 2 100
            2 5 100
            3 4 100
        0th operation - init array
            0 0 0 0 0
        1st operation - 1 ~ 2 with 100
            100 0 -100 0 0
        2nd operation - 2 ~ 5 with 100
            100 100 -100 0 0
        3rd operation - 3 ~ 4 with 100
            100 100 0 0 -100
        Find Max Sum 
            1st -> 100, MAX = 100
            2nd -> 100, Max = 200
            3rd -> 0,   Max = 200
            4th -> 0,   Max = 200
            5th -> -100,Max = 200
    */
    vector<long> addArray(n, 0);
    for(auto valABK: queries){
        addArray[valABK[0]-1] += valABK[2];
        if(valABK[1] < n ){
            addArray[valABK[1]] -= valABK[2];
        }
    }
    long maxInArray = LONG_MIN;
    long tempMax = 0;
    for(auto valArray: addArray){
        tempMax += valArray;
        maxInArray = max(maxInArray, tempMax);
    }



    /*
    Big-O
        O(n*m) for time complexity
        O(1) for space complexity
    Idea Behind the alogrithm
        It follows the description.
        It starts with initailizing array.
        It iters the list of queries to add 'k' to array within 'a' to 'b'.
        After entire filling and addtion operation is done,
            it iters the array to find Max-Value in the array.

    vector<long> addArray(n, 0);    
    for(auto valABK: queries){
        for(int startP = valABK[0]-1; startP < valABK[1]; startP++){
            addArray[startP] += valABK[2];
            

        }
    }
    long maxInArray = LONG_MIN;
    for(auto iterArray: addArray){
        maxInArray = max(maxInArray,  iterArray);
    }
    */
    return maxInArray;
}


int main()
{
    vector<vector<int>> testCase;
    testCase.push_back(vector<int>(1, 2, 100));
    testCase.push_back(vector<int>(2, 5, 100));
    testCase.push_back(vector<int>(3, 4, 100));

    long result = arrayManipulation(n, queries);

    cout << "Expected: " << 200 << " Output: " << arrayManipulation(5, testCase) << endl;

    return 0;
}