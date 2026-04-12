class Solution {
public:
    vector<int> parent = vector<int>(26);

    int find(int n) 
    {
        if (n == parent[n])
            return n;
        return parent[n] = find(parent[n]);
    }

    void unite(int x, int y)
    {
        int x_p = find(x), y_p = find(y);
        if (x_p != y_p)
            parent[y_p] = x_p;
    }

    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) parent[i] = i;

        for (string& eq : equations) 
        {
            if (eq[1] == '=') 
            {
                int lhs = eq[0] - 'a';
                int rhs = eq[3] - 'a';
                unite(lhs, rhs);
            }
        }

        for (string& eq : equations) 
        {
            if (eq[1] == '!')
            {
                int lhs = eq[0] - 'a';
                int rhs = eq[3] - 'a';
                if (find(lhs) == find(rhs)) return false;
            }
        }

        return true;
    }
};

