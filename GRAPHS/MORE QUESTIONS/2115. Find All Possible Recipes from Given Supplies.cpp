// 2115. Find All Possible Recipes from Given Supplies
#include <bits/stdc++.h>
using namespace std;

static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<string> findAllRecipes(vector<string> &recipes,
                              vector<vector<string>> &ingredients,
                              vector<string> &supplies)
{
    int n = recipes.size();

    unordered_set<string> st(supplies.begin(), supplies.end());

    // adj List
    unordered_map<string, vector<int>> adj;

    vector<int> indegree(n, 0);
    for (int i = 0; i < n; ++i)
    {
        for (auto ing : ingredients[i])
        {
            if (!st.count(ing))
            {
                adj[ing].push_back(i);
                indegree[i]++;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<string> res;
    while (!q.empty())
    {
        int ingredient = q.front();
        q.pop();
        string recipe = recipes[ingredient];
        res.push_back(recipe);

        for (auto it : adj[recipe])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return res;
}

int main()
{
    // Hardcoded test case
    vector<string> recipes = {"pizza", "sauce", "cheese", "dough", "salad"};
    vector<vector<string>> ingredients = {{"dough", "sauce", "cheese"},
                                          {"tomato", "spices"},
                                          {"milk", "vinegar"},
                                          {"flour", "water"},
                                          {"lettuce", "olive oil"}};
    vector<string> supplies = {"flour", "water", "milk", "vinegar", "lettuce", "olive oil"};

    vector<string> result = findAllRecipes(recipes, ingredients, supplies);

    cout << "Recipes that can be made: ";
    for (const auto &recipe : result)
    {
        cout << recipe << " ";
    }
    cout << "\n";

    return 0;
}

/*
Time Complexity (TC):
- Let 'n' be the number of recipes and 'm' be the total number of ingredients.
- Constructing the adjacency list takes O(n * m) time.
- BFS traversal takes O(n + m) time.
- Overall complexity: O(n * m)

Space Complexity (SC):
- Storage for the adjacency list: O(m)
- Indegree array and result storage: O(n)
- Queue space: O(n)
- Overall space: O(n + m)
*/