#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if ((c == '\t' || c == ' ') && c != 0){
    return 1;
  }
  return 0;
}

int non_space_char(char c)
{
  if ((c != '\t' && c != ' ') && c != 0){
    return 1;
  }
  return 0;
}

char *token_start(char *str)
{
  int i;
  for (i = 0; *(str+i) != '\0'; i++){
    if (non_space_char(*(str+i))){
      return str+i;
    }
  }
  return str+i:
}

char *token_terminator(char *token);
{
  int i;
  for (i = 0; *(word+i) != '\0'; i++){
    if (space_char(*(word+i))){
      return word+i;
    }
  }
  return word+i:
}

int count_tokens(char *str);
{
  int token_count = 0;
  char *p = token_start(str);
  while (*p != '\0'){
    if (non_space_char(*p)){
      token_count += 1;
    }
    p = token_terminator(p);
    p = token_start(p);
  }
  return token_count;
}

char *copy_str(char *inStr, short len)
{
  char *scopy = malloc((len+1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++){
    scopy[i] = inStr[i];
  }
  scopy[i] = '\0';
  return scopy;
}

char **tokenize(char* str):
{
  int num_tokens = count_tokens(str)
  char **tokens = malloc((num_tokens + 1) * sizeof(char *));
  char *p = str;
  int i;
  for (i = 0; i < num_tokens; i++){
    p = token_start(p);
    int length = token_length(p);
    tokens[i] = copy_str(p, length);
    p = token_terminator(p);
  }
  tokens[i] = 0;
  return tokens;
}

void print_tokens(char **tokens);
{
  int i;
  for (i = 0; tokens[i] != 0; i++){
    printf("%s\n", tokens[i]);
  }
}

void free_tokens(char **tokens)
{
  int i;
  for (i = 0; tokens[i] != 0; i++){
    free(tokens[i]);
  }
  free(tokens[i]);
}

short string_length(char *str)
{
  int length = 0;
  int i;
  for (i = 0; *(str+i) != '\0'; i++){
    length += 1;
  }
  return length;
}

int token_length(char *str)
{
  int length = 0;
  int i;
  for (i=0; *(str+i) != '\0'; i++){
    if (non_space_char(*(str+i))){
      length += 1;
    }
    else{
      break;
    }
  }
  return length;
}
