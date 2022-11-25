#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class TrieNode
{
    public:
    unordered_map<char, TrieNode *> children;
    bool endOfWord;

    TrieNode(bool endOfWord = false) {
        this->endOfWord = endOfWord;
    }
};

class Trie
{
    TrieNode *root;

    public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string s) {
        TrieNode *ptr = root;

        for (char c : s) {
            if (ptr->children.find(c) == ptr->children.end()) ptr->children[c] = new TrieNode();
            ptr = ptr->children[c];
        }
        ptr->endOfWord = true;
    }

    bool search(string s) {
        TrieNode *ptr = root;

        for (char c : s) {
            if (ptr->children.find(c) == ptr->children.end()) return false;
            ptr = ptr->children[c];
        }

        return ptr->endOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode *ptr = root;

        for (char c : prefix) {
            if (ptr->children.find(c) == ptr->children.end()) return false;
            ptr = ptr->children[c];
        }

        return true;
    }
};

int main() {
    Trie *t1 = new Trie();
    t1->insert("apple");
    cout << t1->search("apple") << endl; // True
    cout << t1->search("app") << endl; // False
    cout << t1->startsWith("app") << endl; // True
    t1->insert("app");
    cout << t1->search("app") << endl; // True
}