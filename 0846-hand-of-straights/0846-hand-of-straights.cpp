class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        //base case
        if(n % groupSize != 0)
        return false;

        //create a tree map-> hash map + sorted order
        map<int, int> freq;

        for(int card: hand){
            freq[card]++;
        }

        while(!freq.empty()){
            int start = freq.begin()->first;

            for(int i=0; i<groupSize; i++){
                int card = start + i;

                if(freq.find(card) == freq.end()){
                    return false;
                }

                freq[card]--;

                if(freq[card] == 0)
                   freq.erase(card);
            }
        }

        return true;
    }
};