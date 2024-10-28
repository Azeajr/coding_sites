#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dna_to_rna(const char *dna) {
  int dnaLength = strlen(dna);

  char *rna = malloc((sizeof(char)) * (dnaLength + 1));

  strcpy(rna, dna);

  for (int i = 0; i < strlen(rna); i++) {
    if (rna[i] == 'T') {
      rna[i] = 'U';
    }
  }

  return rna;
}

int main(int argc, char const *argv[]) {
  char buffer[20];

  printf("Enter DNA: ");
  scanf("%19s", buffer);

  printf("Entered DNA: %s\n", buffer);

  char *rna = dna_to_rna(buffer);

  printf("Entered DNA: %s\n", buffer);
  printf("Entered RNA: %s\n", rna);

  return 0;
}
