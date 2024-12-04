#include <stdio.h>
#include <stdlib.h>

struct pair {
    double arr;
    double dep;
};

int compare(const void *x_void, const void *y_void) {
    double x = *(double *)x_void;
    double y = *(double *)y_void;
    return (x > y) - (x < y);
}

int main() {
    double arr[] = {2.00, 2.10, 3.00, 3.20, 3.50, 5.00};
    double dep[] = {2.30, 3.40, 3.20, 4.30, 4.00, 5.20};

    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(double), compare);
    qsort(dep, n, sizeof(double), compare);

    struct pair set[n];

    for(int i = 0; i < n; i++) {
        set[i].arr = arr[i];
        set[i].dep = dep[i];
    }

    int platforms_needed = 0;
    int max_platforms = 0;

    int i = 0, j = 0;
    while (i < n && j < n) {
        if (set[i].arr < set[j].dep) {
            platforms_needed++;
            if (platforms_needed > max_platforms) {
                max_platforms = platforms_needed;
            }
            i++;
        } else {
            platforms_needed--;
            j++;
        }
    }

    printf("Minimum number of platforms required: %d\n", max_platforms);

    return 0;
}
