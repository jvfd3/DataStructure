

void  printString      (char* str) {        // simply prints a string
  printf("%s", str);
}


int  isBetween        (int n, int min, int max) {
  return ((min <= n) && (n <= max));
}


int  isAlpha          (int n) {             //    checks if certain character is alphabetical
  return (isBetween(n,65,90)||isBetween(n,97,122));
}


void  cleanSpecialChar (char* str) {       // (NOT USED) turns punctuation into spaces " ' , . - { [ ( ) ] } @ ! #
  int i;
  for (i=0; i<=(int) strlen(str);i++) {  // Runs through all characters of the string
    // printf("%d\n",i);
    if (!(isBetween(str[i],65,90)||isBetween(str[i],97,122)||str[i]=='\0')) {
    // if (!(isAlpha(str1[i])||str1[i]=='\0')) {
      str[i] = ' ';
    }
  }
  printf("After cleanSpecialChar\t");
  printString(str);
  printf("\n");
}


/* void normalizeCharacter (char* s) {   // turns special characters into normal characters ç á à â ã é ê í ó ô õ ú Ç Á À Â Ã É Ê Í Ó Ô Õ Ú
  
  int i;
  for (i=0; i<=(int) strlen(s);i++) {  // Runs through all characters of the string
    // it will now turn all of the ascii equivalent of vowels and c to it correspondent normal letter
    if (isBetween(s[i],192,198)||isBetween(s[i],224,230)) {
      s[i] = 'a';
    } else if (isBetween(s[i],200,203)||isBetween(s[i],232,235)) {
      s[i] = 'e';
    } else if (isBetween(s[i],204,207)||isBetween(s[i],236,239)) {
      s[i] = 'i';
    } else if (isBetween(s[i],210,214)||isBetween(s[i],242,246)) {
      s[i] = 'o';
    } else if (isBetween(s[i],217,220)||isBetween(s[i],249,252)) {
      s[i] = 'u';
    } else if ((s[i] == 199)||(s[i] == 231)) {
      s[i] = 'c';
    }
  }
  printf("After normalizeCharacter\t");
  printString(s);
}
 */


int   alphaSize        (char* str) {          //Counts the number of alpha characters
  int i, cont=0;
  for (i=0; i<=(int) strlen(str);i++) {  // Runs through all characters of the string
    if (isAlpha(str[i])) {
      cont++;
    }
  }
  return cont;
}


int   spaceCount       (char* str1) {          //Counts the number of spaces
  int i, cont=0;
  for (i=0; i<=(int) strlen(str1);i++) {  // Runs through all characters of the string
    if (str1[i]==' ') {
      cont++;
    }
  }
  return cont;
}


void  swap             (int* a, int* b) {   // swap the value of two integers (OR CHARs) (NOT USED)
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}


void  spacelessSwap    (char* str1) {       // remove all of the spaces
  // this part of the code is a mess. don't stare at it too much
  int i=0, j, spaces=spaceCount(str1);
  do {
    // printf("%dspaces\n", spaces);
    // printString(s);
    if (str1[i]==' ') {
      for (j=i; j<(int) strlen(str1);j++) {
        // swap (&(s[j]), &(s[j+1]));
        // i'm sweeping dirt over the \0
        str1[j]    = str1[j] + str1[j+1];
        str1[j+1]  = str1[j] - str1[j+1];
        str1[j]    = str1[j] - str1[j+1];

        // printString(s);
      }
      spaces--;
      i--;
    }
    i++;
  } while (spaces!=0);


  printf("After spaceless\t\t");
  printString(str1);
  printf("\n");
}


void  turnLower        (char* str1) {          // turn all characters of a string to minuscule
  int i;
  for (i=0;i<(int) strlen(str1);i++) {
    if (isBetween(str1[i],65,90)) {
      str1[i] += 32;
    }
  }
  printf("After turnLower\t\t");
  printString(str1);
  printf("\n");
}


void  cleanString      (char* str1, char* original) {   //Clean all non-"normal" characters of the strings
  
  strcpy(str1, original);
  
  printf("\n\n\nBefore cleanString\t");
  printString(str1);

  cleanSpecialChar(str1);        // turns punctuation into spaces " ' , . - { [ ( ) ] } @ ! #
  turnLower(str1);               // turn all characters to minuscule
  spacelessSwap(str1);           // remove all of the spaces
  // normalizeCharacter(str1);   // turns special characters into normal characters ç á à â ã é ê í ó ô õ ú Ç Á À Â Ã É Ê Í Ó Ô Õ Ú 
  // printString(original);
  // printString(str1);
}


/* void  invertString     (char* str1, char* str2) {

} */


int   sameSize         (char* str1, char* str2) {
  // printf("size str1:\t%d\n", strlen(str1));
  // printf("size str2:\t%d\n", strlen(str2));
  if (strlen(str1)==strlen(str2)) {
    return 1;
  }
  printf("\n(strlen(str1)=%d) != (strlen(str2)=%d)\n", strlen(str1), strlen(str2));
  return 0;
}


int   sameCharacters   (char* str1, char* str2) {
  int i;
  for (i=0; i<(int) strlen(str1); i++) {
    // printf("(%c==%c)\n",str1[i],str2[i]);
    if (str1[i]!=str2[i]) {
      printf("(%c) != (%c)\n", str1[i], str2[i]);
      return 0;
    }
  }
  return 1;
}
