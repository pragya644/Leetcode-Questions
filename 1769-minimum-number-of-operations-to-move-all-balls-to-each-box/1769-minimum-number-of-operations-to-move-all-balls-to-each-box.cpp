class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);
        int ahead = 0;
        int behind = 0;
        for(int i=0; i<boxes.length(); i++)
        {
            if(boxes[i]=='1')
            {
                ahead++;
                res[0] += i;
            }
        }
        if(boxes[0]=='1')
        {
            ahead--;
            behind++;
        }
        for(int i=1; i<boxes.length(); i++)
        {
            res[i] = res[i-1]-ahead+behind;
            if(boxes[i]=='1')
            {
                ahead--;
                behind++;
            }
        }
        return res;
    }
};