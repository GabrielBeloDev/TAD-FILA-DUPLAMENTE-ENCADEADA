#include "dllist.h"
#include <stdio.h>
#include <string.h>

int main()
{
    DLList *lista = NULL;
    Time data, key, *temp;
    DLNode *current;
    int opcao;

    do
    {
        printf("\n\t============== MENU ==============\n");
        printf("\t\t1 - Criar Lista \n");
        printf("\t\t2 - Inserir \n");
        printf("\t\t3 - Remover \n");
        printf("\t\t4 - Listar \n");
        printf("\t\t5 - Consultar \n");
        printf("\t\t6 - Esvaziar \n");
        printf("\t\t7 - Destruir lista\n");
        printf("\t\t8 - Sair \n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (lista == NULL)
            {
                lista = dllCreate();
                printf("Lista criada.\n");
            }
            else
            {
                printf("A lista já existe.\n");
            }
            break;

        case 2:
            if (lista == NULL)
            {
                printf("Por favor, crie uma lista primeiro.\n");
                break;
            }
            printf("Insira o nome, número de vitórias e pontuação do time: ");
            scanf("%s %d %f", data.nome, &data.vitorias, &data.pontuacao);
            temp = (Time *)malloc(sizeof(Time));
            *temp = data;
            dllInsertFirst(lista, temp);
            printf("Time inserido.\n");
            break;

        case 3:
            if (lista == NULL || lista->first == NULL)
            {
                printf("A lista está vazia ou não foi criada.\n");
                break;
            }
            printf("Insira o nome do time para remover: ");
            scanf("%s", key.nome);
            Time *removedTime = dllRemoveSpec(lista, &key, comparaTime);
            if (removedTime != NULL)
            {
                free(removedTime);
                printf("Time removido.\n");
            }
            else
            {
                printf("Time não encontrado.\n");
            }
            break;

        case 4:
            if (lista == NULL || lista->first == NULL)
            {
                printf("A lista está vazia ou não foi criada.\n");
                break;
            }
            printf("Listando todos os times:\n");
            current = lista->first;
            while (current != NULL)
            {
                mostrarTime(current->data);
                current = current->next;
            }
            break;

        case 5:
            if (lista == NULL || lista->first == NULL)
            {
                printf("A lista está vazia ou não foi criada.\n");
                break;
            }
            printf("Insira o nome do time para consulta: ");
            scanf("%s", key.nome);

            current = lista->first;
            int found = 0;
            while (current != NULL)
            {
                if (strcmp(current->data->nome, key.nome) == 0)
                {
                    printf("Time encontrado\n");
                    mostrarTime(current->data);
                    found = 1;
                    break;
                }
                current = current->next;
            }

            if (!found)
            {
                printf("Time não encontrado.\n");
            }
            break;
        case 6:
            if (lista == NULL || lista->first == NULL)
            {
                printf("A lista está vazia ou não foi criada.\n");
                break;
            }

            current = lista->first;
            DLNode *nextNode;
            while (current != NULL)
            {
                nextNode = current->next;
                free(current->data);
                free(current);
                current = nextNode;
            }
            lista->first = NULL;
            printf("Lista esvaziada.\n");
            break;

        case 7:
            if (lista != NULL)
            {
                dllDestroy(lista);
                lista = NULL;
                printf("Lista destruída.\n");
            }
            else
            {
                printf("A lista já está vazia ou não foi criada.\n");
            }
            break;

        case 8:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida.\n");
        }
    } while (opcao != 8);

    if (lista != NULL)
    {
        dllDestroy(lista);
    }

    return 0;
}

int comparaTime(Time *a, Time *b)
{
    return strcmp(a->nome, b->nome) == 0;
}

void mostrarTime(Time *t)
{
    if (t != NULL)
    {
        printf("Nome: %s, Vitórias: %d, Pontuação: %.2f\n", t->nome, t->vitorias, t->pontuacao);
    }
}
