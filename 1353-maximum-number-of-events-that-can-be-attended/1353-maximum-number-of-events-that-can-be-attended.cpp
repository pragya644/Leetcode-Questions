class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        int noOfEvents = events.size();
        
        int maxiday = INT_MIN;  
        for(auto x: events){
            maxiday = max(maxiday, x[1]);
        }
        
        int attendEvents = 0;
        
        priority_queue<int,vector<int>, greater<int>> pq;
        int currIdx = 0;
        
        for(int day=1; day<=maxiday; day++){
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
            while(currIdx < noOfEvents && events[currIdx][0]==day){
                pq.push(events[currIdx][1]); //enddate
                currIdx++;
            }  
            
            if(!pq.empty() && pq.top()>=day){
                attendEvents++;
                pq.pop();
            }
            
            if(pq.empty() && currIdx==noOfEvents)
                break;
            
        }
        
        return attendEvents;
    }
};