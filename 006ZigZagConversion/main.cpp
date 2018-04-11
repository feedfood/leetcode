#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <exception>
#include <sstream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if( s.size() <= numRows || numRows <= 1) {
            return s;
        }
        
        stringstream ret;
        int x_step = 2*numRows-2;
        for(int i=0;i<numRows; i++) {
            for(int n=0; i+n<s.size(); n+=x_step) {
                ret << s[i+n];

                if( i>0 && i<numRows-1 && i+n+x_step-2*i <s.size()) {
                    ret << s[i+n+x_step-2*i];
                }
            }
        }

        return ret.str();
    }
};

int main(){
    Solution s;
    
    //case 1: empty string
    std::cout << "case 1: empty string. return empty ";
    string answer;
    string input;
    answer = s.convert(input,0);
    if( answer.size() ==  0 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR ";
    }
    std::cout << endl;

    //case 2: abc -> abc
    std::cout << "case 2: abc -> abc ";
    input = "abc";
    answer = s.convert(input,3);
    if( answer == "abc" ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer.c_str();
    }
    std::cout << endl;

    //case 3: abcd -> adbc
    std::cout << "case 3: abcd -> abdc ";
    input = "abcd";
    answer = s.convert(input,3);
    if( answer == "abdc" ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer.c_str();
    }
    std::cout << endl;

    //case 4: abcde -> aebdc
    std::cout << "case 4: abcde -> aebdc ";
    input = "abcde";
    answer = s.convert(input,3);
    if( answer == "aebdc" ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer.c_str();
    }
    std::cout << endl;

    //case 5: abcde -> aebdc
    std::cout << "case 5: abcde -> abced ";
    input = "abcde";
    answer = s.convert(input,4);
    if( answer == "abced" ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer.c_str();
    }
    std::cout << endl;

    //case 5: ab -> ab
    std::cout << "case 5: ab -> ab ";
    input = "ab";
    answer = s.convert(input,1);
    if( answer == "ab" ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer.c_str();
    }
    std::cout << endl;
}
