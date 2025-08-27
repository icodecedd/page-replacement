#include <utility.h>

// Global variables
int row[20], proc[50], frames = 0, noOfProcess = 0, pageFault = 0;

// Function to push a value into the frame, handling repeated values
void push(int val, int index) {
	// Check if the value exists in the current pages
	for (int x = 0; x < frames; x++) {
		if (row[x] == val) {
			// If found, shift values up to make space at row[0]
			for (int y = x; y > 0; y--)
				row[y] = row[y - 1];

			row[0] = val; // Place the repeated value at row[0]
			return;
		}
	}

	// If the value doesn't exist
	for (int x = frames - 1; x > 0; x--) {
		if (x + 1 < index) // Begins when the rows are full
			row[x] = row[x]; // Copies the value
		else
			row[x] = row[x - 1]; // Push down the value while the rows are not full
	}

	row[0] = val; // Place the new value at row[0]
	pageFault++;  // Increment page fault count
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

	// Ask for number of frames and processes
	printf("How many Frames: ");
	scanf("%d", &frames);
	printf("How many processes: ");
	scanf("%d", &noOfProcess);
	printf("Input processes: ");

	// Initialize row array
	for (int x = 0; x < frames; x++) {
		row[x] = -1;
	}

	// Display process as it is being input
	// The first segment is separate from the rest for visual purposes
	gotoxy(x + 1, 4);
	scanf("%d", &proc[0]);
	box3(x, 3, x + 2, 5);
	for (int i = 0; i < frames; i++) {
		boxtab2(x, rows + 2, x + 2, rows + 4);
		rows += 2;
	}
	x += 2;

	// While loop for displaying as being input
	while (counter < noOfProcess) {
		rows = 0;
		gotoxy(x + 1, 4);
		scanf("%d", &proc[counter]);
		boxtab(x, 3, x + 2, 5);
		for (int i = 0; i < frames; i++) {
			boxtab3(x, rows + 5, x + 2, rows + 7);
			rows += 2;
		}
		x += 2;
		index++;
		counter++;
	}

	// Display output per process
	for (x = 0; x < noOfProcess; x++) { // Per process
		push(proc[x], x);
		for (int i = 0; i < frames; i++) { // Per row
			gotoxy(3 + x * 2, 6 + i * 2);
			if (row[i] == -1)
				printf(" ");
			else
				printf("%d", row[i]);
		}
	}

	// Display total page fault
	gotoxy(24, 72);
	totalPageFault();

	return 0;
}
