#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<stdlib.h> 
main()
{	
float x,y,z,f;
system("color 94");
for(y=1.5f;y>-1.5f;y-=0.1f)
{
for(x=-1.5f;x<1.5f;x+=0.05f)
{
z=x*x+y*y-1;
f=z*z*z-x*x*y*y*y;
putchar(f<=0.0f?".:-=*#%@"[(int)(f*-8.0f)]:' ');
Sleep(10); 
}
putchar('\n');
}
for(;;){
    system("color be");
	printf("\t��\t");
	Sleep (40);
	printf("��\t");
	Sleep (40);
	printf("Զ\t");
	Sleep (40);
	printf("��\t");
	Sleep (40);
	printf("��\t");
	Sleep (40);
	printf("��\t");
	Sleep (40);
	printf("��\n");
	Sleep (40);
}

}
