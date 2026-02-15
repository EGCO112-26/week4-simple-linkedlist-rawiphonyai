#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_node.h"

int main(int argc, const char * argv[]) {
    std_NodePtr head,temp;
    head = (std_NodePtr)malloc(sizeof(struct std_node));
    temp = head;
    int i,n=(argc-1)/2;

    for(i=0;i<n-1;i++){
        temp->id = atoi(argv[2*i+1]);
        strcpy(temp->name ,argv[2*i+2]);
        temp->next = (std_NodePtr)malloc(sizeof(struct std_node));
        temp=temp->next;
    }

    temp->id = atoi(argv[2*i+1]);
    strcpy(temp->name ,argv[2*i+2]);
    temp->next=NULL;

    printf("Student List :\n");
    temp = head;
    while(temp){
        printf("%d ", temp->id);
        printf(" %s\n", temp->name);
        temp=temp->next;
    }

    temp = head;
    while(temp){
        head = head->next;
        free(temp);
        temp = head;
    }
    head = NULL;

    return 0;
}
