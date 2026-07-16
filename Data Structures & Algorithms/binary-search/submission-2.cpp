class Solution {
public:
    int search(vector<int>& nums, int target) {
        //pick middle value and see if it's more or less than target.
        int len = size(nums)/2; //initial length
        auto it = nums.begin() + (len);       
        int whilecount = 0; //track how many times the loop executes.

        while( whilecount<=log2(size(nums)/4) ){
            whilecount++;
            
            if(*it==target){
                //use 'distance' to return the index.
                int index = distance(nums.begin(),it);
                return index;
            }
                
            if(*it < target){
                //disregard the left side, and find the center.
                int len = len/2;
                it+=len;
                continue;
            }
            if(*it > target){
                int len = len/2;
                it-=len;
                continue;
            }
        }
        return -1;
    }
};
