#include <stdio.h>
#include "string.h"

int main(){
    int n = 100;
    int *returnSize = n;
    int i = 0;
    char* arr = (char*)malloc(sizeof(char)*9*n);
    char **strings = (char**)malloc(sizeof(char*)*n);
    for(i = 0;i < n;i ++){
        strings[i] = &arr[9*i];
    }
    for(i=1;i<=n;i++){
        if(i%15==0)strcpy(strings[i-1],"FizzBuzz");
        else if(i%3==0)strcpy(strings[i-1],"Fizz");
        else if(i%5==0)strcpy(strings[i-1],"Buzz");
        else sprintf(strings[i-1],"%d",i);
        printf("%s\n",strings[i-1]);
    }
    return 0;
}

// char ** fizzBuzz(int n, int* returnSize){
//     *returnSize = n;
    // int i = 0;
    // char* arr = (char*)malloc(sizeof(char)*9*n);
    // char **strings = (char**)malloc(sizeof(char*)*n);
    // for(i = 0;i < n;i ++){
    //     strings[i] = &arr[9*i];
    // }
    // for(i=1;i<=n;i++){
    //     if(i%15==0)strcpy(strings[i-1],"FizzBuzz");
    //     else if(i%3==0)strcpy(strings[i-1],"Fizz");
    //     else if(i%5==0)strcpy(strings[i-1],"Buzz");
    //     else sprintf(strings[i-1],"%d",i);
    // }
//     return strings;
// }