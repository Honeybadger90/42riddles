#include <stdio.h>
#include <string.h>

typedef struct {
  int id;
  char name[20];
} item;

int main() { 
  FILE *fptr;
  item first, second, secondf;

  /* create records */
  first.id = 10276;
  strcpy(first.name, "Widget");
  second.id = 11786;
  strcpy(second.name, "Gadget");
  
  /* write records to a file */
  fptr = fopen("info.dat", "wb");
  fwrite(&first, 1, sizeof(first), fptr);
  fwrite(&second, 1, sizeof(second), fptr);
  fclose(fptr); 

  /* file contains 2 records of type item */
  fptr = fopen("info.dat", "rb");

  /* seek second record */
  fseek(fptr, 0*sizeof(item), SEEK_SET); /* setting here SEEK_SET to SEEK_END doesnt return the value of 2nd id */
  fread(&secondf, 1, sizeof(item), fptr);
  printf("%d  %s\n", secondf.id, secondf.name);

  fseek(fptr, 0*sizeof(item), SEEK_CUR); /* copy the 2nd the printsection and setting SEEK_SET to SEEK_CUR prints 1st and 2nd id's */
  fread(&secondf, 1, sizeof(item), fptr); /* setting SEEK_CUR to SEEK_END returns 1st and 1st id's */
  printf("%d  %s\n", secondf.id, secondf.name); /* */


  fclose(fptr);
  return 0;
}