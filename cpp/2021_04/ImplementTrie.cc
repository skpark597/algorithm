/* Implement Trie (Prefix Tree) */
/** A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve 
 *  keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.
 *  Implement the Trie class:
 *  
 *  Trie() Initializes the trie object.
 *  void insert(String word) Inserts the string word into the trie.
 *  boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
 *  boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 * 
 *  Example 1:
 *  Input
 *  ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 *  [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 *  Output
 *  [null, null, true, false, true, null, true]
 * 
 *  Explanation
 *  Trie trie = new Trie();
 *  trie.insert("apple");
 *  trie.search("apple");   // return True
 *  trie.search("app");     // return False
 *  trie.startsWith("app"); // return True
 *  trie.insert("app");
 *  trie.search("app");     // return True
 * 
 *  Constraints:
 *  1 <= word.length, prefix.length <= 2000
 *  word and prefix consist only of lowercase English letters.
 *  At most 3 * 10^4 calls in total will be made to insert, search, and startsWith. **/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAX_NUMBER = 26;

class Trie {
private:
    Trie *next[MAX_NUMBER];
    bool exist;

    void insertInternal(const char *word) {
        if (*word == 0) {
            exist = true;
            return;
        }

        if (next[*word-'a'] == nullptr) next[*word-'a'] = new Trie();
        next[*word-'a']->insertInternal(word+1);
    }

    bool searchInternal(const char *word, bool search) {
        if (*word == 0) {
            return search ? exist : true;
        }

        if (next[*word-'a'] == nullptr) return false;
        return next[*word-'a']->searchInternal(word + 1, search);
    }

public:
    /** Initialize your data structure here. */
    Trie() {
        memset(next, 0, sizeof(next));
        exist = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertInternal(word.c_str());
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchInternal(word.c_str(), true);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return searchInternal(prefix.c_str(), false);
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    bool test0 = trie.search("apple");   
    bool test1 = trie.search("app");     
    bool test2 = trie.startsWith("app"); 
    trie.insert("app");
    bool test3 = trie.search("app");     

    cout << test0 << endl; // true
    cout << test1 << endl; // false
    cout << test2 << endl; // true
    cout << test3 << endl; // true
  
    return 0;
}

