#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <exception>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        return "";
    }
};

int main(){
    Solution s;
    
    //case 1: empty string
    std::cout << "case 1: empty string. return empty ";
    string answer;
    string input;
    answer = s.longestPalindrome(input);
    if( answer.size() ==  0 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR ";
    }
    std::cout << endl;
}
