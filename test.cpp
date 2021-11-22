#include<iostream>
#include<string>
using namespace std;

int main(void){

    FILE *fptr;
    char buff[1000],c[5];

    fptr = fopen("sample.zzz","r");
      
      c[1] = fgetc(fptr);
    do {
        c[0] = c[1];
        c[1] = c[2];
        c[2] = fgetc(fptr);
      
      if( feof(fptr) ) {
         break ;
      }
      printf("%c", c[1]);
   } while(1);;

   fclose(fptr);

}