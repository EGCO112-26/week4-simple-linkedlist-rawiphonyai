//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    struct node a,b,*head ;
    a.value = c;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8

/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */

    printf("Exercise 1 : Insert in The End\n");
    struct node d;
    b.next=&d;
    d.value=b.next->value=11;
    printf("%d\n", head ->value); //what value for 5
    printf("%d\n", head ->next ->value); //what value for 8
    printf("%d\n", head ->next ->next ->value); // what value for 11
    
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
        
*/
    
    printf("Exercise 2 : Insert in front\n");
    struct node e;
    e.value=2;
    e.next=&a;
    head=&e;
    printf("%d\n", head ->value ); //what value for 2
    printf("%d\n", head ->next ->value ); //what value for 5
    printf("%d\n", head ->next ->next ->value); //what value for 8
    printf("%d\n", head ->next ->next ->next->value); // what value for 11


    printf("Exercise 2.5 : Insert in The Middle\n");
    struct node f;
    f.value=7;
    f.next=&b;
    a.next=&f;
    printf("%d\n", head ->value ); //what value for 2
    printf("%d\n", head ->next ->value ); //what value for 5
    printf("%d\n", head ->next ->next ->value); //what value for 7
    printf("%d\n", head ->next ->next ->next ->value); //what value for 8
    printf("%d\n", head ->next ->next ->next ->next->value); // what value for 11


    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
        
    /*  Exercise III Use loop to print everything
        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
          // What is missing???
        }
    */

    printf("Exercise 3 : Use loop to print everything\n");
    printf("Print using loop :");
    int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
            tmp=tmp->next;
        }
    printf("\n");


   /*  Exercise IV change to while loop!! (you can use NULL to help)
       
         while(){
            printf("%3d", tmp->value);
           // What is missing???
        }
    */

    printf("Exercise 4 : change to while loop\n");
    printf("Print using while loop :");
    tmp=head;
    while(tmp){ //tmp!=NULL
        printf("%3d",tmp->value);
        tmp=tmp->next;
    }
    printf("\n");
    
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
          
     */

    printf("Exercise 5 : Use malloc to create all node\n");
    printf("Create node by malloc :");
    NodePtr temp;
    head = (NodePtr)malloc(sizeof(struct node));
    temp = head;
    n=5;
    for(i=0;i<n;i++){
        temp->value=7+i*2;
        printf("%3d",temp->value);
        temp->next = (NodePtr)malloc(sizeof(struct node));
        temp=temp->next;
    }
    temp->value=7+i*2;
    temp->next=NULL;
    printf("\n");
    

    /*  Exercise VI Free all node !!
         //use a loop to help
          
     */

    printf("Exercise 6 : Free all node\n");
    temp = head;
    while(temp){
        head = head->next;
        printf("Freeing : %d\n",temp->value);
        free(temp);
        temp = head;
    }
    head = NULL;
    
    return 0;
}
