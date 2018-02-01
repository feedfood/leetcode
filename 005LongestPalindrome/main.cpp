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

        string temp;
        if( s.size() < 2 ) {
            temp = s;
        }

        if( s.size() >= 2 && s[0] == s[1]) {
            if( temp.size() < 2 ) {
                temp = s.substr(0,2);
            }
        }

        for(int i=0;i<s.size();i++) {
            for(int n=1;;n++) {
                int rightPos = i + n;
                int leftPos = i - n;
                if(rightPos>=s.size()) {
                    break;
                }
                if(leftPos<0) {
                    break;
                }
                if(s[i] == s[rightPos]) {
                    if( temp.size() < rightPos - i + 1 ) {
                        temp = s.substr(i,rightPos - i + 1);
                    }
                }
                if(s[leftPos] == s[rightPos]) {
                    if( temp.size() < rightPos - leftPos + 1 ) {
                        temp = s.substr(leftPos, rightPos - leftPos + 1);
                    }
                }
            }
        }

        return temp;
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

    //case 2
    std::cout << "case 2: single char. return itself ";
    input = "a";
    answer = s.longestPalindrome(input);
    if( answer ==  "a" ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR ";
    }
    std::cout << endl;

    //case 3
    std::cout << "case 3: aa, return aa ";
    input = "aa";
    answer = s.longestPalindrome(input);
    if( answer ==  "aa" ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR ";
    }
    std::cout << endl;

    //case 4
    std::cout << "case 4: ab, return empty ";
    input = "ab";
    answer = s.longestPalindrome(input);
    if( answer.size() == 0 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR ";
    }
    std::cout << endl;

    //case 5
    std::cout << "case 5: abc, return empty ";
    input = "abc";
    answer = s.longestPalindrome(input);
    if( answer.size() == 0 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR ";
    }
    std::cout << endl;

    //case 6
    std::cout << "case 6: aab, return empty ";
    input = "aab";
    answer = s.longestPalindrome(input);
    if( answer == "aa" ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR \"" << answer.c_str() << "\"";
    }
    std::cout << endl;

    //case 7
    std::cout << "case 7: abb, return empty ";
    input = "abb";
    answer = s.longestPalindrome(input);
    if( answer == "bb" ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR \"" << answer.c_str() << "\"";
    }
    std::cout << endl;
}
