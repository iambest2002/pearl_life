

#include <string>
#include <vector>

using namespace std;
namespace pearl {
namespace algorithm {
namespace array_and_string {

class MoveChangeSimulate {
// move
public:
  // special move 
  //leetcode 189 : using a vector to save value, calc size to carry.
    void rotate(vector<int>& nums, int k) {
      vector<int> res = nums;

      k = (k + nums.size()) % nums.size();

      for (int i = 0; i < nums.size(); ++i) {
        if (i + k < nums.size()) {
          nums[i + k] = res[i];  
        } else {
          nums[i + k - nums.size()] = res[i];
        }
      }
    } 

    // left right two pointer move: 

    //
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left  = 0, right = nums.size() - 1;
        while (left < right) {
          while(nums[left] % 2 == 0 && left < right) {
            left++;
          }
          while (nums[right] % 2 != 0 && left < right) {
            right--;
          }
          if (left < right) {
            swap(nums[left], nums[right]);
          }
        }
        return nums;
    }

    // 
 
//change
public:
    int titleToNumber(string columnTitle);

//silmut
public:
    int a = 0;
};

}  // namespace array_and_string

}  // namespace algorithm

}  // namespace pearl
