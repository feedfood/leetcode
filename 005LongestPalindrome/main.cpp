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

        if( s.size() < 2 ) {
            return s;
        }

        string temp;
        for(int i=0;i<s.size() ;i++) {
            for(int odd=0; odd<=1; odd++) {
                for(int n=1;;n++) {
                    int rightPos = i + n;
                    int leftPos = i - (n - odd);
                    if(rightPos>=s.size()) {
                        break;
                    }
                    if(leftPos<0) {
                        break;
                    }
                    if(s[leftPos] == s[rightPos]) {
                        if( temp.size() < rightPos - leftPos + 1 ) {
                            temp = s.substr(leftPos, rightPos - leftPos + 1);
                        }
                    } else {
                        break;
                    }
                }
            }
        }

        if( temp.size() == 0 ) {
            temp = s[0];
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
    if( answer == "a" ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR ";
    }
    std::cout << endl;

    //case 5
    std::cout << "case 5: abc, return empty ";
    input = "abc";
    answer = s.longestPalindrome(input);
    if( answer == "a" ) {
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

        //case 8
    std::cout << "case 8: abcda, return a ";
    input = "abcd";
    answer = s.longestPalindrome(input);
    if( answer == "a" ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR \"" << answer.c_str() << "\"";
    }
    std::cout << endl;
}
