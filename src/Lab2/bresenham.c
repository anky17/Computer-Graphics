#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

void lineBre(int x1, int y1, int x2, int y2) {
	int x, y, p, dx, dy;
	putpixel(x1, y1, WHITE);
	dx = x2 - x1;
	dy = y2 - y1;
	p = 2 * dy - dx;
	x = x1;
	y = y1;
	while (x < x2) {
		delay(100);
		if (p >= 0) {
			putpixel(x, y, WHITE);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		} else {
			putpixel(x, y, WHITE);
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}

int main() {
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");

	errorcode = graphresult();
	if (errorcode != grOk) {
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1);
	}
	lineBre(0, 0, 100, 100);
	lineBre(100, 100, 300, 200);
	lineBre(200, 0, 400, 200);

	getch();
	return 0;
}