#include <stdio.h>
#include <stdlib.h>

int **Table;

int LCS(int *&Arr1, int *&Arr2, int size);

int main(void) {
    FILE *input, *output;
    char s[20];
    int size, i, length;
    int *Arr1, *Arr2;

    input = fopen("input.txt", "r");
    fgets(s, 20, input);
    size = atoi(s);
    Arr1 = (int*) calloc(size, sizeof(int));
    Arr2 = (int*) calloc(size, sizeof(int));
    for(i=0;i<size;i++) {
        if(i == size-1) {
            fgets(s, 20, input);
            Arr1[i] = atoi(s);
        }else {
            fscanf(input, "%s", s);
            Arr1[i] = atoi(s);
        }
    }
    for(i=0;i<size;i++) {
        if(i == size-1) {
            fgets(s, 20, input);
            Arr2[i] = atoi(s);
        }else {
            fscanf(input, "%s", s);
            Arr2[i] = atoi(s);
        }
    }
    fclose(input);

    length = LCS(Arr1, Arr2, size);

    output = fopen("output.txt", "w");
    fprintf(output, "%d\n", length);
    fclose(output);
    free(Arr1);
    free(Arr2);
    return 0;
}

int LCS(int *&Arr1, int *&Arr2, int size) {
    int **Table;
    int i, j, length;
    Table = (int**) calloc(size+1, sizeof(int*));
    for(i=0;i<=size;i++) Table[i] = (int*) calloc(size+1, sizeof(int));
    for(i=0;i<=size;i++) {
        Table[i][0] = 0;
        Table[0][i] = 0;
    }
    for(i=1;i<=size;i++) {
        for(j=1;j<=size;j++) {
            if(Arr1[i-1] == Arr2[j-1]) Table[i][j] = Table[i-1][j-1] + 1;  //upper left
            else if(Table[i-1][j] >= Table[i][j-1]) Table[i][j] = Table[i-1][j];  //up
            else Table[i][j] = Table[i][j-1];  //left
        }
    }
    length = Table[size][size];
    for(i=0;i<=size;i++) free(Table[i]);
    free(Table);
    return length;
}
