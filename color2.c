#include <stdio.h>

#define RESET		0
#define BRIGHT 		1
#define DIM		2
#define UNDERLINE 	3
#define BLINK		4
#define REVERSE		7
#define HIDDEN		8

#define BLACK 		0
#define RED		1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

char *attrs[] = {"NORMAL", "BRIGHT", "DIM", "UNDERLINE", "BLINK",
		 "REVERSE", "HIDDEN", "EXIT"};
char *colors[] = {"BLACK", "RED", "GREEN", "YELLOW", "BLUE", "MAGENTA",
		 "CYAN", "WHITE", "EXIT"};
void textcolor(int attr, int fg, int bg);
int print_menu(char *array[], int n_options, char *title);
int main()
{	int attr, fg, bg;
	int attr_size, colors_size;
	
	attr_size = ARRAY_SIZE(attrs);
	colors_size = ARRAY_SIZE(colors);
	while(1)
	{	printf("\n");
		attr = print_menu(attrs, attr_size, "Choose the attr you want:");
		if(attr == attr_size - 1)
			break;
		fg = print_menu(colors, colors_size, "Choose the foreground you want:");
		if(attr == colors_size - 1)
			break;
		bg = print_menu(colors, colors_size, "Choose the background you want:");
		if(attr == colors_size - 1)
			break;
		printf("\n");
		textcolor(attr, fg, bg);	
		printf("This is what you get if you use the combination %s attribute %s foreground and %s background", attrs[attr], colors[fg], colors[bg]);
		textcolor(RESET, WHITE, BLACK);
		system("clear");
	}
	return 0;
}

int print_menu(char *array[], int n_options, char *title)
{	int choice, i;
	for(i = 0;i < n_options; ++i)
		printf("%d.%s\n", i, array[i]);
	printf("%s", title);
	scanf("%d", &choice);
	return choice;
}		
void textcolor(int attr, int fg, int bg)
{	char command[13];

	/* Command is the control command to the terminal */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}

