/* 
   	Função para criar uma lupinha de pesquisa
	
	- passe como parâmetro (a coluna de inicio, a linha de inicio)
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

//text_info vActual = {0, 0, 79, 24, WHITE, WHITE, C80, 80, 28, 1, 1}; // Define os limites para linha (35) e coluna (80)

// Funções conio.c

void textcolor(int newcolor);
void textbackground(int newcolor);
void gotoxy(int x, int y);

// Função utilizada para a criar a lupa
void lupa(int ic, int il);

main()
{
	SetConsoleTitle("Func_Lupa"); 		 // Define o nome do console
    system("mode con:cols=80 lines=28");  // Define o tamanho do console
	
	textbackground(3);  //12 linhas
	system("cls");
	
	lupa(10, 4);
	
	gotoxy(25,25);
}

void lupa(int ic, int il){
	
	textcolor(0);
	textbackground(3);
	// Linha 1 - Borda Preta
	gotoxy(ic+4, il); 		printf("%c%c%c%c%c%c%c%c%c%c%c",220 ,220, 219, 219, 219, 219, 219, 219, 219, 220, 220);	
	// Linha 2  
	gotoxy(ic+2, il+1); 	printf("%c%c%c%c       %c%c%c%c", 220, 219, 219, 223, 223, 219, 219, 220);
	//linha 3
	gotoxy(ic+1, il+2); 	printf("%c%c             %c%c", 219, 223, 223, 219);
	//linha 4
	gotoxy(ic, il+3);  		printf("%c%c               %c%c", 219, 223, 223, 219);
	//linha 5
	gotoxy(ic, il+4);	 	printf("%c                 %c", 219, 219);	
	//linha 6
	gotoxy(ic, il+5);  		printf("%c%c               %c%c", 219, 220, 220, 219);
	//linha 7
	gotoxy(ic+1, il+6);		printf("%c%c             %c%c", 219, 220, 220, 219);	
	// Linha 8  
	gotoxy(ic+2, il+7); 	printf("%c%c%c%c       %c%c%c%c", 223, 219, 219, 220, 220, 219, 219, 223);
	// Linha 9 
	gotoxy(ic+4, il+8); 	printf("%c%c%c%c%c%c%c%c%c%c%c",223 ,223, 219, 219, 219, 219, 219, 219, 219, 223, 223);		
	
	//brilhinho
	textcolor(15);
	gotoxy(ic+3, il+4); printf("%c", 219);
	gotoxy(ic+4, il+5); printf("%c%c%c", 219, 219, 220);
	gotoxy(ic+7, il+6); printf("%c%c", 219, 220);
	
	//cabo
	textcolor(15);
	gotoxy(ic+18, il+6); printf("%c%c", 219,220);
	gotoxy(ic+16, il+7); printf("%c%c%c%c%c%c", 219, 219, 219, 219, 219, 220);
	gotoxy(ic+15, il+8); printf("%c%c%c%c%c%c%c%c%c", 223, 223, 219, 219, 219, 219, 219, 219,220);
	gotoxy(ic+18, il+9); printf("%c%c%c%c%c%c%c%c", 223, 219, 219, 219, 219, 219, 219, 220);			//cabo
	gotoxy(ic+20, il+10); printf("%c%c%c%c%c%c%c%c", 223, 219, 219, 219, 219, 219, 219, 220);
	gotoxy(ic+22, il+11);printf("%c%c%c%c%c%c%c", 223, 219, 219, 219, 219, 219, 219);
	gotoxy(ic+24, il+12);printf("%c%c%c%c%c", 223, 219, 219, 219, 219,223);
	
}

void textcolor(int newcolor)
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0xf0) | newcolor);
   //vActual.attribute = (csbi.wAttributes & 0xf0) | newcolor;
}

void textbackground(int newcolor)
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0x0f) | (newcolor << 4));
   //vActual.attribute = (csbi.wAttributes & 0x0f) | (newcolor << 4);
}

void gotoxy(int x, int y)
{
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

