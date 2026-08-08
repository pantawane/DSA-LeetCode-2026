class Solution {
public:

    bool isFreqMatches(vector<int>& freq1, vector<int>& freq2) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {

        vector<int> freq(26, 0);

        // Frequency of s1
        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }

        int windowSize = s1.length();

        for (int i = 0; i < s2.length(); i++) {

            int windowIdx = 0;
            int idx = i;

            vector<int> windowFreq(26, 0);

            while (windowIdx < windowSize && idx < s2.length()) {

                windowFreq[s2[idx] - 'a']++;

                windowIdx++;
                idx++;
            }

            if (isFreqMatches(freq, windowFreq)) {
                return true;
            }
        }

        return false;
    }
};