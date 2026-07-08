class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int r = 0, i = 0;

        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;

            if (i == n)
                break;

            int start = r;
            while (i < n && s[i] != ' ')
                s[r++] = s[i++];
            reverse(s.begin() + start, s.begin() + r);
            s[r++] = ' ';
        }
        s.resize(r - 1);
        reverse(s.begin(), s.end());

        return s;
    }
};