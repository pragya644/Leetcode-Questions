class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int i=0;
        int jump = 0;
        priority_queue<int> pq;
        while(i<n-1)
        {
            if(heights[i]>=heights[i+1])
                i++;
            else
            {
                int req_bricks = heights[i+1]-heights[i];
                jump += req_bricks;
                pq.push(req_bricks);
                if(jump>bricks && ladders>0)
                {
                    jump = jump-pq.top();
                    pq.pop();
                    ladders--;
                }
                else if(jump>bricks && ladders<=0)
                {
                    break;
                }
                i++;
            }
        }
        return i;
    }
};