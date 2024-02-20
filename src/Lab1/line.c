#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void) {
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");

   errorcode = graphresult();
   if (errorcode != grOk) {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

   setcolor(getmaxcolor());
   line(100, 100, 300, 300);
   getch();
   closegraph();
   return 0;
}

