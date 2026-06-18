class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int x = nums1.size();
        int y = nums2.size();

        int start = 0;
        int end = x;

        while(start <= end){

            int partX = (start + end) / 2;
            int partY = (x + y + 1) / 2 - partX;

            int xLeft  = (partX == 0) ? INT_MIN : nums1[partX - 1];
            int xRight = (partX == x) ? INT_MAX : nums1[partX];

            int yLeft  = (partY == 0) ? INT_MIN : nums2[partY - 1];
            int yRight = (partY == y) ? INT_MAX : nums2[partY];

            if(xLeft <= yRight && yLeft <= xRight){

                if((x + y) % 2 == 0){
                    return (max(xLeft, yLeft) + min(xRight, yRight)) / 2.0;
                }

                return max(xLeft, yLeft);
            }

            else if(xLeft > yRight){
                end = partX - 1;
            }

            else{
                start = partX + 1;
            }
        }

        return 0.0;
    }
};