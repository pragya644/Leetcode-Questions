class MyCalendar {
public:
    
    vector<pair<int,int>> dates;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(dates.empty()==true)
        {
            dates.push_back({start,end});
            return true;
        }
        for(int i=0; i<dates.size(); i++){
            auto curr = dates[i];
            if((start<=curr.first || start>curr.first) && start<curr.second && (end<curr.second || end>=curr.second) && end>curr.first)
                return false;
        }
        dates.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */