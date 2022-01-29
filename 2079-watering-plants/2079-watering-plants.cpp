class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int count = 0;
        int temp = 0;
        int amount = capacity;
        for(int i=0; i<plants.size(); i++)
        {
            if(plants[i]<=amount)
            {
                temp++;
                amount = amount-plants[i];
            }
            else
            {
                count += temp+temp;
                amount = capacity;
                i--;
            }
        }
        count += temp;
        return count;
    }
};