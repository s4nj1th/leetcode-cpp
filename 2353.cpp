class Food {
public:
    int rating;
    string name;

    Food(int rating, string name) {
        this->rating = rating;
        this->name = name;
    }

    bool operator<(const Food& other) const {
        if (rating == other.rating) {
            return name > other.name;
        }
        return rating < other.rating;
    }
};

class FoodRatings {
    unordered_map<string, int> frht;
    unordered_map<string, string> fcht;
    
    unordered_map<string, priority_queue<Food>> cfht;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            frht[foods[i]] = ratings[i];
            fcht[foods[i]] = cuisines[i];
            cfht[cuisines[i]].push(Food(ratings[i], foods[i]));
        }
    } 
    
    void changeRating(string food, int newRating) {
        frht[food] = newRating;
        auto cuisineName = fcht[food];
        cfht[cuisineName].push(Food(newRating, food));
    }
    
    string highestRated(string cuisine) {
        auto highestRated = cfht[cuisine].top();
        
        while (frht[highestRated.name] != highestRated.rating) {
            cfht[cuisine].pop();
            highestRated = cfht[cuisine].top();
        }
        
        return highestRated.name;
    }
};
