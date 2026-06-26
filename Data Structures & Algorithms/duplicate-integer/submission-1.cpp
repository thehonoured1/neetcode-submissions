class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.empty())
            return false;
        sort(nums.begin(),nums.end());

        for(auto it = nums.begin(); (it+1)!=nums.end(); ++it){
            if(*it==*(it+1))
                return true;
        }
        return false;
    }
};

//attampt at doble pointer:
/*
sort(nums);
        *ptr1 = &nums[0]
        **ptr2 = &ptr1;
        int len = nums.size();
        for(int i = 0; i<len; i++){
            if(*ptr2->next)
        }
*/