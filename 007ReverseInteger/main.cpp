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
    int reverse(int y) {
        int x = y;

        int r = 0;
        int ret = 0;

        // int max = (int32_t)0x7fffffff / 10;
        // int min = (int32_t)0x80000000 / 10;

        while( x != 0 ) {
            r = x % 10;
            x = x / 10;
            // if( ret > max || ret < min) {
            //     return 0;
            // } 
            int p = ret * 10 + r;
            if( p / 10 != ret ) {
                return 0;
            } else {
                ret = p;
            }
        }

        return ret;
    }
};

int main(){
    Solution s;
    
    //case 1: 1->1
    std::cout << "case 1: 1->1 ";
    int answer;
    int input = 1;
    answer = s.reverse(input);
    if( answer==  1 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer;
    }
    std::cout << endl;

    //case 2: 12->21
    std::cout << "case 2: 12->21 ";
    input = 12;
    answer = s.reverse(input);
    if( answer==  21 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer;
    }
    std::cout << endl;
    
    //case 3: 123->321
    std::cout << "case 3: 123->321 ";
    input = 123;
    answer = s.reverse(input);
    if( answer==  321 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer;
    }
    std::cout << endl;

    //case 4: -123->-321
    std::cout << "case 4: -123->-321 ";
    input = -123;
    answer = s.reverse(input);
    if( answer==  -321 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer;
    }
    std::cout << endl;

    //case 5: 
    std::cout << "case 5: 1534236469->0 ";
    input = 1534236469;
    answer = s.reverse(input);
    if( answer == 0 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer;
    }
    std::cout << endl;

    //case 6: 
    std::cout << "case 6: -1534236469->0 ";
    input = -1534236469;
    answer = s.reverse(input);
    if( answer == 0 ) {
        std::cout << " OK ";
    } else {
        std::cout << " ERROR, actual is " << answer;
    }
    std::cout << endl;
}
