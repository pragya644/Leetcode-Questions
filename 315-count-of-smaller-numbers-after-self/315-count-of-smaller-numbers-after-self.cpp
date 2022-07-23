class Solution {
public:
    
    vector<int> ans;
    
    void mergeSort(vector<int> &ans, vector<pair<int,int>> &v, int l,int m, int r){
        vector<pair<int,int>> temp(r-l+1);
        int i=l;
        int j = m+1;
        int k = 0;
        int count = 0;
        while(i<=m && j<=r){
            if(v[i].first <= v[j].first){
                ans[v[i].second] += count;
                temp[k] = v[i];
                k++;
                i++;
            }else{
                count++;
                temp[k] = v[j];
                k++;
                j++;
            }
        }
        while(i<=m){
            ans[v[i].second] += count;
            temp[k] = v[i];
            k++;
            i++;
        }
        while(j<=r){
            temp[k] = v[j];
            k++;
            j++;
        }
        for(int i=l; i<=r; i++){
            v[i] = temp[i-l];
        }
    }
    
    
    void merge(vector<int> &ans, vector<pair<int,int>> &v, int l, int r){
        if(l>=r)
            return;
        int mid = l+(r-l)/2;
        merge(ans,v,l,mid);
        merge(ans,v,mid+1,r);
        mergeSort(ans,v,l,mid,r);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++)
            v.push_back({nums[i],i});
        vector<int> ans(n,0);
        merge(ans,v,0,n-1);
        return ans;
    }
};