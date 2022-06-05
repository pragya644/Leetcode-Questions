class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int x=-1,y=-1;
        vector<int> ans;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid]==target)
            {
                x = mid;
                while(x>=0 && nums[x]==target)
                    x--;
                y = mid;
                while(y<n && nums[y]==target)
                    y++;
                break;
            }
            else if(nums[mid]>target)
                r = mid-1;
            else
                l = mid+1;
        }
        if(x==-1 && y==-1)
        {
            ans.push_back(x);
            ans.push_back(y);
            return ans;
        }
        x++;
        y--;
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};