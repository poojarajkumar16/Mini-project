#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int calculateFLAMES(char name1[], char name2[]) {
    int count1[26] = {0};
    int count2[26] = {0};
    int i, common_letters = 0;

    // Count frequency of characters in both names
    for (i = 0; name1[i] != '\0'; i++) {
        if (name1[i] >= 'a' && name1[i] <= 'z')
            count1[name1[i] - 'a']++;
    }
    for (i = 0; name2[i] != '\0'; i++) {
        if (name2[i] >= 'a' && name2[i] <= 'z')
            count2[name2[i] - 'a']++;
    }

    // Count common letters
    for (i = 0; i < 26; i++) {
        common_letters += (count1[i] > 0 && count2[i] > 0);
    }

    // Calculate FLAMES score
    int total_letters = strlen(name1) + strlen(name2) - 2 * common_letters;
    int flames_index = total_letters % 6;

    return flames_index;
}

char* getFLAMESResult(int index) {
    char* result[] = {"Friendship", "Love", "Affection", "Marriage", "Enemy", "Sibling"};
    return result[index];
}

int main() {
    char name1[MAX_LENGTH], name2[MAX_LENGTH];
    printf("Enter first name: ");
    fgets(name1, sizeof(name1), stdin);
    printf("Enter second name: ");
    fgets(name2, sizeof(name2), stdin);

    // Remove newline characters
    name1[strcspn(name1, "\n")] = '\0';
    name2[strcspn(name2, "\n")] = '\0';

    int flames_index = calculateFLAMES(name1, name2);
    char* result = getFLAMESResult(flames_index);

    printf("FLAMES result for %s and %s: %s\n", name1, name2, result);

    return 0;
}
