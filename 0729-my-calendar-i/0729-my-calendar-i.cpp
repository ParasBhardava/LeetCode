class MyCalendar {
    
private:
    map<int, int>mp;
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = mp.upper_bound(start);
        
        if(it != mp.end() && (*it).second < end)
            return false;
        
        mp.insert({end, start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */