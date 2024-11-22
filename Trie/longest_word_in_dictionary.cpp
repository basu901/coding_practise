
#include<vector>
#include<string>

class Solution {
public:
    std::string max_len_word = "";
    
    struct Node{
        std::vector<Node*> children{26,nullptr};
        char c;
    };

    Node* root = new Node();

    void insert(std::string word){
        //cout<<"In insert"<<endl;
        Node* cur=root;
        for(int i=0;i<word.size();i++){
            if(cur->children[word[i]-'a']==nullptr)
             {
                if(word.size()==1)
                {
                    Node* n=new Node();
                    n->c = word[i];
                    cur->children[word[i]-'a'] = n;
                }
                else if(i==word.size()-1)
                {
                    Node* n = new Node();
                    n->c = word[i];
                    cur->children[word[i]-'a'] = n;   
                }
                else
                    return;
             }

            cur=cur->children[word[i]-'a']; 
        }

        if(word.size()>max_len_word.size())
            max_len_word = word;

        if(word.size()==max_len_word.size()){
            if(word<max_len_word)
                max_len_word = word;
        }
    }

    static bool comp(const std::string& a, const std::string& b){
        if(a.size()==b.size())
            return a<b;
        else
            return a.size()<b.size();
    }

    std::string longestWord(std::vector<std::string>& words) {
        
        sort(words.begin(),words.end(),comp);
        //cout<<words[0]<<endl;
        if(words[0].size()>1)
            return max_len_word;

        for(std::string word: words){
            insert(word);
        }

        return max_len_word;
    }
};