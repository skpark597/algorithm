#include <vector>
using namespace std;

class ListNode {
public:
	int val;
    ListNode *next;
    ListNode();
    ListNode(int x);
	ListNode(int x, ListNode *next);
};

namespace util {
    ListNode *makeLinkedList(vector<int> nums);
	void printList(ListNode *head);
}
