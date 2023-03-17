class TrieNode {
public:
    bool isWord;
    vector<TrieNode*> children;
    TrieNode() {
        isWord=0;
        children.resize(26);
    }
};

class Trie {
public:
    TrieNode* root=new TrieNode();
    Trie() {
        
    }
    
    void insert(string s) {
        auto p=root;
        for(int i=0;i<s.size();i++){
            if(p->children[s[i]-'a']==NULL)
                p->children[s[i]-'a']=new TrieNode();
            p=p->children[s[i]-'a'];
        }
        p->isWord=1;
    }
    
    bool search(string s) {
        auto p=root;
        for(int i=0;i<s.size();i++){
            if(p->children[s[i]-'a']==NULL)
                return 0;
            p=p->children[s[i]-'a'];
        }
        return p->isWord;
    }
    
    bool startsWith(string s) {
        auto p=root;
        for(int i=0;i<s.size();i++){
            if(p->children[s[i]-'a']==NULL)
                return 0;
            p=p->children[s[i]-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */