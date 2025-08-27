#include <utility.h>

// Global variables
int row[20], proc[50], frames = 0, noOfProcess = 0, pageFault = 0;

// Function to push a value into the frame (FIFO logic)
void push(int val, int index) {
	// Check if the value already exists in the current pages
	for (int x = 0; x < frames; x++) {
		if (row[x] == proc[index]) {
			return; // If it exists, no page fault occurs
		}
	}

	// Shift values down to make space for the new value
	for (int x = frames; x >= 0; x--) {
		row[x] = row[x - 1];
	}

	// Increment page fault count and add the new value to the top
	pageFault++;
	row[0] = val;
}

// Function to calculate and display the total page fault percentage
void totalPageFault() {
	double totPage = ((double)pageFault / (double)noOfProcess) * 100;
	gotoxy(1, frames * 2 + 7);
	printf("Page Fault: %d/%d = %.2lf%%", pageFault, noOfProcess, totPage);
}

int main() {
	// Local variables for main
	int x = 2, rows = 3, counter = 1, index = 1;

	// Ask for the number of frames and processes
	printf("How many Frames: ");
	scanf("%d", &frames);
	printf("How many processes: ");
	scanf("%d", &noOfProcess);
	printf("Input processes: ");

	// Initialize the row array
	for (int x = 0; x < frames; x++) {
		row[x] = -1; // Set all frame slots to -1 (empty)
	}

	// Display the first process as it is being input
	gotoxy(x + 1, 4);
	scanf("%d", &proc[0]);
	box3(x, 3, x + 2, 5);

	// Draw the initial frame boxes
	for (int i = 0; i < frames; i++) {
		boxtab2(x, rows + 2, x + 2, rows + 4);
		rows += 2;
	}
	x += 2;

	// While loop for displaying processes as they are being input
	while (counter < noOfProcess) {
		rows = 0;
		gotoxy(x + 1, 4);
		scanf("%d", &proc[counter]);
		boxtab(x, 3, x + 2, 5);

		// Draw the frame boxes for the current process
		for (int i = 0; i < frames; i++) {
			boxtab3(x, rows + 5, x + 2, rows + 7);
			rows += 2;
		}
		x += 2;
		index++;
		counter++;
	}

	// Display the output for each process
	for (x = 0; x < noOfProcess; x++) {
		push(proc[x], x); // Push the current process into the frame

		// Display the current state of the frames
		for (int i = 0; i < frames; i++) {
			gotoxy(3 + x * 2, 6 + i * 2);
			if (row[i] == -1) {
				printf(" "); // Empty frame
			} else {
				printf("%d", row[i]); // Display the page number
			}
		}
	}

	// Display the total page fault percentage
	gotoxy(24, 72);
	totalPageFault();

	return 0;
}
