#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define DISK_SIZE 200

// Function to perform SCAN disk scheduling
void SCAN(int arr[], int head, char direction) {
    int seek_count = 0;
    int distance, cur_track;
    int left[SIZE], right[SIZE];
    int seek_sequence[SIZE * 2];
    int left_index = 0, right_index = 0, sequence_index = 0;

    // Append end values which has to be visited before reversing the direction
    if (direction == 'l') {
        left[left_index++] = 0;
    } else if (direction == 'r') {
        right[right_index++] = DISK_SIZE - 1;
    }

    // Separate tracks into two arrays
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < head) {
            left[left_index++] = arr[i];
        }
        if (arr[i] > head) {
            right[right_index++] = arr[i];
        }
    }

    // Sort left and right arrays
    for (int i = 0; i < left_index - 1; i++) {
        for (int j = i + 1; j < left_index; j++) {
            if (left[i] > left[j]) {
                int temp = left[i];
                left[i] = left[j];
                left[j] = temp;
            }
        }
    }

    for (int i = 0; i < right_index - 1; i++) {
        for (int j = i + 1; j < right_index; j++) {
            if (right[i] > right[j]) {
                int temp = right[i];
                right[i] = right[j];
                right[j] = temp;
            }
        }
    }

    // Run the while loop two times. One by one scanning right and left of the head
    int run = 2;
    while (run--) {
        if (direction == 'l') {
            for (int i = left_index - 1; i >= 0; i--) {
                cur_track = left[i];

                // Append current track to seek sequence
                seek_sequence[sequence_index++] = cur_track;

                // Calculate absolute distance
                distance = abs(cur_track - head);

                // Increase the total count
                seek_count += distance;

                // Accessed track is now the new head
                head = cur_track;
            }
            direction = 'r';
        } else if (direction == 'r') {
            for (int i = 0; i < right_index; i++) {
                cur_track = right[i];

                // Append current track to seek sequence
                seek_sequence[sequence_index++] = cur_track;

                // Calculate absolute distance
                distance = abs(cur_track - head);

                // Increase the total count
                seek_count += distance;

                // Accessed track is now new head
                head = cur_track;
            }
            direction = 'l';
        }
    }

    printf("Total number of seek operations = %d\n", seek_count);

    printf("Seek Sequence is\n");

    for (int i = 0; i < sequence_index; i++) {
        printf("%d\n", seek_sequence[i]);
    }
}

// Driver code
int main() {
    // Request array
    int arr[SIZE] = {166, 79, 39, 50, 92, 11, 41, 116};
    int head = 50;
    char direction = 'l';

    SCAN(arr, head, direction);

    return 0;
}