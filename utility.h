#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<colors.h>

using namespace std;
void loadingBar(char color[], int col, int row);
void typeWriterUninterrupted(char arrayName[], int time, int colNumber, int rowNumber);

void gotoxy(int x, int y)
{
	HANDLE col=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD row;
	row.X=x;
	row.Y=y;
	SetConsoleCursorPosition(col,row);	
}
void box1(int x1, int y1, int x2, int y2, char ch)
{
	int x;
	for(x=x1;x<=x2;x++)
	{
		gotoxy(x,y1);putchar(ch);
		gotoxy(x,y2);putchar(ch);
	}
	for(x=y1;x<=y2;x++)
	{
		gotoxy(x1,x);putchar(ch);
		gotoxy(x2,x);putchar(ch);
	}
}
void box2(int x1, int y1, int x2, int y2)
{
	int x;
	for(x=x1;x<=x2;x++)
	{
		gotoxy(x,y1);putchar(205);
		gotoxy(x,y2);putchar(205);
	}
	for(x=y1;x<=y2;x++)
	{
		gotoxy(x1,x);putchar(186);
		gotoxy(x2,x);putchar(186);
	}
		gotoxy(x1,y1);putchar(201);
		gotoxy(x2,y1);putchar(187);
		gotoxy(x1,y2);putchar(200);
		gotoxy(x2,y2);putchar(188);
}
void box3(int x1, int y1, int x2, int y2)
{
	int x;
	for(x=x1;x<=x2;x++)
	{
		gotoxy(x,y1);putchar(196);
		gotoxy(x,y2);putchar(196);
	}
	for(x=y1;x<=y2;x++)
	{
		gotoxy(x1,x);putchar(179);
		gotoxy(x2,x);putchar(179);
	}
		gotoxy(x1,y1);putchar(218);
		gotoxy(x2,y1);putchar(191);
		gotoxy(x1,y2);putchar(192);
		gotoxy(x2,y2);putchar(217);
}
void fillscreen(int x1, int y1, int x2, int y2, char ch)
{
	int col,row;
	for(col=x1;col<=x2;col++)
	{
		for(row=y1;row<=y2;row++)
		{
			gotoxy(col,row);putchar(ch);
		}
	}
}
void clearportion(int x1, int y1, int x2, int y2)
{
	int col,row;
	for(col=x1;col<=x2;col++)
	{
		for(row=y1;row<=y2;row++)
		{
			gotoxy(col,row);putchar(' ');
		}
	}
}
void printxy(int col, int row, char ch[])
{
	gotoxy(col,row);puts(ch);
}
void printxy2(int col, int row, char ch[], char variable)
{
	gotoxy(col,row);printf(ch, variable);
}
void center(int row, char ch[])
{
	int col;
	col=(80-strlen(ch))/2+1;
	gotoxy(col,row);puts(ch);
}
void hline(int row,int col1,int col2,char ch)
{ //creates a horizontal line 
	int x; 
	for(x=col1;x<=col2;x++)
	{
		gotoxy(x,row); 
		putchar(ch);
	}
}
void vline(int col,int row1,int row2,char ch)
{ //creates a vertical line 
	int x; 
	for(x=row1;x<=row2;x++)
	{
		gotoxy(col,x); 
		putchar(ch);
	}
}
void eraserow(int row,int col1, int col2)
{ //clears a particular row in a screen 
	int x;
	for (x=col1;x<=col2;x++)
	{
		gotoxy(x,row);printf(" ");
	}
}
void boxtab(int x1,int y1, int x2, int y2)
{
	int x=0; 
	for (x=x1+1;x<=x2-1;x++)
	{
	gotoxy(x,y1);putchar(196); 
	gotoxy(x,y2);putchar(196);
	}
	
	for (x=y1;x<=y2;x++)
	{
	gotoxy(x1,x);putchar(179); 
	gotoxy(x2,x);putchar(179);
	}
	gotoxy(x1,y1);putchar(194);
	gotoxy(x2,y1);putchar(191);
	gotoxy(x1,y2);putchar(193);
	gotoxy(x2,y2);putchar(217);
	
}
void boxtab2(int x1,int y1, int x2, int y2)
{
	int x=0; 
	for (x=x1+1;x<=x2-1;x++)
	{
	gotoxy(x,y1);putchar(196); 
	gotoxy(x,y2);putchar(196);
	}
	
	for (x=y1;x<=y2;x++)
	{
	gotoxy(x1,x);putchar(179); 
	gotoxy(x2,x);putchar(179);
	}
	gotoxy(x1,y1);putchar(195);
	gotoxy(x2,y1);putchar(180);
	gotoxy(x1,y2);putchar(192);
	gotoxy(x2,y2);putchar(217);
	
}
void boxtab3(int x1,int y1, int x2, int y2)
{
	int x=0; 
	for (x=x1+1;x<=x2-1;x++)
	{
	gotoxy(x,y1);putchar(196); 
	gotoxy(x,y2);putchar(196);
	}
	
	for (x=y1;x<=y2;x++)
	{
	gotoxy(x1,x);putchar(179); 
	gotoxy(x2,x);putchar(179);
	}
	gotoxy(x1,y1);putchar(197);
	gotoxy(x2,y1);putchar(180);
	gotoxy(x1,y2);putchar(193);
	gotoxy(x2,y2);putchar(217);
	
}
void login()
{	
	char consUsername[10] = "admin";
	char consPassword[10] = "1234";
	char username[20];
	char password[20];
	
	system("cls");
	
	box3(38, 3, 77, 26);
	printxy(49, 6, "   _ \\  _ \\ __ __| \n");
	printxy(49, 7, "  (   | __/    | \n");
	printxy(49, 8," \\___/ _|     _| \n");

	
	box3(45, 13, 70, 15);
	printxy(46, 12, "Username");
	
	box3(45, 18, 70, 20);
	printxy(46, 17, "Password");
	
	gotoxy(46, 14);scanf("%s", &username);
	gotoxy(46, 19);scanf("%s", &password);
	
while (1){	
	if (strcmp(username, consUsername) == 0 && strcmp(password, consPassword) == 0){
		clearportion(39, 22, 76, 24);
		printxy(49, 22, "Login successful!");Sleep(500);
		printxy(45, 23, "Redirecting to dashboard...");Sleep(800);
		break;
     }
	else {
		if (strcmp(username, consUsername) != 0 && strcmp(password, consPassword) != 0){
			clearportion(39, 22, 76, 24);
			printxy(43, 22, "Invalid username and password.");
			printxy(49, 23, "Please try again.");
			printxy(46, 14, "                        ");
			printxy(46, 19, "                        ");
			gotoxy(46, 14);scanf("%s", &username);
			gotoxy(46, 19);scanf("%s", &password);
			continue;	
		}
		else if (strcmp(username, consUsername) != 0) {
			clearportion(39, 22, 76, 24); 
			printxy(49, 22, "Invalid username.");
			printxy(49, 23, "Please try again.");
			printxy(46, 14, "                        ");
			gotoxy(46, 14);scanf("%s", &username);
			continue;
		}
		else if (strcmp(password, consPassword) != 0) {
			clearportion(39, 22, 76, 24);
			printxy(49, 22, "Invalid password.");
			printxy(49, 23, "Please try again.");
			printxy(46, 19, "                        ");
			gotoxy(46, 19);scanf("%s", &password);
			continue;
		}
	}
}
}
void typeWriter(char arrayName[], int time, int colNumber, int rowNumber) {
	int currentCol = colNumber;
    int currentRow = rowNumber;
    

    for (int i = 0; arrayName[i] != '\0'; i++) {
    	
    	if (kbhit()){
    		typeWriterUninterrupted(arrayName, 0, colNumber, rowNumber);
    		
    		return;
    	}
        if (arrayName[i] == '\n') {
            currentRow++;  
            currentCol = colNumber;  
            gotoxy(currentCol, currentRow);
        } 
		else {
            gotoxy(currentCol, currentRow);
            printf("%c", arrayName[i]);  
            fflush(stdout);  
            currentCol++;
        }
        Sleep(time); 
    }
}
void typeWriterUninterrupted(char arrayName[], int time, int colNumber, int rowNumber) {
	int currentCol = colNumber;
    int currentRow = rowNumber;
    

    for (int i = 0; arrayName[i] != '\0'; i++) {
    	
        if (arrayName[i] == '\n') {
            currentRow++;  
            currentCol = colNumber;  
            gotoxy(currentCol, currentRow);
        } 
		else {
            gotoxy(currentCol, currentRow);
            printf("%c", arrayName[i]);  
            fflush(stdout);  
            currentCol++;
        }
        Sleep(time); 
    }
}

void loadingBar(char color[], int col, int row) {
	int totalBar = 100;
	
    for (int i = 0; i <= totalBar; i+=5) {
    	printf("%s", color);
    	int barLength = (i * 30) / totalBar;
        gotoxy(col, row);
		printf("[");
        for (int j = 0; j < barLength; j++) printf("%c", 219);  
        for (int j = barLength + 1; j < 30; j++) printf(" "); 
        printf("] %d%%", i); 
        fflush(stdout); 
        Sleep(100);
        printf(RESET);
    }
}
void splashScreen()
{
	printf(BOLD BLUE);
	system("cls");
	box3(27, 4, 92, 20);
	printxy(30, 6," .----------------.  .----------------.  .----------------. ");
	printxy(30, 7, "| .--------------. || .--------------. || .--------------. |");
	printxy(30, 8, "| |     ____     | || |   ______     | || |  _________   | |");
	printxy(30, 9, "| |   .'    `.   | || |  |_   __ \\   | || | |  _   _  |  | |");
	printxy(30, 10, "| |  /  .--.  \\  | || |    | |__) |  | || | |_/ | | \\_|  | |");
	printxy(30, 11, "| |  | |    | |  | || |    |  ___/   | || |     | |      | |");
	printxy(30, 12, "| |  \\  `--'  /  | || |   _| |_      | || |    _| |_     | |");
	printxy(30, 13, "| |   `.____.'   | || |  |_____|     | || |   |_____|    | |");
	printxy(30, 14, "| |              | || |              | || |              | |");
	printxy(30, 15, "| '--------------' || '--------------' || '--------------' |");
	printxy(30, 16, " '----------------'  '----------------'  '----------------' ");
	
	char startingPhrase[40] = "Opening the OPT Algorithm Menu. . . .";
	int j = 40;
	for (int i = 0; startingPhrase[i] != '\0'; i++){
		gotoxy(j, 18);
		printf("%c", startingPhrase[i]);
		Sleep(25);
		j++;
	}
	loadingBar(BOLD CYAN, 40, 22);
	printf(RESET);
}
void ourLogo()
{
	printxy(17, 1, " ______   ______  ______ \n");
	printxy(17, 2, "/\\  __ \\ /\\  == \\/\\__  _\\\n");
	printxy(17, 3, "\\ \\ \\/\\ \\\\ \\  _-/\\/_/\\ \\/\n");
 	printxy(17, 4, " \\ \\_____\\\\ \\_\\     \\ \\_\\\n");
 	printxy(17, 5, "  \\/_____/ \\/_/      \\/_/ \n");
}
void isometric1() {
	
	printxy(39, 9, "	     ___           ___           ___");
	printxy(39, 10, "     /\\  \\         /\\  \\         /\\  \\");
	printxy(39, 11, "    /::\\  \\       /::\\  \\        \\:\\  \\ ");
	printxy(39, 12, "   /:/\\:\\  \\     /:/\\:\\  \\        \\:\\  \\  ");
	printxy(39, 13, "  /:/  \\:\\  \\   /::\\~\\:\\  \\       /::\\  \\ ");
	printxy(39, 14, " /:/__/ \\:\\__\\ /:/\\:\\ \\:\\__\\     /:/\\:\\__\\");
	printxy(39, 15, " \\:\\  \\ /:/  / \\/__\\:\\/:/  /    /:/  \\/__/");
	printxy(39, 16, "  \\:\\  /:/  /       \\::/  /    /:/  / ");
	printxy(39, 17, "   \\:\\/:/  /         \\/__/     \\/__/ ");
	printxy(39, 18, "    \\::/  / ");
	printxy(39, 19, "     \\/__/");                         
       
}
void isometric2() {
	
	printxy(39, 9, "      ___           ___               ");
	printxy(39, 10, "     /\\  \\         /\\  \\             ");
	printxy(39, 11, "    /::\\  \\       /::\\  \\       ___  ");
	printxy(39, 12, "   /:/\\:\\  \\     /:/\\:\\__\\     /\\__\\ ");
	printxy(39, 13, "  /:/  \\:\\  \\   /:/ /:/  /    /:/  /   ");
	printxy(39, 14, " /:/__/ \\:\\__\\ /:/_/:/  /    /:/__/   ");
	printxy(39, 15, " \\:\\  \\ /:/  / \\:\\/:/  /    /::\\  \\   ");
	printxy(39, 16, "  \\:\\  /:/  /   \\::/__/    /:/\\:\\  \\ ");
	printxy(39, 17, "   \\:\\/:/  /     \\:\\  \\    \\/__\\:\\  \\ ");
	printxy(39, 18, "    \\::/  /       \\:\\__\\        \\:\\__\\ ");
	printxy(39, 19, "     \\/__/         \\/__/         \\/__/ ");                             

}
void isometric3() {
	
	printxy(39, 9, "      ___           ___               ");
	printxy(39, 10, "     /  /\\         /  /\\        ___   ");
	printxy(39, 11, "    /  /::\\       /  /::\\      /  /\\");
	printxy(39, 12, "   /  /:/\\:\\     /  /:/\\:\\    /  /:/");
	printxy(39, 13, "  /  /:/  \\:\\   /  /:/~/:/   /  /:/");
	printxy(39, 14, " /__/:/ \\__\\:\\ /__/:/ /:/   /  /::\\");
	printxy(39, 15, " \\  \\:\\ /  /:/ \\  \\:\\/:/   /__/:/\\:\\");
	printxy(39, 16, "  \\  \\:\\  /:/   \\  \\::/    \\__\\/  \\:\\");
	printxy(39, 17, "   \\  \\:\\/:/     \\  \\:\\         \\  \\:\\");
	printxy(39, 18, "    \\  \\::/       \\  \\:\\         \\__\\/");
	printxy(39, 19, "     \\__\\/         \\__\\/  ");                         
           
}
void isometric4() {
	
	printxy(39, 9, "	     ___");
	printxy(39, 10, "     /  /\\          ___           ___ ");
	printxy(39, 11, "    /  /::\\        /  /\\         /__/\\ ");
	printxy(39, 12, "   /  /:/\\:\\      /  /::\\        \\  \\:\\");
	printxy(39, 13, "  /  /:/  \\:\\    /  /:/\\:\\        \\__\\:\\ ");
	printxy(39, 14, " /__/:/ \\__\\:\\  /  /::\\ \\:\\       /  /::\\");
	printxy(39, 15, " \\  \\:\\ /  /:/ /__/:/\\:\\_\\:\\     /  /:/\\:\\");
	printxy(39, 16, "  \\  \\:\\  /:/  \\__\\/  \\:\\/:/    /  /:/__\\/");
	printxy(39, 17, "   \\  \\:\\/:/        \\  \\::/    /__/:/ ");
	printxy(39, 18, "    \\  \\::/          \\__\\/     \\__\\/ ");
	printxy(39, 19, "     \\__\\/   ");                         
                                    
}

