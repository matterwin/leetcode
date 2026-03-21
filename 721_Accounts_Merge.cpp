#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string find (string e1, unordered_map<string, string>& parent)
    {
        if (!parent.count(e1)) parent[e1] = e1;
        if (e1 == parent[e1]) return e1;
        return parent[e1] = find(parent[e1], parent);
    }
    void unite(string e1, string e2, unordered_map<string, string>& parent)
    {
        string e1p = find(e1, parent);  
        string e2p = find(e2, parent);  

        if (e1p == e2p)
            return;

        parent[e1p] = e2p;
    }
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string,string> parent, email_to_name;

    // Union all emails in each account
    for (auto& acc : accounts) {
        string name = acc[0];
        string first = acc[1];
        email_to_name[first] = name;
        for (int i = 2; i < acc.size(); ++i) {
            unite(first, acc[i], parent);
            email_to_name[acc[i]] = name;
        }
    }

    // Build root → emails map
    unordered_map<string, vector<string>> groups;
    for (auto& [email, name] : email_to_name) {
        groups[find(email, parent)].push_back(email);
    }

    // Build result
    vector<vector<string>> ret;
    for (auto& [root, emails] : groups) {
        sort(emails.begin(), emails.end());
        emails.insert(emails.begin(), email_to_name[root]); // prepend name
        ret.push_back(move(emails));
    }

    return ret;
    }
};
