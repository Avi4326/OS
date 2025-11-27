#include <stdio.h>
#include <pthread.h>

int a[100], n;
int sum = 0;

void* find_sum(void* arg) {
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return NULL;
}

int main() {
    pthread_t t1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // create thread
    pthread_create(&t1, NULL, find_sum, NULL);

    // wait for thread to finish
    pthread_join(t1, NULL);

    printf("Sum = %d\n", sum);

    return 0;
}
