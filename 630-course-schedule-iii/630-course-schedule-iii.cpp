class Solution {
public:
    
    static bool cmp(vector<int> a, vector<int> b) {
        return a[1]<b[1];
    }
    

    
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int> q;
        int days = 0;
        for(int i=0; i<n; i++)
        {
            int comp = days+courses[i][0];
            if(comp<=courses[i][1]){
                q.push(courses[i][0]);
                days += courses[i][0];
            }
            else
            {
                if(!q.empty() && q.top()>courses[i][0])
                {
                    days -= q.top();
                    q.pop();
                    days += courses[i][0];
                    q.push(courses[i][0]);
                }
            }
        }
        return q.size();
    }
};