from collections import defaultdict

class Solution:
    def find(self, e, parent):
        if e not in parent:
            parent[e] = e
        if parent[e] == e:
            return e
        parent[e] = self.find(parent[e], parent)
        return parent[e]
    
    def unite(self, e1, e2, parent):
        p1 = self.find(e1, parent)
        p2 = self.find(e2, parent)
        if p1 == p2:
            return
        parent[p1] = p2
    
    def accountsMerge(self, accounts):
        parent = {}
        email_to_name = {}

        for acc in accounts:
            name = acc[0]
            first = acc[1]
            email_to_name[first] = name
            for email in acc[2:]:
                self.unite(first, email, parent)
                email_to_name[email] = name
        
        groups = defaultdict(list)
        for email in email_to_name:
            root = self.find(email, parent)
            groups[root].append(email)
        
        ret = []
        for root, emails in groups.items():
            emails.sort()
            ret.append([email_to_name[root]] + emails)
        
        return ret
