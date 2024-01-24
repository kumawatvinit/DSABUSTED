#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a patient
struct Patient {
    char name[100];
    int priority;
    char admitTime[10];
};

// Structure to represent the max heap
struct MaxHeap {
    struct Patient *patients;
    int size;
    int capacity;
};

// Function to initialize a max heap
struct MaxHeap* createMaxHeap(int capacity) {
    struct MaxHeap* maxHeap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
    maxHeap->patients = (struct Patient*)malloc(capacity * sizeof(struct Patient));
    maxHeap->size = 0;
    maxHeap->capacity = capacity;
    return maxHeap;
}

// Function to swap two patients
void swap(struct Patient* a, struct Patient* b) {
    struct Patient temp = *a;
    *a = *b;
    *b = temp;
}

void customSort(struct MaxHeap* maxHeap)
{
    // write bubble sort here in C language, keep biggest at starting, 
    // Here biggest means: High priority value, if priority is same then keep the one which came first at first.
    // You can use strcmp function to compare two strings.


    for (int i = 0; i < maxHeap->size; i++) {
        for (int j = 0; j < maxHeap->size - i - 1; j++) {
            if (maxHeap->patients[j].priority < maxHeap->patients[j + 1].priority) {
                swap(&maxHeap->patients[j], &maxHeap->patients[j + 1]);
            }
            else if (maxHeap->patients[j].priority == maxHeap->patients[j + 1].priority) {
                if (strcmp(maxHeap->patients[j].admitTime, maxHeap->patients[j + 1].admitTime) > 0) {
                    swap(&maxHeap->patients[j], &maxHeap->patients[j + 1]);
                }
            }
        }
    }


}

// Function to heapify a subtree rooted with node i
void maxHeapify(struct MaxHeap* maxHeap, int i) {
     // Include the necessary header file

    // Function to compare two patients based on priority

    // Sort the patients array using the compare function
    customSort(maxHeap);
    return;

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < maxHeap->size &&
        maxHeap->patients[left].priority > maxHeap->patients[largest].priority)
        largest = left;

    if (right < maxHeap->size &&
        maxHeap->patients[right].priority > maxHeap->patients[largest].priority)
        largest = right;

    if (largest != i) {
        swap(&maxHeap->patients[i], &maxHeap->patients[largest]);
        maxHeapify(maxHeap, largest);
    }
}

// Function to insert a new patient into the max heap
void admitPatient(struct MaxHeap* maxHeap, char* name, int priority, char* admitTime) {
    if (maxHeap->size == maxHeap->capacity) {
        // printf("Error: Priority queue is full.\n");
        return;
    }

    struct Patient newPatient;
    strcpy(newPatient.name, name);
    newPatient.priority = priority;
    strcpy(newPatient.admitTime, admitTime);

    maxHeap->patients[maxHeap->size] = newPatient;
    int i = maxHeap->size;
    maxHeap->size++;

    customSort(maxHeap);
    return;

    // Fix the max heap property
    while (i > 0 && maxHeap->patients[(i - 1) / 2].priority < maxHeap->patients[i].priority) {
        swap(&maxHeap->patients[i], &maxHeap->patients[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to treat the next patient
void treatNextPatient(struct MaxHeap* maxHeap) {
    if (maxHeap->size == 0) {
        // printf("Error: Priority queue is empty.\n");
        return;
    }

    struct Patient treatedPatient = maxHeap->patients[0];
    printf("%s %d %s\n", treatedPatient.name, treatedPatient.priority, treatedPatient.admitTime);

    // Replace the root with the last patient and heapify the root
    for(int i = 0; i < maxHeap->size - 1; i++) {
        maxHeap->patients[i] = maxHeap->patients[i + 1];
    }

    maxHeap->size--;
}

// Function to check the next patient without removing them
void checkNextPatient(struct MaxHeap* maxHeap) {
    if (maxHeap->size == 0) {
        // printf("Error: Priority queue is empty.\n");
        return;
    }

    struct Patient nextPatient = maxHeap->patients[0];
    printf("%s %d %s\n", nextPatient.name, nextPatient.priority, nextPatient.admitTime);
}

// Function to discharge a specific patient
void dischargePatient(struct MaxHeap* maxHeap, char* name, char* admitTime) {
    int i;
    for (i = 0; i < maxHeap->size; i++) {
        if (strcmp(maxHeap->patients[i].name, name) == 0 && strcmp(maxHeap->patients[i].admitTime, admitTime) == 0)
            break;
    }

    if (i == maxHeap->size) {
        // printf("-1\n");
        return;
    }

    for(int j = i; j < maxHeap->size - 1; j++) {
        maxHeap->patients[j] = maxHeap->patients[j + 1];
    }

    maxHeap->size--;
}

// Function to update condition severity of a specific patient
void updateConditionSeverity(struct MaxHeap* maxHeap, char* name, char* admitTime, int newPriority) {
    int i;
    for (i = 0; i < maxHeap->size; i++) {
        if (strcmp(maxHeap->patients[i].name, name) == 0 && strcmp(maxHeap->patients[i].admitTime, admitTime) == 0)
            break;
    }

    if (i == maxHeap->size) {
        // printf("Error: Patient not found.\n");
        return;
    }

    maxHeap->patients[i].priority = newPriority;

    for(int j=i; j>0; j--) {
        if(maxHeap->patients[j].priority > maxHeap->patients[j-1].priority) {
            swap(&maxHeap->patients[j], &maxHeap->patients[j-1]);
        }
        else if(maxHeap->patients[j].priority == maxHeap->patients[j-1].priority) {
            if(strcmp(maxHeap->patients[j].admitTime, maxHeap->patients[j-1].admitTime) < 0) {
                swap(&maxHeap->patients[j], &maxHeap->patients[j-1]);
            }
        }
        else {
            break;
        }
    }
}

// Function to print all patients in priority order
void printAllPatients(struct MaxHeap* maxHeap) {
    for (int i = 0; i < maxHeap->size; i++) {
        printf("%s %d %s\n", maxHeap->patients[i].name, maxHeap->patients[i].priority, maxHeap->patients[i].admitTime);
    }

    return;


    if (maxHeap->size == 0) {
        printf("-1\n");
        return;
    }

    // printf("All Patients:\n");
    for (int i = 0; i < maxHeap->size; i++) {
        printf("%s %d %s\n", maxHeap->patients[i].name, maxHeap->patients[i].priority, maxHeap->patients[i].admitTime);
    }
}

int main() {
    struct MaxHeap* priorityQueue = createMaxHeap(1000);

    char option;
    while (1) {
        scanf("%c", &option);

        switch (option) 
        {
            case 'a':
                // Admit new patient
                {
                    char name[100];
                    int priority;
                    char admitTime[10];
                    // printf("Enter patient name, priority, and admit time: ");
                    scanf("%s%d%s", name, &priority, admitTime);

                    // printf("Input yeh liye:'%s, %d, %s'\n", name, priority, admitTime);
                    admitPatient(priorityQueue, name, priority, admitTime);
                    break;
                }
            case 't':
                // Treat next patient
                treatNextPatient(priorityQueue);
                break;
            case 'c':
                // Check next patient
                checkNextPatient(priorityQueue);
                break;
            case 'd':
                // Discharge patient
                {
                    char name[100];
                    char admitTime[10];
                    // printf("Enter patient name and admit time: ");
                    scanf("%s%s", name, admitTime);
                    // printf("Input yeh liye:'%s, %s'\n", name, admitTime);
                    dischargePatient(priorityQueue, name, admitTime);
                    break;
                }
            case 'u':
                // Update condition severity of a patient
                {
                    char name[100];
                    char admitTime[10];
                    int newPriority;
                    // // printf("Enter patient name, admit time, and new priority: ");
                    scanf("%s%s%d", name, admitTime, &newPriority);
                    // printf("Input yeh liye:'%s, %s, %d'\n", name, admitTime, newPriority);
                    updateConditionSeverity(priorityQueue, name, admitTime, newPriority);
                    break;
                }
            case 'p':
                // Print all patients
                printAllPatients(priorityQueue);
                break;
            case 'e':
                // Exit the program
                return 0;
            // default:
                // printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
