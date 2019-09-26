/** Reference:
 *  GeeksforGeeks (geeksforgeeks.org)
 */

/** 
 *  The interpolation search is an improvement over binary search for
 *  instances, where the values in a sorted array are uniformly distributed.
 *  Binary search always goes to the middle element to check. On the other
 *  hand, interpolation search may go to different locations according to the
 *  value of the key being searched. For example, if the value of the key is
 *  closer to the last element, interpolation search is likely to start search 
 *  toward the end side.
 */

int interpolationSearch(int a[], int n, int x) { 
    int lo = 0, hi = (n - 1); // Find the index of two corners 
  
    // Any given element must be in the range defined by corners
    // (array is sorted)
    while (lo <= hi && x >= a[lo] && x <= a[hi]) { 
        if (lo == hi) { 
            if (a[lo] == x) return lo; 
            return -1; 
        } 

        int pos = lo + (((double)(hi - lo) / (a[hi] - a[lo])) * (x - a[lo])); 
  
        // If x is found
        if (a[pos] == x) 
            return pos; 
  
        // If x is larger
        if (a[pos] < x) 
            lo = pos + 1; 
  
        // If x is smaller
        else
            hi = pos - 1; 
    }

    return -1; // Key not found
}