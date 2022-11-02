#include<stdio.h>
//#include<curses.h>
#include<ncurses.h>
//#include<wchar.h>
#include<locale.h>
#include<string.h>

// ╔ ╗ ╚ ╝ ╣ ╠ ╦ ╩ ╬ ═ ║ " "
// 0 1 2 3 4 5 6 7 x h v s

//printf("╔════╝   ╚════╗\n");
//printf("║             ║\n");
//printf("╝             ╚\n");
//printf("               \n");
//printf("╗             ╔\n");
//printf("║             ║\n");
//printf("╚════╗   ╔════╝\n");

//=====[NOTES]================|
// Finish Counter System
// Create world system
// merge world and counter
// create special worlds



// Global key variable

void clrscr(){
	initscr();
	erase();
	noecho();
	raw();
	move(0,0);
	// Cursor off
	curs_set(0);
	refresh();
}

// Move cursor to coordinate
void moveCursor(unsigned int x, unsigned int y){
	// Maybe swap these idk
	move(x,y);
}

void charPrint(unsigned int x, unsigned int y, char outString[255]){
	mvprintw(y,x,outString);
}

void worldCheck(unsigned int wx, unsigned int wy){
	if(wx==6&&wy==9){charPrint(0,5,"      NICE!");}
	else{charPrint(0,5,"                 ");}
}


// Global vars
int key;
// Starting location
char x=8,y=5;
char wx=0,wy=0;
int main(){
	setlocale (LC_ALL, "");
	//Clear Screen
	clrscr();
	// Loop until q is pressed
	while ((key = getch()) !='q'){
		charPrint(0,3,"   ▄▄▄▄█ █▄▄▄▄");
		charPrint(0,4,"  ▄█         █▄");
		charPrint(0,5,"               ");
		charPrint(0,6,"  ▀█         █▀");
		charPrint(0,7,"   ▀▀▀▀█ █▀▀▀▀ ");
		worldCheck(wx,wy);


		// Check for character
    int ch[8];// = mvwinch(0, 3, 7);
		sprintf(ch,"&d",mvwinch(0,3,7));
		charPrint(0,2,ch);
		//char pCoords[64];
		//mvprintw(0,0,"                                        ");
		//sprintf(pCoords, "P-Coords:[%d,%d]", x, y);
		//mvprintw(0,0,pCoords);


		// Clears character after moving
		charPrint(x,y," ");
		// Handle Keys [This shit needs to be re-written]
		switch (key){
			case 'w':
				if((x<=3&&y==5)||(x>=13&&y==5)){
					break;
				}else if(((x==8)||(y>4))){
					y--;
				}				
				break;
			case 'a':
				if((x==8&&y<=3)||(x==8&&y>=7)){
					break;
				}else if((y==5)||(x>4)){
					x--;
				}
				break;
			case 's':
				if((x<=3&&y==5)||(x>=13&&y==5)){
					break;
				}else if((x==8)||(y<6)){
					y++;
				}
				break;
			case 'd':
				if((x==8&&y<=3)||(x==8&&y>=7)){
					break;
				}else if((y==5)||(x<12)){
					x++;
				}
				break;
			default:
				break;
		}

		//Real-Time Items

		// Print player character
		charPrint(x,y,"@");
		//==[Check for door]==============|
		// Bottom Door
		if(x==8&&y==8){
      charPrint(8,8," ");
			charPrint(8,3,"@");
			y=3;
			wy--;
			worldCheck(wx,wy);
    }// Top Door
		else if(x==8&&y==2){
			charPrint(8,2," ");
			charPrint(8,7,"@");
			y=7;
			wy++;
			worldCheck(wx,wy);
		}// Right Door
		else if(x==14&&y==5){
      charPrint(14,5," ");
			charPrint(3,5,"@");
			x=3;
			wx++;
			worldCheck(wx,wy);
    }// Left Door
		else if(x==2&&y==5){
			charPrint(2,5," ");
			charPrint(13,5,"@");
			x=13;
			wx--;
			worldCheck(wx,wy);
		}

    char pCoords[64];
    mvprintw(0,0,"                                        ");
    sprintf(pCoords, "P-Coords:[%d,%d]", x, y);
    mvprintw(0,0,pCoords);

    char wCoords[64];
    sprintf(wCoords, "W-Coords:[%d,%d]", wx, wy);
    mvprintw(1,0,wCoords);
		refresh();
	}
	echo();
	curs_set(1);
	endwin();
	return(0);
}


























//EOF
