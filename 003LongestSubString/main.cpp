#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return 0;
    }
};



int main(){
    Solution s;
    
    //case 1: both are empty
    std::cout << "case 1: s is empty. answer = 0 ";
    string input;
    int answer = s.lengthOfLongestSubstring(input);
    if(answer == 0) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;
}
