class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> mp;
    unordered_map<string,pair<double,int>> time;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string s=mp[id].first+"_"+stationName;
        time[s].first+=t-mp[id].second;
        time[s].second++;
        mp.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string s=startStation+"_"+endStation;
        return time[s].first/time[s].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */