#include <stdio.h>
#include <stdlib.h>

void recursive_func(int num_rows);

int main (){
    int num_of_tries = 0;
    int maxnum_of_tries = 5;
    int rows = 0;
    
    // Part 1: Prompt for and read number of Rows 
    while (num_of_tries < maxnum_of_tries) {
        printf("Enter the number of rows: ");
        if (scanf("%d", &rows) != 1) {
            fprintf(stderr, "ERROR: Did not read an integer\n");
            return 1;
        }
        if (rows < 1 || rows > 20) {
            printf("ERROR: The number of Rows is out of range\n");
            printf("Enter 1 <= number of rows <= 20\n");
            num_of_tries++;
            continue;
        }
        
        break; // Break out of the loop if number of Rows is valid
    }
    
    if (num_of_tries >= maxnum_of_tries) {
        printf("ERROR: Too many tries attempting to read the number of rows for the pattern.\n");
        return 1; // Exit the program due to maximum tries exceeded
    }
    recursive_func(rows); // Plug in rows into the recursive function
    return 0;
}

void recursive_func(int num_rows){
    int i;
    if (num_rows == 1){ // Base Case
        printf("%d", num_rows);
    } else if (num_rows % 2 == 0){ // Check if even, 
        recursive_func(num_rows - 1); // If even, then recusively call the next smallest odd number
    } else if (num_rows % 2 == 1){ // Check if odd
        int i, j;
        // Print the upper half of the diamond
        for (i = 1; i <= (num_rows + 1) / 2; i++) {
            for (j = 1; j <= num_rows - i; j++) {
                printf("   "); 
            }
            int num = 1;
            for (int j = 1; j <= 2 * i - 1; j++) { 
                if (num < 10) {
                    printf(" "); 
                }
                printf("%d ", num);
                if (j < i) {
                    num += j + 1; // Increment number according to the pattern
                } else {
                    num -= (2 * i - j); // Decrement number in reverse order
                }
            }
            printf("\n");
        }

        // Print the lower half of the diamond
        for (i = (num_rows - 1) / 2; i >= 1; i--) {
            for (j = 1; j <= num_rows - i; j++) {
                printf("   "); // alignment
            }
            int num = 1;
            for (int j = 1; j <= 2 * i - 1; j++) {
                if (num < 10) {
                    printf(" "); 
                }
                printf("%d ", num);
                if (j < i) {
                    num += j + 1; // Incrementing number according to the pattern
                } else {
                    num -= (2 * i - j); // Decrement number in reverse order
                }
            }
            printf("\n");
        }
    }
}