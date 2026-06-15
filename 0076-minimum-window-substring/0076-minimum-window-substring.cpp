class Solution {
public:
    string minWindow(string s, string t) {
        //base case
        if(t.size() > s.size())
        return "";
        // create need -> what we need from t
        // create window what we currently have in window
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for(char ch : t)
           need[ch]++;

        //initialize variables
        int requirement = need.size();
        int formed = 0;
        int i = 0;
        int minLength = INT_MAX;
        int start = 0;

        //start sliding window
        for(int j = 0; j< s.size(); j++){
            char ch = s[j];
            window[ch]++;

            //check condition
            if(need.count(ch) && window[ch] == need[ch])
               formed++;

            while(formed == requirement){

                //update minLength
                if(j-i+1 < minLength){
                minLength = j-i+1;
                start = i;
            }

            //remove leftChar
            char leftChar = s[i];
            window[leftChar]--;

            if(need.count(leftChar) && window[leftChar] < need[leftChar]){
                formed--;
            }
            i++;
            } 
        }
        if(minLength == INT_MAX)
        return "";
        
        return s.substr(start, minLength);

    }
};