class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes,
                                      vector<vector<string>>& ingredients,
                                      vector<string>& supplies) {
            vector<string> possibleRecipes;
            unordered_map<string, bool> canMake;
            unordered_map<string, int> recipeToIndex;
    
            for (const string& supply : supplies) {
                canMake[supply] = true;
            }
    
            for (int idx = 0; idx < recipes.size(); idx++) {
                recipeToIndex[recipes[idx]] = idx;
            }
    
            for (const string& recipe : recipes) {
                unordered_set<string> visited;
                checkRecipe(recipe, ingredients, visited, canMake, recipeToIndex);
                if (canMake[recipe]) {
                    possibleRecipes.push_back(recipe);
                }
            }
    
            return possibleRecipes;
        }
    
    private:
        void checkRecipe(const string& recipe, vector<vector<string>>& ingredients,
                         unordered_set<string>& visited,
                         unordered_map<string, bool>& canMake,
                         unordered_map<string, int>& recipeToIndex) {
            if (canMake.find(recipe) != canMake.end()) {
                return;
            }
    
            auto idxIt = recipeToIndex.find(recipe);
            if (idxIt == recipeToIndex.end() || visited.count(recipe)) {
                canMake[recipe] = false;
                return;
            }
    
            visited.insert(recipe);
    
            for (const string& ingredient : ingredients[idxIt->second]) {
                checkRecipe(ingredient, ingredients, visited, canMake,
                            recipeToIndex);
                if (!canMake[ingredient]) {
                    canMake[recipe] = false;
                    return;
                }
            }
    
            canMake[recipe] = true;
        }
    };