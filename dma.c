#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *a = malloc(1);  // Start with 1 byte for '\0'
    if (a == NULL) {
        return 1;
    }

    a[0] = '\0';  // Start with an empty string

    printf("enter a word: ");

    int i = 0;
    char c;
    while (scanf("%c", &c) == 1 && c != '\n') {
        char *tmp = realloc(a, i + 2);  // +1 for new char, +1 for '\0'
        if (tmp == NULL) {
            free(a);
            return 2;
        }
        a = tmp;
        a[i] = c;
        a[i + 1] = '\0';
        i++;
    }

    printf("a: %s\n", a);
    printf("strlen of a: %ld\n", strlen(a));
    free(a);
    return 0;
}

/*
//as a function:
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* init_subject();

int main(int argc, char *argv[]){
  char *a=init_subject();
  if(a==NULL){
    return 1;
  }
  free(a);
  return 0;
}

char* init_subject(){
	char *subject_input;
	//subject_input=(char *)calloc(1, sizeof(char));
	subject_input=malloc(2*sizeof(char));
  strcpy(subject_input, "x");
	if(subject_input==NULL){
		printf("unable to allocate memory for subject_input pointer at function init_subject()");
		return subject_input;
	}
	printf("enter a word: ");
	int i=0;
	int j=0;
  while(*(subject_input+j)!='\n'){
    j=i;
    i++;
    subject_input=realloc(subject_input, i+1);
    if(subject_input==NULL){
      return subject_input;
    }
    *(subject_input+i)='\0'; //initialize the realloc
    scanf("%c", subject_input+j);
  }
	int str_len=strlen(subject_input);
	subject_input[str_len-1]='\0'; //replace the newline character '\n' at the end of the string with null character
  printf("user input: %s\n", subject_input);
	str_len=strlen(subject_input); //recalculate str len after the newline character has been stripped off
  printf("strlen of user input: %d\n", str_len);
	return subject_input;
}
*/
