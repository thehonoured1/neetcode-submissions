class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //IDEA: count all numbers, whilst adding to a HEAP.
        //      heap organizes based on first value of tuple
        //      each tuple: <count, value>
        //      after done, pop off the heap k times.
        //  1. put all numbers and counts into a vector
        //  2. loop thru the vector to migrate into the heap
        //  2.1 by converting number/counts into tuples of <count, number>
        //  3. the heap will rank the maximum value.
                    //int biggestNum = *max_element(nums.begin(),nums.end());
                    //vector<int> numCount(biggestNum,0);
        map<int,int> numCount;
        vector<tuple<int,int>> heap ={};
        vector<int> ret = {};

        for(int number : nums){
            numCount[number] +=1;
        }//atp, all numbers and their counts included in map.
        
        //2.
        for (auto it = numCount.begin(); it != numCount.end(); it++)
        {
            heap.push_back(make_tuple(it->second,it->first));
        }//atp, 'heap' includes all non zero tuples.

        //3.
        make_heap(heap.begin(),heap.end());

        while(k!=0){
            pop_heap(heap.begin(),heap.end());
            auto [count, number] = heap.back();
            heap.pop_back();
            ret.push_back(number);
            k--;
        }
        return ret;
    }
};
