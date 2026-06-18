class TimeMap {
public:
    // create hash map and tree map
    unordered_map<string, map<int, string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end())
        return "";

        //first timestamp greater than given timestamp means
        auto it = mp[key].upper_bound(timestamp);

        if(it == mp[key].begin())
           return "";

           //we want value as per condition timestamp_prev <= timestamp(basically we want value whoch is less than equal to given value in the get opperatin or input)
        --it;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */