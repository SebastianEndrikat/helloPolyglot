// 2020-05-23
#include <stdio.h>
#include <math.h> // e.g. pow
#include <stdlib.h> // e.g. exit()

int main(){

  // hello
  printf("Hello from c\n");

  // loop, condition and arithmetic
  double a=0;
  for(int i=0; i<3; i++){
    a=pow(i,2.);

    if (i==1){
      printf("i is one\n");
      a *= 2.;
    }
    else{
      printf("i is not one\n");
      a += 0.5;
    }


    printf("It=%i, a=%.6f\n", i,a);
  }


  // read from file
  FILE *fid;
  char* theFile="../input.dat";
  printf("reading %s\n", theFile);

  if ( (fid = fopen(theFile, "r") ) == NULL )
  {
     printf("Error: can't read file %s", theFile);
     exit(1);
  }

  int nr=5; // number of rows in the file
  int nc=2; // number of columns
  double dat[nr][nc];
  char buffer[100];

  // while not end-of-file
  int r=0; // counting rows
  while (!feof(fid)) { 

    /* we expect buffer pointer back if all is well, get out if we don't get it */
    if (buffer != fgets(buffer, 100, fid))
      break;

    if (buffer[0] != '#') {
      sscanf(buffer, "%lf\t%lf", &dat[r][0], &dat[r][1]);
      printf("%s",buffer);
      r+=1;
    }
  }
  printf("Value with extreme precision: %.30f\n", dat[3][1]);

  fclose(fid);


  // avg read data:
  double avg=0;
  for (r=0; r<nr; r++){
    for (int c=0; c<nc; c++){
      avg+=dat[r][c];
    }
  }
  avg /= (nr*nc);
  printf("Avg of %s is %f\n", theFile,avg);

  // write the value with crazy precision to disk again:
  char* outFile="out.dat";
  fid = fopen(outFile, "w");
    fprintf(fid,"%.40f\n", dat[3][1]); 
    // result: matches the python version for all 40 digits (i.e. including precision errors)
  fclose(fid);

  return 0;
}



