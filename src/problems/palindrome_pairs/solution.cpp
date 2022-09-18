struct trieNode {
    int index = -1;
    bool isWord = false;
    trieNode* next[26] = {0};
    vector<int> strPosition;
};

class Solution {
    trieNode* root;
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        root = new trieNode();
        
        for (int i = 0; i < words.size(); ++i)
            insertTrie(words[i], i);
        
        for (int i = 0; i < words.size(); ++i) {
            trieNode* currentNode = root;
            
            // currentNode不是空指標 && 字元還沒跑完
            for (int pos = words[i].size()-1; pos >= 0 && currentNode; --pos) {
                if (currentNode->isWord && currentNode->index != i && isValid(words[i], 0, pos))
                    // 當前word會是合併的後面的字串
                    ans.push_back({currentNode->index, i});
                // 如果currentNode被指派下個位置時，變成NULL，那麼就代表words[i]還有字元沒判斷
                currentNode = currentNode->next[words[i][pos]-'a'];
            }
            
            if (!currentNode) continue;  // 配合word的trie沒東西了
            
            // 如果兩個字串長度一樣會到這邊(insertTrie的時候每個字串都有加進去了)
            // j裡面會是當前字元往後會有的所有回文的位置
            for (const auto &j : currentNode->strPosition) {
                if (i != j)
                    ans.push_back({j, i});
            }
        }
        
        return ans;
    }
    
    bool isValid(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
    
    void insertTrie(const string& word, int index) {
        trieNode* currentNode = root;

        int strLen = word.size();
        for (int i = 0; i < strLen; ++i) {
            int pos = word[i]-'a';
            
            // 判斷每個位置以後(包含當前位置)是否為回文，並記錄位置
            if (isValid(word, i, word.size()-1))
                currentNode->strPosition.push_back(index);
            if (currentNode->next[pos] == nullptr)
                currentNode->next[pos] = new trieNode();
            currentNode = currentNode->next[pos];
        }
        
        currentNode->index = index;
        currentNode->isWord = true;
        currentNode->strPosition.push_back(index);
    }
};