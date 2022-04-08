// struct TrieNode
// {
//     TrieNode *child[26];
//     bool isend;
//     TrieNode() 
//     {
//         isend=false;
//         for(int i=0;i<26;i++)
//         {
//             child[i]=nullptr;
//         }
//     }
// };

class Trie {
public:

    struct TrieNode
    {
        struct TrieNode *child[26];
        bool isend;
    };
    
     TrieNode* root;
    
    
    Trie() 
    {
        root=new TrieNode();
    }
    
    void insert(string word) 
    {
        TrieNode *curr=root;
        
        for(int i=0;i<word.length();i++)
        {
            int ind=word[i]-'a';
            
            if(curr->child[ind]==nullptr)
            {
                curr->child[ind]=new TrieNode();
            }
            
            curr=curr->child[ind];
        }
        
        curr->isend=true;
    }
    
    bool search(string word) 
    {
        TrieNode *curr=root;
        
        for(int i=0;i<word.length();i++)
        {
            int ind=word[i]-'a';
            
            if(curr->child[ind]==nullptr)
            {
                return false;
            }
            
            curr=curr->child[ind];
        }
        
        return curr->isend;
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode *curr=root;
        
        for(int i=0;i<prefix.length();i++)
        {
            int ind=prefix[i]-'a';
            
            if(curr->child[ind]==nullptr)
            {
                return false;
            }
            
            curr=curr->child[ind];
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