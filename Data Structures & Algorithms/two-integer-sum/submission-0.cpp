class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 1. [4,6,5,1]
        //int hold = 0;
        for(int i=0; i<nums.size() ; i++){
            for(int j = 0;j<nums.size() ; j++){
                
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
    }
};
