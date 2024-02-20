#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void) {
   int gdriver = DETECT, gmode, errorcode;
   int left, top, right, bottom;
   initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");

   errorcode = graphresult();
   if (errorcode != grOk) {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   left = getmaxx() / 2 - 50;
   top = getmaxy() / 2 - 40;
   right = getmaxx() / 2 + 70;
   bottom = getmaxy() / 2 + 50;

   rectangle(left, top, right, bottom);
   getch();
   closegraph();
   return 0;
}


