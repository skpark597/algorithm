/* 93. Restore IP Address */
/** Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.
 *  A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros. 
 *  For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 
 * 
 *  Example 1:
 *  Input: s = "25525511135"
 *  Output: ["255.255.11.135","255.255.111.35"]
 *  
 *  Example 2:
 *  Input: s = "0000"
 *  Output: ["0.0.0.0"]
 * 
 *  Example 3:
 *  Input: s = "1111"
 *  Output: ["1.1.1.1"]
 * 
 *  Example 4:
 *  Input: s = "010010"
 *  Output: ["0.10.0.10","0.100.1.0"]
 * 
 *  Example 5:
 *  Input: s = "101023"
 *  Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 *  
 *  Constraints:
 *  0 <= s.length <= 3000
 *  s consists of digits only **/

#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<string> backtracking(const string &s, int start, int dotCount) {
    vector<string> ret;
    int length = s.length()-start;
    int num = min(3, length);

    if (dotCount == 0) {
        string temp = s.substr(start, length);
        if (length <= 0 || length > 3 || (length > 1 && s[start] == '0')) return ret;
        if (stoi(temp) < 0 || stoi(temp) > 255) return ret;
        ret.push_back (s.substr(start, length));

        return ret;
    }

    for (int i = 1; i <= num; ++i) {
        string temp;
        for (int j = 0; j < i; ++j) {
            temp += s[start+j];
        }

        if (s[start] == '0' && i != 1) break;
        if (stoi(temp) < 0 || stoi(temp) > 255) break;

        vector<string> prevRet = backtracking(s, start+i, dotCount-1);
        for (string iter : prevRet) {
            ret.push_back(temp + "." + iter);
        }
    }

    return ret;
}

vector<string> restoreIpAddresses(string s) {
    if (s.length() > 12 || s.length() < 4) return vector<string>();

    return backtracking(s, 0, 3);
}

int main() {
    string s0 = "25525511135";
    vector<string> ans0 = restoreIpAddresses(s0);

    string s1 = "0000";
    vector<string> ans1 = restoreIpAddresses(s1);

    string s2 = "010010";
    vector<string> ans2 = restoreIpAddresses(s2);

    string s3 = "101023";
    vector<string> ans3 = restoreIpAddresses(s3);

    for (string iter : ans0) {
        cout << iter << " ";
    }
    cout << endl;

    for (string iter : ans1) {
        cout << iter << " ";
    }
    cout << endl;

    for (string iter : ans2) {
        cout << iter << " ";
    }
    cout << endl;

    for (string iter : ans3) {
        cout << iter << " ";
    }
    cout << endl;


    return 0;
}


