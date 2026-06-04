/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 4 - Dynamic Structures
 *   Hari dan Tanggal    : Senin, 20 April 2026
 *   Nama (NIM)          : Yozia Gedalya Marcho Ginting (13224001)
 *   Nama File           : soal1.c
 *   Deskripsi           : Program memperbaiki data invalid.
 * 
 */

 /************* LIBRARIES **************/
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <math.h>

 /************** STRUCTS ***************/
 struct List
 {
    int data;
    struct List *next;
 };

 /************** FUNCTIONS *************/
 int main() {
    // Initialise Linked List
    struct List *head = NULL;
    head = (struct List *)malloc(sizeof(struct List));
    if (!head) {
        printf("Memory Allocation Failed/n");
        return 1;
    }
    head->data = 0;
    head->next = NULL;

    // Reads number of commands
    int num;
    scanf("%d", &num);

    // Reads list of commands
    int commands[num*2];
    for (int i = 0; i < num*2; i++) {
        scanf("%d", &commands[i]);
    }

    for (int i = 0; i < num*2; i += 2) {
        // Grabs command prefix
        struct List *temp = head;
        if (commands[i] == 1) {
            if (head->next == NULL)
                head->data = commands[i+1];
            else {
                struct List *new_head = (struct List *)malloc(sizeof(struct List));
                new_head->next = head;
                new_head->data = commands[i+1];
                head = new_head;
            }
        } else if (commands[i] == 2) {
            if (head->data == 0)
                head->data = commands[i+1];

            else {
                struct List *before = NULL;
                // Traverse to the end of the linked list
                while (temp != NULL) {
                    before = temp;
                    temp = temp->next;
                }
                struct List *new_node = (struct List *)malloc(sizeof(struct List));
                new_node->data = commands[i+1];
                new_node->next = NULL;
                before->next = new_node;
            }
        } else if (commands[i] == 3) {
            struct List *before = NULL;
            struct List *after = temp->next;
            while (temp != NULL) {
                if (temp->data == commands[i+1]) {
                    if (before == NULL) {
                        head = after;
                        free(temp);
                        break;
                    } else {
                        before->next = after;
                        free(temp);
                        break;
                    }
                }
                before = temp;
                temp = after;
                after = temp->next;
            }
        } else if (commands[i] == 4) {
            int index = 0;
            while (temp != NULL) {
                if (temp->data == commands[i+1]) {
                    printf("FOUND %d\n", index);
                }
                else if (temp->data != commands[i+1] && temp->next == NULL)
                    printf("NOT FOUND\n");
                temp = temp->next;
                index++;
            }
        }
    }
    struct List *read = head;
    if (read == NULL || read->data == 0)
        printf("LIST EMPTY\n");
    else {
        printf("LIST");
        while(read != NULL) {
            printf(" %d", read->data);
            read = read->next;
        }
    }
    printf("\n");
    return 0;
 }
