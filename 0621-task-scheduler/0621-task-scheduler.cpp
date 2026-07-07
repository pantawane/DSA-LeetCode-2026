class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //create a freqMap
        unordered_map<char, int> freqMap;
        //map each task of tasks in freqMap
        for(char task: tasks){
            freqMap[task]++;
        }
        //create max heap
        priority_queue<int> maxHeap;
        for(auto& it: freqMap){
            maxHeap.push(it.second);
        }
        // process n+1 tasks
        int time = 0;
        while(!maxHeap.empty()){
            vector<int> temp;
            for(int i=0; i<n+1; i++){
                if(!maxHeap.empty()){
                    temp.push_back(maxHeap.top());
                    maxHeap.pop();
                }
            }
            //decrease freq and push back if task remain
            for(int freq: temp){
                freq--;
                if(freq > 0)
                maxHeap.push(freq);
            }

            //update time
            if(maxHeap.empty()){
                time += temp.size();
            }else{
                time += n+1;
            }
        }
        return time;
    }
};