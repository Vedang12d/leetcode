class SnapshotArray {
public:
    map<int,map<int,int>> mp;
    int ct=0;
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        mp[index][ct]=val;
    }
    
    int snap() {
        return ct++;
    }
    
    int get(int index, int snap_id) {
        if(!mp.count(index))
            return 0;
        auto it=mp[index].upper_bound(snap_id);
        return (it==mp[index].begin()?0:prev(it)->second);
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */