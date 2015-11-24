#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int randrange(int lower, int higher) {
    // Inclusive for higher and lower
    return random() % ((higher - lower) + 1) + lower;
}

int canshuffle(char *s1) {
    if (strlen(s1) < 4) {
//        printf("\ncan't shuffle (%s), too short\n", s1);
        return 0;
    }
    char ch = s1[1];
    for (int i = 1; i < strlen(s1)-1; i++) {
        if (ch != s1[i]) {
            return 1;
        }
    }
//    printf("\ncan't shuffle (%s), no unique chars\n", s1);
    return 0;
}

int main() {
    struct timespec tm;
    clock_gettime(CLOCK_REALTIME, &tm);

    srand(tm.tv_nsec);

    char word[255];
    char origword[255];
    int randnum;
    char tmp;

    int endindex;

    while (scanf("%s", origword) != EOF) {

        endindex = strlen(origword) - 2;

        strcpy(word, origword);
        if (canshuffle(origword)) {
            while ((strcmp(word, origword) == 0 )) {
                for (int i=1; i<endindex; i++) {

                    randnum = randrange(i, endindex);

                    tmp = word[i];
                    word[i] = word[randnum];
                    word[randnum] = tmp;

                }
            }

        }

        printf("%s ", word);
    }
    printf("\n");

}
