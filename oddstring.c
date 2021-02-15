#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>


struct node{
   char* val;
   struct node *next;
};

char* Solve (struct node *Head) {
    struct node * temp = Head;
    char *x = (char *)(malloc(20*sizeof(char)));
    char *final_string = (char *)(malloc(50*sizeof(char)));
    char list[10];
    int freq[10];
    int list_length = 0,i,j;
    while(temp != NULL)
    {
        x = temp->val;
        for(i=0;i<strlen(x);i++)
        {
            
            for(j=0;j<list_length;j++)
            {
                if(list[j] == x[i])
                {
                    freq[j]++;
                    break;
                }
            }
            if(j == list_length)
            {
                list[list_length] = x[i];
                freq[list_length] = 1;
                list_length++;
            }

        }
        //flag = 1;
        for(j=0;j<list_length;j++)
        {
            if(freq[j]%2 != 0)
            {
                break;
            }
        }
        strcat(final_string,x);

        if(j==list_length)
        {
            list_length = 0;
            final_string[0] = '\0';
        }
        
        temp = temp->next; 
    }

    return final_string;
}

struct node* createNode()
{
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    char* x = (char*)malloc(20 * sizeof(char));
    scanf("\n%[^\n]s", x);
    ptr->val = x;
    ptr->next = NULL;
    return ptr;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        scanf("%d", &N);
        struct node *Head = createNode();
        struct node *cur = Head;
        for(int t_j = 1;t_j < N;++t_j){
           cur->next = createNode();
           cur = cur->next;
        }
        
        char* out_ = Solve(Head);
        printf("%s", out_);
        printf("\n");
    }
}