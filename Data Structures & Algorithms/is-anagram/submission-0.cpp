class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> smap;
        map<char,int> tmap;
        //populate smap with word s
        for(char c : s){
            if(!smap.contains(c)){
                smap.insert({c,1});
                continue;
            }
            smap[c]+=1;         
        }
        //populate tmap with t
        for(char c : t){
            if(!smap.contains(c)) //!contains in original set==not anagram.
                return false;
            if(!tmap.contains(c)){ //new and existing char gets added initially.
                tmap.insert({c,1});
                continue;
            }
            tmap[c]+=1;
            if(smap[c]<tmap[c]) // word t exceeds a certain char== not anagram.
                return false;
        }
        //comparison of underwhelming letter count between s and t:
        if(smap==tmap)
            return true;
        else
            return false;
    }
};
