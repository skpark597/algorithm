/* 142. Linked List Cycle II */
/** Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *  There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
 *  Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
 * 
 *  Notice that you should not modify the linked list.
 * 
 * Follow up: Can you solve it using O(1) (i.e. constant) memory?
 * 
 * 
 * Example 1:
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the second node.
 * 
 * Example 2:
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the first node.
 * 
 * Example 3:
 * Input: head = [1], pos = -1
 * Output: no cycle
 * Explanation: There is no cycle in the linked list.
 * 
 * Constraints:
 * The number of the nodes in the list is in the range [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * pos is -1 or a valid index in the linked-list. **/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    const int num = 200001;
    ListNode *cycle = nullptr;
    ListNode *cur = head;

    while (true) {
        if (cur == nullptr) {
            break;
        } else if (cur->val > 100000) {
            cycle = cur;
            break;
        } 

        cur->val += num;
        cur = cur->next;
    }

    /* 아래 코드는 list를 순회하며 num 만큼 더했던 부분을 다시 원복해주는 부분. 꼭 필요한 과정은 아니다. */
    cur = head;

    while (true) {
        if (cur == nullptr || cur->val <= 100000) {
            break;
        }
        
        cur->val -= num;
        cur = cur->next;
    }

    return cycle;
}

int main() {
    ListNode *node0 = new ListNode(3);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(0);
    ListNode *node3 = new ListNode(-4);
    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;
    
    //ListNode *node0 = new ListNode(1);
    //ListNode *node1 = new ListNode(2);
    //node0->next = node1;
    //node1->next = node0;

    ListNode *answer = detectCycle(node0);

    if (answer == nullptr) {
        cout << "nullptr" << endl;
    } else {
        cout << answer->val << endl;
    }

    return 0;
}












