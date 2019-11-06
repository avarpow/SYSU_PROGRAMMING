/*
Given a number n, print a "W" with n x 4n-3 characters. (height is n and width is 4n-3)

Please complete the program according to the input and output examples.

EXAMPLE INPUT 1
7

EXAMPLE OUTPUT 1
*           *           *
 *         * *         * 
  *       *   *       *  
   *     *     *     *   
    *   *       *   *    
     * *         * *     
      *           *     
EXAMPLE INPUT 2
10

EXAMPLE OUTPUT 2
*                 *                 *
 *               * *               * 
  *             *   *             *  
   *           *     *           *   
    *         *       *         *    
     *       *         *       *     
      *     *           *     *      
       *   *             *   *       
        * *               * *        
         *                 *         
*/
#include<stdio.h>
int a[500][500]={0};
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n ;i++){
        a[i][i] = '*';
        a[i][i+2*n-2] = '*';
        a[i][2*n-2-i] =  '*';
        a[i][4*n-4-i] =  '*';
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < 4*n-1;j++){
            if(a[i][j])
                printf("%c", a[i][j]);
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}