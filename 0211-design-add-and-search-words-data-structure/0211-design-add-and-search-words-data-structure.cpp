class TrieNode {
public:
    vector<TrieNode*> child;
    bool isWord;
    TrieNode(){
        isWord=0;
        child.resize(26);
    }
};

class WordDictionary {
public:
    TrieNode* root=new TrieNode();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        auto node=root;
        for(auto ch:word){
            if(!node->child[ch-'a'])
                node->child[ch-'a']=new TrieNode();
            node=node->child[ch-'a'];
        }
        node->isWord=1;
    }
    
    bool search(string word) {
        return search(word,0,root);
    }
    
    bool search(string &word, int pos, TrieNode* node){
        if(pos==word.size())
            return node->isWord;
        if(word[pos]!='.'){
            node=node->child[word[pos]-'a'];
            if(!node)
                return 0;
            return search(word,pos+1,node);
        }
        for(int i=0;i<26;i++){
            if(node->child[i]&&search(word,pos+1,node->child[i]))
                return 1;
        }
        return 0;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */