#include <stdio.h>
#include <stdlib.h>



//// true if c is a tab or space, and not zero

int space_char(char c){

  if(c == '\t' || c == ' '){

    return 1;

  }

  return 0;

}



// true if c not a tab or space, and not zero

int non_space_char(char c){

  if(c != '\t' && c != ' '){

    return 1;

  }

  return 0;

}



// * to first (non-space) char in first word in s

char *word_start(char *str){

  while(space_char(str[0])){  //skips whitespace

    if(str[0] == '\0'){   //if hits end string

      return str;

    }

    str++;

  }



  return str;

}



// * to char after end of word

char *word_terminator(char *word){

  char* start = word_start(word);



  while(non_space_char(start[0])){

    start++;

  }



  return start;

}



// the number of words in s

int count_words(char *str){

  str = word_start(str);



  int counter = 0;

  while(str[0] != '\0'){

    if(non_space_char(str[0])){ //counts characters

      counter++;

    }





    str = word_terminator(str);

    str = word_start(str);

  }

  printf("Counter: %d \n", counter);

  return counter;
}



char *copy_str(char *inStr, short len){

  char* copy = (char*)malloc((len + 1) * sizeof(inStr));



  //copy characters into 'copy' string

  int i;

  for(i = 0; i < len; i++){

    copy[i] = inStr[i];

  }

  copy[i] = '\0';



  return copy;

}



char **tokenize(char* str){

  //to not change value of str

  char* temp = str;



  //skips invalid chars

  temp = word_start(temp);



  //allocate memory for number of words + null

  int numWords = count_words(temp);

  char** tokenized = (char**)malloc((numWords + 1) * sizeof(char*));



  //tokenizes string

  int i;

  short counter;

  for(i = 0; temp[0] != '\0'; i++){

    //counts for length of a single word

    for(counter = 0; non_space_char(temp[counter]) == 1; counter++);

    tokenized[i] = copy_str(temp, counter);



    //goes to next word

    temp = word_terminator(temp);

    temp = word_start(temp);

  }

  //accounts for null character

  tokenized[i] = (char*)malloc(sizeof(char));

  tokenized[i][0] = '\0';



  return tokenized;

}



void print_tokens(char **tokens){

  int i = 0;



  //if not empty print tokens

  for(i = 0; tokens[i][0] != '\0' && tokens[i][0] != '\n'; i++){

    printf("'%s'\n", tokens[i]);

  }

}



void free_tokens(char **tokens){

  int i;



  //if not empty clear memory

  for(i = 0; tokens[i][0] != '\0'; i++){

    free(tokens[i]);

  }

  free(tokens);

}
