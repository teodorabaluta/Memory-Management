#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include <inttypes.h>

// adaug in vector arr
int add_last(void **arr, int *len, data_structure *data)
{ if( *arr == NULL) { // verific daca arr e null
    *arr = malloc(sizeof(head) + data->header->len); // daca e null il aloc
  }
  else
  {
    *arr = realloc(*arr, *len + sizeof(head) + data->header->len); // daca nu e null, il realoc cu ce era inainte + ce vreau sa adaug
  }

  void *inceput = *arr; // memorez adresa initiala
  *arr = *arr + *len; // ajung unde trebuie sa adaug
  memcpy(*arr, data->header, sizeof(head));  // copiez partea header
  *arr = *arr + sizeof(head); // ma mut cu partea header
  memcpy(*arr, data->data, data->header->len); // copiez partea void data
  *arr = inceput; // ma mut la inceput

  return 0;
}

void print(void *arr , int len) {
   if(len != 0) { // daca am ce sa afisez, afisez

   void *inceput = arr; // tin minte adresa initiala
   int ok = 1;
   int contor = 0;
   int dim_nume1, dim_nume2;

    while(ok == 1) { // afisez pana la final
    char tip = *(char *)arr; // vad ce tip am si afisez in functie de tip

        if(tip == '1') 
        {   printf("Tipul 1\n"); // printez tipul
            dim_nume1 = strlen((char *)(arr + sizeof(head))) + 1; // tin minte dimensiunea la nume1
            dim_nume2 = strlen((char *)(arr + sizeof(head) + dim_nume1 + 2 * sizeof(int8_t))) + 1; // tin minte dim la nume2
            printf("%s pentru %s\n", (char *)(arr + sizeof(head)), (char *)(arr + sizeof(head) + dim_nume1 + 2 * sizeof(int8_t))); // afisez dupa bitii corespunzatori, ma mut cu cat trebuie
            printf("%"PRId8"\n", *(int8_t *)(arr + sizeof(head) + dim_nume1)); // printez bancnota 1
            printf("%"PRId8"\n", *(int8_t *)(arr + sizeof(head) + dim_nume1 + sizeof(int8_t))); // si a doua
            printf("\n");

            contor = contor + sizeof(head) + dim_nume1 + dim_nume2 + 2 * sizeof(int8_t); // cresc contorul

            if(len > contor) { // vad daca am ajuns la final
                arr = arr + sizeof(head) + dim_nume1 + dim_nume2 + 2 * sizeof(int8_t); // cresc cu cat m am mutat
            }
            else
            {
                ok = 0 ; // ies din while
            }
        }

        if(tip == '2') // la fel si aici, modific doar pasii de mutat de la bancnote
        {   printf("Tipul 2\n");
            dim_nume1 = strlen((char *)(arr + sizeof(head))) + 1;
            dim_nume2 = strlen((char *)(arr + sizeof(head) + dim_nume1 + sizeof(int16_t) + sizeof(int32_t))) + 1;
            printf("%s pentru %s\n", (char *)(arr + sizeof(head)), (char *)(arr + sizeof(head) + dim_nume1 + sizeof(int16_t) + sizeof(int32_t)));
            printf("%"PRId16"\n", *(int16_t *)(arr + sizeof(head) + dim_nume1));
            printf("%"PRId32"\n", *(int32_t *)(arr + sizeof(head) + dim_nume1 + sizeof(int16_t)));
            printf("\n");

            contor = contor + sizeof(head) + dim_nume1 + dim_nume2 + sizeof(int16_t) + sizeof(int32_t);

             if(len > contor) {
                arr = arr + sizeof(head) + dim_nume1 + dim_nume2 + sizeof(int16_t) + sizeof(int32_t);
            }
            else
            {
                ok = 0 ;
            }
        }

        if(tip == '3') // la fel si aici
        {   printf("Tipul 3\n");
            dim_nume1 = strlen((char *)(arr + sizeof(head))) + 1;
            dim_nume2 = strlen((char *)(arr + sizeof(head) + dim_nume1 + 2 * sizeof(int32_t))) + 1;
            printf("%s pentru %s\n", (char *)(arr + sizeof(head)), (char *)(arr + sizeof(head) + dim_nume1 + 2 * sizeof(int32_t)));
            printf("%"PRId32"\n", *(int32_t *)(arr + sizeof(head) + dim_nume1));
            printf("%"PRId32"\n", *(int32_t *)(arr + sizeof(head) + dim_nume1 + sizeof(int32_t)));
            printf("\n");

            contor = contor + sizeof(head) + dim_nume1 + dim_nume2 + 2 * sizeof(int32_t);

            if(len > contor) {
                arr = arr + sizeof(head) + dim_nume1 + dim_nume2 + 2 * sizeof(int32_t);
            }
            else
            {
                ok = 0 ;
            }
        }

    }

   arr = inceput; // pun adresa de start pentru a putea da print de mai multe ori
   }

}


void find(void *data_block, int len, int index) 
{   if (index >= 0) { // daca avem un index real
    int cautare = 0;

    int dim_void = *(int *)(data_block + 4); // vad ce dimensiune am la void
    // ma mut cu 4 ca head are 8 si primii 4 biti sunt pentru char
    
    while (cautare != index)
    {   cautare = cautare + 1; // cresc indexul
        data_block = data_block + sizeof(head) + dim_void; // ma misc
        dim_void = *(int *)(data_block + 4); // extrag dimensiune void iar
    }
    
    // afisez (sunt luate cu copy paste din functia printare)
    char tip = *(char *)data_block;
    int dim_nume1;
    if(tip == '1')
        {   printf("Tipul 1\n");
            dim_nume1 = strlen((char *)(data_block + sizeof(head))) + 1;
            printf("%s pentru %s\n", (char *)(data_block + sizeof(head)), (char *)(data_block + sizeof(head) + dim_nume1 + 2 * sizeof(int8_t)));
            printf("%"PRId8"\n", *(int8_t *)(data_block + sizeof(head) + dim_nume1));
            printf("%"PRId8"\n", *(int8_t *)(data_block + sizeof(head) + dim_nume1 + sizeof(int8_t)));
            printf("\n");
        }
    if(tip == '2')
        {   printf("Tipul 2\n");
            dim_nume1 = strlen((char *)(data_block + sizeof(head))) + 1;
            printf("%s pentru %s\n", (char *)(data_block + sizeof(head)), (char *)(data_block + sizeof(head) + dim_nume1 + sizeof(int16_t) + sizeof(int32_t)));
            printf("%"PRId16"\n", *(int16_t *)(data_block + sizeof(head) + dim_nume1));
            printf("%"PRId32"\n", *(int32_t *)(data_block + sizeof(head) + dim_nume1 + sizeof(int16_t)));
            printf("\n");
        }
    if(tip == '3')
        {   printf("Tipul 3\n");
            dim_nume1 = strlen((char *)(data_block + sizeof(head))) + 1;
            printf("%s pentru %s\n", (char *)(data_block + sizeof(head)), (char *)(data_block + sizeof(head) + dim_nume1 + 2 * sizeof(int32_t)));
            printf("%"PRId32"\n", *(int32_t *)(data_block + sizeof(head) + dim_nume1));
            printf("%"PRId32"\n", *(int32_t *)(data_block + sizeof(head) + dim_nume1 + sizeof(int32_t)));
            printf("\n");
        }

    }

}

int delete_at(void **arr, int *len, int index)
{   void *inceput = *arr; // tin minte adresa de start
    
    int stergere = 0; // index pt stergere
    int dim_void = *(int *)(*arr + 4); // extrag dimensiune data
    int contor = 0; // aici vad cu cat ma mut
    while (stergere != index) 
    {   stergere = stergere + 1; // cresc indexul
        *arr += + sizeof(head) + dim_void; // ma mut
        contor += sizeof(head) + dim_void; // tin minte cu cat ma mut
        dim_void = *(int *)(*arr + 4); // extrag iar dimensiunea la data urmatoare
    }
    // copiez la arr ce e peste elementul de sters, cu exact dimensiunea la tot vectorul minus cat m am mutat pana acum minus elementul de sters
    memcpy(*arr, *arr + sizeof(head) + dim_void , *len - contor - sizeof(head) - dim_void);
    // arr ia adresa de inceput
    *arr = inceput;
    *len = *len - sizeof(head) - dim_void; // scade si lungimea cu dimensiunea la elementul sters
    *arr = realloc(*arr, *len); // realoc vectorul cu cat trebuie
    return 0;
}


int main(){
    void *arr = NULL; // astea sunt date de ei
    int len = 0;
    int ok = 1; // aici iau un ok sa citesc comenzi pana ma opresc

    
    data_structure *item = (data_structure *)malloc(sizeof(data_structure)); // aloc dinamic ce trebuie
    item->header = (head *)malloc(sizeof(head));

    while(ok == 1) {
        char *comanda = malloc(50); // aloc comanda
        scanf("%s", comanda); // citesc

        if(strcmp(comanda, "insert") == 0) {
            int tip; // aici bag in element
            scanf("%d", &tip); // scanez tipul si bag in functie de tip
            if( tip == 1) {
            item->header->type = '1'; // stochez tipul
            char *nume1 = (char *) malloc(200); // aloc primu nume
            scanf("%s", nume1); // citesc primu nume

            int8_t bancnota1; // declar bancnota1
            scanf("%"SCNd8"", &bancnota1);
 
            int8_t bancnota2; // o declar si pe cealalta
            scanf("%"SCNd8"", &bancnota2);

            char *nume2 = (char*) malloc(200); // aloc nume2
            scanf("%s", nume2);
            
            // vad cat trebuie sa bag in void data
            int lungime = 2 * sizeof(int8_t) + strlen(nume1) + strlen(nume2) + 2;
            item->header->len = lungime;

            item->data = malloc(lungime); // aloc cat trebuie sa bag
            memcpy(item->data, nume1, strlen(nume1)+1); // copiez numele
            item->data = item->data + strlen(nume1) + 1; // ma mut cu numele 
            memcpy(item->data, &bancnota1, sizeof(int8_t)); // copiez bancnota
            item->data = item->data + sizeof(int8_t); // ma mut cu bancnota
            memcpy(item->data, &bancnota2, sizeof(int8_t)); // copiez bancnota
            item->data = item->data + sizeof(int8_t); // ma mut cu bancnota
            memcpy(item->data, nume2, strlen(nume2)+1); // copiez restu de nume
            item->data = item->data + strlen(nume2) + 1; // ma mut cu numele
            item->data = item->data - lungime; // ajung la adresa de inceput

            if(add_last(&arr, &len , item) != 0) // adaug 
            printf("EROARE");
            len = len + sizeof(head) + lungime; // maresc lungimea
            // dezaloc ce am alocat
            free(nume1);
            free(nume2);
            free(item->data);
            }
            
            // la fel si aici
            if( tip == 2) {
            item->header->type = '2';
            char *nume1 = (char*) malloc(200);
            scanf("%s", nume1);

            int16_t bancnota1;
            scanf("%"SCNd16"", &bancnota1);

            int32_t bancnota2;
            scanf("%"SCNd32"", &bancnota2);

            char *nume2 = (char*) malloc(200);
            scanf("%s", nume2);

            int lungime = sizeof(int16_t) + sizeof(int32_t) + strlen(nume1) + strlen(nume2) + 2;
            item->header->len = lungime;

            item->data = malloc(lungime);
            memcpy(item->data, nume1, strlen(nume1)+1);
            item->data = item->data + strlen(nume1) + 1;
            memcpy(item->data, &bancnota1, sizeof(int16_t));
            item->data = item->data + sizeof(int16_t);
            memcpy(item->data, &bancnota2, sizeof(int32_t));
            item->data = item->data + sizeof(int32_t);
            memcpy(item->data, nume2, strlen(nume2)+1);
            item->data = item->data + strlen(nume2) + 1;
            item->data = item->data - lungime;

            if(add_last(&arr, &len , item) != 0)
            printf("EROARE");     
            len = len + sizeof(head) + lungime;  
            free(nume1);
            free(nume2);
            free(item->data);
            }
            
            // la fel si aici
            if( tip == 3) {
            item->header->type = '3';
            char *nume1 = (char*) malloc(200);
            scanf("%s", nume1);

            int32_t bancnota1;
            scanf("%"SCNd32"", &bancnota1);

            int32_t bancnota2;
            scanf("%"SCNd32 "", &bancnota2);

            char *nume2 = (char*) malloc(200);
            scanf("%s", nume2);

            int lungime = 2 * sizeof(int32_t) + strlen(nume1) + strlen(nume2) + 2;
            item->header->len = lungime;

             item->data = malloc(lungime);
            // printf(" ADRESA %p\n", item->data);
            memcpy(item->data, nume1, strlen(nume1)+1);
            item->data = item->data + strlen(nume1) + 1;
            memcpy(item->data, &bancnota1, sizeof(int32_t));
            item->data = item->data + sizeof(int32_t);
            // printf(" ADRESA %p\n", item->data);
            memcpy(item->data, &bancnota2, sizeof(int32_t));
            item->data = item->data + sizeof(int32_t);
            memcpy(item->data, nume2, strlen(nume2)+1);
            item->data = item->data + strlen(nume2) + 1;
            item->data = item->data - lungime;

            if(add_last(&arr, &len , item) != 0)
            printf("EROARE");     
            len = len + sizeof(head) + lungime;   
            free(nume1);
            free(nume2);
            free(item->data);
            }

        

        
        
        }
        
        if(strcmp(comanda, "print") == 0){
            print(arr,len); // printez
        }
         
        if(strcmp(comanda, "find") == 0){
            int index; // citesc un index in plus si apelez functia
            scanf("%d", &index);
            find(arr,len,index);
        }

        if(strcmp(comanda, "delete_at") == 0){
            int index; // citesc index si apelez
            scanf("%d", &index);
            delete_at(&arr,&len,index);
        }

        if(strcmp(comanda, "exit") == 0){
            ok = 0; // ies din while
        }

       // dezaloc comanda
       free(comanda);
 
    }
    
    // dezaloc elementul si cu vectorul in care am bagat
    free(item->header);
    free(item);
    free(arr);
     
    return 0;
}