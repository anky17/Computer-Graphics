#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void eightWaySymmetry(int xc, int yc, int x, int y){
   putpixel(xc + x, yc + y, 7);
   putpixel(xc - x, yc + y, 7);
   putpixel(xc + x, yc - y, 7);
   putpixel(xc - x, yc - y, 7);
   putpixel(xc + y, yc + x, 7);
   putpixel(xc - y, yc + x, 7);
   putpixel(xc + y, yc - x, 7);
   putpixel(xc - y, yc - x, 7);
   delay(50);
}

void midPoint(int xc, int yc, int r){
	int x = 0, y = r;
	int p = 1 - r;

	while (x < y){
		x++;
		if (p < 0){
			 p = p + 2 * x + 1;
		} else {
			 y--;
			 p = p + 2 * x + 1 - 2 * y;
		}
		eightWaySymmetry(xc, yc, x, y);
   }   
}

int main(){
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
   errorcode = graphresult();
   if (errorcode != grOk) {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); 
   }
   midPoint(180, 240, 100);
   getch();
   closegraph();
   return 0;
}