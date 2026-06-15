class Solution {
public:
    int characterReplacement(string s, int k) {
        //create freq where we can store count of each character
        unordered_map<char, int> freq;

        //initialize variables
        int i = 0;
        int maxFreq = 0;
        int maxLength = 0;

        //traverse j loop
        for(int j = 0; j<s.size(); j++){
            //add each char and freq
            freq[s[j]]++;

            //update maxFreq
            maxFreq = max(maxFreq, freq[s[j]]);

            //condition to check window size is valid or not
            while((j-i+1) - maxFreq > k){
               freq[s[i]]--;
                i++;
            }
            //update maxLength
            maxLength = max(maxLength, j-i+1);
        }

        return maxLength;
    }
};