#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};
    int len = strlen(s);

    // Count frequency of each character
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }

    // Find first character with frequency 1
    for (int i = 0; i < len; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    printf("$\n");
    return 0;
}
