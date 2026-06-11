class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //create map (key-> list of string)
        unordered_map<string, vector<string>> mp;

        //iterate each string
        for(string str: strs){
            vector<int> count(26,0);

            for(char ch: str){
                count[ch - 'a']++;
            }
            //generate unique key to identify map element
            string key = "";
            for(int i=0; i<26; i++){
                key += "#" + to_string(count[i]);
            }
            mp[key].push_back(str);
        }
        // store the ans
        vector<vector<string>> ans;
        //iterate to all key-value pair and return grouped anagram
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};