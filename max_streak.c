#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[100];

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);

        for (int j = 0; j < k; j++) {
            scanf("%d", &a[j]);
        }

        int count = 0;
        int maxstreak = 0;

        for (int j = 0; j < k; j++) {
            if (a[j] > 0) {
                count++;
                if (count > maxstreak) {
                    maxstreak = count;
                }
            } else {
                count = 0;
            }
        }

        printf("%d\n", maxstreak);
    }

    return 0;
}
