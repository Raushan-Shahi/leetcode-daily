// There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

// You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). 
// You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

// A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for
//  every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

// Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

 






class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(),k=26;
        vector<int> indegrees(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            indegrees[v]++;
        }
        unordered_set<int> zero_indegree;
        for (int i = 0; i < n; i++) {
            if (indegrees[i] == 0) {
                zero_indegree.insert(i);
            }
        }
        vector<vector<int>> counts(n, vector<int>(k, 0));
        for (int i = 0; i < n; i++) {
            counts[i][colors[i] - 'a']++;
        }
        int max_count = 0,visited = 0;
        while (!zero_indegree.empty()) {
            int u = *zero_indegree.begin();
            zero_indegree.erase(u);
            visited++;
            for (int v : graph[u]) {
                for (int i = 0; i < k; i++)
                    counts[v][i] = max(counts[v][i], counts[u][i] + (colors[v] - 'a' == i ? 1 : 0));
                indegrees[v]--;
                if (indegrees[v] == 0) {
                    zero_indegree.insert(v);
                }
            }
            max_count = max(max_count, *max_element(counts[u].begin(), counts[u].end()));
        }
        return visited == n ? max_count : -1;
    }
};