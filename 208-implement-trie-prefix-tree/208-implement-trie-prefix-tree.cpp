class TrieNode
{
  public:
    TrieNode*child[26];
    bool isend;
    TrieNode()
    {
       isend = false;
       for(int i=0; i<26; i++)
           child[i] = NULL;
    }
};

class Trie {
public:
    TrieNode*root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode*curr = root;
        for(int i=0; i<word.length(); i++)
        {
            int idx = word[i]-'a';
            if(curr->child[idx]==NULL)
                curr->child[idx] = new TrieNode();
            curr = curr->child[idx];
        }
        curr->isend = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.length(); i++)
        {
            int idx = word[i]-'a';
            if(curr->child[idx]==NULL)
                return false;
            curr = curr->child[idx];
        }
        return curr->isend;
    }
    
    bool startsWith(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.length(); i++)
        {
            int idx = word[i]-'a';
            if(curr->child[idx]==NULL)
                return false;
            curr = curr->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */