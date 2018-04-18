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
    int myAtoi(string str) {
        long long ret = 0;
        bool start_convert = false;
        int negitive = 1;
        for( char c : str ) {
            if( (c == ' '|| c == '\t') && start_convert == false) {
                continue;
            }
            if( c == '-' && start_convert == false) {
                start_convert = true;
                negitive = -1;
                continue;
            }
            if( c == '+' && start_convert == false) {
                start_convert = true;
                negitive = 1;
                continue;
            }
            if( c >= '0' && c <= '9' ) {
                start_convert = true;
                ret = ret * 10 + (c - '0');

                if( negitive == 1 && ret > INT_MAX ) return INT_MAX;
                if( negitive == -1 && ret*-1 < INT_MIN) return INT_MIN; 
            } else {
                break;
            }
        }

        return ret * negitive;
    }
};

int main(){
    Solution s;
    
    //case 1: ""->0
    std::cout << "case 1: 1->1 ";
    int answer;
    string input = "";
    answer = s.myAtoi(input);
    if( answer==  0 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer;
    }
    std::cout << endl;

    //case 2: "1"->1
    std::cout << "case 2: '1'->1 ";
    input = "1";
    answer = s.myAtoi(input);
    if( answer ==  1 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer;
    }
    std::cout << endl;

    //case 3: "12"->12
    std::cout << "case 3: '10'->10 ";
    input = "10";
    answer = s.myAtoi(input);
    if( answer ==  10 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer;
    }
    std::cout << endl;

    //case 4: "-10"->-10
    std::cout << "case 4: '-10'->-10 ";
    input = "-10";
    answer = s.myAtoi(input);
    if( answer ==  -10 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer;
    }
    std::cout << endl;

    //case 5: "  -10"->-10
    std::cout << "case 5: '  \\t-10'->-10 ";
    input = "  \t-10";
    answer = s.myAtoi(input);
    if( answer ==  -10 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer;
    }
    std::cout << endl;

    //case 5: "  -10"->-10
    std::cout << "case 6: '23abc'->23 ";
    input = "23abc";
    answer = s.myAtoi(input);
    if( answer ==  23 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer;
    }
    std::cout << endl;

    //case 5: "  -10"->-10
    std::cout << "case 7: '-91283472332'->-2147483648 ";
    input = "-91283472332";
    answer = s.myAtoi(input);
    if( answer ==  -2147483648 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer;
    }
    std::cout << endl;

    //case 5: "  -10"->-10
    std::cout << "case 8: '91283472332'->2147483647 ";
    input = "91283472332";
    answer = s.myAtoi(input);
    if( answer ==  2147483647 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer;
    }
    std::cout << endl;

    //case 5: "  -10"->-10
    std::cout << "case 9: 'ab23'->0 ";
    input = "ab23";
    answer = s.myAtoi(input);
    if( answer ==  0 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer;
    }
    std::cout << endl;

    //case 10: "+10"->10
    std::cout << "case 10: '+10'->10 ";
    input = "+10";
    answer = s.myAtoi(input);
    if( answer ==  10 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer;
    }
    std::cout << endl;
}
