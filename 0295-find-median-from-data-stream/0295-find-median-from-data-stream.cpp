class MedianFinder {
public:

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {

    }

    int sigNum(int a, int b){

        if(a == b)
            return 0;
        else if(a > b)
            return 1;
        else
            return -1;
    }

    void addNum(int num) {

        switch(sigNum(maxHeap.size(), minHeap.size())){

        // Both heaps have equal size
        case 0:

            if(maxHeap.empty() || num <= maxHeap.top())
                maxHeap.push(num);
            else
                minHeap.push(num);

            break;

        // maxHeap has one extra element
        case 1:

            if(num > maxHeap.top()){
                minHeap.push(num);
            }
            else{
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }

            break;

        // minHeap has one extra element
        case -1:

            if(num < minHeap.top()){
                maxHeap.push(num);
            }
            else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }

            break;
        }
    }

    double findMedian() {

        switch(sigNum(maxHeap.size(), minHeap.size())){

            case 0:
                return (maxHeap.top() + minHeap.top()) / 2.0;

            case 1:
                return maxHeap.top();

            case -1:
                return minHeap.top();
        }

        return 0;
    }
};