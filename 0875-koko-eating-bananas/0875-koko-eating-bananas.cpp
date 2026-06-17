class Solution {
public:
    // Calculate total hours required at speed k
    long long totalHours(vector<int>& piles, int k) {

        long long hours = 0;

        for (int pile : piles) {
            hours += ceil((double)pile / k);
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long hours = totalHours(piles, mid);

            if (hours <= h) {
                ans = mid;          // Possible answer
                high = mid - 1;     // Try smaller speed
            }
            else {
                low = mid + 1;      // Increase speed
            }
        }

        return ans;
    }
};