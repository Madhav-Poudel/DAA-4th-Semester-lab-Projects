#include <stdio.h>
#include <stdlib.h>

// A structure to represent a job
typedef struct Job {
    char id;     // Job Id
    int deadline; // Deadline of job
    int profit;   // Profit if job is completed before or on deadline
} Job;

// Comparator function to sort jobs according to profit in descending order
int compare(const void *a, const void *b) {
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    return job2->profit - job1->profit;
}

// Function to find the maximum deadline in jobs array
int findMaxDeadline(Job jobs[], int n) {
    int max = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > max) {
            max = jobs[i].deadline;
        }
    }
    return max;
}

// Function to schedule jobs to maximize profit
void jobSequencing(Job jobs[], int n) {
    // Sort jobs according to profit in descending order
    qsort(jobs, n, sizeof(Job), compare);

    // Find the maximum deadline to create a result array
    int maxDeadline = findMaxDeadline(jobs, n);

    // Create an array to keep track of free time slots
    int *result = (int *)malloc(maxDeadline * sizeof(int));
    for (int i = 0; i < maxDeadline; i++) {
        result[i] = -1; // Initialize all slots to free
    }

    int totalProfit = 0; // Initialize total profit

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (we start from the last possible slot)
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (result[j] == -1) { // Free slot found
                result[j] = i;     // Assign this job to the free slot
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print the result
    printf("Job sequence to maximize profit:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != -1) {
            printf("%c ", jobs[result[i]].id);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);

    // Free the allocated memory
    free(result);
}

int main() {
    // Array of jobs {job id, deadline, profit}
    Job jobs[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    printf("Given jobs:\n");
    for (int i = 0; i < n; i++) {
        printf("Job %c: deadline = %d, profit = %d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }

    jobSequencing(jobs, n);

    return 0;
}
