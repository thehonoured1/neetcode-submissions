class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //two-pointer tech, beginning and end. taking advantage of sorted.
        auto ptrb =numbers.begin();
        auto ptre =numbers.end() - 1;
        vector<int> ret(2);
       
        while(ptrb < ptre){           
            //match:
            if(*ptrb + *ptre == target){
                ret[0]=1+distance(numbers.begin(),ptrb);
                ret[1]=1+ distance(numbers.begin(),ptre);
                return ret;
            }
            //advance ptrb if summation is too small:
            if(*ptrb + *ptre < target){
                ptrb++;
                
                continue;
            }
            //advance ptre if summation is too large:
            if(*ptrb + *ptre > target){
                ptre--;
                
                continue;
            }
        }
        cout<<"while loop exited";
        return ret;
    }
};
