/*
 * Return an array of size *returnSize
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct elmt {
	int  val;
	bool added;
	struct elmt *next;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	int *str;
	struct elmt *htable[10] = {NULL};
	int i, indx;
	
	if (!returnSize)
		return NULL;

 	if (!nums1 || !nums1Size || !nums2 || !nums2Size) {
		*returnSize = 0;
		return NULL;   
	}

	str = (int *) malloc((nums1Size + nums2Size) * sizeof(int));
	if (!str) {
		*returnSize = -ENOMEM;
		return NULL;
	}

	// construct a hash table for array 1
	for (i = 0; i < nums1Size; i++) {
		struct elmt *prev;
		struct elmt *curr =  htable[nums1[i] % 10];

		while (curr) {
			if (curr->val < nums1[i]) {
				prev = curr;
				curr = curr->next;
				continue;
			}

			if (curr->val == nums1[i]) 
				break;
			
			if (curr->val > nums1[i]) {
				// insert a new element between prev and curr
				struct elmt *node = (struct elmt *) malloc(sizeof(struct elmt));
				if (!node) {
					*returnSize = -ENOMEM;
					return NULL;
				}
					
				node->val   = nums1[i];
				node->added = false;
				
				prev->next = node;
				node->next = curr;

				break;
			}
		}
		if (!curr) {
			/* element not found
			 * add a new element at the tail of the list
			 */
			struct elmt *node = (struct elmt *) malloc(sizeof(struct elemt));
			if (!node) {
				*returnSize = -ENOMEM;
				return NULL;
			}

			node->val   = nums1[i];
			node->added = false;

			prev->next = node;
			node->next = NULL;
		}
	}
	
	indx = 0;
	// find intersection
	for (i = 0; i < nums2Size; i++) {
		struct elmt *curr = htable[nums2[i] % 10];

		while (curr) {
			if (curr->val == nums2[i]) {
				if (curr->added == false) {
					// add to str---array to return
					str[indx]   = nums2[i];

					curr->added = true;
					++indx;
				}
				break;
			}

			curr = curr->next;
		}
	}
	*returnSize = indx;
	
	// free hash table elements, if any
	for (i = 0; i < 10; i++) {
		struct element *next;
		struct element *curr = htable[i];

		while (curr) {
			next = curr->next;
			free(curr);
			curr = next;
		}
	}

	return str;
}
