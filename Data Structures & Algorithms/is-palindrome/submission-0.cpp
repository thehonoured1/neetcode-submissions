class Solution {
public:
    bool isPalindrome(string s) {

        /*idiom: remove space chars using "remove() erase()"" idiom:    
            remove: moves all char except specified the front, returns iterator that begins at the first unwanted char.
            remove_if: added feature to include 'if' lambda function.
            erase: removes everything in range.
            ( # remove doesn't delete because it accepts iterators that may belong to any kind of data structure, it cant make assumptions.)
        */
        string ts = s;
        auto new_end = remove_if(ts.begin(), ts.end(),[](unsigned char c){
                        return ispunct(c) || isspace(c);
                        }); //the iterator.
        ts.erase(new_end,ts.end());
        cout<<ts<<'\n';

        /*tolower: change case across string
            Transform: applies function across a sequence of elements.
            [](...){return...} is a lambda function.
            tolower: accepts only unsigned char; its a C relic.
        */
        transform(ts.begin(), ts.end(), ts.begin(), [](unsigned char c){return tolower(c);} );
        cout<<"in order string: "<<ts<<'\n';
        string rts = ts;
        reverse(rts.begin(), rts.end());
        cout<<"reversed string:"<<rts;
        if(rts == s){
            return true;
        }
        else return false;
    }
};
