#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// insere o livro
struct cad_livro{
	   char titulo[50]; 
	   char autor[40];
	   int numeroDeRegistro;
	   char anoDePublicacao[10];
	   int ISBN;
	   int vol;
	   char editora[25];
	   char disp[20];
};		
struct cad_livro dados_livro;

void insere_livro(FILE *cad_livro, struct cad_livro dados_livro){
	cad_livro = fopen("cad_livro.txt", "a");
	
			system("clear || cls");
				
			printf("Título (máximo 50 caracteres): ");
			scanf("%s", dados_livro.titulo);
			fprintf(cad_livro,"%s ", dados_livro.titulo);
			
			printf("Autor(a) (máximo 40 caracteres): ");
			scanf("%s", dados_livro.autor);
			fprintf(cad_livro,"%s ", dados_livro.autor);
		
			
			printf("Número de registro (apenas números): ");
			scanf("%d", &dados_livro.numeroDeRegistro);
			fprintf(cad_livro,"%d ", dados_livro.numeroDeRegistro);
			
			printf("Ano de publicação (xx/xx/xxxx): ");
			scanf("%s", dados_livro.anoDePublicacao);
			fprintf(cad_livro,"%s ", dados_livro.anoDePublicacao);
			
			
			printf("ISBN (apenas números): ");
			scanf("%d", &dados_livro.ISBN);
			fprintf(cad_livro,"%d ", dados_livro.ISBN);
			
			
			printf("Volume (apenas números): ");
			scanf("%d", &dados_livro.vol); 
			fprintf(cad_livro,"%d ", dados_livro.vol);
			
			
			printf("Editora (máximo 25 caracteres): ");
			scanf("%s", dados_livro.editora);
			fprintf(cad_livro,"%s ", dados_livro.editora);
			
			fprintf(cad_livro, "Disponível \n");
			
			printf("Livro cadastrado! (aperte enter)");
			fgets(dados_livro.editora, 25, stdin);
			getchar();
			
			fclose(cad_livro);
}

//procura o livro pelo título
void procura_livro_titulo(FILE *cad_livro, struct cad_livro dados_livro){
	
	char titulo[50];
	int registro;
	
	system("clear || cls");
	
	printf("Informe o título do livro: ");
	scanf("%s", titulo);

	cad_livro = fopen("cad_livro.txt", "r");
	
	while (fscanf(cad_livro, "%s %s %d %s %d %d %s %s", dados_livro.titulo, dados_livro.autor, &dados_livro.numeroDeRegistro, dados_livro.anoDePublicacao, &dados_livro.ISBN, &dados_livro.vol, dados_livro.editora, dados_livro.disp) == 8){
			
			if(strcmp(dados_livro.titulo, titulo) == 0) {
				registro = 1;
				printf("Livro %s, vol %d registrado (aperte enter) \n", titulo, dados_livro.vol);
				fgets(dados_livro.editora, 25, stdin);
				getchar();
				system("clear || cls");
				
				break;
			} else {
				registro = 0;
			}
	}
	
	fclose(cad_livro);
	
	if (registro == 0){
		printf ("Livro %s não registrado (aperte enter)", titulo);
		fgets(dados_livro.editora, 25, stdin);
		getchar();
		//system("clear || cls");
	}
}
//procura o livro pelo autor
void procura_livro_autor(FILE *cad_livro, struct cad_livro dados_livro){
	
	char autor[40];
	int registro;
	
	system("clear || cls");
	printf("Informe o autor(a): ");
	scanf("%s", autor);
	
	cad_livro = fopen("cad_livro.txt", "r");
	
	printf("Livros do(a) autor(a) registrados: \n");
	
	while (fscanf(cad_livro, "%s %s %d %s %d %d %s %s", dados_livro.titulo, dados_livro.autor, &dados_livro.numeroDeRegistro, dados_livro.anoDePublicacao, &dados_livro.ISBN, &dados_livro.vol, dados_livro.editora, dados_livro.disp) == 8){
			
			if(strcmp(dados_livro.autor, autor) == 0){
				printf("%s, volume:%d\n", dados_livro.titulo, dados_livro.vol);
				registro = 1;		
			} else {
				registro = 0;
			}
	}
	
	if (registro == 1){
		printf("\nLista terminada (aperte enter)");
		fgets(dados_livro.editora, 25, stdin);
		getchar();
	} else {
		printf("Não há livros do autor (aperte enter)");
		fgets(dados_livro.editora, 25, stdin);
		getchar();
	}
	
	fclose(cad_livro);
}

//apaga um livro
void apaga_livro(FILE *cad_livro, struct cad_livro dados_livro){
	
	FILE *apaga;
	char livro[50];
	int i, j;
	i=0;
	j=0;
	
	system("clear || cls");
	
	printf("Digite o título do livro que deseja apagar: ");
	scanf("%s",livro);
	
	apaga = fopen("apaga.txt", "w");
	cad_livro = fopen("cad_livro.txt", "r");
	
	
	while (fscanf(cad_livro, "%s %s %d %s %d %d %s %s", dados_livro.titulo, dados_livro.autor, &dados_livro.numeroDeRegistro, dados_livro.anoDePublicacao, &dados_livro.ISBN, &dados_livro.vol, dados_livro.editora, dados_livro.disp) == 8){
		i++;
		
		if(strcmp(dados_livro.titulo, livro) == 0){
			continue;
		} else {
			fprintf(apaga, "%s %s %d %s %d %d %s %s\n", dados_livro.titulo, dados_livro.autor, dados_livro.numeroDeRegistro, dados_livro.anoDePublicacao, dados_livro.ISBN, dados_livro.vol, dados_livro.editora, dados_livro.disp);
			j++;
		}
	}	
	
	fclose(cad_livro);	
	
	remove("cad_livro.txt");
	
	char nome_velho[] = "apaga.txt";
	char nome_novo[] = "cad_livro.txt";
	
	rename(nome_velho, nome_novo);
	
	fclose(apaga);
	
	if(i==j){
		system("clear || cls");
		printf("Título não existe ou livro não foi apagado com sucesso (aperte enter)");
		fgets(dados_livro.editora, 25, stdin);
		getchar();
	}else{
		system("clear || cls");
		printf("Livro apagado com sucesso (aperte enter)");
		fgets(dados_livro.editora, 25, stdin);
		getchar();
	}
	
	
}

struct reserva_livro{
	char dataReserva[15];
};

struct reserva_livro reserva;

struct emprestimo{
	
	char dataEmprestimo[15];
	char dataDevolucao[15];

};

struct emprestimo emprestimo;

//lista livro
void lista_livro(FILE *cad_livro, struct cad_livro dados_livro){
	    
	    system("clear || cls");	
	    
	    cad_livro = fopen("cad_livro.txt", "r");
	    
	    
	    int verificacao;
	    
	 	printf("--- LISTA DE LIVROS ---\n");
	 	
		while (fscanf(cad_livro, "%s %s %d %s %d %d %s %s", dados_livro.titulo, dados_livro.autor, &dados_livro.numeroDeRegistro, dados_livro.anoDePublicacao, &dados_livro.ISBN, &dados_livro.vol, dados_livro.editora, dados_livro.disp) == 8){
			verificacao = 1;
	    	printf("Título: %s, autor: %s, volume: %d, editora: %s, situação: %s\n", dados_livro.titulo, dados_livro.autor, dados_livro.vol, dados_livro.editora, dados_livro.disp);
	}
	
    if (verificacao == 1){
 	  printf("Listagem terminada! (aperte enter)");
 	  fgets(dados_livro.editora, 25, stdin);
	  getchar();
    } else {
 	  printf("Não há livros para serem listados (aperte enter)");
 	  fgets(dados_livro.editora, 25, stdin);
	  getchar();
   }
	
	fclose(cad_livro);
}


//registra data de emprestimo
void registra_data_emprestimo(FILE *cad_livro, FILE *cad_emprestimo, struct cad_livro dados_livro, struct emprestimo emprestimo){
	
	system("clear || cls");	

	FILE *apaga;		
	char livro[50];	
	char nome[50];	
	int verificacao;	
		
	printf("Informe o título do livro a ser emprestado: ");
	scanf("%s", livro);
	printf("Informe o nome da pessoa a quem será emprestado: ");
	scanf("%s", nome);
	

	cad_livro = fopen("cad_livro.txt", "r");
	cad_emprestimo = fopen("cad_emprestimo.txt", "a");
	
		while (fscanf(cad_livro, "%s %s %d %s %d %d %s %s", dados_livro.titulo, dados_livro.autor, &dados_livro.numeroDeRegistro, dados_livro.anoDePublicacao, &dados_livro.ISBN, &dados_livro.vol, dados_livro.editora, dados_livro.disp) == 8){
				if (strcmp(dados_livro.titulo, livro) == 0) {
					if(strcmp(dados_livro.disp, "Disponível") == 0){
					
						printf("informe a data de empréstimo (xx/xx/xxxx): ");
						scanf("%s", emprestimo.dataEmprestimo);
						printf("informe a data de devolução (xx/xx/xxxx): ");
						scanf("%s", emprestimo.dataDevolucao);
				
						fprintf(cad_emprestimo, "%s %d emprestado [%s] [%s] %s\n", dados_livro.titulo, dados_livro.vol, emprestimo.dataEmprestimo, emprestimo.dataDevolucao, nome);
						
						verificacao = 1;
						break;
								
					} else {
						verificacao = 0;
					}
				}
				
		    }
		    
		fclose(cad_livro);	
		cad_livro = fopen("cad_livro.txt", "r");    
		    
		  if(verificacao == 1){  
		  apaga = fopen("apaga.txt", "w");
		  while (fscanf(cad_livro, "%s %s %d %s %d %d %s %s", dados_livro.titulo, dados_livro.autor, &dados_livro.numeroDeRegistro, dados_livro.anoDePublicacao, &dados_livro.ISBN, &dados_livro.vol, dados_livro.editora, dados_livro.disp) == 8){
		  if(strcmp(dados_livro.titulo, livro) == 0){
		   	  strcpy(dados_livro.disp, "emprestado");
			  fprintf(apaga, "%s %s %d %s %d %d %s %s \n", dados_livro.titulo, dados_livro.autor, dados_livro.numeroDeRegistro, dados_livro.anoDePublicacao, dados_livro.ISBN, dados_livro.vol, dados_livro.editora, dados_livro.disp);				
			} else {
				fprintf(apaga, "%s %s %d %s %d %d %s %s \n", dados_livro.titulo, dados_livro.autor, dados_livro.numeroDeRegistro, dados_livro.anoDePublicacao, dados_livro.ISBN, dados_livro.vol, dados_livro.editora, dados_livro.disp);	
			}
		  } 
		fclose(cad_livro);	
		fclose(apaga);				
		remove("cad_livro.txt");
						
		char nome_velho[] = "apaga.txt";
		char nome_novo[] = "cad_livro.txt";
						
		rename(nome_velho, nome_novo);
		
		printf("Empréstimo registrado com sucesso! (aperte enter)");
		fgets(nome, 50, stdin);
		getchar();
		} else {
			printf("Livro não disponível, considere fazer uma reserva. (aperte enter)");
			fgets(nome, 50, stdin);
			getchar();
		} 
		    	   				
		fclose(cad_emprestimo);   
		    
	    }


//registra reserva		
void registra_reserva(FILE *cad_livro, FILE *cad_reserva, struct cad_livro dados_livro, struct reserva_livro reserva){
	
	system("clear || cls");	

	FILE *apaga;
	char livro[50];
	char nome[50];
	int verificacao;
	
	
	cad_livro = fopen("cad_livro.txt", "r");
	cad_reserva = fopen("cad_reserva.txt", "a");


	printf("Informe o título do livro: ");
	scanf("%s", livro);
	
	 printf("Informe o nome da pessoa a quem será reservado: ");
	 scanf("%s", nome);	

	
	while (fscanf(cad_livro, "%s %s %d %s %d %d %s %s", dados_livro.titulo, dados_livro.autor, &dados_livro.numeroDeRegistro, dados_livro.anoDePublicacao, &dados_livro.ISBN, &dados_livro.vol, dados_livro.editora, dados_livro.disp) == 8){
				if (strcmp(dados_livro.titulo, livro) == 0) {
					 
					printf("Informe a data da reserva (xx/xx/xxxx): ");
					scanf("%s", reserva.dataReserva);
					fprintf(cad_reserva, "%s %d reservado [%s] %s\n", dados_livro.titulo, dados_livro.vol, reserva.dataReserva, nome);	
					verificacao = 1;
					break;
			} else {
				verificacao = 0;
			
			}
	}
	
	
	fclose(cad_livro);
	cad_livro = fopen("cad_livro.txt", "r");
	
	if(verificacao == 1){
		apaga = fopen("apaga.txt", "w");
		while (fscanf(cad_livro, "%s %s %d %s %d %d %s %s", dados_livro.titulo, dados_livro.autor, &dados_livro.numeroDeRegistro, dados_livro.anoDePublicacao, &dados_livro.ISBN, &dados_livro.vol, dados_livro.editora, dados_livro.disp) == 8){
		  	if( strcmp(dados_livro.titulo, livro) == 0 && strcmp(dados_livro.disp, "Disponível") == 0){
		 			strcpy(dados_livro.disp, "reservado");
		 		 	fprintf(apaga, "%s %s %d %s %d %d %s %s \n", dados_livro.titulo, dados_livro.autor, dados_livro.numeroDeRegistro, dados_livro.anoDePublicacao, dados_livro.ISBN, dados_livro.vol, dados_livro.editora, dados_livro.disp);						
			} else {
			
				fprintf(apaga, "%s %s %d %s %d %d %s %s \n", dados_livro.titulo, dados_livro.autor, dados_livro.numeroDeRegistro, dados_livro.anoDePublicacao, dados_livro.ISBN, dados_livro.vol, dados_livro.editora, dados_livro.disp);	
			}
		}
	  printf("Livro registrado com sucesso! (aperte enter)");
	  fgets(dados_livro.disp, 20, stdin);
	  getchar();
	
	  fclose(cad_livro);	 
	  fclose (apaga);
			
	  remove("cad_livro.txt");
	  					
	  char nome_velho[] = "apaga.txt";
	  char nome_novo[] = "cad_livro.txt";
						
	  rename(nome_velho, nome_novo);
		
	  fclose(cad_reserva);
		 
	} else {
		printf("Livro não encontrado (aperte enter)");	
		fgets(dados_livro.disp, 20, stdin);
		getchar();
		fclose(cad_livro);	 
		fclose (apaga);
		fclose(cad_reserva);
   }		
		
		
}	


// renova emprestimo
void renova_emprestimo(FILE *cad_livro, FILE *cad_emprestimo, struct cad_livro dados_livro, struct emprestimo emprestimo, char login[30]){

	system("clear || cls");
	
	char livro[50];
	char nome[50];
	char novadata[15];
	int verificacao;
	
	FILE *apaga;
	
	apaga = fopen("apaga.txt","w");
	cad_livro = fopen("cad_livro.txt", "r");
	cad_emprestimo = fopen("cad_emprestimo.txt", "r");
	
	printf("Informe o título do livro: ");	
	scanf("%s", livro);	
	
	while(fscanf(cad_emprestimo,"%s %d %s %s %s %s",  dados_livro.titulo, &dados_livro.vol, dados_livro.disp, emprestimo.dataEmprestimo, emprestimo.dataDevolucao, nome) == 6){
		if(strcmp(dados_livro.titulo, livro) == 0){
			if(strcmp(login, nome) == 0){
				printf("informe a nova data de devolução (xx/xx/xxxx): ");
				scanf("%s", novadata);
				verificacao = 1;
				break;
			}
		} else {
			verificacao = 0;
		}
	}
	
	
 fclose(cad_emprestimo);
 cad_emprestimo = fopen("cad_emprestimo.txt", "r");
 
 if(verificacao == 1){
 	
	while (fscanf(cad_emprestimo, "%s %d %s %s %s %s",  dados_livro.titulo, &dados_livro.vol, dados_livro.disp, emprestimo.dataEmprestimo, emprestimo.dataDevolucao, nome) == 6){
		  if(strcmp(dados_livro.titulo, livro) == 0){
		   	  strcpy(emprestimo.dataDevolucao, novadata);
			  fprintf(apaga, "%s %d %s %s [%s] %s\n",  dados_livro.titulo, dados_livro.vol, dados_livro.disp, emprestimo.dataEmprestimo, emprestimo.dataDevolucao, nome);			
			} else {
				fprintf(apaga, "%s %d %s %s %s %s\n",  dados_livro.titulo, dados_livro.vol, dados_livro.disp, emprestimo.dataEmprestimo, emprestimo.dataDevolucao, nome);	
			}
		  } 
	
		fclose(cad_emprestimo);				
		remove("cad_emprestimo.txt");
						
		char nome_velho[] = "apaga.txt";
		char nome_novo[] = "cad_emprestimo.txt";
						
		rename(nome_velho, nome_novo);
		
		printf("Empréstimo renovado com sucesso! (aperte enter)");
		fgets(dados_livro.disp, 20, stdin);
		getchar();
		
} else {
	printf("O nome do usuário ou livro não corresponde com o nome no empréstimo (aperte enter).");
	fgets(dados_livro.disp, 20, stdin);
	getchar();
}		
	
  fclose(cad_livro);

  fclose(apaga);
}	
	
int main(){

	//declaração das structs
	struct cad_usuario{ 	
		
		char nome[30];
		int id;
		char email[40];
		char senha[20];
		char curso[25];
		int cpf;
		char tipo[15];
	
	};	
	
	
	//outras declarações
	int num;
	struct cad_usuario dados_usuario;
	char login[30];
	char senha[20];
	int login_efetuado;
	char tipo_login[15];


	//declaração dos arquivos
	FILE *cad_usuario;
	FILE *cad_livro;
	FILE *cad_reserva;
	FILE *cad_emprestimo;
	cad_usuario = fopen("cad_usuario.txt", "w");
	cad_livro = fopen("cad_livro.txt", "w");
	cad_reserva = fopen("cad_reserva.txt", "w");
	cad_emprestimo = fopen("cad_emprestimo.txt", "w");
	fclose(cad_emprestimo);
	fclose(cad_livro);
	fclose(cad_reserva);
	fclose(cad_usuario);
	
	
	//criação do menu
	while(num != 3){
	
	
	system("clear || cls");
	printf("---- MENU PRINCIPAL ----\n");
	printf("[1] Entrar no sistema\n");
	printf("[2] Cadastrar usuário\n");
	printf("[3] Sair\n");
	printf("Escolha uma das opções: ");
	scanf("%d", &num);
	
	
	if(num != 1 && num != 2 && num != 3){
		printf("Opção inválida (aperte enter)");	
		getchar();
		getchar();
	}	
	system("clear || cls");
		
		
	switch(num){
		
		case 1:
		
			cad_usuario = fopen("cad_usuario.txt", "r");
			
			printf("------ LOGIN ------\n");
			printf("Usuário: ");
			scanf("%s", login);
			printf("Senha: ");
			scanf("%s", senha);
			
			
		while (fscanf(cad_usuario, "%s %d %s %s %s %d %s", dados_usuario.nome, &dados_usuario.id, dados_usuario.email, dados_usuario.senha, dados_usuario.curso, 	 &dados_usuario.cpf, dados_usuario.tipo) == 7){
			
			
			if( (strcmp(login,dados_usuario.nome) == 0) && (strcmp(senha, dados_usuario.senha)==0) ){
				printf("Login efetuado com sucesso! (aperte enter)");
				login_efetuado = 1;
				strcpy(tipo_login, dados_usuario.tipo);
				fgets(dados_usuario.tipo, 15, stdin);
				getchar();
				printf("\n");	
				break;
			}else{
				login_efetuado = 0;
			}
		}
		
		fclose(cad_usuario);
		
		if (login_efetuado == 0){
			printf("O login não foi efetuado (aperte enter)");
			fgets(dados_usuario.tipo, 15, stdin);
			getchar();
		} else {
		
			while (num != 9){
			
			system("clear || cls");
			
			printf("------- BIBLIOTECA -------\n");
			printf("[1] Inserir novo livro\n");
			printf("[2] Procurar livro por título\n");
			printf("[3] Procurar livro por autor\n");
			printf("[4] Apagar livro\n");
			printf("[5] Listar livros existentes na biblioteca\n"); 
			printf("[6] Registar data de empréstimo e devolução de um livro\n");
			printf("[7] Registrar reservas\n");
			printf("[8] Renovar empréstimo\n");
			printf("[9] Sair\n");
			printf("Escolha uma opção: ");
			scanf("%d", &num);
			printf("\n");
			
			switch(num){
				
				case 1:
				
					if (strcmp(tipo_login, "funcionarioBib") == 0){
						insere_livro(cad_livro, dados_livro);
					}else{
						system("clear || cls");
						printf("acesso não autorizadao (aperte enter)");
						getchar();
						getchar();
					}
					
				break;
				
				case 2:
					procura_livro_titulo(cad_livro, dados_livro);
				break;
				
				case 3:
					procura_livro_autor(cad_livro, dados_livro);
				break;
				
				case 4:
				
					if (strcmp(tipo_login, "funcionarioBib") == 0){
						apaga_livro(cad_livro, dados_livro);
					}else{
						system("clear || cls");
						printf("acesso não autorizado (aperte enter)");
						getchar();
						getchar();
					}
				
				break;
				
				case 5:
					lista_livro(cad_livro, dados_livro);
				break;
				
				case 6:
				
					if (strcmp(tipo_login, "funcionarioBib") == 0){
						registra_data_emprestimo(cad_livro, cad_emprestimo, dados_livro, emprestimo);
					   }else{
						system("clear || cls");
						printf("acesso não autorizado (aperte enter)");
						getchar();
						getchar();
					}
				
				break;
				
				case 7:
				
					if (strcmp(tipo_login, "funcionarioBib") == 0){
					registra_reserva(cad_livro, cad_reserva, dados_livro, reserva);
					}else{
						system("clear || cls");
						printf("Acesso não autorizado (aperte enter)");
						getchar();
						getchar();
					}
				
				break;
				
				case 8:
				 	renova_emprestimo(cad_livro, cad_emprestimo, dados_livro, emprestimo, login);
				
				break;
				
				case 9:
					system("clear || cls");
					printf("Sistema encerrado\n");
					return 0;	
			}
		}
	}
		
		
		
		system("clear || cls");
			
		break;
		
		case 2:
			cad_usuario = fopen("cad_usuario.txt", "a");
			
			printf("------------ CADASTRO ----------\n");
			
			printf("Nome (máximo 30 caracteres): ");
			scanf("%s", dados_usuario.nome);
			fprintf(cad_usuario,"%s ", dados_usuario.nome);
			
			printf("ID (apenas números): ");
			scanf("%d", &dados_usuario.id);
			fprintf(cad_usuario,"%d ", dados_usuario.id);
		
			
			printf("E-mail (máximo 40 caracteres): ");
			scanf("%s", dados_usuario.email);
			fprintf(cad_usuario,"%s ", dados_usuario.email);
			
			printf("Senha (máximo 20 caracteres): ");
			scanf("%s", dados_usuario.senha);
			fprintf(cad_usuario,"%s ", dados_usuario.senha);
			
			
			printf("Curso (turismo, física, engcomp ou matemática): ");
			scanf("%s", dados_usuario.curso);
			fprintf(cad_usuario,"%s ", dados_usuario.curso);
			
			
			printf("CPF (apenas números): ");
			scanf("%d", &dados_usuario.cpf); 
			fprintf(cad_usuario,"%d ", dados_usuario.cpf);
			
			
			printf("Tipo (aluno, docente, funcionarioBib): ");
			scanf("%s", dados_usuario.tipo);
			fprintf(cad_usuario,"%s \n", dados_usuario.tipo);
			
			
			fclose(cad_usuario);
			
			printf("Cadastro realizado com sucesso! (aperte enter)");
			fgets(dados_usuario.tipo, 15, stdin);
			getchar();
				
		break;
		
		case 3:
			printf("Sistema encerrado\n");
			return 0;
	
	
		}
	}
	
  		

	return 0;
}
