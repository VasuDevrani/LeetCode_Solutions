struct Node{
    Node* links[26];
    bool isWord = false;
    
    bool contains(char ch){
        return links[ch-'a'] != NULL;
    }
    
    void addNew(char ch){
        links[ch-'a'] = new Node();
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        isWord = true;
    }
};

class Solution {
public:
    string addWord(Node* node, const string&word, string longestPrefix)
    {
        for(char ch : word)
        {
            if(node -> contains(ch))
            {
                longestPrefix += ch;
            }
            if(!node -> contains(ch))
            {
                node->addNew(ch);
            }
            node = node -> get(ch);
        }
        
        node -> setEnd();
        
        return longestPrefix;
    }
    string longestCommonPrefix(vector<string>& strs) {
        
        Node* head = new Node();
        string ans = strs[0];
        
        for(int i=0;i<strs.size();i++)
        {
            string s = strs[i];
            Node*root = head;
            
            string longestPrefix = addWord(root, s, "");
            
            if(i > 0)
            {
                ans = ans.size() < longestPrefix.size() ? ans : longestPrefix;
            }
        }
        return ans;
    }
};