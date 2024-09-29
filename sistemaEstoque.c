#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto{

    char nome[50];
    int cod;
    int quant;
    float preco; 
    struct produto* ante;
    struct produto* prox;

} produto;

produto* inserirProduto(produto** head_ref ,char* nome, int cod, int quant, float preco){

    produto* inserirProduto = (struct produto*)malloc(sizeof(struct produto));

            if(inserirProduto == NULL){

                printf(" Erro ao alocar memoria");
            
            return NULL;
            
            }

    strncpy(inserirProduto->nome, nome, sizeof(inserirProduto->nome) - 1);
    
    inserirProduto-> nome[sizeof(inserirProduto->nome) - 1] = '\0';
    inserirProduto-> cod = cod;
    inserirProduto-> quant = quant;
    inserirProduto-> preco = preco;
    inserirProduto-> prox = NULL;
    inserirProduto-> ante = NULL;

            if(*head_ref == NULL){

            *head_ref = inserirProduto;

            return inserirProduto;
            }

    produto* ultimo = *head_ref;

            while (ultimo->prox != NULL){
                
            ultimo = ultimo->prox;

            }

    ultimo->prox = inserirProduto;
    inserirProduto->ante = ultimo;
                
return inserirProduto;
}

produto* removerProduto(produto** head_ref, int cod){

    produto* temp = *head_ref;

            while(temp != NULL && temp->cod != cod){

            temp = temp->prox;

            }

            if(temp == NULL){

                printf(" Produto cod: %d não foi encontrado. \n",cod);

            return NULL;
            }

            if(*head_ref == temp){

            *head_ref = temp->prox;

            }

            if(temp->prox != NULL){

            temp->prox->ante = temp->ante;

            }

            if(temp->ante != NULL){

            temp->ante->prox = temp->prox;     

            }

    free(temp);

    printf(" Produto cod: %d removido com sucesso.\n", cod);
    
    return NULL;
}

produto* buscarProduto(produto* head, int cod){

    produto* temp = head;

            while(temp != NULL){

                    if(temp->cod == cod){

                    return temp;
                    }

            temp = temp->prox;

            }

return NULL;
}

void imprimirListaProdutos(produto* head){

    produto* temp = head;

        if(temp == NULL){
            printf(" Nenhum produto na lista.\n");
            return;
        }

        printf(" Lista de produtos:\n"); 

            while(temp != NULL){

                    printf("\n - Nome: %s - Codigo: %d - Quantidade: %d - Preco: %.2f \n", temp->nome, temp->cod, temp->quant, temp->preco);

            temp = temp->prox;

            }
}



int main(){

produto* listaProdutos = NULL;
    int escolha, cod, quant;
    float preco;
    char nome[50];

            do {
                printf("\n 1. Inserir produto \n 2. Remover produto \n 3. Buscar produto\n 4. Imprimir lista de produtos \n 5. Sair \n");
                printf(" Escolha uma opcao: ");
                scanf("%d", &escolha);

                switch (escolha) {
                    case 1:

                        printf(" Nome do produto: ");
                        scanf (" %[^\n]%*c", nome); 
                        printf(" Codigo do produto: ");
                        scanf ("%d", &cod);
                        printf(" Quantidade: ");
                        scanf ("%d", &quant);
                        printf(" Preco: ");
                        scanf ("%f", &preco);

                    inserirProduto(&listaProdutos, nome, cod, quant, preco);
                
                    break;

                    case 2:

                        printf(" Codigo do produto a ser removido: ");
                        scanf ("%d", &cod);

                    removerProduto(&listaProdutos, cod);
                    
                    break;

                    case 3:

                        printf(" Codigo do produto a ser buscado: ");
                        scanf ("%d", &cod);

                    produto* encontrado = buscarProduto(listaProdutos, cod);
                    
                            if(encontrado != NULL){
                                
                                printf(" Produto encontrado: Nome: %s - Codigo: %d - Quantidade: %d - Preco: %.2f \n", encontrado->nome, encontrado->cod, encontrado->quant, encontrado->preco);
                            
                                } else{

                                    printf(" Produto nao encontrado!\n");
                                
                                }

                    break;

                    case 4:

                    imprimirListaProdutos(listaProdutos);
                    
                    break;

                    case 5:

                        printf(" Programa encerrado.\n");
                
                    break;

                    default:

                        printf(" Opcao invalida!\n");
                }

            } while (escolha != 5);

return 0;
}