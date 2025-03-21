#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
    unordered_map<string, int> inDegree;
    unordered_map<string, unordered_set<string>> adjGraph;

    void createGraph(vector<string>& recipes, vector<vector<string>>& ingredients) {
        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = ingredients[i].size();
            for (auto& curRecipeIngredient : ingredients[i]) {
                adjGraph[curRecipeIngredient].insert(recipes[i]);
            }
        }
    }

   public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        createGraph(recipes, ingredients);

        unordered_set<string> recipesMade;
        queue<string> zeroIndegQ;
        for (auto& supply : supplies) zeroIndegQ.push(supply);

        while (!zeroIndegQ.empty()) {
            string curIng = zeroIndegQ.front();
            zeroIndegQ.pop();
            for (string dep : adjGraph[curIng]) {
                inDegree[dep]--;
                if (inDegree[dep] == 0) {
                    zeroIndegQ.push(dep);
                    recipesMade.insert(dep);
                }
            }
        }

        vector<string> allRecipes;
        for (string& r : recipes) {
            if (recipesMade.find(r) != recipesMade.end()) allRecipes.push_back(r);
        }
        return allRecipes;
    }
};

int main() {
    vector<tuple<vector<string>, vector<vector<string>>, vector<string>>> testCases = {
        {{"bread"}, {{"yeast", "flour"}}, {"yeast", "flour", "corn"}},
        {{"bread", "sandwich"}, {{"yeast", "flour"}, {"bread", "meat"}}, {"yeast", "flour", "meat"}},
        {{"bread", "sandwich", "burger"}, {{"yeast", "flour"}, {"bread", "meat"}, {"sandwich", "meat", "bread"}}, {"yeast", "flour", "meat"}},
    };
    for (auto& t : testCases) {
        printVector(Solution().findAllRecipes(get<0>(t), get<1>(t), get<2>(t)));
    }
}
