class Solution {
public:
    
    int findArea(stack<int> &s, int i, vector<int> &heights){
        
        int curr = s.top();
        int right = i;
        s.pop();
        int left = -1;
        if(s.empty()==false){
            left = s.top();
        }
        int width = right-left-1;
        int area = width*heights[curr];
        return area;
        
    }
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        stack<int> s;
        int maxArea = 0;
        for(int i=0; i<n; i++){
            
            while(s.empty()==false && heights[s.top()]>heights[i]){
                int area = findArea(s,i,heights);
                maxArea = max(maxArea, area);
            }
            s.push(i);
            
        }
        
        while(s.empty()==false){
            int area = findArea(s,n,heights);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};