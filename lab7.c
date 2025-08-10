#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x;
    int n;
    int r;
    int score;
    int min, max;

    srand(time(NULL)); // เพื่อให้ตัวเลขสุ่มเปลี่ยนทุกครั้ง

    while (1) {
        printf("Do you want to play game (1=play,-1=exit) :\n");

        if (scanf("%d", &x) != 1) {
            // กรณีผู้ใช้ป้อนค่าที่ไม่ใช่ตัวเลข
            while (getchar() != '\n'); // เคลียร์ buffer
            printf("Please enter only 1 or -1.\n");
            continue;
        }

        if (x == -1) {
            printf("See you again.\n");
            break;
        } else if (x != 1) {
            printf("Please enter only 1 or -1.\n");
            continue;
        }

        // เริ่มเกม
        score = 100;
        min = 1;
        max = 100;
        r = rand() % 100 + 1;

        printf("\n(Score=100)\n");

        while (1) {
            printf("Guess the winning number (%d-%d) :\n", min, max);
            if (scanf("%d", &n) != 1) {
                while (getchar() != '\n'); // เคลียร์ buffer
                printf("Please enter a number between %d and %d.\n", min, max);
                continue;
            }

            if (n < min || n > max) {
                printf("Please guess a number between %d and %d.\n", min, max);
                continue;
            }

            if (n == r) {
                printf("That is correct! The winning number is %d.\n", r);
                printf("\nScore this game: %d\n\n", score);
                break;
            } else {
                score -= 10;
                if (n < r) {
                    printf("Sorry, the winning number is HIGHER than %d. (Score=%d)\n\n", n, score);
                    if (n + 1 > min)
                        min = n + 1;
                } else {
                    printf("Sorry, the winning number is LOWER than %d. (Score=%d)\n\n", n, score);
                    if (n - 1 < max)
                        max = n - 1;
                }
            }
        }
    }

    return 0;
}
