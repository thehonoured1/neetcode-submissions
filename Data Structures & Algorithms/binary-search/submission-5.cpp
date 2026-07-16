class Solution {
public:
    int search(vector<int>& nums, int target) {
        //pick middle value and see if it's more or less than target.
        int left = 0;
        int right = nums.size() -1;
        int mid = (right-left)/2;

        while( left <= right ){
            
            if(nums[mid]==target){
                return mid;
            }
                
            if(nums[mid] < target){
                //disregard the left side, and find the center.
                left = mid +1;
                mid = left + (right-left)/2;
                continue;
            }
            if(nums[mid] > target){
                right = mid -1;
                mid = left + (right-left)/2;
                continue;
            }
        }
        return -1;
    }
};
