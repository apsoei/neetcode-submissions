class Solution {
public:
    bool isValid(string s) {
        string st;

        unordered_map<char, char> mp;
        mp['{'] = '}';
        mp['['] = ']';
        mp['('] = ')';

        for (char& c : s) {
            if (mp.count(c)) {
                st += c;
            } else if (st.empty() || mp[st.back()] != c) {
                return false;
            } else {
                st.pop_back();
            }
        }

        return st.empty();
    }
};
