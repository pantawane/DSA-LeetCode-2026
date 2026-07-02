class Solution {
public:
    int count = 0;
    void expand(string &s, int left, int right){
        
         while(left >=0 && right < s.length() && s[left] == s[right]){
            count++;
            left--;
            right++;
        }
    }
    int countSubstrings(string s) {
        for(int i=0; i<s.length(); i++){
            expand(s, i, i); //odd
            expand(s, i, i+1); //even
        }
        return count;
    }
};