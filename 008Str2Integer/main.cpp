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
        return 0;
    }
};

int main(){
    Solution s;
    
    //case 1: 1->1
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
}
