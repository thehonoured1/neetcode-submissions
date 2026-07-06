class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        sort(nums.begin(),nums.end());
        int lastconsec=0;
        int count=1;

        for(int i=0; i<nums.size()-1; i++){
            
            //next num is larger by +1
            if((nums[i]+1)==nums[i+1]){
                lastconsec=nums[i+1];
                count++;
            }
        }
        return count;
    }
};
