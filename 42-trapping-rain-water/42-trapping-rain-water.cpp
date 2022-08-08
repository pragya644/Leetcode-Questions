class Solution {
public:
    int trap(vector<int>& bridges) {
        int noOfBridges = bridges.size();
    vector<int> leftMax(noOfBridges, -1);
    vector<int> rightMax(noOfBridges, -1);

    for (int i = 1; i < noOfBridges; i++)
    {
        if (leftMax[i - 1] > bridges[i])
        {
            leftMax[i] = leftMax[i - 1];
        }
        else if (bridges[i - 1] > bridges[i])
        {
            leftMax[i] = bridges[i - 1];
        }
    }

    for (int i = noOfBridges - 2; i >= 0; i--)
    {
        if (rightMax[i + 1] > bridges[i])
        {
            rightMax[i] = rightMax[i + 1];
        }
        else if (bridges[i + 1] > bridges[i])
        {
            rightMax[i] = bridges[i + 1];
        }
    }

    int maxWater = 0;
    for (int i = 1; i < noOfBridges - 1; i++)
    {
        if (leftMax[i] != -1 && rightMax[i] != -1)
        {
            int minOfMaxBridges = min(leftMax[i], rightMax[i]);
            int waterStore = minOfMaxBridges - bridges[i];
            maxWater += waterStore;
        }
    }
    return maxWater;
    }
};