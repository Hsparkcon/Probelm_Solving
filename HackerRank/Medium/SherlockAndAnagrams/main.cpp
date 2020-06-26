#include <iostream>
#include <string>
#include <map>
#include <array>
#include <vector>

using namespace std;


int sherlockAndAnagrams(string s);


int main()
{
    vector<pair<string, int>> testCase;
    testCase.push_back(make_pair("abba", 4));
    testCase.push_back(make_pair("abcd", 0));
    testCase.push_back(make_pair("ifailuhkqq", 3));
    testCase.push_back(make_pair("kkkk", 10));
    testCase.push_back(make_pair("cdcd", 5));


    for(auto iterTestCase: testCase){
        cout << "Output: " << sherlockAndAnagrams(iterTestCase.first) << " Expected: " << iterTestCase.second << endl;
    }

    return 0;
}



int sherlockAndAnagrams(string s) {
    // stage 1
    int lenStr = s.size(); 
    map<array<int, 26>, int> subStrTable; 
    array<int, 26> subStrCharTable;
    for (int i=0; i<lenStr; i++){ 
        subStrCharTable.fill(0); 
        for (int j=i; j<lenStr; j++){ 
            subStrCharTable[s[j] - 'a']++;
            subStrTable[subStrCharTable]++; 
        }
    }

    // stage 2
    int numAnagrams = 0; 
    for (auto checkStuStr: subStrTable){
        if(checkStuStr.second > 1){ 
            numAnagrams += ((checkStuStr.second) * (checkStuStr.second-1)) / 2; 
        }
    } 
    
    return numAnagrams; 
}