class Solution {
public:
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string begin;
    int sz;

    void dfs(string word, vector<string>& path) {
        if (word == begin) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        int steps = mpp[word];

        for (int i = 0; i < sz; i++) {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == original) continue;

                word[i] = ch;

                if (mpp.count(word) && mpp[word] + 1 == steps) {
                    path.push_back(word);
                    dfs(word, path);
                    path.pop_back();
                }
            }

            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord))
            return {};

        begin = beginWord;
        sz = beginWord.length();

        queue<string> q;
        q.push(beginWord);

        mpp[beginWord] = 1;
        st.erase(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int n = q.size();

            vector<string> usedThisLevel;

            while (n--) {
                string word = q.front();
                q.pop();

                int steps = mpp[word];

                for (int i = 0; i < sz; i++) {
                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == original) continue;

                        word[i] = ch;

                        if (st.count(word)) {
                            if (!mpp.count(word)) {
                                mpp[word] = steps + 1;
                                q.push(word);
                                usedThisLevel.push_back(word);
                            }

                            if (word == endWord)
                                found = true;
                        }
                    }

                    word[i] = original;
                }
            }

            for (auto &x : usedThisLevel)
                st.erase(x);
        }

        if (!mpp.count(endWord))
            return {};

        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, path);

        return ans;
    }
};