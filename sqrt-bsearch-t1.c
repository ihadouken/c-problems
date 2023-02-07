/* Find the square root (integer) of given postive integer. */

#include <stdio.h>

int mysqrt(int x);

int main() {
    int num = 80;
    printf("I: %d\n", num);
    printf("O: %d\n", mysqrt(num));
    return 0;
}

/* Complexity: O(sqrt(n)) */
// int mysqrt(int x) {
//     int root;
//     root = 1;
//     while (root*root <= x) {
//         ++root;
//     }
//     return root - 1;
// }

/* Complexity: O(log(n)) (using binary search) */
int mysqrt(int x) {
    int l, r, m, msquare;
    /* For any positive integer x, sqrt(x) >= 1 */
    l = 1;
    /* x^2 >= cx (or x >= c*sqrt(x)), for any x >= 1 and c >= 1 */
    r = x;

    while (l <= r) {
        m = (l + r)/2;
        msquare = m*m;

        if (x < msquare)
            r = m - 1;
        else if (x > msquare)
            l = m + 1;
        else
            return m;
    }
    /* If m^2 exceeds x in the last iteration, then the perfect square closest
     * to x is given by m-1 which will coincidently be equal to right pointer.
     * Because in last iteration, l = m and r = l-1 = m-1 */
    return r;
    // return m - 1;
}
