#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    char key[100]; 
    char value[10];
}keyvalue;

    keyvalue entry[1000];
    int entrycount = 0;

 int parseline(const char *line){
    char key [101];
    char value[11];

    const char *colon = strchr(line,':');
    if(colon==NULL){
    return 0;
    }
    int keylength = colon - line;

    strncpy(key, line,keylength);
    key[keylength] = '\0';

    const char *valuestart = colon + 1;
    int valuelength = strlen(valuestart);

    if (valuelength > 0 && valuestart[valuelength - 1] == '\n') {
        valuelength--;
    }

    strncpy(value,valuestart,valuelength);
    value[valuelength] = '\0';

    strcpy(entry[entrycount].key,key);
    strcpy(entry[entrycount].value,value);
 
    entrycount++;
    return 1;
}
void parsefile(){
    FILE *file = fopen("data.txt","r");
    char line[100];
    while (fgets(line,sizeof(line),file)!=NULL){ 
    int is_empty = 1;
     for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\r') {
                is_empty = 0;
                break;
            }
        }
        
        if (is_empty) {
            continue; 
        }    
    parseline(line);   
    }    
    fclose(file);
}

const char *findvalue(const char *key){
    for (int i= 0; i < entrycount;i++)
    {
      if(strcmp(entry[i].key,key)==0)        
        return entry[i].value;
      }
      return NULL;
    }
    
int main(){
    parsefile();
    printf("please enter the key:\n");
    char input[50];
    while (1) {
        printf(">\n");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "Quit") == 0) {
            break;
        }
    const char *value = findvalue(input);
    if (value != NULL)
    {
        printf("%s\n",value);
      }
   else{
         printf("Error\n");
   }
        }
    return 0;
}