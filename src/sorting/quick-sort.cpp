/** 
 * Reference:
 * Introduction to Algorithms (CLRS)
 */

/**
 * Time complexity: O(n^2)
 * Space complexity: O(log(n))
*/

/**
 * The quicksort algorithm has a worst-case running time of O(n^2) on an input
 * array of n numbers. Despite this slow worst-case running time, quicksort is
 * often the best practical choice for sorting because it is remarkably efficient
 * on the average: it's expected running time is O(nlog(n)) and the constant factors
 * hidden in the O(nlog(n)) notation are quite small. It also has the advantage of 
 * sorting in place, and it works well even in virtual-memory environments.
 */

/**
 * The following partition always produces a 9-to-1 split yielding a run-time of 
 * O(nlog(n)). Nodes represent subproblem sizes and per level cost on the right.
 * 
 * 							n ----------------------------------->   (cn)
 * 					     *      *
 * 				 (1/10)n         (9/10)n ------------------------>   (cn)
 *              *       *       *       *
 *          (1/100)n (9/100)n (9/100)n (81/100)n ---------------->   (cn)
 *          *      * *      * *      * *       *
 *                                (81/1000)n (729/1000)n -------->   (cn)
 *                                *        *   *        *
 * 								*   *     * * * *      * * ------>  (<= cn)
 *                                                         *
 *                                                          1 --->  (<= cn)
 *                                                                 ----------
 *                                                                 O(nlog(n))
 * Recurrence -> T(n) = T(9n/10) + T(n/10) + (cn)
 */

void quickSort(int a[], int l, int r) {
	int i = l;
	int j = r;
	int tmp;
	int pivot = a[l + ((r - l) / 2)]; // Integer overflow-safe approach

	while (i <= j) {
		while (a[i] < pivot)
			i++;

		while (a[j] > pivot)
			j--;

        // If elements are unsorted:
		// swap then update indices
		if (i <= j) {
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}

	if (l < j)
		quickSort(a, l, j); // Recursively sort the first half

	if (i < r)
		quickSort(a, i, r); // Recursively sort the second half
}