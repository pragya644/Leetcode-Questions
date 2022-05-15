class Solution {
public:
    int numTrees(int n) {
        if(n==0 || n==1)
            return 1;
        vector<int> v(n+1,0);  
        v[0]= v[1] = 1;
        for(int i=2; i<=n; i++) // it means when we have 2 nodes... 3 nodes.. 
        {
            for(int j=1; j<=i ; j++)  // it means every node will be root
                v[i] += v[j-1]*v[i-j];
                // v[j-1] = no of nodes on the left side
              // v[i-j] = no of nodes on the right side
        }
        return v[n];
    }
    
    // n=4;
    // vector v 
    // 0 1 2 3 4  (no represent n value , like when n=0, then 1, then 2 and so on)
    // 1 1 ? ? ?  v[4] = ans; v[0] = v[1] = 1 means when we have 0 node we can make one BST, v[1] means when we have 1 node we can make only BST
    // v[2] = represent 2 nodes (1,2)
    // so now when 1 will be root node , no of nodes on the left is 1-1 = 0 and no of nodes on the right is (i=2) 2-1 = 1; 
    // total possible subtree would be v[0]*v[1] = 1*1 = 1;
    // now when 2 will be subtree , no of nodes on left is 2-1 = 1, right is 2-2 = 0, total = v[1]*v[0] = 1*1 = 1;
    // v[2] = 1+1 = 2;
    // 0 1 2 3 4
    // 1 1 2 5 14
};