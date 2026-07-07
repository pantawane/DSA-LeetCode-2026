class Twitter {
private:
    //stores tweets of each user as a vector of (timestamps, tweetsID)
    unordered_map<int, vector<pair<int, int>>> tweets;
    //stores the set of followers for each user
    unordered_map<int, unordered_set<int>> following;
    //global time counter
    int time = 0;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        //Add tweet to current timeStaps 
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        //create minHeap to store tweets based on timestamps
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        //insert user own tweets
        for(auto& t: tweets[userId]){
            pq.push(t);
            //keep size max 10
            if(pq.size() > 10)
            pq.pop();
        }
        //insert tweets from user being followed
        for( int followee : following[userId]){
            for(auto& t: tweets[followee]){
                pq.push(t);
                //keep size max 10
                if(pq.size() > 10)
                pq.pop();
                }
        }
        //extract tweet from heap in reverse order
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */