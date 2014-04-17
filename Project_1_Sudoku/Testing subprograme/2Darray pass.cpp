 /* 
2 (C) OOMusou 2008 http://oomusou.cnblogs.com
3 
4 Filename    : array_2_dim_pass_to_function_full_subscript.c
5 Compiler    : Visual C++ 8.0
6 Description : Pass 2 dim array to function by subscript
7 Release     : 03/16/2007 1.0
8 */
#include <stdio.h>
#include <stdlib.h> 
 #define ROWSIZE 3
 #define COLSIZE 2
 
 void func(int ia[ROWSIZE][COLSIZE]) {
   int i,j;
   for(i = 0; i < ROWSIZE; ++i) {
     for(j = 0; j < COLSIZE; ++j) {
       printf("%d ", ia[i][j]);
     }
     printf("\n");
   }
 }
 
 int main() {
   int ia[ROWSIZE][COLSIZE] = {{1, 2}, {3, 4}, {5,6}};
   func(ia); 
   system("pause");
   return 0;
 }

