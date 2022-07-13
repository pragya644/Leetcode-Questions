class Solution {
public:
    
    //time complexity is O(n*n)
    
    string getPermutation(int n, int k) {
        vector<int> value;
        int factorial = 1;
        for(int  i=1; i<n; i++)
        {
            value.push_back(i);
            factorial *= i; //we are not multiplying last value bcoz we want the no of perumtaion in each block. eg 4! = 24 means 6 block at each idx. 6 = 3!
        }
        value.push_back(n);
        k -= 1; // 0 indexing 
        string s;
        while(true)
        {
            s += to_string(value[k/factorial]);
            value.erase(value.begin()+k/factorial);
            if(value.size()==0)
                break;
            k = k% factorial;
            factorial = factorial/value.size();
        }
        return s;
    }
};