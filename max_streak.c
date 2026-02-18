#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int k;
        scanf("%d", &k);

        int count = 0, maxstreak = 0, num;

        for (int i = 0; i < k; i++) {
            scanf("%d", &num);

            if (num > 0) {
                count++;
                if (count > maxstreak)
                    maxstreak = count;
            } else {
                count = 0;
            }
        }

        printf("%d\n", maxstreak);
    }

    return 0;
}
