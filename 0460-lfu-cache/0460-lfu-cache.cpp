#define ff first
#define ss second
#define pb push_back

class LFUCache {
public:
    int size;
    int freq=0;
    unordered_map<int,pair<int,int>> kv;
    unordered_map<int,list<int>> fl;
    unordered_map<int,list<int>::iterator> pos;
    LFUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        if(!kv.count(key))
            return -1;
        fl[kv[key].ss].erase(pos[key]);
        kv[key].ss++;
        fl[kv[key].ss].pb(key);
        pos[key]=--fl[kv[key].ss].end();
        if(fl[freq].empty())
            freq++;
        return kv[key].ff;
    }
    
    void put(int key, int val) {
        if(!size)
            return;
        if(kv.count(key)){
            kv[key].ff=val;
            fl[kv[key].ss].erase(pos[key]);
            kv[key].ss++;
            fl[kv[key].ss].pb(key);
            pos[key]=--fl[kv[key].ss].end();
            if(fl[freq].empty())
                freq++;
        }else{
            if(kv.size()==size){
                int del=fl[freq].front();
                kv.erase(del);
                pos.erase(del);
                fl[freq].pop_front();
            }
            kv[key]={val,1};
            fl[1].pb(key);
            pos[key]=--fl[1].end();
            freq=1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */