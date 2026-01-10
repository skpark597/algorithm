/* 735. Asteroid Collision */
/** We are given an array asteroids of integers representing asteroids in a row.
 *  For each asteroid, the absolute value represents its size, and the sign represents 
 *  its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
 *  Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. 
 *  If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
 * 
 *  Example 1:
 *  Input: asteroids = [5,10,-5]
 *  Output: [5,10]
 *  Explanation: The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.
 * 
 *  Example 2:
 *  Input: asteroids = [8,-8]
 *  Output: []
 *  Explanation: The 8 and -8 collide exploding each other.
 * 
 *  Example 3:
 *  Input: asteroids = [10,2,-5]
 *  Output: [10]
 *  Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10. 
 * 
 *  Example 4:
 *  Input: asteroids = [-2,-1,1,2]
 *  Output: [-2,-1,1,2]
 *  Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving right. Asteroids moving the same direction never meet, so no asteroids will meet each other.
 * 
 *  Constraints:
 *  1 <= asteroids <= 104
 *  -1000 <= asteroids[i] <= 1000
 *  asteroids[i] != 0 **/

/* 처음에 내가 생각했던 풀이 - list를 계속 순회하는 방식, 느리긴 한데 Accepted */

#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> answer;
    stack<int> st;
    bool push = false;

    if (asteroids.empty()) return vector<int> ();

    for (int iter : asteroids) {
        push = true;
        if (iter < 0 && !st.empty() && st.top() > 0) {
            while (!st.empty() && st.top() > 0) {
                if (st.top() < -iter) {
                    st.pop();
                } else if (st.top() > -iter) {
                    push = false;
                    break;
                } else {
                    st.pop();
                    push = false;
                    break;
                }
            }
            if (push) st.push(iter);
        } else {
            st.push(iter);
        }
    }

    answer.resize(st.size());

    for (int i = st.size()-1; i >=0; --i) {
        answer[i] = st.top();
        st.pop();
    }

    return answer;
}

int main() {
    vector<int> asteroids {1,-2,-2,-2};
    vector<int> answer = asteroidCollision(asteroids);

    for (int iter : answer) {
        cout << iter << endl;
    }

    return 0;
}















