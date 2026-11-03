/*
 * Program 85: File I/O: Writing and Reading a Text File
 * Topic: File Streams & error handling
 */
#include <stdio.h>

int main(void) {
    FILE* fp = fopen("temp_test.txt", "w");
    if (!fp) return 1;
    fprintf(fp, "DSA Notes in C\n");
    fclose(fp);

    fp = fopen("temp_test.txt", "r");
    if (!fp) return 1;
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), fp)) {
        printf("Read from file: %s", buffer);
    }
    fclose(fp);
    remove("temp_test.txt");
    return 0;
}
