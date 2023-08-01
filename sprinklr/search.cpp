#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int frequency;

    TrieNode() : frequency(0) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& str, int freq) {
        TrieNode* current = root;
        for (char c : str) {
            if (!current->children[c]) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->frequency = freq;
    }

    int queryPrefixFrequency(const string& prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            if (!current->children[c]) {
                return 0;
            }
            current = current->children[c];
        }
        return current->frequency;
    }

    void updateFrequency(const string& str, int newFreq) {
        TrieNode* current = root;
        for (char c : str) {
            if (!current->children[c]) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->frequency = newFreq;
    }
};

int main() {
    Trie trie;

    // Query 1: Insert strings and frequencies into the trie
    trie.insert("apple", 5);
    trie.insert("banana", 3);
    trie.insert("orange", 7);

    // Query 2: Get frequency of a prefix string
    string prefix = "app";
    int prefixFrequency = trie.queryPrefixFrequency(prefix);
    cout << "Frequency of prefix '" << prefix << "': " << prefixFrequency << endl;

    // Query 3: Update the frequency of a string
    string strToUpdate = "apple";
    int newFrequency = 10;
    trie.updateFrequency(strToUpdate, newFrequency);
    cout << "Updated frequency of '" << strToUpdate << "': " << newFrequency << endl;

    return 0;
}
