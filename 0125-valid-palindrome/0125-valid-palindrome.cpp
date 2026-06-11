class Solution {
public:
    bool isPalindrome(string s) {
        // initialize two pointer
        int i = 0;
        int j = s.length()-1;

        while(i < j){
            //removing non-alphanumeric characters
            while(i < j && !isalnum(s[i])){
                i++;
            }
            while(i < j && !isalnum(s[j])){
                j--;
            }

            //converting i and j to lowercase and check
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};