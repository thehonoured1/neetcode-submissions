class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        sort(nums.begin(),nums.end());
                                                    for(int n:nums){
                                                        cout<<n;
                                                    }cout<<'\n';
        int lastconsec=nums[0];
        int count=1;
        int ret=0;
        //bool broken = false; //whether an consecutive seq is broken.

        for(int i=0; i<nums.size()-1; i++){
            //same number:
            if(lastconsec==nums[i+1]){
                continue;
            }
            //next num is larger by +1:
            if((lastconsec+1)==nums[i+1] ){
                //broken=false;
                lastconsec=nums[i+1];
                cout<<"last consecutive num ="<<lastconsec<<'\n';
                count++;
                cout<<count<<"Count \n";
            }
            //Broken chain scenario:
            if((lastconsec+1)<nums[i+1] ){
                //reset count and save the current iteration to ret(if it's larger):
                //broken=true;
                lastconsec = nums[i+1];
                if(count > ret)
                    ret = count;
                count = 1;
                cout<<"count reset,";
                cout<<"Ret = "<<ret<<"last consecutive num="<<lastconsec<<'\n';
            }
        }
        if(count > ret)
            ret = count;
        return ret;
    }
};
