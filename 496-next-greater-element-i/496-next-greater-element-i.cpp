class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        int n = nums2.size();
        for(int i=0; i<nums2.size(); i++){
            m[nums2[i]] = i;
        }
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            int idx = m[nums1[i]];
            int num = -1;
            for(int j=idx+1; j<n; j++){
                if(nums2[j]>nums1[i]){
                    num = nums2[j];
                    break;
                }
            }
            ans.push_back(num);
        }
        return ans;
    }
};