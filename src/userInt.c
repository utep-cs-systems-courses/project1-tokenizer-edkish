#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 1000


int main()
{
  List* list = init_history();
  
  char input[MAX];
  int id;
  while (1) {
    printf("\nType a command: 0,t,h,s \n $ ");
    fgets(input, MAX, stdin);
    input[1] = '\0';
    if (strlen(input)==1 && input[0]=='0') {
      printf("Now exiting program \n");
      break;
    }
      
    if (strlen(input)==1 && input[0]=='t') { //t
      printf("Enter String to tokenize: \n");
      printf("$ ");
      fgets(input, MAX, stdin);
      char **tk = tokenize(input);
      add_history(list, input);
      print_tokens(tk);
      free_tokens(tk);
    }

    if (strlen(input)==1 && input[0]=='h') { //h
      print_history(list);
    }
   
    if (strlen(input)==1 && input[0]=='s') { //s
      printf("Enter sequence number: \n");
      printf("$ ");
      scanf("%d", &id);
      fflush(stdin);
      char* n = get_history(list, id);
      printf(n);
      printf("\n");
   }
  }

  free_history(list);
}
