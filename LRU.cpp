#include <utility.h>
#include <colors.h>

// Global variables
int row[20], proc[50], frames = 0, noOfProcess = 0, pageFault = 0;

// Function to handle page replacement using LRU
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

	// If the value doesn't exist, shift all values down
	for (int x = frames - 1; x > 0; x--)
		row[x] = row[x - 1];

	row[0] = val; // Place the new value at row[0]
	pageFault++;  // Increment page fault count
}

// Function to calculate and display total page faults
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
	gotoxy(x + 1, 4);
	scanf("%d", &proc[0]);
	box3(x, 3, x + 2, 5);

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

		for (int i = 0; i < frames; i++) {
			boxtab3(x, rows + 5, x + 2, rows + 7);
			rows += 2;
		}
		x += 2;
		index++;
		counter++;
	}

	// Display output per process
	for (x = 0; x < noOfProcess; x++) {
		push(proc[x], x); // Perform LRU page replacement

		for (int i = 0; i < frames; i++) {
			gotoxy(3 + x * 2, 6 + i * 2);
			if (row[i] == -1)
				printf(" ");
			else
				printf("%d", row[i]);
		}
	}

	// Display total page faults
	gotoxy(24, 72);
	totalPageFault();

	return 0;
}
