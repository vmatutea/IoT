#include<stdio.h>#include<conio.h>void main(){ clrscr(); int a; printf("enter the starting number"); scanf("%d",&a); int b=0; int c=1; printf("%d\t",b); printf("%d\t",c); for (int i=0;i<a;i++) {  int d=b+c;  printf("%d\t",d);  b=c;  c=d;  }  getch();  }
