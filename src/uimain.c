#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

void token_to_history(List *history, char **tokens);
int main()
{
  char input[100];
  List *history = initial_history();
  while (1){
    printf("\nSelect one of the following:\n");
    printf("1. 'q' to quit\n 2.'i' to input\n 3. '!' and a number to get the history for that number.\n 4. 'h' for histories list.\n");
    printf("$");
    fgets(input,100,stdin);
    if (input[0] == 'q'){
      printf("goodbye\n");
      free_history(history);
      return 0;
    }
    else if (input[0] == '!'){
      char *hist = get_history(history,atoi(input+1));
      char **tokens = tokenize(hist);
      printf("History: %s\n",hist);
      printf("Tokenized:\n");
      print_tokens(tokens);
      free_tokens(tokens);
    }
    else if(input[0] == 'h'){
      print_history(history);
    }
    else if(input[0] == 'i'){
      printf("Input string:\n$");
      fgets(input, 100, stdin);
      char **tokens = tokenize(input);
      print_tokens(tokens);
      add_history(history,input);
      free_tokens(tokens);
    }
    else{
      printf("NOT A VALID INPUT!");
    }
  }
}
