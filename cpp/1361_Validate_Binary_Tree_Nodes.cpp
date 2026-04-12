class Solution 
{
public:
    bool dfs(int cur, vector<bool>& visited, 
             vector<int>& leftChild, vector<int>& rightChild)
    {
        if (cur == -1) return true;

        // cycle
        if (visited[cur]) return false;

        visited[cur] = true;

        return dfs(leftChild[cur], visited, leftChild, rightChild) &&
               dfs(rightChild[cur], visited, leftChild, rightChild);
    }

    bool validateBinaryTreeNodes(int n, 
                                 vector<int>& leftChild, 
                                 vector<int>& rightChild) 
    {
        vector<int> indeg(n, 0);

        for (int i = 0; i < n; ++i)
        {
            if (leftChild[i] != -1)
            {
                indeg[leftChild[i]]++;
                if (indeg[leftChild[i]] > 1) return false;
            }

            if (rightChild[i] != -1)
            {
                indeg[rightChild[i]]++;
                if (indeg[rightChild[i]] > 1) return false;
            }
        }

        int root = -1;
        int rootCount = 0;

        for (int i = 0; i < n; ++i)
        {
            if (indeg[i] == 0)
            {
                root = i;
                rootCount++;
            }
        }

        if (rootCount != 1) 
            return false;

        vector<bool> visited(n, false);

        if (!dfs(root, visited, leftChild, rightChild)) return false;

        // connectivity
        for (bool v : visited)
            if (!v) return false;

        return true;
    }
};
