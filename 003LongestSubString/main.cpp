#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     string ss = s;
    //     int maxLength = 0;
    //     unordered_map<string::value_type, int > checkMap;
    //     for(; ss.size() > 0 && checkMap.size() != ss.size(); ) {
    //         checkMap.clear();

    //         for(int i=0; i<ss.size(); i++) {
    //             string::value_type c = ss[i];
    //             if( checkMap.find(c) != checkMap.end() ) {
    //                 ss = ss.substr(checkMap[c]+1);
    //                 break;
    //             } else {
    //                 checkMap[ss[i]] = i;
    //             }
    //         }
    //         maxLength = maxLength < checkMap.size() ? checkMap.size() : maxLength;
    //     }
    //     return maxLength;
    // }

    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int start = 0;
        unordered_map<string::value_type, int > checkMap;
        for(int i=0; i<s.size(); i++) {
            string::value_type c = s[i];
            if( checkMap.find(c) != checkMap.end() ) {
                if( start < checkMap[c]+1 ) {
                    start = checkMap[c]+1;
                }
            }
            checkMap[c] = i;
            if( maxLength < i - start + 1 ) {
                maxLength = i - start + 1;
            }
        }

        return maxLength;
    }
};



int main(){
    Solution s;
    
    //case 1: empty string
    std::cout << "case 1: empty string. answer = 0 ";
    string input;
    int answer = s.lengthOfLongestSubstring(input);
    if(answer == 0) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;

    //case 2: 1 character
    std::cout << "case 2: 1 character. answer = 1 ";
    input = "a";
    answer = s.lengthOfLongestSubstring(input);
    if(answer == 1) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;

    //case 3: no same character
    std::cout << "case 3: no same character. answer = string size ";
    input = "abc";
    answer = s.lengthOfLongestSubstring(input);
    if(answer == input.size()) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;

    //case 4
    std::cout << "case 4: abca. answer = 3 ";
    input = "abca";
    answer = s.lengthOfLongestSubstring(input);
    if(answer == 3) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;

    //case 5
    std::cout << "case 5: aa. answer = 1 ";
    input = "aa";
    answer = s.lengthOfLongestSubstring(input);
    if(answer == 1) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;

    //case 6
    std::cout << "case 6: abcb. answer = 1 ";
    input = "abcb";
    answer = s.lengthOfLongestSubstring(input);
    if(answer == 3) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;

    //case 7
    std::cout << "case 7: ababcb. answer = 3 ";
    input = "ababcb";
    answer = s.lengthOfLongestSubstring(input);
    if(answer == 3) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;
}
