class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //IDEA: map content can be compared directly.
        //      create an array[26] for each word processed. Use ASCII numbering to perform arithmetic on chars
        //      exist map, which is <array: string vector>
        //
        // iterate over the map and compare arrays (keys).
        // if match, add to corresponding vector
        // if it's unique, create a new entry in map, using secondary map as its key.

        map< array<int,26> , vector<string> > MasterMap;

        // Traverse the vector of strings
        for(string word:strs){
            array<int,26> arrCharCount={};

            // iterate and count the letters of the string to array:
            for(char c: word){     
                arrCharCount[c-'a']++;
            }//atp the whole word char count is in array.
            
            // add word to the array. Existance check isn't needed in c++.
            MasterMap[arrCharCount].push_back(word);
        }
        // populate return matrix:
        vector<vector<string>> ret;
        for(auto& [key, stringVector]: MasterMap){
            ret.push_back(stringVector);
        }
        return ret;
    }
};
