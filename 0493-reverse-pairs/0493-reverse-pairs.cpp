class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high){
        int right = mid + 1;
        int left = low;
        vector<int> temp;
         //merge two sorted halves
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right])
               temp.push_back(arr[left++]);
            else
               temp.push_back(arr[right++]);   
        }
        //copy remaining elements form left half
        while(left <= mid){
            temp.push_back(arr[left++]);
        }

        //copy remaining elements form right half
        while(right <= high){
            temp.push_back(arr[right++]);
        }
        //copy sorted elements back to the original array
        for(int i=low; i<=high; i++){
            arr[i] = temp[i - low];
        }
    }
    int countPairs(vector<int> &arr, int low, int mid, int high){

        int right = mid + 1;
        int cnt = 0;
        for(int i=low; i<= mid; i++){
            while(right <= high && (long long)arr[i] > 2LL * arr[right]){
                right++;
            }
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    int mergeSort(vector<int> &arr, int low, int high){
        int cnt = 0;
        if(low >= high)
        return cnt;
        //middle element
        int mid = (low + high) / 2;
        //recursive call for left part
        cnt += mergeSort(arr, low, mid);
        //recursive call for right part
        cnt += mergeSort(arr, mid+1, high);
        //count number of pairs
        cnt += countPairs(arr, low, mid, high);
        //merge both parts
        merge(arr, low, mid, high);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};