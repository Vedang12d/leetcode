class LRUCache {
public:
    list<int> lru;
    unordered_map<int,list<int>::iterator> mp;
    unordered_map<int,int> memo;
    int size;
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        if(!mp.count(key))
            return -1;
        update(key);
        return memo[key];
    }
    
    void put(int key, int value) {
        if(lru.size()==size and !mp.count(key)){
            mp.erase(lru.back());
            memo.erase(lru.back());
            lru.pop_back();
        }
        update(key);
        memo[key]=value;
    }
    
    void update(int key){
        if(mp.count(key))
            lru.erase(mp[key]);
        lru.push_front(key);
        mp[key]=lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */