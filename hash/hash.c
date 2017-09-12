/*Hash?,??????,2012.9.28*/ 

#include<stdio.h>
#define DataType int
#define M 30
 
typedef struct HashNode    
{
    DataType data;    //??? 
    int isNull;           //??????????? 
}HashTable;

HashTable hashTable[M];

void initHashTable()     //?hash?????? 
{
    int i;
    for(i = 0; i<M; i++)
    {
        hashTable[i].isNull = 1;    //?????? 
    }
}

int getHashAddress(DataType key)    //Hash?? 
{
    return key % 29;     //Hash??? key%29 
}

int insert(DataType key)    //?hash?????? 
{
    int address = getHashAddress(key);       
    if(hashTable[address].isNull == 1)  //?????? 
    {
        hashTable[address].data = key;
        hashTable[address].isNull = 0;
    }
    else    //???????? 
    {
        while(hashTable[address].isNull == 0 && address<M)
        {
            address++;     //???????,???1 
        }
        if(address == M)    //Hash????? 
            return -1;
        hashTable[address].data = key;
        hashTable[address].isNull = 0;
    }
    return 0;
}

int find(DataType key)      //???? 
{
    int address = getHashAddress(key);
    while( !(hashTable[address].isNull == 0 && hashTable[address].data == key && address<M))
    {
        address++;
    } 
    if( address == M)
        address = -1;
    return address;
}


int main(int argc, char *argv[])
{
    int key[]={123,456,7000,8,1,13,11,555,425,393,212,546,2,99,196};
    int i;
    initHashTable();
    for(i = 0; i<15; i++)
    {
        insert(key[i]);
    }
    
    for(i = 0; i<15; i++)
    {
        int address;
        address = find(key[i]);
        printf("%d %d\n", key[i],address);
    }
    return 0;
}
