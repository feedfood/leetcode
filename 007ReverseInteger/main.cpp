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
    int reverse(int x) {
        if( x < 10 ) {
            return x;
        }
        int r = x % 10;
        x = x / 10;
        int ret = r;

        r = x % 10;
        x = x / 10;
        ret = ret * 10 + r;

        if( x == 0 ) {
            return ret;
        }
        
        r = x % 10;
        x = x / 10;
        ret = ret * 10 + r;

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
}
