class Solution {
public:
    int search(vector<int>& nums, int target) {
        //pick middle value and see if it's more or less than target.
        int left = 0;
        int right = nums.length()-1;

        while( whilecount <= log2(size(nums)/4 +1) ){
            whilecount++;
            
            if(*it==target){
                //use 'distance' to return the index.
                int index = distance(nums.begin(),it);
                return index;
            }
                
            if(*it < target){
                //disregard the left side, and find the center.
                len = len/2;
                if(len==0){
                    len = 1; //hardcoded for 2 index scenarios.
                }
                it+=len;
                continue;
            }
            if(*it > target){
                len = len/2;
                if(len==0){
                    cout<<"activated 2 index special case";
                    len = 1; //hardcoded for 2 index scenarios.
                }
                it-=len;
                continue;
            }
        }
        return -1;
    }
};
