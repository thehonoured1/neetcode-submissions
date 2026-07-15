class Solution {
public:
// water is trapped according to the lowest of 2 bars.
// TWO POINTER search:
//  # we can safely confirm a water pool's position when an equal or higher further bar exists.
//  using this rule, calculate and add water to the total volume.
//  however, if either or both pointers have an open pool:
//      use the taller of the two side's "tallest bar" to create a final pool
//      

    int trap(vector<int>& height) {
        stack<int> height
    }
};


/* DISCARDED THOUGHT PROCESS BELOW*/
//  if we reach the end of the array without a taller right bar, reverse the order of 'search'
//   which will solve the problem of no taller right bar exist.
//   use stack to backtrack.