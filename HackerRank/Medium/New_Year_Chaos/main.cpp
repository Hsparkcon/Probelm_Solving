#include <iostream>
#include <vector>
#include <string>

using namespace std;


void minimumBribes(vector<int> q);

int main(){
    vector<pair<vector<int>, string>> testCase;
    testCase.push_back(make_pair({2, 1, 5, 3, 4}, "3"));
    testCase.push_back(make_pair({2, 5, 1, 3, 4}, "Too chaotic"));
    testCase.push_back(make_pair({5, 1, 2, 3, 7, 8, 6, 4}, "Too chaotic"));
    testCase.push_back(make_pair({1, 2, 5, 3, 7, 8, 6, 4}, "7"));

    for(auto iterTestCase: testCase){
        cout << "Output: " << minimumBribes(iterTestCase.first) << " Expected: " << iterTestCase.second << endl;
    }

    return 0;
}



void minimumBribes(vector<int> q) {
    int countBribing = 0;
    bool isChaotic = false; 
    for(int upperBound = q.size() - 1; upperBound >= 0 ; upperBound--){
        int diffCurrPInitP = q[upperBound] - (upperBound + 1);
        if(diffCurrPInitP <= 0){
            for(int lowerBound = max(0, q[upperBound] - 2);  lowerBound < upperBound; lowerBound++){
                int diffCurrPInitP2 = q[lowerBound] - (upperBound + 1);
                if(diffCurrPInitP2 > 2){
                    break;
                }
                if(q[upperBound] < q[lowerBound]){
                    countBribing++;
                }
            }
        }else if(diffCurrPInitP > 2){
            isChaotic = true;
        }
    }

    if(isChaotic == false){
        cout << countBribing << endl;
    }else{
        cout << "Too chaotic" << endl;
    }
}