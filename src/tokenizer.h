#ifndef _TOKENIZER_
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c);
{
  if ((c == '\t' || c == ' ') && c != 0) {
    return 1;
      }
  return 0;
}
/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c);
{
  if ((c != '\t' && c != ' ') && c != 0) {
    return 1:
  }
  return 0;
}
/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str); 
{
  int i;
  for (i = 0;  *str + i ! = '\0'; i++){
    if (non_space_char(*(str+i))){
      return str+i;
    }
  }
  return str+i;
}
/* Returns a pointer terminator char following *token */
char *token_terminator(char *token);
{
  int i;
  for (i = 0; *(word+i) != '\0'; i++){
    if (space_char(*(word+i))){
      return word+i;
    }
  }
  return word+i;
}
/* Counts the number of tokens in the string argument. */
int count_tokens(char *str);
{
  int tokenCount = 0;
  char *p = word_start(str);
  while (*p != '\0'){
    if (non_space_char(*p)){
      tokenCount += 1;
    }
    p = token_terminator(p);
    p = token_start(p);
  }
  return tokenCount;
}
/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len);
{
  char *copy = malloc((len+1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++){
    copy[i] = inStr[i];
  }
  copy[i] = '\0';
  return copy;
}
/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str);
{
  int numTokens = count_tokens(str);
  char **tokens = malloc((numTokens + 1) * sizeof(char *));
  char *p = str;
  int i;
  for (i=0; i < numTokens; i++;){
      p = token_start(p);
      int length  = token_length(p);
      tokens[i] = copy_str(p, length);
      p = token_teminator(p);
    }
    tokens[i] = 0;
    return tokens;
}
/* Prints all tokens. */
void print_tokens(char **tokens);
{
  int i;
  for (i=0; tokens[i] != 0; i++){
    printf("%s\n", tokens[i]);
  }
}
/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);
{
  int i;
  for (i=0; tokens[i] != 0; i++){
    free(tokens[i]);
  }
  free(tokens);
}

short string_length(char *str)
{
  short length = 0;
  int i;
  for (i=0; *(str+i) != '\0'; i++){
    length += 1;
  }
  return length
}

int token_length(char *str)
{
  int length = 0;
  int i;
  for (i = 0; *(str+i) != '\0'; i++){
    if (non_space_char(*(str+i))){
      length +=1;
    }
    else{
      break;
    }
  }
  return length;
}
#endif
