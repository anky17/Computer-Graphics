#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>

void fourWaySymmetry(float xc,float yc,float x,float y){
	putpixel(xc+x,yc+y,7);
	putpixel(xc-x,yc+y,7);
	putpixel(xc+x,yc-y,7);
	putpixel(xc-x,yc-y,7);
}

void ellipsemidpoint(float xc,float yc,float rx,float ry){
	float rxsq=rx*rx;
	float rysq=ry*ry;
	float x=0,y=ry,p;
	float px=0,py=2*rxsq*y;
	fourWaySymmetry(xc,yc,x,y);
	//region 1
	p=rysq - (rxsq * ry) + (0.25 * rxsq);
	while(px<py){
		x++;
		px=px+2*rysq;
		if(p<0){
			p=p+rysq+px;
		} else	{
			y--;
			py=py-2*rxsq;
			p=p+rysq+px-py;
		}
		fourWaySymmetry(xc,yc,x,y);
		delay(30);
	}
	//region 2
	p=rysq * (x+0.5) * (x+0.5) +rxsq * (y-1) * (y-1)-rxsq * rysq;
	while(y>0){
		y--;
		py=py-2*rxsq;
		if(p>0){
			p=p+rxsq-py;
		} else{
			x++;
			px=px+2*rysq;
			p=p+rxsq-py+px;
		}
		fourWaySymmetry(xc,yc,x,y);
		delay(30);
	}
}


int main(){
	int gd=DETECT,gm, errorcode;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");  
	errorcode = graphresult();
	if (errorcode != grOk){
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); 
    }	
	ellipsemidpoint(240,180,50,100);
	ellipsemidpoint(180,340,100,50);
	getch();
}

