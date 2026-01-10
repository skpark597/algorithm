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
#include <list>
#include <iterator>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> answer;
    list<int> asteroid_list;
    list<int>::iterator iter;
    bool no_collision = false;
    
    if (asteroids.empty()) return vector<int> ();

    for (int i = 0; i < asteroids.size(); ++i) {
        asteroid_list.push_back(asteroids[i]);
    }

    while (!no_collision) {
        no_collision = true;
        iter = asteroid_list.begin();

        while (iter != asteroid_list.end() && next(iter) != asteroid_list.end()) {
            int cur_elem = *iter;
            int next_elem = *next(iter);

            if (cur_elem > 0 && next_elem < 0) {
                no_collision = false;
                if (cur_elem > - next_elem) {
                    iter = asteroid_list.erase(next(iter));
                } else if (cur_elem < -next_elem) {
                    iter = asteroid_list.erase(iter);
                } else {
                    iter = asteroid_list.erase(iter);
                    iter = asteroid_list.erase(iter);
                }
            } else {
                iter++;
            }
        }
    }

    for (iter = asteroid_list.begin(); iter != asteroid_list.end(); ++iter) {
        answer.push_back(*iter);
    }

    return answer;
}

int main() {
    vector<int> asteroids {-2,-1,1,2};
    vector<int> answer = asteroidCollision(asteroids);

    for (int iter : answer) {
        cout << iter << endl;
    }

    return 0;
}















