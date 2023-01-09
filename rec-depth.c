/* Simple recursive algorithm to demonstrate recursion depth
 * Sample recursion tree for n = 3
 *               3
 *              / \
 *             2   2
 *            / \ / \
 *           1  1 1  1 
*/

#include <stdio.h>
#define TAB "    "

/* Parameter depth records recursion depth */
int func(int n, int depth) {
    for (int i = 1; i < depth; ++i)
        printf(TAB);
    printf("-> F(%d)\n", n);

    if (n <= 1)
        return 1;
    /* Increment depth on every recursive call */
    return func(n - 1, depth + 1) + func(n - 1, depth + 1);
}

int main(void) {
    /* Call above func with unity as initial depth */
    func(6, 1);
    return 0;
}
