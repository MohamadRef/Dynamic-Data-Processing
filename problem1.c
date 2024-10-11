#include <stdio.h>
#include <stdlib.h>

void RunningMean(double* measurements, double* runningMean, int numInRunningMean) {
    // Calculate running means
    for (int k = 0; k <= numInRunningMean - 3; k++) {
        runningMean[k] = (measurements[k] + measurements[k + 1] + measurements[k + 2]) / 3.0;
    }
}

int main() {
    char filename[100];
    int numMeas;

    printf("TEST 5: Input file contains less data than expected\n");

    int fileOpenFailures = 0;
    FILE* inputFile = NULL;

    // Try opening the input file up to 3 times
    while (fileOpenFailures < 3) {
        printf("Enter the name of the input file: ");
        scanf("%s", filename);

        inputFile = fopen(filename, "r");
        if (inputFile == NULL) {
            fprintf(stderr, "ERROR: Input file %s not opened\n", filename);
            fileOpenFailures++;
        } else {
            break; // Exit loop if file is successfully opened
        }
    }

    if (fileOpenFailures == 3) {
        fprintf(stderr, "ERROR: Too many failures opening input file\n");
        return 1;
    }

    // Prompt for and read the number of data points to be analyzed
    printf("Enter the number of measurements: ");
    scanf("%d", &numMeas);

    // Dynamically allocate arrays for measurements and running mean
    double* myMeasurements = (double*)malloc(numMeas * sizeof(double));
    double* myRunningMean = (double*)malloc((numMeas - 2) * sizeof(double));
    if (myMeasurements == NULL || myRunningMean == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        if (myMeasurements != NULL) free(myMeasurements);
        if (myRunningMean != NULL) free(myRunningMean);
        fclose(inputFile);
        return 1;
    }

    int numRead = 0;
    for (int i = 0; i < numMeas; i++) {
        if (fscanf(inputFile, "%lf", &myMeasurements[i]) == 1) {
            numRead++;
        }
    }

    // Check if the file is empty after reading
    if (numRead == 0) {
        fprintf(stderr, "ERROR: input file is empty\n");
        free(myMeasurements);
        free(myRunningMean);
        fclose(inputFile);
        return 1;
    }

    // Check if there are enough measurements in the file
    if (numRead < 3) {
        fprintf(stderr, "ERROR: insufficient data to calculate a running average\n");
        free(myMeasurements);
        free(myRunningMean);
        fclose(inputFile);
        return 1;
    } else if (numRead < numMeas) {
        fprintf(stderr, "ERROR: fewer than numMeas measurements in the file\n");
    }

    // Calculate running means
    RunningMean(myMeasurements, myRunningMean, numMeas);
    printf("The running sums are\n");

    // Print running means
    for (int j = 0; j < numMeas - 2; j++) {
        printf("%10.2lf ", myRunningMean[j]);
        if ((j + 1) % 5 == 0) printf("\n");
    }
    printf("\n");

    // Clean up and close files
    free(myMeasurements);
    free(myRunningMean);
    fclose(inputFile);

    return 0;
}


