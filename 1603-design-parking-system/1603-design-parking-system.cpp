class ParkingSystem {
public:
    int a,b,c;
    ParkingSystem(int big, int medium, int small) {
        a=big,b=medium,c=small;
    }
    
    bool addCar(int ct) {
        if(ct==1)
            return 0<a--;
        else if(ct==2)
            return 0<b--;
        else
            return 0<c--;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */