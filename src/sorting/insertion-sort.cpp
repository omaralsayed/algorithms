/** 
 * Reference:
 * Introduction to Algorithms (CLRS)
 */

/**
 * Time complexity: O(n^2)
 * Space complexity: O(1)
*/

/**
 * Insertions sort is an effecient algorithm
 * for sorting a small number of elements.
 * 
 * The sorting routine (insertion) puts the 
 * keys in-place: rearranges the keys within 
 * the array with at most a constant number 
 * of them stored outside the array at any 
 * time.
 * 
 * The operation of insertion sort on {5, 2, 4, 6, 1, 3}:
 * {5, 2, 4, 6, 1, 3}
 *  ^  ^
 * {2, 5, 4, 6, 1, 3}
 *     ^  ^
 * {2, 4, 5, 6, 1, 3}
 *           ^
 * {2, 4, 5, 6, 1, 3}
 *  ^           ^
 * {1, 2, 4, 5, 6, 3}
 *        ^        ^
 * {1, 2, 3, 4, 5, 6}
 */

template <typename T>
void insertionSort(T a[], int n) {
    for (int i = 1; i < n; i++) {
        T t = a[i];
        for (int j = i - 1; j >= 0 && t < a[j]; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = t;
    }
}