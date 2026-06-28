class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //"prefix suffix technique", precalculate from the right and from the left, then product of left*right.
        vector<int> ret;
        vector<int> left;
        vector<int> right;

        //product from left-to-right, with initial index pushed:
        int product=nums[0];
        left.push_back(product);

        for(int i=1; i<nums.size(); i++){     //begin from index 1
            product *= nums[i];
            left.push_back(product);
        }
        //product from right:
        vector<int> nums_reverse = nums;
        reverse(nums_reverse.begin(), nums_reverse.end());

        product=nums_reverse[0];
        right.push_back(product);

        for(int i=1; i<nums.size(); i++){     //begin from index 1
            product *= nums_reverse[i];
            right.push_back(product);
        }
        //return vector:
        for(int i=0; i<nums.size(); i++){

            if(i==0){
                ret.push_back(right[right.size()-1-1]);
                continue;
            }
            if(i==nums.size()-1){
                ret.push_back(left[i-1]);
                continue;
            }
            ret.push_back(left[i-1]*right[right.size()-1-1-i]);
        }
        return ret;
    }
};
