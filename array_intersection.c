/*
 * Return an array of size *returnSize
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define ENOMEM 12
#define DEBUG_HTABLE_CONSTRUCT

struct elmt {
	int  val;
	bool added;
	struct elmt *next;
};

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	int *arr;
	struct elmt *htab[10] = {NULL};
	int i, indx;
	
	if (!returnSize)
		return NULL;

 	if (!nums1 || !nums1Size || !nums2 || !nums2Size) {
		*returnSize = 0;
		return NULL;   
	}

	arr = (int *) malloc((nums1Size + nums2Size) * sizeof(int));
	if (!arr) {
		*returnSize = -ENOMEM;
		return NULL;
	}

	// construct a hash table for array 1
	for (i = 0; i < nums1Size; i++) {
		int hval = nums1[i] % 10;
		struct elmt *prev = NULL;
		struct elmt *curr = htab[hval];

		while (curr) {
			if (nums1[i] > curr->val) {
				prev = curr;
				curr = curr->next;
				continue;
			}

			if (nums1[i] == curr->val)
				break;
			
			if (nums1[i] < curr->val) {
				// insert a new element between prev and curr
				struct elmt *node = (struct elmt *) malloc(sizeof(struct elmt));
				if (!node) {
					*returnSize = -ENOMEM;
					return NULL;
				}
					
				node->val   = nums1[i];
				node->added = false;
				
				if (prev)
					prev->next = node;
				else
					htab[hval] = node;
				node->next = curr;

				break;
			}
		}
		if (!curr) {
			/* element not found
			 * add a new element to the tail of the list
			 */
			struct elmt *node = (struct elmt *) malloc(sizeof(struct elmt));
			if (!node) {
				*returnSize = -ENOMEM;
				return NULL;
			}

			node->val   = nums1[i];
			node->added = false;

			if (prev)
				prev->next = node;
			else
				htab[hval] = node;
			node->next = NULL;
		}
	}
	
#ifdef DEBUG_HTABLE_CONSTRUCT
	for (i = 0; i < 10; i++) {
		struct elmt *curr = htab[i];

		printf("%d:" ,i);
		while (curr) {
			printf(" %d", curr->val);
			curr = curr->next;
		}
		printf("\n");
	}
#endif

	indx = 0;
	// find intersection
	for (i = 0; i < nums2Size; i++) {
		struct elmt *curr = htab[nums2[i] % 10];

		while (curr) {
			if (nums2[i] < curr->val)
				break;

			if (nums2[i] > curr->val) {
				curr = curr->next;
				continue;
			}

			if (curr->val == nums2[i]) {
				if (curr->added == false) {
					// first-time occurrence
					// add to arr---array to return
					arr[indx]   = nums2[i];

					curr->added = true;
					++indx;
				}

				break;
			}
		}
	}
	*returnSize = indx;
	
	// free hash table elements, if any
	for (i = 0; i < 10; i++) {
		struct elmt *next;
		struct elmt *curr = htab[i];

		while (curr) {
			next = curr->next;
			free(curr);
			curr = next;
		}
	}

	return arr;
}
