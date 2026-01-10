/* 824. Goat Latin */ 
/** A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.
 *  We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)
 *  The rules of Goat Latin are as follows:
 *  
 *  If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
 *  For example, the word 'apple' becomes 'applema'.
 * 
 *  If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
 *  For example, the word "goat" becomes "oatgma".
 *  
 *  Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
 *  For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
 *  Return the final sentence representing the conversion from S to Goat Latin. 
 * 
 *  Example 1:
 *  Input: "I speak Goat Latin"
 *  Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
 * 
 *  Example 2:
 *  Input: "The quick brown fox jumped over the lazy dog"
 *  Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 * 
 *  Notes:
 *  S contains only uppercase, lowercase and spaces. Exactly one space between each word.
 *  1 <= S.length <= 150. **/

#include <string>
#include <vector>

using namespace std;

vector<string> getToken(const string &S) {
    vector<string> tokens;
    int start = 0;

    for (int i=0; i < S.length(); ++i) {
        char ith = S[i];
        if (ith == ' ') {
            tokens.push_back(S.substr(start, i-start));
            start = i+1;
        } else if (i == S.length()-1) {
            tokens.push_back(S.substr(start, i-start+1));
        }
    }

    return tokens;
}

bool isVowel (char word) {
    if (word == 'a' || word == 'e' || word == 'i' || word == 'o' || word =='u' ||
        word == 'A' || word == 'E' || word == 'I' || word == 'O' || word == 'U')
        return true;

    return false;
}

string toGoatLatin(string S) {
    vector<string> tokens = getToken(S);
    vector<string> goatLatin;
    string answer;

    for (int i=0; i < tokens.size(); ++i) {
        string ithToken = tokens[i];

        if (!isVowel(ithToken[0])) {
            char first = ithToken[0];
            ithToken.erase(ithToken.begin());
            ithToken = ithToken + first;
        }
        
        ithToken.append("ma");
        for (int j=0; j < i+1; ++j) {
            ithToken.append("a");
        }

        goatLatin.push_back(ithToken);
        
        if (i == tokens.size()-1) answer += ithToken;
        else answer += ithToken + " ";
    }

    return answer;
}


int main() {
    //string test = "I speak Goat Latin";
    string test = "The quick brown fox jumped over the lazy dog";
    string answer = toGoatLatin(test);

    return 0;
}








