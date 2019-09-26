/** 
 * Reference:
 * GeeksforGeeks (geeksforgeeks.org)
 */

/** 
 * Search a sorted array by repeatedly dividing the search interval
 * in half. Begin with an interval covering the whole array. If the
 * value of the search key is less than the item in the middle of 
 * the interval, narrow the interval to the lower half. Otherwise narrow
 * it to the upper half. Repeatedly check until the value is found or
 * the interval is empty.
 */

template <typename T>
int binarySearch(T a[], int len, T val) {
    int mid, r = len - 1, l = 0;

    while (l <= r) {
        mid = l + (r - l) / 2; // Integer overflow-safe approach
        if (a[mid] > val)
            r = mid - 1;
        else if (a[mid] < val)
            l = mid + 1;
        else if (a[mid] == val)
            return mid;
    }

    return -1; // Key not found
}