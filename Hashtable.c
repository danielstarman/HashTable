#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hrow{
    char value[12];
}hashRow;

typedef struct hT{
    hashRow rows[13];
}hashTable;

hashTable* populateHash(FILE* data);

int hash(int value);

void getMessage(hashTable *table, FILE* data);

int main(int argc, char *argv[])
{
    FILE* data = fopen(argv[1], "r");
    hashTable *myTable = populateHash(data);
    getMessage(myTable, data);
    return 0;
}

hashTable* populateHash(FILE* data){
    char newString[12];
    int counter, wordcounter;
    int max;
    char maxvalue[10];
    hashTable *table;
    table = (hashTable*)malloc(sizeof(hashTable));
    fgets(maxvalue, 10, data);
    max = atoi(maxvalue);
    for (counter = 0; counter <  max; counter++){
        fgets(newString, 100, data);
        for(wordcounter = 0; wordcounter < 12; wordcounter++){
            if (newString[wordcounter] == '\n'){
                newString[wordcounter] = '\0';
                break;
            }
        }
        strcpy(table->rows[counter].value, newString);
    }
    return table;
}

void getMessage(hashTable *table, FILE* data){
    int num;
    char numtemp[10];
    int hashvalue;
    do{
        fgets(numtemp, 10, data);
        num = atoi(numtemp);
        if (num == 0){
            return;
        }
        hashvalue = hash(num);
        printf("%s ", table->rows[hashvalue].value);
    } while (num != 0);

}

int hash(int value){
    return 1 + value % 13;
}

