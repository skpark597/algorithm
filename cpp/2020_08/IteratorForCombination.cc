/* 1286. Iterator for Combination */
/** Design the CombinationIterator class:
 *  CombinationIterator(string characters, int combinationLength) Initializes the object with a string 
 *  characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
 *  next() Returns the next combination of length combinationLength in lexicographical order.
 *  hasNext() Returns true if and only if there exists a next combination.
 * 
 *  Example 1:
 *  Input
 *  ["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
 *  [["abc", 2], [], [], [], [], [], []]
 *  Output
 *  [null, "ab", true, "ac", true, "bc", false]
 * 
 *  Explanation
 *  CombinationIterator itr = new CombinationIterator("abc", 2);
 *  itr.next();    // return "ab"
 *  itr.hasNext(); // return True
 *  itr.next();    // return "ac"
 *  itr.hasNext(); // return True
 *  itr.next();    // return "bc"
 *  itr.hasNext(); // return False
 * 
 *  Constraints:
 *  1 <= combinationLength <= characters.length <= 15
 *  All the characters of characters are unique.
 *  At most 104 calls will be made to next and hasNext.
 *  It's guaranteed that all calls of the function next are valid. **/

#include <queue>
#include <string>

using namespace std;

class CombinationIterator {
public:
    vector<string>  combinations;
    
    CombinationIterator(string characters, int combinationLength) {
        priority_queue<string> pq;
        setCombination(pq, "", characters, combinationLength);
        int pq_size = pq.size();
        combinations.resize(pq_size);

        for (int i = 0; i< pq_size; ++i) {
            combinations[i] = pq.top();
            pq.pop();
        }
    }
    
    void setCombination(priority_queue<string> &pq, string combination, string characters, int combinationLength) {
        if (combination.length() == combinationLength) {
            pq.push(combination);
            return;
        }

        for (int i=0; i < characters.length(); ++i) {
            if (combination.length() + characters.length()-i >= combinationLength) {
                setCombination(pq, combination + characters[i], characters.substr(i+1, characters.length()-i-1), combinationLength);
            }
        }
    }

    string next() {
        string next = combinations.back();
        combinations.pop_back();
        return next;
    }
    
    bool hasNext() {
        return combinations.size() > 0;
    }
};


int main() {
    CombinationIterator test ("abc",2);
    string first = test.next();
    bool f1 = test.hasNext();
    
    string s = test.next();
    bool s1 = test.hasNext();

    string t = test.next();
    bool t1 = test.hasNext();

    return 0;
}












