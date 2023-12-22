
/**
 * 艹！做了这么久tmd最后还是超时了
 * */

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    string s;
    vector<string>ans;
    vector<int>ret;
    void computeNext(const string& pattern, vector<int>& next) {
        int m = pattern.length();
        next.resize(m + 1);
        int i = 0, j = -1;
        next[0] = -1;

        while (i < m) {
            if (j == -1 || pattern[i] == pattern[j]) {
                i++;
                j++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
    }

    vector<int> KMP(const string& text, const string& pattern) {
        int n = text.length();
        int m = pattern.length();
        vector<int> next, positions;
        computeNext(pattern, next);
        int i = 0, j = 0;

        while (i < n) {
            if (j == -1 || text[i] == pattern[j]) {
                i++;
                j++;
                if (j == m) {
                    positions.push_back(i - m);
                    j = next[j];
                }
            } else {
                j = next[j];
            }
        }

        return positions;
    }
    void dfs(int pos,vector<string>words,vector<bool>flag,int n)

    {
        if(pos == n)
        {
            ans.push_back(s);
            return;
        }
        string tmp = s;
        for(int i = 0; i < n;i++)
        {
            if(flag[i])continue;
            flag[i] = true;
            s.append(words[i]);

            dfs(pos + 1,words,flag,n);
            s = tmp;

            flag[i] = false;
        }

    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        vector<bool>flag(n + 1,false);
        dfs(0,words,flag,n);
        vector<int> matches; // 存储所有KMP匹配位置

        for(int i = 0; i < ans.size(); i++) {
            matches = KMP(s, ans[i]); // KMP返回一个vector

            // 将返回的所有匹配加入ret
            ret.insert(ret.end(), matches.begin(), matches.end());
        }
        set<int>sett(ret.begin(),ret.end());
        ret.assign(sett.begin(),sett.end());
        return ret;

    }
};
int main() {

    string s = "barfoothefoobarman";
    vector<string> words {"foo","bar"};

    Solution sol;
    vector<int> result = sol.findSubstring(s, words);

    for(int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
