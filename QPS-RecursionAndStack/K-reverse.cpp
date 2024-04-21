#define node ListNode
class Solution {
public:

	void reverseLL(node* &head, node* &tail) {
		node*p, *c, *n;
		p = NULL;
		while (c) {
			n = c->next;
			c->next = p;
			p = c;
			c = n;
		}
		swap(head, tail);
	}

	node* reverseKGroup(node* head, int k) {

		node* c, *p, *n;
		c = head;
		p = NULL;

		while (c) {
			node* h, *t;
			h = c;
			t = c;
			bool kyaKNodesMillGai = true;
			for (int i = 0; i < k - 1; ++i)
			{
				t = t->next;
				if (!t) {
					kyaKNodesMillGai = false;
					break;
				}
			}

			if (kyaKNodesMillGai) {
				n = t->next;
				t->next = NULL;
				reverseLL(h, t);
				if (p == NULL) {
					head = h;
					t->next = n;
					p = c;
					c = n;
				}
				else {
					p -> next = h;
					t->next = n;
					p = c;
					c = n;
				}
			}
			else {
				break;
			}

		}

		return head;
	}
};
















