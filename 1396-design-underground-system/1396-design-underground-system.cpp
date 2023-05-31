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
        time[mp[id].first+"_"+stationName].first+=t-mp[id].second;
        time[mp[id].first+"_"+stationName].second++;
        mp.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return time[startStation+"_"+endStation].first/time[startStation+"_"+endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */