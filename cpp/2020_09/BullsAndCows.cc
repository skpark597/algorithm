/* 299. Bulls and Cows */
/* You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. 
 * Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") 
 * and how many digits match the secret number but locate in the wrong position (called "cows"). 
 * Your friend will use successive guesses and hints to eventually derive the secret number.
 * Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 
 * Please note that both secret number and friend's guess may contain duplicate digits.
 *
 * Example 1:
 * Input: secret = "1807", guess = "7810"
 * Output: "1A3B"
 * Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
 * 
 * Example 2:
 * Input: secret = "1123", guess = "0111"
 * Output: "1A1B"
 * Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
 * 
 * Note: You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.**/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string getHint(string secret, string guess) {
    vector<int> count (10, 0);
    vector<int> nonBull;
    string answers;
    int bullCount = 0;
    int cowCount = 0;

    // 각 숫자들의 개수를 count에 저장
    for (int i=0; i< secret.length(); ++i) {
        int num = secret[i]-'0';
        count[num]++;
    }

    // bull이 되는 숫자들을 찾고, 아닌 숫자들을 nonBull에 세팅
    for (int i=0; i < guess.length(); ++i) {
        int num = guess[i]-'0';
        if (secret[i] == guess[i]) {
            bullCount++;
            count[num]--;
        } else {
            nonBull.push_back(num);
        }
    }

    // nonBull에서 cow가 될 수 있는 숫자들을 찾음
    for (int &iter : nonBull) {
        if (count[iter] > 0) {
            cowCount++;
            count[iter]--;
        }
    }

    answers = to_string(bullCount) + "A" + to_string(cowCount) + "B";
    return answers;
}

int main() {
    //string secret = "1123";
    //string guess = "0111";

    string secret = "1122";
    string guess = "1222";

    string answer = getHint(secret, guess);
    cout << answer << endl;

    return 0;
}