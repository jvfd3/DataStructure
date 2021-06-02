
passos até uma das listas estar vazia ou os elementos do topo forem diferente: compararemos o
topo da pilha de ambos, se forem iguais remove o primeiro elemento de cada pilha e insere esse
valor em uma pilha auxiliar; Se os;;;diferentes a pilha é diferente então caso a pilha auxiliar estiver, 



void SaoIguais(*Pilha A, *Pilha B){
    int Temp;
    int SaoIguais=1;
    Pilha* Aux;
    CriaPilha(Aux);

    se (ContadorPilha(A) != ContadorPilha(B)){
        SaoIguais=0;
    }

    enquanto (!(PilhaVazia(A)||PilhaVazia(B))&&SaoIguais){
        se (TopoPilha(A)!=TopoPilha(B)) {
            SaoIguais=0;
        } senao {
            Temp=RemovePilha(A);
            Temp=RemovePilha(B);
            InserirPilha(Aux,Temp);
        }
    }

    enquanto (!PilhaVazia(Aux)){
        Temp = RemovePilha(Aux);
        InserirPilha(A, Temp);
        InserirPilha(B, Temp);
    }
    
    se (SaoIguais) {
        imprime("Sao Iguais\n");
    } senao {
        imprime("Sao diferentes\n");
    }
}

int main (){
    Criar Pilha (Create Stack);
    Inserir Pilha (Push Stack);
    Remover Pilha (Pop Stack);
    Topo Pilha (Stack Top);
    Pilha Vazia (Empty Stack);
    Pilha Cheia (Full Stack);
    Contador Pilha (Stack Count);
    Destruir Pilha (Destroy Stack).

    Criar Pilha A;
    Criar Pilha B;
    Criar Pilha Temp;

    InsereValoresAleatorios(A);
    InsereValoresAleatorios(B);

    SaoIguais(A,B);
    

}