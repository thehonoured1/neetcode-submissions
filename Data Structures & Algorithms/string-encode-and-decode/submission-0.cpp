class Solution {
public:

    string encode(vector<string>& strs) {
        string ret = "";
        if(strs.empty()==1)
            return ret;
        for(string str: strs){
            ret+=str+","; //the entire str will end in ","
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret_vector;
        if(s.empty()==1){
            //ret_vector.push_back("");
            return ret_vector;
        }      
        string word = "";
        int s_len = s.length();
        for (int i=0; i < s_len; i++){
            if(s[i]==','){
                ret_vector.push_back(word);
                word = "";
                continue;
            }           
            word+=s[i];
        }
        //ret_vector.push_back(word); // final word.
        return ret_vector;
    }
};
