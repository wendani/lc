/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct list_node_head {
	struct list_node *next;
	struct list_node *prev;

	uint32_t qlen;
};

/**
 * Caller ensures that argument head is not NULL
 */
static inline void __list_head_init(struct list_node_head *head)
{
	head->next = (struct list_node *) head;
	head->prev = (struct list_node *) head;

	head->qlen = 0;
}

struct list_node {
	struct list_node *next;
	struct list_node *prev;

	struct TreeNode  *tnode;
};

int find_depth(struct TreeNode *root)
{
	int ldepth, rdepth;

	if (!root)
		return 0;

	ldepth = find_depth(root->left);
	rdepth = find_depth(root->right);

	return (ldepth >= rdepth) ? (ldepth + 1) : (rdepth + 1);
}

/**
 * return 1, if list is empty
 * 0, otherwise
 */
static inline int __list_empty(struct list_node_head *head)
{
	return (head->next == (struct list_node *) head) ? 1 : 0;
}

static inline int __list_len(struct list_node_head *head)
{
	return head->qlen;
}

static inline void __list_add_tail(struct list_node_head *head, struct list_node *node)
{
	struct list_node *prev = head->prev;

	prev->next = node;
	node->next = (struct list_node *) head;

	head->prev = node;
	node->prev = prev;

	++head->qlen;
}

/**
 * Caller ensures that list is not empty
 */
static inline struct list_node *__list_dequeue(struct list_node_head *head)
{
	struct list_node *curr = head->next;
	struct list_node *next = curr->next;

	head->next = next;
	next->prev = (struct list_node *) head;
	--head->qlen;

	return curr;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
	int depth, rindx, cindx;
	int **arr;
	int *colmn;
	struct list_node_head *head;
	struct list_node *curr, *level_tail;
	struct list_node *new_lnode;
	struct TreeNode *tnode;

	if (!columnSizes && !returnSize)
		return NULL;

	if (!columnSizes) {
		*returnSize = 0;
		return NULL;
	}

	if (!returnSize) {
		*columnSizes = NULL;
		return NULL;
	}

	if (!root) {
		*returnSize  = 0;
		*columnSizes = NULL;
		return NULL;
	}

	// find the depth of the tree to determine the array size for allocation
	depth = find_depth(root);
	arr = (int **) malloc(depth * sizeof(int *));
	colmn = (int *) malloc(depth * sizeof(int));

	head = (struct list_node_head *) malloc(sizeof(struct list_node_head));
	__list_head_init(head);

	new_lnode = (struct list_node *) malloc(sizeof(struct list_node));
	new_lnode->tnode = root;
	__list_add_tail(head, new_lnode);
	rindx = 0;
	colmn[rindx] = head->qlen;
	arr[rindx] = (int *) malloc(colmn[rindx] * sizeof(int));
	cindx = 0;
	level_tail = head->prev;
	// level order traversal with the help of FIFO queue
	while (!__list_empty(head)) {
		curr = __list_dequeue(head);
		tnode = curr->tnode;
		arr[rindx][cindx] = tnode->val;
		++cindx;

		// enqueue
		if (tnode->left) {
			new_lnode = (struct list_node *) malloc(sizeof(struct list_node));
			new_lnode->tnode = tnode->left;
			__list_add_tail(head, new_lnode);
		}
		if (tnode->right) {
			new_lnode = (struct list_node *) malloc(sizeof(struct list_node));
			new_lnode->tnode = tnode->right;
			__list_add_tail(head, new_lnode);
		}

		if (curr == level_tail) {
			++rindx;
			if (rindx == depth)
				break;

			colmn[rindx] = head->qlen;
			arr[rindx] = (int *) malloc(colmn[rindx] * sizeof(int));

			cindx = 0;
			level_tail = head->prev;
		}
	}

	*returnSize  = depth;
	*columnSizes = colmn;
	return arr;
}
