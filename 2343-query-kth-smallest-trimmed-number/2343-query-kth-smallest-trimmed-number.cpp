class Solution {
public:
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int noOfqueries = queries.size();
        vector<int> answer;
        for(int i=0; i<noOfqueries; i++)
        {
            vector<pair<string,int>> trimStrings;
            int kthtrim = queries[i][0];
            int lenOftrim = queries[i][1];
            int noOfStrings = nums.size();
            for(int i=0; i<noOfStrings; i++)
            {
                string x = nums[i];
                int lenOfString = x.length();
                int idxOftrim = lenOfString-lenOftrim;
                string trimString = x.substr(idxOftrim);
                trimStrings.push_back({trimString,i});
            }
            sort(trimStrings.begin(), trimStrings.end());
            answer.push_back(trimStrings[kthtrim-1].second);
        }
        return answer;
    }
};