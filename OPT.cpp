#include <utility.h>
#include <colors.h>

// Global variables
int row[20], proc[50], frames = 0, noOfProcess = 0, pageFault = 0;

// Function declarations
void welcomeDescription();
void showInformation();
void showAboutUs();
void showExit();
void showMainHeader();
void showOptSimulator();
int findFurthest(int z);
char push(int val, int index);
void totalPageFault();

// Main header function
void showMainHeader() {
	char option = ' ';
	system("cls");

	// Display the main menu
	printf(BOLD CYAN);
	ourLogo();
	printf(BOLD WHITE);
	box2(15, 0, 105, 29);
	printf(BOLD CYAN);
	box3(43, 2, 102, 4);
	box3(18, 7, 65, 28);
	box3(67, 7, 102, 28);
	box3(70, 8, 99, 10);
	printf(BOLD YELLOW);
	printxy(45, 3, "[A]Home  [B]Simulator  [C]Information  [D]About  [E]Exit");
	printxy(76, 9, "OPT Algorithm Menu");
	printxy(75, 13, "[A] Home");
	printxy(75, 15, "[B] Simulator");
	printxy(75, 17, "[C] Information");
	printxy(75, 19, "[D] About");
	printxy(75, 21, "[E] Exit");
	printf(BOLD GREEN);
	printxy(75, 23, "Select an Option: ");
	printf(RESET);

	// Display welcome description
	welcomeDescription();

	// Handle user input for menu navigation
	while (option != 'E') {
		if (kbhit())
			option = toupper(getch());
		else {
			gotoxy(94, 23);
			option = toupper(getche());
		}

		// Navigate to the selected option
		switch (option) {
			case 'A': {
				showMainHeader();
				break;
			}
			case 'B': {
				showOptSimulator();
				break;
			}
			case 'C': {
				showInformation();
				break;
			}
			case 'D': {
				showAboutUs();
				break;
			}
			case 'E': {
				showExit();
				break;
			}
			default: {
				clearportion(93, 23, 97, 23);
				break;
			}
		}
		fflush(stdin);
	}
}

// Simulator for the Optimal Page Replacement Algorithm
void showOptSimulator() {
	system("cls");

	// Display simulator header
	printf(BOLD CYAN);
	ourLogo();
	printf(BOLD WHITE);
	box2(15, 0, 105, 29);
	printf(BOLD CYAN);
	box3(43, 2, 102, 4);
	printf(BOLD YELLOW);
	printxy(56, 3, "Optimal Page Replacement Algorithm");

	// Local variables
	int x = 20, rows = 9, counter = 1, index = 1, valid = 0;

	// Ask for the number of frames
	while (valid == 0) {
		printf(BOLD YELLOW);
		printxy(20, 7, "Enter Number of Frames: ");
		gotoxy(45, 7);

		if (scanf("%d", &frames) == 1) {
			if (frames >= 3 && frames <= 6) {
				valid = 1;
			} else {
				// Display error message for invalid input
				char notValidMessage[60] =
					"Invalid input. Please enter an\n"
					"   integer between 3 and 6";
				printf(RED);
				box3(42, 10, 76, 13);
				typeWriter(notValidMessage, 2, 44, 11);
				printf(RESET);
				getch();
				clearportion(40, 10, 100, 13);
				clearportion(45, 7, 55, 7);
			}
		} else {
			// Display error message for non-integer input
			char notIntMessage[70] =
				"Invalid input. Please enter a\n"
				"        valid integer";
			printf(BOLD RED);
			box3(42, 10, 75, 13);
			typeWriter(notIntMessage, 2, 44, 11);
			printf(RESET);
			getch();
			clearportion(40, 10, 100, 13);
			clearportion(45, 7, 55, 7);
		}
		fflush(stdin); // Clear the input buffer
	}

	valid = 0;

	// Ask for the number of processes
	while (valid == 0) {
		printf(BOLD YELLOW);
		printxy(58, 7, "Enter Number of Processes: ");
		gotoxy(86, 7);

		if (scanf("%d", &noOfProcess) == 1) {
			if (noOfProcess >= 10 && noOfProcess <= 25) {
				valid = 1;
			} else {
				// Display error message for invalid input
				char notValidMessage[80] =
					"Invalid input. Please enter an\n"
					"  integer between 10 and 25";
				printf(RED);
				box3(42, 10, 76, 13);
				typeWriter(notValidMessage, 1, 44, 11);
				printf(RESET);
				getch();
				clearportion(40, 10, 100, 13);
				clearportion(86, 7, 90, 7);
			}
		} else {
			// Display error message for non-integer input
			char notIntMessage[70] =
				"Invalid input. Please enter a\n"
				"        valid integer";
			printf(BOLD RED);
			box3(42, 10, 75, 13);
			typeWriter(notIntMessage, 2, 44, 11);
			printf(RESET);
			getch();
			clearportion(40, 10, 100, 13);
			clearportion(86, 7, 90, 7);
		}
		fflush(stdin); // Clear the input buffer
	}

	// Clear the input area
	clearportion(20, 7, 100, 9);
	printxy(20, 7, "Provide the Sequence of Processes: ");

	// Initialize the row array
	for (int x = 0; x < frames; x++) {
		row[x] = -10;
	}

	// Input and display process sequence
	valid = 0;
	while (valid == 0) {
		printf(BOLD CYAN);
		gotoxy(32, 28);
		printf("Note: Please enter a single-digit integer between -9 and 9");
		gotoxy(x + 2, 10);

		if (scanf("%d", &proc[0]) == 1) {
			if (proc[0] > -10 && proc[0] < 10) {
				if (proc[0] > -10 && proc[0] < 0) {
					printxy2(x + 1, 10, "%d", proc[0]);
					box3(x, 9, x + 3, 11);
				} else {
					box3(x, 9, x + 3, 11);
				}

				for (int i = 0; i <= frames; i++) {
					boxtab2(x, rows + 2, x + 3, rows + 4);
					rows += 2;
				}
				x += 3;
				valid = 1;
			} else {
				clearportion(x + 1, 10, x + 25, 10);
			}
		} else {
			clearportion(x + 1, 10, x + 25, 10);
		}
		fflush(stdin); // Clear the input buffer
	}

	// Continue input for the remaining processes
	while (counter < noOfProcess) {
		rows = 9;
		gotoxy(x + 2, 10);

		if (scanf("%d", &proc[counter]) == 1) {
			if (proc[counter] > -10 && proc[counter] < 10) {
				if (proc[counter] > -10 && proc[counter] < 0) {
					printxy2(x + 1, 10, "%d", proc[counter]);
					boxtab(x, 9, x + 3, 11);
				} else {
					boxtab(x, 9, x + 3, 11);
				}

				for (int i = 0; i <= frames; i++) {
					boxtab3(x, rows + 2, x + 3, rows + 4);
					rows += 2;
				}
				x += 3;
				index++;
				counter++;
			} else {
				clearportion(x + 1, 10, x + 25, 10);
			}
		} else {
			clearportion(x + 1, 10, x + 25, 10);
		}
		fflush(stdin); // Clear the input buffer
	}

	// Display output per process
	int n = 21;

	for (x = 0; x < noOfProcess; x++) {
		char result = push(proc[x], x);
		gotoxy(n, frames * 2 + 12);
		printf(" %c", result);
		n += 3;

		for (int i = 0; i < frames; i++) {
			gotoxy(21 + x * 3, 12 + i * 2);
			if (row[i] == -10) {
				printf("  ");
			} else {
				if (proc[x] > 0 && proc[x] < 10) {
					if (row[i] > -10 && row[i] < 0) {
						printf("%d", row[i]);
					} else {
						printf(" %d", row[i]);
					}
				} else {
					if (row[i] > -10 && row[i] < 0) {
						printf("%d", row[i]);
					} else {
						printf(" %d", row[i]);
					}
				}
			}
		}
	}

	// Display total page faults
	gotoxy(24, 72);
	printf(BOLD RED);
	totalPageFault();

	// Ask user if they want to compute again
	char message[50] = "Do you want to compute again? ";
	printf(BOLD YELLOW);
	typeWriter(message, 25, 20, frames * 2 + 15);
	char ans = ' ';

	while (ans != 'N') {
		gotoxy(51, frames * 2 + 15);
		ans = toupper(getche());

		switch (ans) {
			case 'Y': {
				pageFault = 0;
				showOptSimulator();
				break;
			}
			case 'N': {
				showMainHeader();
				break;
			}
			default:
				clearportion(50, frames * 2 + 15, 60, frames * 2 + 15);
				break;
		}
		printf(RESET);
	}
}

// Function to find the furthest page to replace
int findFurthest(int z) {
	int further = -1;
	int rowToSwitch = -1;
	int y;

	if (z > frames - 1) {
		for (int x = frames - 1; x >= 0; x--) {
			if (row[x] != -10) {
				for (y = z + 1; y <= noOfProcess; y++) {
					if (row[x] != proc[y] && y == noOfProcess) {
						return x;
					}
					if (row[x] == proc[y]) {
						if (y > further) {
							further = y;
							rowToSwitch = x;
						}
						break;
					}
				}
			}
		}
		return rowToSwitch;
	} else {
		return z;
	}
}

// Function to push a page into memory
char push(int val, int index) {
	// Check if the page already exists in memory
	for (int x = 0; x < frames; x++) {
		if (row[x] == proc[index]) {
			pageFault++;
			return 'N';
		}
	}

	// Replace the furthest page
	for (int x = findFurthest(index); x >= 0; x--) {
		row[x] = row[x - 1];
	}
	row[0] = val;
	return 'Y';
}

// Function to calculate and display total page faults
void totalPageFault() {
	pageFault = noOfProcess - pageFault;
	double totPage = ((double)pageFault / (double)noOfProcess) * 100;
	char finalPageFault[100];

	// Format the string with the values
	snprintf(finalPageFault, sizeof(finalPageFault), "Page Fault: %d/%d = %.2lf%%", pageFault, noOfProcess, totPage);
	typeWriter(finalPageFault, 15, 56, 7);
}

// Welcome description function
void welcomeDescription() {
	char welcomeTitle[70] = "Welcome to the Optimal Page Replacement\nAlgorithm Simulator!";
	char welcomePhrase[500] =
		"\nOptimal Page Replacement is one of the\n"
		"Algorithms of Page Replacement. In this\n"
		"algorithm, pages are replaced which would\n"
		"not be used for the longest duration of\n"
		"time in the future.\n\n"
		"How to Use:\n\n"
		" 1. Enter the number of Frames (3 - 6)\n"
		" 2. Enter the number of Processes (10 - 25)\n"
		" 3. Enter the reference strings\n"
		" 4. Run the simulation to see the results\n\n"
		" Let's get started! ";

	printf(BOLD MAGENTA);
	typeWriter(welcomeTitle, 3, 20, 9);
	printf(WHITE);
	typeWriter(welcomePhrase, 3, 20, 12);
	printf(RESET);
}

// Main function
int main() {
	splashScreen();
	showMainHeader();
	return 0;
}
