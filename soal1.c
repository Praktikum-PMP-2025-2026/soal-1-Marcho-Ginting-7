/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2 - Data Manipulation and External Files
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
    head->data = NULL;
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
        if (commands == 1) {
            while (1) {
                if (head->next == NULL)
                    head->data = commands[i+1];
                else {
                    head->next
                }
            }
        } else if (commands == 2) {
            if (head->next == NULL)
                head->data = commands[i+1];
        } else if (commands == 3) {
            
        } else if (commands == 4) {
            
        }
    }

    return 0;
 }
