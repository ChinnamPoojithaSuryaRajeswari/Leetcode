class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    
    map<int, int>mp;
    bool book(int start, int end) 
    {
        mp[start] += 1;
        mp[end] -= 1;
        int e = 0;
        for(auto [value, count] : mp)
        {
            e += count;
            if(e > 2)
            {
                mp[start] -= 1;
                mp[end] += 1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */