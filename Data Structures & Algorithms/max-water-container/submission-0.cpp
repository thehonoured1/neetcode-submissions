class Solution {
public:
    int maxArea(vector<int>& heights) {
        // pass through the array with 2 pointers, make the calculation for pairs
        // hint 3: move the pointer pointing to the smaller bar, logically.
        //record the highest outcome and indices.
        auto itb = heights.begin();
        auto ite = heights.end()-1;
        int b;
        int e;
        vector<int> volumes;

        while(itb!=ite){
            b = *itb;
            e = *ite;
            volumes.push_back(min(*itb,*ite) * (ite-itb));
            if(*itb < *ite){
                itb++;
                continue;
            }
            if(*ite < *itb){
                ite--;
                continue;
            }
            if(*itb == *ite){
                itb++;
                continue;
            }
        }
        sort(volumes.begin(),volumes.end());
        return *(volumes.end()-1);
    }
};
