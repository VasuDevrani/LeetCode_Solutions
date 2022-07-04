// all operations are O(n) time complexity

class Node{
    Node*links[26]; //array of pointers with address to other trie nodes
    bool flag = false;
    
    public:
    bool contains(char ch){
        return (links[ch - 'a'] != NULL);
    }
    void putNew(char ch, Node*node){
        links[ch - 'a'] = node;
    }
    Node*get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
    Node*root;
    
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node*node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!(node -> contains(word[i]))){ //if the node does not contain the letter
                node -> putNew(word[i], new Node());
            }
//             move to reference node
            node = node -> get(word[i]);
        }
//         finally mark the last node as true
        node -> setEnd();
    }
    
    bool search(string word) {
        Node*node = root;
        for(int i=0;i<word.length();i++)
        {
            if((!node -> contains(word[i])))
                return false;
            node = node -> get(word[i]);
        }
        
//         final check if reference node is true
        return node -> isEnd();
    }
    
    bool startsWith(string prefix) {
        Node*node = root;
        for(int i=0;i<prefix.length();i++)
        {
            if((!node -> contains(prefix[i])))
                return false;
            node = node -> get(prefix[i]);
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