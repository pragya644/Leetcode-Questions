class FoodRatings {
public:
    
    unordered_map<string,int> food_rat;
    unordered_map<string,string> food_cus;
    unordered_map<string,set<pair<int,string>>> cusi;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0; i<n; i++){
            food_rat[foods[i]] = ratings[i];
            food_cus[foods[i]] = cuisines[i];
            cusi[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto c = food_cus[food];
        int rat = food_rat[food];
        cusi[c].erase({-rat,food});
        cusi[c].insert({-newRating,food});
        food_rat[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto it = cusi[cuisine].begin();
        return it->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */