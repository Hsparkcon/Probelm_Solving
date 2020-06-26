#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

long countTriplets(vector<long> arr, long r) {
    map<long,long> secondReqEleTable;
    map<long,long> thridReqEleTable;

    /*
        Big-O
            O(n*log(n)) for Time Complexity
            O(n) for Space Complexity
        Idea behind the method
            Use two map to track required elements for triplets.
            For example, arr = {1 3 3 1 3 9 27} and r = 3
            1st element is 1 and raito is 3,
                thus the second element of Triplemt needs to be 3.
                2nd Required Element Table
                    3 - 1
            2nd element is 3,
                2nd required element for triplet starts with 1 is fufilled,
                3rd required element for triplet starts with 1 is 9.
                Also, update for triple starts with 3 is 9, thus...
                2nd Required Element Table
                    3 - 1
                    9 - 1
                3rd Required Element Table
                    9 - 1
            3rd elemet is 3
                2nd required element for triplet starts with 1 is fufilled again,
                and 2 triplet can be made if there is 9, 
                so updates 3rd required Element Talbe,
                Also, it means there are two possible triplet that can start with 3
                so updates 2nd required Element Talbe, also.
                2nd Required Element Table
                    3 - 1
                    9 - 2
                3rd Required Element Table
                    9 - 2
            4th element is 1 => this is important part.
    */

    long numTriplets = 0;
    for(auto element: arr){
        if (thridReqEleTable.find(element) != thridReqEleTable.end()){        
            numTriplets += thridReqEleTable[element];
        }
        if (secondReqEleTable.find(element) != secondReqEleTable.end()){     
            thridReqEleTable[element*r] += secondReqEleTable[element];
        }
        secondReqEleTable[element*r]++;   

        /*
        cout << "ele: " << element << endl;
        cout << "Required Second Element" << endl;
        for(auto secondRequired: secondReqEleTable){
            cout << secondRequired.first << ": " << secondRequired.second << endl;
        }
        cout << "Required Third Element" << endl;
        for(auto thiredRequired: thridReqEleTable){
            cout << thiredRequired.first << ": " << thiredRequired.second << endl;
        }
        cout << "current possible triplets: " << numTriplets << '\n' << endl;
        */
    }
    return numTriplets;
}

int main()
{
    vector<tuple<vector<long>, long, long>> testCase;
    testCase.push_back(make_tuple(vector<long>{1, 2, 2, 4}, 2, 2));
    testCase.push_back(make_tuple(vector<long>{1, 3, 9, 9, 27, 81}, 3, 6));
    testCase.push_back(make_tuple(vector<long>{1, 5, 5, 25, 125}, 5, 4));


    for(auto checkResult: testCase){
        cout << "Expected: " << get<2>(checkResult) << " Output: " << countTriplets(get<0>(checkResult), get<1>(checkResult)) << endl;
    }
    return 0;
}