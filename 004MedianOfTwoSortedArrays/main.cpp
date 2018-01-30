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

        vector<int>& longArray = nums1.size() > nums2.size() ? nums1 : nums2;
        vector<int>& shortArray = nums1.size() > nums2.size() ? nums2 : nums1;
        int totalLen = shortArray.size() + longArray.size();
        int shortArrayLen = shortArray.size(); 
        for( ;shortArrayLen > 0 && shortArray[shortArrayLen-1] > longArray[0] ; ) {
            swap(shortArray[shortArrayLen-1], longArray[0]);
            for(int i=shortArray.size() - 1 ; i>0 ; i--) {
                if( shortArray[i] < shortArray[i-1] ) {
                    swap(shortArray[i-1],shortArray[i] );
                } else {
                    break;
                }
            }

            for(int i=0; i<longArray.size()-1; i++) {
                if( longArray[i] > longArray[i+1] ) {
                    swap(longArray[i+1],longArray[i] );
                } else {
                    break;
                }
            }
        }

        if( totalLen % 2 == 0 ) {
             if( longArray.size() > (totalLen/2) ) {
                int a = longArray[longArray.size()-(totalLen/2) - 1];
                int b = longArray[longArray.size()-(totalLen/2)];

                return double(a+b)/2;
            } 

            if( longArray.size() == (totalLen/2) ) {
                int a = longArray[0];
                int b = shortArray[totalLen/2-1];

                return double(a+b)/2;
            } 
        } else {
            return longArray[longArray.size() - (totalLen+1)/2];
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

    //case 2: nums1 : empty; nums2: 1
    std::cout << "case 2: nums1 : empty; nums2: 1 ";
    nums2 = {1};
    double answer = s.findMedianSortedArrays(nums1,nums2);
    if( answer == 1 ) {
        std::cout << " ok ";
    } else {
        std::cout << " error ";
    }
    std::cout << endl;

    //case 3: 
    std::cout << "case 3: nums1 : empty; nums2: 1,2 ";
    nums2 = {1,2};
    answer = s.findMedianSortedArrays(nums1,nums2);
    if( answer == 1.5 ) {
        std::cout << " ok ";
    } else {
        std::cout << " error, actual is " << answer ;
    }
    std::cout << endl;

    //case 4: 
    std::cout << "case 4: nums1 1: empty; nums2: 2,3 ";
    nums1 = {1};
    nums2 = {2,3};
    answer = s.findMedianSortedArrays(nums1,nums2);
    if( answer == 2 ) {
        std::cout << " ok ";
    } else {
        std::cout << " error, actual is " << answer ;
    }
    std::cout << endl;

    //case 5: 
    std::cout << "case 5: nums1 2,3: empty; nums2: 1 ";
    nums1 = {2,3};
    nums2 = {1};
    answer = s.findMedianSortedArrays(nums1,nums2);
    if( answer == 2 ) {
        std::cout << " ok ";
    } else {
        std::cout << " error, actual is " << answer ;
    }
    std::cout << endl;

    //case 6: 
    std::cout << "case 6: nums1 1,3: empty; nums2: 2 ";
    nums1 = {1,3};
    nums2 = {2};
    answer = s.findMedianSortedArrays(nums1,nums2);
    if( answer == 2 ) {
        std::cout << " ok ";
    } else {
        std::cout << " error, actual is " << answer ;
    }
    std::cout << endl;

    //case 7: 
    std::cout << "case 7: nums1 3,4: empty; nums2: 1,2,5 ";
    nums1 = {3,4};
    nums2 = {1,2,5};
    answer = s.findMedianSortedArrays(nums1,nums2);
    if( answer == 3 ) {
        std::cout << " ok ";
    } else {
        std::cout << " error, actual is " << answer ;
    }
    std::cout << endl;
}
