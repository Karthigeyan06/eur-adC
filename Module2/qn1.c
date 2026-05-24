#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int N;

void* primeSum(void* arg) {

    int count = 0, num = 2, sum = 0;

    while(count < N) {

        int prime = 1;

        for(int i = 2; i <= num / 2; i++) {
            if(num % i == 0) {
                prime = 0;
                break;
            }
        }

        if(prime) {
            sum += num;
            count++;
        }

        num++;
    }

    printf("Sum of first %d prime numbers = %d\n", N, sum);

    return NULL;
}

void* thread1(void* arg) {

    for(int i = 0; i < 100; i++) {
        printf("Thread 1 running\n");
        sleep(2);
    }

    return NULL;
}

void* thread2(void* arg) {

    for(int i = 0; i < 100; i++) {
        printf("Thread 2 running\n");
        sleep(3);
    }

    return NULL;
}

int main() {

    pthread_t t1, t2, t3;

    printf("Enter N: ");
    scanf("%d", &N);

    pthread_create(&t1, NULL, primeSum, NULL);
    pthread_create(&t2, NULL, thread1, NULL);
    pthread_create(&t3, NULL, thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}
