#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history()
{
  List *list = malloc(sizeof(List));
  list-> root = malloc(sizeof(Item));
  return list;
}

void add_history(List *list,char *str)
{
  int id = 1;
  Item *temp = list->root;
  while (temp->next != 0){
    temp = temp->next;
    id++;
  }
  temp->next = malloc(sizeof(Item));
  temp->next->str = copy_str(str,string_length(str));
  temp->next->id = id;
}

char *get_history(List *list, int id)
{
  Item *temp = list->root;
  while (temp != 0){
    if (temp->id == id){
      return temp->str;
    }
    temp = temp->next;
  }
  return "id not found";
}

void print_history(List *list)
{
  Item *temp = list->root->next;
  while (temp != 0){
    printf("%d. %s", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list)
{
  Item *cur = list->root;
  while (cur->next != 0){
    Item *prev = cur;
    cur = cur->next;
    free(prev->str);
    free(prev);
  }
  free(cur-str);
  free(cur);
  free(list);
}
