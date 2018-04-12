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
        return x;
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

    
}
