#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/*
Trabalho feito por:

Felipe Eduardo Costa Lopes Ra: 27332-3
Ramon do Lago Pereira Ra: 27439-5
Felipe Oliveira Sendão Ra: 27177-4
Giovanni D'Olivo Margoto 27133-3

*/

// Como nós fomos bobos e irresponsáveis e deixamos para ultima hora, o código ficou um pouquinho feio cof cof, e n deu tempo de comentar tudo rsrsrsrsrsr

//#declaração das structs 
struct Telefone{ 
	int ddd;
	int telefone;
};

struct Data{ // utilizei o data, pq posso reutilizar p/ qlqr data
	int dia;
	int mes;
	int ano;
};

struct Inadiplencia{ 
	int valor;
	struct Data dtInadiplencia;
	char rua[100];
	int numero;
	int ativa; //utilizei esta flag, para poder identificar as ativas e inativas
};

struct Residente{
	int id;
	char nome[100];
	char sexo[100];
	struct Data dtNascimento;
	struct Telefone contato;
	char cpf[12];
};

struct Endereco{
	char rua[100];
	char cidade[100];
	char estado[100];
	char CEP[10];
	int numero;
};

struct Residencia{
	struct Endereco endereco;
	struct Residente *residentes;
	struct Inadiplencia *inadiplencia;
	char residenteResponsavel[100];
	int qtdResidentes;
	int qtdInadiplencias;
};

int cadastro(struct Residencia* residencias, int *pos){
	
	struct Residente residentes;
	
	int resposta =0, qtdResidentes = 0, verificaIdade = 0;
	int i = 0, j = 0, qtd = (sizeof(struct Residencia) * 100);
	bool pode_cadastrar = true; //n consegui arrumar a realocação dos vetores :(
	
	if(pode_cadastrar) // aqui seria a parte em que iriamos fazer a realocação de vetores, mas vacilamos.
	{		
		printf("\n\n --cadastrando o imovel --\n\n");
		
		printf("Informe o logradouro do imovel: "); //aqui cadastramos o imovel
		gets(residencias[*pos].endereco.rua);
		printf("Informe o numero do imovel: ");
		scanf("%d",&residencias[*pos].endereco.numero);
		setbuf(stdin, NULL); //funcção para limpar o buffer
		printf("Informe a cidade do imovel: ");
		gets(residencias[*pos].endereco.cidade);
		printf("Informe a estado do imovel: ");
		gets(residencias[*pos].endereco.estado);
		printf("Informe o cep do imovel: ");
		gets(residencias[*pos].endereco.CEP);
		printf("Informe a quantidade de residentes: ");
		scanf("%d",&residencias[*pos].qtdResidentes);
		setbuf(stdin, NULL);
		
		qtdResidentes = residencias[*pos].qtdResidentes; //aloca o espaço somente necessário
		
		residencias[*pos].residentes = malloc(sizeof(struct Residente) * qtdResidentes); //alocamos espaço para os residentes
		
		printf("\n\n--Cadastrando Residentes--\n\n");
		
		printf("Informe o nome do residente responsavel: ");
		gets(residencias[*pos].residenteResponsavel);
		
		for(i = 0; i < qtdResidentes; i++){ //cadastramos os residentes
			printf("\nInforme o nome do residente: ");
			gets(residencias[*pos].residentes[i].nome);
			printf("Informe o sexo do residente: ");
			gets(residencias[*pos].residentes[i].sexo);
			printf("Informe o CPF residente: ");
			gets(residencias[*pos].residentes[i].cpf);
			printf("Informe a data de nascimento do residente(dia): ");
			scanf("%d", &residencias[*pos].residentes[i].dtNascimento.dia);
			printf("Informe a data de nascimento do residente(mes): ");
			scanf("%d", &residencias[*pos].residentes[i].dtNascimento.mes);
			printf("Informe a data de nascimento do residente(ano): ");
			scanf("%d", &residencias[*pos].residentes[i].dtNascimento.ano);
			
			if(residencias[*pos].residentes[i].dtNascimento.ano > 2004) //verifica se é maior de idade
			{
				verificaIdade = 1;
			}
			
			if(verificaIdade != 1){
				printf("Informe o telefone do residente (ddd): ");
				scanf("%d", &residencias[*pos].residentes[i].contato.ddd);
				printf("Informe o telefone do residente (telefone): ");
				scanf("%d", &residencias[*pos].residentes[i].contato.telefone);
				setbuf(stdin, NULL);
			}
			
			printf("\n\n");
		}
		
		(*pos)++;	
		resposta = 1;
	}	
	
	return resposta;
}

int cadastroInadiplencia(struct Residencia* residencias, int *pos, int qtd){ //, struct Residencia* residencias*/
		
	struct Inadiplencia inadiplencias;
	int posTemp = 0, resposta = 0, i = 0, num, valor;

	printf("\n\n--Cadastrando Inadiplencia--\n\n"); //aqui cadastramos as inadiplencias
	
	printf("Informe a rua do imovel da inadiplencia: ");
	gets(inadiplencias.rua);
	printf("Informe o numero do imovel da inadiplencia: ");
	scanf("%d", &num);
	printf("Informe a data de abertura da inadiplencia(mes): ");
	scanf("%d", &inadiplencias.dtInadiplencia.mes); //&inadiplencias[*pos].dtInadiplencia.mes*/
	printf("Informe a data de abertura da inadiplencia(ano): ");
	scanf("%d", &inadiplencias.dtInadiplencia.ano);
	printf("Informe o valor da inadiplencia em R$: ");
	scanf("%d", &inadiplencias.valor);
	setbuf(stdin, NULL);
	printf("\n\n"); 
	
	for(i = 0; i < qtd; i++){ //verificamos a quantidade de imoveis, p/ então poder comparar os imoveis com a struct temporaria, se for igual atribui a inadiplencia a residencia.
		if(strcmp(inadiplencias.rua, residencias[i].endereco.rua) == 0 && num == residencias[i].endereco.numero ){
			
			if(residencias[i].qtdInadiplencias < 1){
				residencias[i].inadiplencia = malloc(sizeof(struct Inadiplencia) * 100);
			}
			
			residencias[i].inadiplencia[residencias[i].qtdInadiplencias] = inadiplencias;
			residencias[i].inadiplencia[residencias[i].qtdInadiplencias].numero = num;
			residencias[i].inadiplencia[residencias[i].qtdInadiplencias].ativa = 1;
			residencias[i].qtdInadiplencias = residencias[i].qtdInadiplencias + 1;
			resposta = 1;
		}
	}
	
	return resposta;
}

int removerInadiplencia(struct Residencia* residencias, int qtd){ // aqui removemos, a logica é quase a mesma, a diferença é que ela irá retirar 1 da qtd de inadiplencia ativa e ira deixar o status de ativa em 0
	
	struct Inadiplencia removeInadiplencia;
	int num, ano, mes, i, j,resposta;
	
	printf("\n\n--_*informe a inadiplencia para remocao*_--\n\n");
	
	printf("Informe a rua do imovel da inadiplencia: ");
	gets(removeInadiplencia.rua);
	printf("Informe o numero do imovel da inadiplencia: ");
	scanf("%d", &num);
	printf("Informe a data de abertura da inadiplencia(mes): ");
	scanf("%d", &mes);
	printf("Informe a data de abertura da inadiplencia(ano): ");
	scanf("%d", &ano);
	setbuf(stdin, NULL);
	printf("\n\n");
	
	for(i = 0; i < qtd; i++){
		if(strcmp(removeInadiplencia.rua, residencias[i].endereco.rua) == 0 && num == residencias[i].endereco.numero)
		{
			for(j = 0; j < residencias[i].qtdInadiplencias; j++){
				if(residencias[i].inadiplencia[j].dtInadiplencia.mes == mes && residencias[i].inadiplencia[j].dtInadiplencia.ano == ano){		
					residencias[i].inadiplencia[j].ativa = 0;
					residencias[i].qtdInadiplencias = residencias[i].qtdInadiplencias - 1;
					resposta = 1;		
				}
			}
		}
	}
	
	return resposta;
	
}

int montaMenu(){ // monta o menu e valida
	
	int opcao = 0;
	
	do{
		printf("\t--_-*MENU*-_--\n");
		printf("\t1-)Cadastrar Residencia\n");
		printf("\t2-)Cadastrar Inadiplencia\n");
		printf("\t3-)Remover Inadiplencia\n");
		printf("\t4-)Relatar Inadiplencias\n");
		printf("\t5-)Relatar Imovel/moradores\n");
		printf("\t6-)Encerrar\n");
		printf("\tOpcao: ");
		scanf("%d", &opcao);
		setbuf(stdin, NULL);
			
		if(opcao > 6){
			printf("Opcao invalida, por favor digite uma opcao valida!\n\n");
		}
			
	}while(opcao > 6);
	
	return opcao;
}

int main(){ // main chamando as funções e fazendo algumas validações 
	
	// as impressões não tem segredo, primeiro valida a residencia, e depois seus sub-itens, como pessoas e inadiplencias
	// por isso na maioria dos casos são usados 2 funções for, para poder fazer essa impressão.
	// da mesma forma serve o cadastrp, é importante passar sempre por ambas structs dentro da struct, para isso são utilizadas suas posições do for.
	
	
	int opcao, resposta, pos, i, j, k, verificaIdade, qtdResidencias = 0;
	struct Residencia *residencias = malloc(sizeof(struct Residencia) * 100);
	struct Inadiplencia *inadiplencias = malloc(sizeof(struct Inadiplencia) * 100);
	
	do{
		
		opcao = montaMenu();
		
		switch(opcao){
			case 1: // cadastro de casas
				resposta = cadastro(residencias, &pos);
				qtdResidencias++;
				break;
			case 2:
				if(pos == 0){ //valida se há casas cadastradas
					printf("\n\nAinda nao ha casas cadastradas, por favor cadastre uma casa primeiro!\n\n");
				}else{
					resposta = cadastroInadiplencia(residencias, &pos, qtdResidencias); // faz o cadastro, retornando um status
				}
				break;
			case 3:
				if(pos == 0){
					printf("\n\nAinda nao ha casas cadastradas, por favor cadastre uma casa primeiro!\n\n");
				}else{
					resposta = removerInadiplencia(residencias, qtdResidencias); //remoce, validando se é realmente possível remover uma casa
					
					if(resposta == 1){
						printf("\n\nInadiplencia inativada com sucesso!\n\n");
					}
					else{
						printf("\nFalha ao remover Inadiplencia\n\n");
					}
				}
				break;
			case 4: //impressão das inadiplencias
				
				if(pos == 0){
					printf("\n\nAinda nao ha casas cadastradas, por favor cadastre uma casa primeiro!\n\n");
				}else{
					for(i=0; i < pos; i++){
					
						if(residencias[i].qtdInadiplencias > 0){
						printf("\n\n --_*Mostrando Inadiplencias do Imovel_*-- \n");
						
							for(j = 0; j < residencias[i].qtdInadiplencias; j++){
								printf("\n\nInadiplencia da residencia da rua: %s", residencias[i].inadiplencia[j].rua);
								printf("\nInadiplencia da residencia de numero: %d", residencias[i].inadiplencia[j].numero);
								printf("\nMes da Inadiplencia: %d", residencias[i].inadiplencia[j].dtInadiplencia.mes);
								printf("\nMes da Inadiplencia: %d", residencias[i].inadiplencia[j].dtInadiplencia.ano);
								printf("\nValor da inadiplencia: %d", residencias[i].inadiplencia[j].valor);
							}	
						}else{
							printf("\n\nNao ha Inadiplencias cadastradas para o imovel[%d]!", i + 1);
						}	
					}
					printf("\n\n");	
				}
				break;
			case 5: //impressao dos imoveis
				for(i = 0; i < pos; i++){ 
					
					printf("\n--_*Mostrando Imovel*_--\n");
					
					printf("cidade imovel [%d]: %s\n",  i + 1, residencias[i].endereco.cidade);
					printf("estado imovel [%d]: %s\n", i + 1, residencias[i].endereco.estado);
					printf("CEP imovel [%d]: %s\n", i + 1, residencias[i].endereco.CEP);
					printf("logradouro imovel [%d]: %s\n", i + 1, residencias[i].endereco.rua);
					printf("numero imovel [%d]: %d\n", i + 1, residencias[i].endereco.numero);
					printf("Numero de residentes imovel [%d]: %d\n", i + 1, residencias[i].qtdResidentes);
					
					printf("\n\n --_*Mostrando Residentes dos Imovel_*-- \n");
				
					printf("Nome do residente responsavel do imovel [%d]: %s\n", i + 1, residencias[i].residenteResponsavel);
					for(j = 0; j < residencias[i].qtdResidentes; j++){
						printf("\nnome do residente [%d]: %s\n" , j + 1, residencias[i].residentes[j].nome);
						printf("sexo do residente [%d]: %s\n" , j + 1, residencias[i].residentes[j].sexo);
						printf("CPF do residente [%d]: %s\n", j + 1, residencias[i].residentes[j].cpf);
						printf("date de nascimento do residente [%d]: %d/%d/%d\n", j + 1, residencias[i].residentes[j].dtNascimento.dia, residencias[i].residentes[j].dtNascimento.mes, residencias[i].residentes[j].dtNascimento.ano);
						
						if(residencias[i].residentes[j].dtNascimento.ano > 2004)
						{
							verificaIdade = 1;
						}
						
						if(verificaIdade != 1){
							printf("telefone do residente [%d]: (%d)%d\n\n", j + 1, residencias[i].residentes[j].contato.ddd, residencias[i].residentes[j].contato.telefone);	
						}
					}
				}
				printf("\n");
				break;			
			case 6: //validações se o programa encontrou algum erro, e fechamento
				printf("\n\n O programa ira encerrar! \n\n");
				return 0;
			default: 
				printf("\n\n\ Ocorreu um erro inesperado o programa irá encerrar! \n\n");
				return 0;
		}
		
	}while (opcao != 6);
	
	return 0;
}
