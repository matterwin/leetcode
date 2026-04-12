class Solution {
public:
    void dfs(int cur, vector<vector<int>>& rooms, vector<bool>& done)
    {
        if (done[cur]) return;

        done[cur] = true;
        for (int next : rooms[cur])
            dfs(next, rooms, done);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> done(rooms.size());
        dfs(0, rooms, done);

        for (int node : done)
            if (!node) return false;
        return true;
    }
};

