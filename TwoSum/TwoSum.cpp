#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> ret;

    //     if( nums.size() >= 2 ) {
    //         for( int i=0; i<=nums.size()-2; i++) {
    //             for( int j=i+1; j<=nums.size()-1; j++ ) {
    //                 if( nums[i] + nums[j] == target ) {
    //                     ret.resize(2);
    //                     ret[0] = i;
    //                     ret[1] = j;
    //                 }
    //             }
    //         }
    //     }

    //     return ret;
    // }

    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> checkMap;

        if( nums.size() >= 2 ) {
            checkMap[nums[0]] = 0;
            for(int i=1; i<= nums.size()-1; i++ ) {
                auto it = checkMap.find(target-nums[i]);
                if( it != checkMap.end()) {
                    return vector<int> {it->second,i};
                } else {
                    checkMap.emplace(nums[i], i );
                }
            }
        }

        return vector<int>();
    }

};

int main(){
    Solution s;

    
    //case 1: empty nums
    std::vector<int> nums = {};
    int target = 10;
    vector<int> answer = s.twoSum(nums,target);
    if( answer.size() == 0 ) {
        std::cout << "case 1 ok" << std::endl;
    } else {
        std::cout << "case 1 error" << std::endl;
    }

    //case 2: 1 nums
    nums = {1};
    target = 10;
    answer = s.twoSum(nums,target);
    if( answer.size() == 0 ) {
        std::cout << "case 2 ok" << std::endl;
    } else {
        std::cout << "case 2 error" << std::endl;
    }

    std::cout << "case 3: find sum(3) in {1,2}";
    bool error = true;
    nums = {1,2};
    target = 3;
    answer = s.twoSum(nums,target);
    if( answer.size() == 2 ) {
        if( answer[0] == 0 && answer[1] == 1 ) {
            std::cout << "ok" << std::endl;
            error = false;
        } 
    }

    if( error ) {
        std::cout << "error" << std::endl;
    }

    std::cout << "case 4: find sum(0) in {1,2}";
    error = true;
    nums = {1,2};
    target = 0;
    answer = s.twoSum(nums,target);
    if( answer.size() == 0 ) {
        std::cout << "ok" << std::endl;
        error = false;
    }

    if( error ) {
        std::cout << "error" << std::endl;
    }

    std::cout << "case 5: find sum(5) in {1,2,3}";
    error = true;
    nums = {1,2,3};
    target = 5;
    answer = s.twoSum(nums,target);
    if( answer.size() == 2 ) {
        if( answer[0] == 1 && answer[1] == 2 ) {
            std::cout << "ok" << std::endl;
            error = false;
        } 
    }

    if( error ) {
        std::cout << "error" << std::endl;
    }

    std::cout << "case 6: find sum(3) in {6,4,5}";
    error = true;
    nums = {4,5,6};
    target = 3;
    answer = s.twoSum(nums,target);
    if( answer.size() == 0 ) {
        std::cout << "ok" << std::endl;
        error = false;
    }

    if( error ) {
        std::cout << "error" << std::endl;
    }

    std::cout << "case 7: find sum(6) in {6,5,4,3,2,1}";
    error = true;
    nums = {6,5,4,3,2,1};
    target = 6;
    answer = s.twoSum(nums,target);

    if( answer.size() == 2 ) {
        if( answer[0] == 2 && answer[1] == 4 ) {
            std::cout << "ok" << std::endl;
            error = false;
        } 
    }

    if( error ) {
        std::cout << "error" << std::endl;
    }
    
}
