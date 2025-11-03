/*
NAME: Kiptui Kipyator 
REG NO: PA106/G/28740/25
Date: 3rd November 2025
*/

#include <stdio.h>
#include <stdlib.h> ()


void write_input_file(const char *filename);
void process_file_data(const char *input_file, const char *output_file);
void display_file_contents(const char *input_file, const char *output_file);

int main() {
    const char *INPUT_FILE = "input.txt";
    const char *OUTPUT_FILE = "output.txt";

    
    printf("--- Task 1: Writing input to %s ---\n", INPUT_FILE);
    write_input_file(INPUT_FILE);
    printf("\n--- Task 2: Processing data and writing results to %s ---\n", OUTPUT_FILE);
    process_file_data(INPUT_FILE, OUTPUT_FILE);

    
    printf("\n--- Task 3: Displaying file contents ---\n");
    display_file_contents(INPUT_FILE, OUTPUT_FILE);

    return 0;
}


void write_input_file(const char *filename) {
    FILE *file_ptr;
    int number;

    
    file_ptr = fopen(filename, "w"); 
    if (file_ptr == NULL) {
        perror("Error opening input file for writing");
        return; 
    }

    printf("Please enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Enter integer %d: ", i + 1);
        if (scanf("%d", &number) != 1) {
            
            printf("Invalid input. Skipping number %d.\n", i + 1);
            while (getchar() != '\n'); 
            i--; 
            continue;
        }
        
        fprintf(file_ptr, "%d\n", number); 
    }

    printf("Successfully wrote 10 integers to %s.\n", filename);
    fclose(file_ptr);
}
void process_file_data(const char *input_file, const char *output_file) {
    FILE *in_ptr, *out_ptr;
    int number;
    int count = 0;
    long sum = 0; 
    double average = 0.0;

    
    in_ptr = fopen(input_file, "r"); 
    if (in_ptr == NULL) {
        perror("Error opening input file for reading");
        return;
    }

    
    while (fscanf(in_ptr, "%d", &number) == 1) {
        sum += number;
        count++;
    }
    
    
    fclose(in_ptr); 

    if (count > 0) {
        average = (double)sum / count;

        
        out_ptr = fopen(output_file, "w"); 
        if (out_ptr == NULL) {
            perror("Error opening output file for writing");
            return;
        }

        
        fprintf(out_ptr, "Total numbers read: %d\n", count);
        fprintf(out_ptr, "Sum of the numbers: %ld\n", sum);
        fprintf(out_ptr, "Average of the numbers: %.2f\n", average);

        printf("Calculated Sum (%ld) and Average (%.2f) and wrote to %s.\n", sum, average, output_file);
        
        
        fclose(out_ptr); 
    } else {
        printf("No integers found in %s to process.\n", input_file);
    }
}


void display_file_contents(const char *input_file, const char *output_file) {
    FILE *file_ptr;
    char buffer[256]; 

    
    file_ptr = fopen(input_file, "r");
    if (file_ptr == NULL) {
        perror("Error opening input file for display");
        return;
    }

    printf("\nContents of **%s**:\n", input_file);
    printf("---------------------------\n");
    
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
        printf("> %s", buffer);
    }
    printf("---------------------------\n");
    fclose(file_ptr);

    
    file_ptr = fopen(output_file, "r");
    if (file_ptr == NULL) {
        perror("Error opening output file for display");
        return;
    }

    printf("\nContents of **%s**:\n", output_file);
    printf("---------------------------\n");
    
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
        printf("> %s", buffer);
    }
    printf("---------------------------\n");
    fclose(file_ptr);
}
