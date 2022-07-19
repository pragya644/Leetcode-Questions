class Solution {
public:
    
    //time complexity is O(n), n is the size of nums2
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int> m;
        int size = nums1.size();
        for(int i=0; i<nums1.size(); i++){
            m[nums1[i]] = i;
        }
        stack<int> s;
        vector<int> ans(size,-1);
        for(int i=0; i<n; i++){
            while(!s.empty() && s.top()<nums2[i]){
                ans[m[s.top()]] = nums2[i];
                s.pop();
            }
            if(m.find(nums2[i])!=m.end()){
                s.push(nums2[i]);
            }
        }
        return ans;
    }
};