#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited)
    {
        visited[u] = true;
        for (int v : graph[u])
        {
            if (!visited[v])
            {
                dfs(v, graph, visited);
            }
        }
    }

    bool hasPathBetweenAllPairs(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<bool> visited(n, false);

        // for (int u = 0; u < n; ++u)
        // {
        //     if (!visited[u])
        //     {
                dfs(0, graph, visited);
        //     }
        // }

        for (bool nodeVisited : visited)
        {
            if (!nodeVisited)
            {
                return false;
            }
        }

        return true;
    }

    void print(vector<vector<int>> &ans)
    {
        cout << "Start: \n";
        
        for(auto &i: ans)
        {
            for(auto &j: i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << "End!\n";
    }

    bool canTraverseAllPairs(vector<int> &nums)
    {
        vector<vector<int>> graph(nums.size());

        for (int i = 0; i < nums.size(); ++i)
        {
            // graph[i].push_back(i);
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (__gcd(nums[i], nums[j]) > 1)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        print(graph);

        return hasPathBetweenAllPairs(graph);
    }
};

int main()
{
    Solution obj;

    // vector<int> nums = {2,3,6,9,2,3,6,9};
    // vector<int> nums = {2,3,6};
    vector<int> nums = {3, 9, 5};
    // vector<int> nums = {4,3,12,8};
    cout << obj.canTraverseAllPairs(nums);

    return 0;
}