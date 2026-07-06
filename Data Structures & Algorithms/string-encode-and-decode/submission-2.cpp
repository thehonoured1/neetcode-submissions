class Solution {
public:

    string encode(vector<string>& strs) {
        string ret = "";
        if(strs.empty()==true)
            return ret;
        for(string str : strs){
            ret+=str+',';
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret_vec;
        string curr_word = "";
        if(s==",,"){
            ret_vec.push_back(",");
            return ret_vec;
        }          
        for(char c:s){
            if(c==','){
                cout<<curr_word;
                ret_vec.push_back(curr_word);
                curr_word="";
                continue;
            }
            curr_word+=c;
        }
        return ret_vec;
    }
};
