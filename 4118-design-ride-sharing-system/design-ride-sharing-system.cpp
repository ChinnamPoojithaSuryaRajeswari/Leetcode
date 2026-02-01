class RideSharingSystem {
public:
    queue<int> ride;
    map<int,int>mpp;
    queue<int> drive;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        mpp[riderId]=0;
        ride.push(riderId);
    }
    
    void addDriver(int driverId) {
        drive.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!drive.empty() and !ride.empty()){
            if(mpp[ride.front()]!=1){
                int rdFrnt = drive.front();
                int drFrnt = ride.front();
                drive.pop();
                ride.pop();
                return {rdFrnt,drFrnt};
            }
            else{
                mpp[ride.front()]=0;
                ride.pop();
            }
        }
        return {-1,-1};
    }
    void cancelRider(int riderId) {
        mpp[riderId]=1;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */