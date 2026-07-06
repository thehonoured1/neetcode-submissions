class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Hint 3: -nums[i] = nums[j] + nums[k]
        sort(nums.begin(),nums.end());
                                        for(int i: nums){
                                            cout<<i;
                                        } cout<<'\n';
        auto itb = nums.begin();
        auto ite = nums.end()-1;
                                        cout<<*ite;
        vector<vector<int>> ret;

        for(int i=0; i<nums.size(); i++){
            itb = nums.begin()+1+i; //after each i, all triplet cases are exhausted with said i.
            ite = nums.end()-1;

            while(itb < ite){
                // sum is too small:
                if(-(nums[i]) > *itb + *ite){
                    itb++;
                    continue;
                }
                // sum is too large:
                if(-(nums[i]) < *itb + *ite){
                    ite--;
                    continue;
                }
                //match
                if(-(nums[i]) == *itb + *ite){
                    //position of iterators:
                    int b = distance(nums.begin(),itb);
                    int e = distance(nums.begin(),ite);
                    ret.push_back(vector<int>{nums[i],nums[b],nums[e]} );
                    break;
                }
            }
            
        }
        //remove duplicates, using the "unique-erase" idiom, highly similar to "remove-erase".
        auto itu = unique(ret.begin(),ret.end());
        ret.erase(itu,ret.end());
        return ret;
    }
};
