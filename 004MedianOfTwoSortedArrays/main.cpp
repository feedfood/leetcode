#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <exception>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if( nums1.size() == 0 && nums2.size() == 0) {
            throw invalid_argument("all arrays are empty");
        }
    }
};



int main(){
    Solution s;
    
    //case 1: empty string
    std::cout << "case 1: empty string. throw exception ";
    vector<int> nums1,nums2;
    try{
    double answer = s.findMedianSortedArrays(nums1,nums2);
    } catch ( std::invalid_argument& e ) {
        std::cout << " ok ";
    } catch (...) {
        std::cout << " error ";
    }
    std::cout << endl;

}
