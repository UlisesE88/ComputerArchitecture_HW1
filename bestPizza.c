#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct pizza{
    char name[64];
    float pizza_per_dollar;
    struct pizza *next;
} pizzaPtr; 

float pizza_per_dollar_function(float, float);
pizzaPtr* insertAtHead(struct pizza* head, char name_pizza[], float);
pizzaPtr* sorting_linklist(struct pizza* head);
void print_linklist(struct pizza* head);

int main(int argc, char * argv[]){
    char name_1[64];
    float diameter, price;
    pizzaPtr * head = NULL;

    FILE *pFile;
    pFile = fopen(argv[1], "r");

    if (pFile) {
    	fseek(pFile, 0, SEEK_END);
    	int size = ftell(pFile);
    	if (size == 0) {
            fclose(pFile);
        	printf("PIZZA FILE IS EMPTY\n");
            return (EXIT_SUCCESS);
    	}
	}
    rewind(pFile);
    fscanf(pFile, "%s", name_1);
     while(strcmp(name_1, "DONE") != 0){
     	fscanf(pFile, "%f", &diameter);
     	fscanf(pFile, "%f", &price);

        float ppd = pizza_per_dollar_function(diameter, price);

     	head = insertAtHead(head, name_1, ppd);
        fscanf(pFile, "%s", name_1);
     }
     fclose(pFile);

     head = sorting_linklist(head);
     print_linklist(head);
     return (EXIT_SUCCESS);
}

pizzaPtr* insertAtHead(pizzaPtr *head, char name_pizza[], float ppd) {
    pizzaPtr *new_pizza;
    new_pizza = (pizzaPtr*)malloc(sizeof(pizzaPtr));

    strcpy(new_pizza->name, name_pizza);
    new_pizza->pizza_per_dollar = ppd;

    new_pizza->next = head;
    head = new_pizza;
    return head;
}

float pizza_per_dollar_function(float D, float P) {
  	if (D == 0 || P ==0){
  		return 0;
  	}
  	float PI = 3.14159265358979323846;
  	float area = (PI/4) * pow(D,2);
  	float pizza_per_dollar_val = area/P;
  	return pizza_per_dollar_val;
  }

pizzaPtr* sorting_linklist(pizzaPtr *head){
 	pizzaPtr *curr, *second; 
 	char temp_name[64];
 	float temp_ppd;
    curr = head;
    second = curr->next;
 	for(curr = head; curr != NULL; curr = curr->next){
 		for(second = curr->next; second != NULL; second = second->next){
 			int i = strcmp(curr->name, second->name);
 			if(curr->pizza_per_dollar < second->pizza_per_dollar){
                strcpy(temp_name, curr->name);
 				temp_ppd = curr->pizza_per_dollar;

                strcpy(curr->name, second->name);
 				curr->pizza_per_dollar = second->pizza_per_dollar;

                strcpy(second->name, temp_name);
 				second->pizza_per_dollar = temp_ppd;
 			}
 			if(curr->pizza_per_dollar == second->pizza_per_dollar && i > 0){
                strcpy(temp_name, curr->name);
                strcpy(curr->name, second->name);
                strcpy(second->name, temp_name);
 			}
 		}
 	}
    return head;
}

void print_linklist(pizzaPtr *head) {
     pizzaPtr *current = head;
     while(current != NULL){
         printf("%s %f\n", head->name, head->pizza_per_dollar);
         head = head->next;
         free(current);
         current = head;
     }
 }