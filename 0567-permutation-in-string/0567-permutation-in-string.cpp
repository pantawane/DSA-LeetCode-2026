class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        //base case
        if(n > m)
        return false;

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(char ch: s1)
          freq1[ch - 'a']++;

        for(int i=0; i<n; i++)
          freq2[s2[i] - 'a']++;

        if(freq1 == freq2)
        return true;

        //slide window
        for(int j = n; j< m; j++){
            //add next character
            freq2[s2[j] -'a']++;

            //remove 1st elemnt
            freq2[s2[j-n] - 'a']--;

            if(freq1 == freq2)
            return true;
        }    
        return false;
    }
};