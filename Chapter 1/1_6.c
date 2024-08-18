//Verify that the expression getchar() != EOF is 0 or 1.

#include <stdio.h>

int main(){
  int nc = 0;
  while(getchar() != EOF)
    ++nc;
  printf("%d\n", nc);
  printf("%d\n", getchar() != EOF);
}
