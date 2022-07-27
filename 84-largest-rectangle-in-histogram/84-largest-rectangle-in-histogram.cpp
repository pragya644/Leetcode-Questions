class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmaller(n,0);
        vector<int> rightSmaller(n,n-1);
        stack<int> s;
        for(int i=0; i<n; i++){
            
            while(s.empty()==false && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()==false){
                leftSmaller[i] = s.top()+1;
            }
            s.push(i);
            
        }
        
        while(s.empty()==false){
            s.pop();
        }
        
        for(int i=n-1; i>=0; i--){
            
            while(s.empty()==false && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()==false){
                rightSmaller[i] = s.top()-1;
            }
            s.push(i);
            
        }
        
        int maxArea = 0;
        for(int i=0; i<n; i++){
            
            int width = rightSmaller[i]-leftSmaller[i]+1;
            int area = width*heights[i];
            maxArea = max(maxArea, area);
            
        }
        
        return maxArea;
        
    }
};