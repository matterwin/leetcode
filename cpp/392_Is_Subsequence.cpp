class Solution {
public:
    bool isSubsequence(string s, string t) {
		int sp = 0, tp = 0;			        
		int slen = s.size(), tlen = t.size();

		if (slen > tlen) return false;

		while (sp < slen && tp < tlen) {
			// early break
			if (tlen - tp < slen - sp) return false;
			if (s[sp] == t[tp]) ++sp; 
			++tp;
		}

		return sp == slen;
    }
};

