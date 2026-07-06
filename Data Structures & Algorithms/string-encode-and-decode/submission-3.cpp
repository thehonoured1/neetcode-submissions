class Solution {
public:

    string encode(vector<string>& strs) {
        string ret = "";
        int len = 0;
        if(strs.empty()==true)
            return ret;
        for(string str : strs){         
            ret+=to_string(str.length())+'#'+str; //length prefix encoding
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret_vec;
        //char c = '';
        string curr_word = "";
        string slen="";
        int ilen = 0;

        for(int i = 0; i < s.length(); i++){
            //slen will record the length value as a string, then converted to an int.
            slen+=s[i];

            if(s[i]=='#'){
                //stop recording the numbers
                ilen=stoi(slen);
                i++; // skip #
                int j = 0;
                for(; j < ilen; j++){ //j is borrowing position i, and i will reclaim j after
                    curr_word+=s[j];
                }
                i=j;
                j=0; //reset j
                ret_vec.push_back(curr_word);
                curr_word="";
                continue;
            }
        }
        return ret_vec;
    }
};
