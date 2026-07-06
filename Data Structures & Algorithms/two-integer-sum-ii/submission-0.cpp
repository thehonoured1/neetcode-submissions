class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //two-pointer tech, beginning and end. taking advantage of sorted.
        auto ptrb =numbers.begin();
        auto ptre =numbers.end() - 1;
        vector<int> ret(2);
       
        // no valid answer:
        if(*ptrb + *ptre > target)
            return ret;
        while(ptrb < ptre){           
            //match:
            if(*ptrb + *ptre == target){
                ret[0]= *ptrb;
                ret[1]= *ptre;
                return ret;
            }
            //advance ptrb if summation is too small:
            if(*ptrb + *ptre < target){
                ptrb++;
                
                continue;
            }
            if(*ptrb + *ptre > target){
                ptre--;
                
                continue;
            }
        }
        return ret;
    }
};
