o Criar Lista (create List);
o Adicionar No (add Node);
o Remover No (remove Node)
o Procurar Lista (search List);
o Recuperar No (retrieve Node);
o Posicionar (traverse);
o Lista Vazia (empty List);
o Lista Cheia (full List);
o Contador Lista (list Count);
o Destruir Lista (destroy List)

 algoritmo que misture duas listas ordenadas em uma
 única lista, usando operações do TAD Lista;

Uma função receberá 3 listas: uma que será a lista mesclada e
as outras duas são as listas que serão mescladas. Haverá uma
repetição até que todos os valores de A e B sejam lidos, essa
repetição seguirá os seguintes passos: Primeiro será comparado
entre os valores das listas A e B, o que tiver menor valor terá
o seu valor copiado para um nó na lista F e a lista da qual foi
tirado o elemento avançará para o próximo nó. Se o valor do nó de
A for igual ao de B, o valor de A é copiado para F e tanto A quanto
B avançam para o próximo nó. Até que todos os nós das duas listas já
tenham sido percorridos.

void mesclarListas (LIST* Final, LIST* A, LIST* B) {
    if(!(emptyList(A)&&emptyList(B))){
        NODE* Anode=A->head;
        NODE* Bnode=B->head;
        NODE* Fnode=Final->head;
        while((Anode!=NULL)&&(Bnode!=NULL)){
            if(Anode==NULL){
                addNode(F,Bnode->dataPtr);
                Bnode=Bnode->link
            } else if(Bnode==NULL){
                addNode(F,Anode->dataPtr);
                Anode=Anode->link
            } else {
                if (Anode->dataPtr<Bnode->dataPtr){
                    addNode(F,Anode->dataPtr);
                    Anode=Anode->link
                } else if(Bnode->dataPtr<Anode->dataPtr){
                    addNode(F,Bnode->dataPtr);
                    Bnode=Bnode->link
                } else if (Anode->dataPtr==Bnode->dataPtr){
                    addNode(F,Anode->dataPtr);
                    Anode=Anode->link
                    Bnode=Bnode->link
                }
            }
        }
    }
}
