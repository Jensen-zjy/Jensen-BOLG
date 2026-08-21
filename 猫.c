#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

static void clear_screen(void)
{
	system("cls");
}

static void draw_frame(int y, int frame)
{
	int i;

	clear_screen();
	printf("                 猫爬树动画\n\n");
	printf("                         **\n");
	printf("                        ****\n");
	printf("                         ||\n");
	printf("                         ||\n");
	printf("                  _______||_______\n");
	printf("                 /        ||       \\\n");
	printf("                /         ||        \\\n");
	printf("                         ||\n");

	for (i = 0; i < y; ++i)
		putchar('\n');

	if (frame % 2 == 0)
		printf("                         /\\_/\\\n");
	else
		printf("                         /\\_/\\\n");
	printf("                        ( o.o )\n");
	printf("                         > ^ <\n");
	if (frame % 2 == 0)
		printf("                          /|\n");
	else
		printf("                         |\\\n");
	printf("                          ||\n");
	printf("                          ||\n");
	printf("                          ||\n");
	printf("                          ||\n");
	printf("                          ||\n");
	printf("                          ||\n");
	printf("                         /  \\\n");
	printf("                        /____\\\n");
}

int main(void)
{
	int y;

	SetConsoleOutputCP(65001);
	for (y = 8; y >= 0; --y) {
		draw_frame(y, y);
		Sleep(250);
	}

	draw_frame(0, 0);
	printf("\n喵！我爬到树顶啦！\n");
	system("pause");
	return 0;
}
