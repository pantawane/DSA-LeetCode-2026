class Solution {
public:
    bool isAnagram(string s, string t) {
        //step1
        if(s.length() != t.length())
        return false;

        //step 2 initialze count
        vector<int> count(26, 0);

        //step 3 traverse s & t
        for(char ch : s){
            count[ch - 'a']++;
        }

        for(char ch : t){
            count[ch - 'a']--;
        }

        //step 4 check count frequency
        for(int freq : count){
            if(freq != 0){
                return false;
            }
        }  
         return true;
    }
};