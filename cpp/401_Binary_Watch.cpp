class Solution {
private:
    vector<string> res;

    void dfs(int idx, int turnedOn, int h, int m) {
        if (h > 11 || m > 59) return;

        if (turnedOn == 0) {
            string time = to_string(h) + ":";
            if (m < 10) time += "0";
            time += to_string(m);
            res.push_back(time);
            return;
        }

        if (idx == 10) return;

		// 2 choices at LED, take or skip (decision tree)

        // option 1: skip this LED
        dfs(idx + 1, turnedOn, h, m);

        // option 2: take this LED
        if (idx < 4)
            dfs(idx + 1, turnedOn - 1, h + (1 << idx), m);
        else
            dfs(idx + 1, turnedOn - 1, h, m + (1 << (idx - 4)));

		// 0 1 2 3				  -- hours
		//		   4 5 6 7 8 9 10 -- mins
    }

public:
    vector<string> readBinaryWatch(int turnedOn) {
        res.clear();
        dfs(0, turnedOn, 0, 0);
        return res;
    }
};
