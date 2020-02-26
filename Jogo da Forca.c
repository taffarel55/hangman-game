
/*-------------------------------------------------------------------------------
   Jogo virtual do nosso clássico Jogo da Forca
   Jogo da Forca - versão 1.0
  
   Autor : Mauricio Taffarel
   Professor: Lucio Marcos
   O programa é como uma ferramenta de estudo à nova linguagem
  
 --------------------------------------------------------------------------------

   Características e funcionalidades:

   O jogo contém uma certa interface utilizando os caracteres da ASCII.
   Este jogo dispõe de 5 temas: Objeto, Animal, Frutas, Paises, Comida.
   É possivel também definir a dificuldade da palavra
   Código totalmente livre para editar mantendo este título
   IMPORTANTE - Caso progama não compile baixe todas as bibiotecas abaixo  
   Hino do Bahia está comentado no codigo do jogo por motivos de melhor facilidade 
   pra testar, caso queira ouvir só descomentar rs  

   
 ---------------------------------------------------------------------------------  
*/


// ------------------------ PALAVRAS DO JOGO -------------------------------------

char PALAVRA[15][14] = 
	 
	 //OBJETO
	 {{'F', 'A', 'C', 'A'}, 
	 {'V', 'E', 'N', 'T', 'I', 'L', 'A', 'D', 'O', 'R'},
     {'D', 'E', 'S', 'F', 'I', 'B', 'R', 'I', 'L', 'A', 'D', 'O', 'R'},
     
     //ANIMAL
	 {'S', 'A', 'P', 'O'},
     {'L', 'A', 'G', 'A', 'R', 'T', 'O'},
     {'O', 'R','N', 'I', 'T', 'O','R','R','I','N','C','O'},
     
     //FRUTAS
     {'U', 'V', 'A'},
     {'A', 'B', 'A', 'C', 'A','X','I'},
     {'K', 'I', 'W', 'I'},
     
     //PAISES
     {'A', 'L', 'E', 'M', 'A','N','H','A'},
     {'A', 'F', 'E', 'G', 'A','N','I','S','T','A','O'},
     {'Z', 'I', 'M', 'B', 'A','B','W','E'},
     
     //COMIDA
     {'M', 'I', 'O', 'J', 'O'},
     {'L', 'A', 'S', 'A', 'N','H','A'},
	 {'S', 'T', 'R', 'O', 'G','O','N','O','F','F'}};
	  
   
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.c>
#include<dos.h>
#include <time.h>

#define ACIMA 38
#define ABAIXO 40
#define DIREITA 39
#define ESQUERDA 37
#define ENTER 13

#define DO 261.625519
#define RE 293.664734
#define MI 329.627533
#define FA 349.228241
#define SOL 391.995392
#define SOLsus 415.304688
#define LA 440.0
#define SI 493.883301 
#define DOm 523.251099
#define REm 587.329529	
#define MIm 659.255127

int PX_MENUd=23, PY_MENUd=16, COMPRIMENTO_MENUd=8, ALTURA_MENUd=2, PX_MENUdA=23;
int PX_MENU=6, PY_MENU=11, COMPRIMENTO_MENU=19, ALTURA_MENU=12;
int PX_MENUi=20, PY_MENUi=11, COMPRIMENTO_MENUi=40, ALTURA_MENUi=12, LINHA_HORIZONTALi=196,LINHA_VERTICALi=179;
int PX_MENUA=6,i,j,k,m,contP=0,DIFICULDADE,TEMA,NUMERO_PALAVRA;
char NE=191,SE=217,SO=192,NO=218,LINHA_HORIZONTAL=196,LINHA_VERTICAL=179,cont='v',DICA[7];	
int laco_jogo=1,laco_menu=1,laco_geral=1,ACERTOS,ERROS,GANHOU,ACERTAR,COMPLETAR,LETRAS;
char letra_usuario,ACERTOU,POSICAO_PALAVRA,LETRA_REPETIDA,menuW,PALAVRA_ANALISE[15][14];


int cabecalho()
{

	int i,j;

	//Cores
	textbackground(BLUE);
	system("CLS");
	textcolor(RED);
	
	//Desenho maior
	for(i=1;i<=7;i++)
	{
    for(j=1;j<=80;j++)
	   {
          gotoxy(j,i); printf("%c",219);
       }
    }
    
    //Linhas da borda
	textcolor(WHITE);
    for(i=1;i<=80;i++)
    {
    	gotoxy(i,1); printf("%c",219);
    	gotoxy(i,8); printf("%c",219);
    }
    for(i=2;i<=7;i++)
    {
    	gotoxy(1,i); printf("%c",219);
    	gotoxy(80,i); printf("%c",219);
    }
    
    //Nome grandão
 	textbackground(RED);
	gotoxy(10,3);printf("    _  ___   ___  ___    ___   _     ___ ___  ___  ___   _ \n");
    gotoxy(10,4);printf(" _ | |/ _ \\ / __|/ _ \\  |   \\ /_\\   | __/ _ \\| _ \\/ __| /_\\  \n");
    gotoxy(10,5);printf("| || | (_) | (_ | (_) | | |) / _ \\  | _| (_) |   / (__ / _ \\ \n");
    gotoxy(10,6);printf(" \\__/ \\___/ \\___|\\___/  |___/_/ \\_\\ |_| \\___/|_|_\\\\___/_/ \\_\\\n");
   
	gotoxy(80,25);
	textbackground(BLUE);
	return(0);	
}

int desenho_palavra()
{
	int i;
		
	gotoxy(32-POSICAO_PALAVRA,22);
	
	for(i=33-contP;i<33;i++)
	{
		printf("_ ");
	}	
		
		
}


int quadroletras_usadas()
{
	int i,j,l;
	
	//Desenho dos botões
	textcolor(RED);
	l=26;
	
		for(i=l;i<=(l+16);i++)
		{
			for(j=12;j<=16;j++)
			{	
				gotoxy(i,j);
				if ((i==l) || (j==12) || (j==16) || (i==l+16)) 
				{
				textcolor(WHITE); printf("%c",219);
			    }
				else
				{
				textcolor(RED); printf("%c",219);
			    }
			}		
		}
		
}

int cabeca()
{    
	int posicao_cabeca=65, altura_cabeca=14;
	gotoxy(posicao_cabeca,altura_cabeca); printf(" _");
	gotoxy(posicao_cabeca,altura_cabeca+1); printf("/ \\");	
	gotoxy(posicao_cabeca,altura_cabeca+2); printf("\\_/");
}

int pescoco()
{
	gotoxy(66,17); printf("|");
}

int tronco()
{
	gotoxy(66,18); printf("|");
	gotoxy(66,19); printf("|");
	gotoxy(66,20); printf("|");
	gotoxy(66,21); printf("|");
}

int braco1()
{
	gotoxy(65,18); printf("  \\");
    gotoxy(64,19); printf("    \\");
		
}

int braco2()
{
	gotoxy(65,18); printf("/ \\");
    gotoxy(64,19); printf("/   \\");	
}

int perna1()
{
	gotoxy(65,22); printf("/");
    gotoxy(64,23); printf("/");
}

int perna2()
{
	gotoxy(65,22); printf("/ \\");
    gotoxy(64,23); printf("/   \\");
}

int contagem()
{	
	// gotoxy(46,25);
	// printf("TESTANDO: ");
	// gotoxy(55,25);
	for(i=0;PALAVRA[NUMERO_PALAVRA-1][i]!='\0';i++)
	    	{
	    		// printf("%c",PALAVRA[NUMERO_PALAVRA-1][i]); 
	    		contP++;
	    		
	    	}
	   	
}

int analise_letra()
{
	int j,k,COMPLETOU,ESCREVEU=1;
	ACERTOU='F';
	LETRA_REPETIDA=' ';
	char LETRAS_ERRADAS[15];
	COMPLETAR=0;
	ACERTAR=1;
	
	
	//Varrendo Palavra
	for(i=0;PALAVRA[NUMERO_PALAVRA-1][i]!='\0';i++)
	    	{
	    		LETRAS_ERRADAS[i]=letra_usuario;
	    		//ACERTOU
				if(PALAVRA[NUMERO_PALAVRA-1][i]==letra_usuario)
	    		{			
					ACERTOU='V';
			
					for(k=0;k<=15;k++)
	   					{	
	   						if (LETRAS_ERRADAS[k]==letra_usuario)
	   							{
	   								LETRA_REPETIDA=letra_usuario;		 	
	   							}
	   										   
	  					 } 
					
					COMPLETOU=1;
					for(j=33-contP;j<33;j++)
					{
						ESCREVEU=1;
						
						//ESCREVER LETRA	
						if((PALAVRA[NUMERO_PALAVRA-1][i]==letra_usuario) && (ESCREVEU))
						{
						ESCREVEU=0;
						
						gotoxy(32-POSICAO_PALAVRA+i+i,22);
						printf("%c ",PALAVRA[NUMERO_PALAVRA-1][i]);
						//ACERTOU
						ACERTAR=1;
						}
						
						//ESCREVER "_"
						if((PALAVRA[NUMERO_PALAVRA-1][i]!=letra_usuario) && (ESCREVEU==0))
						{
					//	gotoxy(32-POSICAO_PALAVRA+i+i,22);
						printf("_ ");
						//COMPLETOU OS ESPACOS
						COMPLETAR=1;
						}
						
						if (COMPLETOU==1)
						{
						if(COMPLETAR==0)
						{
							ACERTOS++;	 
							COMPLETOU++;
						}
					   }
						int o;	
						for(o=0;PALAVRA[NUMERO_PALAVRA-1][o]!='\0';o++)
	    				{
	    				LETRAS++;		
	    				}
						
						
					}									
	    		}						
	    	}
	
	   
	   
	   if ((ACERTOU=='F')&&(LETRA_REPETIDA!=letra_usuario))
	   { 		    		
	   				
	   	
	   					LETRAS_ERRADAS[i]=letra_usuario;
						ERROS++;
					
						textbackground(RED);
						gotoxy(26+ERROS+ERROS,14); printf("%c",letra_usuario);
						textbackground(BLUE);
					
					switch (ERROS)
 					 {
 					  case 1 :
 					       cabeca();
  						   break;
 					  case 2 :
  					      pescoco();
  					  break;
   					  case 3 :
      					   braco1();
    					 break;
   					  case 4 :
     					   braco2();
   					  break;					
  					  case 5 :
   					       tronco();
   					  break;
   					  case 6 :
   					       perna1();
   					  break;
   					  case 7 :
   					       perna2();
   					  break;
    
  					}
  		
 	 }
	  
	
/*	for(i=0;PALAVRA[NUMERO_PALAVRA-1][i]!='\0';i++)
	    	{
	    		if (PALAVRA[NUMERO_PALAVRA-1][i]==PALAVRA_ANALISE[NUMERO_PALAVRA-1][i]) GANHOU=1;
	 			if (PALAVRA[NUMERO_PALAVRA-1][i]!=PALAVRA_ANALISE[NUMERO_PALAVRA-1][i]) GANHOU=0;
	    	}
	  
	  
	  */
	  
	  	 
 	 gotoxy(80,25);
}

int tema()
{
	textbackground(RED);
	gotoxy(30,24);

	 switch (TEMA)
  {
     case 1 :
        printf(" OBJETO ");
     break;
 
     case 2 :
        printf(" ANIMAL ");
     break;
 
     case 3 :
         printf(" FRUTAS ");
     break;
 
     case 4 :
         printf(" PAISES ");
     break;
 
     case 5 :
         printf(" COMIDA ");
     break;
 
    
  }

	textbackground(BLUE);

}




int forca()
{
	int i;
	for(i=67;i<=75;i++)
	{
		gotoxy(i,11); printf("%c",LINHA_HORIZONTAL);
	}
	for(i=12;i<=24;i++)
	{
		gotoxy(75,i); printf("%c",LINHA_VERTICAL);	
	}
		gotoxy(75,11); printf("%c",NE);
		gotoxy(66,11); printf("%c",NO);
		gotoxy(66,12); printf("%c",LINHA_VERTICAL);
		gotoxy(65,13); printf("%c %c",LINHA_HORIZONTAL,LINHA_HORIZONTAL); 
		gotoxy(66,13); printf("%c",193);
		
}

int caps()
{
	int capslook;
	
    while (capslook)
	{
		if ((GetKeyState(VK_CAPITAL) & 0x0001) != 0) 
		{
		gotoxy(17,25); printf ("                                                ");
		capslook=0;  
		}
		else 
		{
		textcolor(YELLOW);
		gotoxy(17,25); printf ("Caps Look desligado, por favor ligue para jogar!");
		Sleep(50);
	    gotoxy(17,25); printf ("                                                ");
		gotoxy(80,25);
		 
		}
		
	}
	textcolor(WHITE);
	return 0;
}

int menu()
{
	int i,j,k,l;
	
	//Desenho dos botões
	textcolor(RED);
	l=7;
	for(k=1;k<=3;k++)
	{
		for(i=l;i<=(l+17);i++)
		{
			for(j=12;j<=22;j++)
			{	
				gotoxy(i,j);
				if ((i==l) || (j==12) || (j==22) || (i==l+17)) 
				{
				textcolor(WHITE); printf("%c",219);
			    }
				else
				{
				textcolor(RED); printf("%c",219);
			    }
			}		
		}
		l=l+25;
    }
    
    //Desenho interno dos botões
    textbackground(RED);
    textcolor(WHITE);
    gotoxy(14,14); printf("%c",219);
    gotoxy(14,15); printf("%c%c",219,219);
    gotoxy(14,16); printf("%c%c%c",219,219,219);
    gotoxy(14,17); printf("%c%c",219,219);
    gotoxy(14,18); printf("%c",219);
    
    gotoxy(40,14); printf("%c",219);
    gotoxy(40,16); printf("%c",219);
    gotoxy(40,17); printf("%c",219);
    gotoxy(40,18); printf("%c",219);
    gotoxy(40,14); printf("%c",219);
    
    gotoxy(65,16); printf("%c",219);
    gotoxy(64,15); printf("%c",219);
    gotoxy(63,14); printf("%c",219);
    gotoxy(66,15); printf("%c",219);
    gotoxy(67,14); printf("%c",219);
    gotoxy(64,17); printf("%c",219);
    gotoxy(63,18); printf("%c",219);
    gotoxy(66,17); printf("%c",219);
    gotoxy(67,18); printf("%c",219);
   
    
    //Nomes do botão
    textbackground(RED);
    textcolor(WHITE);
    gotoxy(14,20); printf("PLAY");
    gotoxy(36,20); printf("INSTRUCOES");
    gotoxy(64,20); printf("SAIR");
    
    //Nomes de baixo
	// textbackground(BLUE); textcolor(YELLOW); gotoxy(30,25); printf("BORA BAHIA MINHA PORRA"); 
    
    
   gotoxy(80,25); 
   textbackground(BLUE);
   textcolor(WHITE); 
   return(0);	
}

int desenho_dificuldade()
{
	int i;
	//Quinas
    gotoxy(PX_MENUd,PY_MENUd); printf("%c",NO); //NO
    gotoxy(PX_MENUd,PY_MENUd+ALTURA_MENUd); printf("%c",SO); //SO
    
    
	//Linhas horizontais
	for(i=PX_MENUd+1;i<=PX_MENUd+COMPRIMENTO_MENUd-1;i++)
	{
		gotoxy(i,PY_MENUd); printf("%c",LINHA_HORIZONTAL);
		gotoxy(i,PY_MENUd+ALTURA_MENUd); printf("%c",LINHA_HORIZONTAL);
    }
    
    //Linhas verticais
    gotoxy(PX_MENUd,PY_MENUd+1); printf("%c",LINHA_VERTICAL);
    gotoxy(PX_MENUd+COMPRIMENTO_MENUd,PY_MENUd+1); printf("%c",LINHA_VERTICAL);
    //Quinas
	gotoxy(PX_MENUd+COMPRIMENTO_MENUd,PY_MENUd); printf("%c",NE); //NE
	gotoxy(PX_MENUd+COMPRIMENTO_MENUd,PY_MENUd+ALTURA_MENUd); printf("%c",SE); //SE
    gotoxy(80,25);
}

int dificuldade()
{


	int c,v,i,NIVEL=1;
	textbackground(BLACK);
	  for (c=14;c<=20;c++)
	  {
	  	for(v=19;v<=61;v++)
	  	{
	  		gotoxy(v,c); printf(" ");
	  	}
	  }
	  
	gotoxy(35,15); printf("DIFICULDADE");  
	gotoxy(25,17); printf("F%ccil",160); 
	gotoxy(38,17); printf("M%cdio",130);  
	gotoxy(50,17); printf("Dif%ccil",161);   
	desenho_dificuldade();
    
	char escolhad=1,opcaod;
	  
	
	while (escolhad)
	{	
			
		opcaod=getch();
	
	//DIREITA	
	if (opcaod=='D') 
	{	
		if (escolhad!=3)		
	    {
	    NE=32;
		SE=32;
		SO=32;
		NO=32;
		LINHA_HORIZONTAL=32;
		LINHA_VERTICAL=32;
	    desenho_dificuldade();
	
	    NE=191;
		SE=217;
		SO=192;
		NO=218;
		LINHA_HORIZONTAL=196;
		LINHA_VERTICAL=179;
		PX_MENUd=PX_MENUd+13;
	    desenho_dificuldade();
		escolhad=escolhad+1;
		NIVEL=NIVEL+1;
		gotoxy(80,25);
			
		}
		else 
		{
		}	 
	}
	
	//ESQUERDA
	else if (opcaod=='A')
	{
     if (escolhad!=1)		
	    {
	    NE=32;
		SE=32;
		SO=32;
		NO=32;
		LINHA_HORIZONTAL=32;
		LINHA_VERTICAL=32;
	    desenho_dificuldade();
	    
	    NE=191;
		SE=217;
		SO=192;
		NO=218;
		LINHA_HORIZONTAL=196;
		LINHA_VERTICAL=179;
		PX_MENUd=PX_MENUd-13;
	    desenho_dificuldade();
		escolhad=escolhad-1;
		NIVEL=NIVEL-1;
		gotoxy(80,25);
		;		
		}
		
	}
	
	 else if (opcaod==ENTER)	
	 
	 {
     	if (escolhad==3)
     	{
     		
			escolhad=0;	
			PX_MENUd=PX_MENUdA;
			
     	}
	 	if (escolhad==2)
	 	{
	 				
			escolhad=0;	
			PX_MENUd=PX_MENUdA;		
	 	}
	 	if (escolhad==1);
		{	
				
			escolhad=0;	
			PX_MENUd=PX_MENUdA;		
		} 
		
      }
    	
     }
DIFICULDADE=NIVEL;	
}
int carregar()
{
	  int c,v;
	  float por;
	  
	  textbackground(BLACK);
	  for (c=14;c<=20;c++)
	  {
	  	for(v=19;v<=61;v++)
	  	{
	  		gotoxy(v,c); printf(" ");
	  	}
	  }
	  
	  
	  gotoxy(35,15);
      textcolor(WHITE);
      printf("Carregando");
      textcolor(RED);
      for(v=20;v<=60;v++)
      {
      	gotoxy(v,17);
      	printf("%c",LINHA_HORIZONTAL);
      	gotoxy(v,19);
      	printf("%c",LINHA_HORIZONTAL);
      }
      gotoxy(20,17); printf("%c",NO);
      gotoxy(20,19); printf("%c",SO);
      gotoxy(60,17); printf("%c",NE);
      gotoxy(60,19); printf("%c",SE);
      
      gotoxy(20,18); printf("%c",LINHA_VERTICAL);
      gotoxy(60,18); printf("%c",LINHA_VERTICAL);
      
      for (c=21;c<=59;c++)
      {
        textcolor(GREEN);
        Sleep(75);
        gotoxy(c,18); printf("%c",219);
        gotoxy(80,25);
      }
      
      gotoxy(35,15);
      textcolor(WHITE);
      printf("Carregado!");
      gotoxy(80,25);
      Sleep(1200);
	  textbackground(BLUE);   

}
int instrucao()
{

	int i,j;
	textcolor(WHITE);
	 //Quinas
    gotoxy(PX_MENUi,PY_MENUi); printf("%c",219); //NO
    gotoxy(PX_MENUi,PY_MENUi+ALTURA_MENUi); printf("%c",219); //SO
    
    
	//Linhas horizontais
	for(i=PX_MENUi+1;i<=PX_MENUi+COMPRIMENTO_MENUi-1;i++)
	{
		gotoxy(i,PY_MENUi); printf("%c",219);
		gotoxy(i,PY_MENUi+ALTURA_MENUi); printf("%c",219);
    }
    
    //Linhas verticais
    for(i=PY_MENUi+1;i<=PY_MENUi+ALTURA_MENUi-1;i++)
    {
        gotoxy(PX_MENUi,i); printf("%c",219);
		gotoxy(PX_MENUi+COMPRIMENTO_MENUi,i); printf("%c",219);	
    }
    
    //Quinas
	gotoxy(PX_MENUi+COMPRIMENTO_MENUi,PY_MENUi); printf("%c",219); //NE
	gotoxy(PX_MENUi+COMPRIMENTO_MENUi,PY_MENU+ALTURA_MENUi); printf("%c",219); //SE
    gotoxy(80,25);
	
	//ESTRELAS
	
	gotoxy(1,12); printf("        /\\        ");
	gotoxy(1,13); printf("       /  \\       ");
	gotoxy(1,14); printf(" _____/    \\______");
	gotoxy(1,15); printf(" \\_             _/");
	gotoxy(1,16); printf("   \\_         _/  ");
	gotoxy(1,17); printf("     \\       /    ");
	gotoxy(1,18); printf("     /   _   \\    ");
	gotoxy(1,19); printf("    /  _/ \\_  \\   ");
	gotoxy(1,20); printf("   / _/     \\_ \\  ");
	gotoxy(1,21); printf("  /_/         \\_\\ ");	
	
	gotoxy(61,12); printf("        /\\        ");
	gotoxy(61,13); printf("       /  \\       ");
	gotoxy(61,14); printf(" _____/    \\______");
	gotoxy(61,15); printf(" \\_             _/");
	gotoxy(61,16); printf("   \\_         _/  ");
	gotoxy(61,17); printf("     \\       /    ");
	gotoxy(61,18); printf("     /   _   \\    ");
	gotoxy(61,19); printf("    /  _/ \\_  \\   ");
	gotoxy(61,20); printf("   / _/     \\_ \\  ");
	gotoxy(61,21); printf("  /_/         \\_\\ ");
	
	textbackground(RED);
	for(j=21;j<=59;j++)
    {
    	for(i=12;i<=22;i++)
    	{
    		gotoxy(j,i); printf(" ");	
    	}
    }
    
    
    gotoxy(35,13); printf("INSTRU%cOES",128);
    
    gotoxy(22,16); printf("O objetivo deste jogo %c descobrir uma",130); 
    gotoxy(22,17); printf("palavra adivinhando as letras que ela "); 
    gotoxy(22,18); printf("possui mas voc%c s%c tem algumas chances",136,162); 
    gotoxy(22,19); printf("at%c que voc%c seja enforcado. Bom jogo!",130,136); 
    gotoxy(39,22); printf("By: Mauricio Taffarel");
    
    
    textbackground(BLUE);
 	
 	
	//SOMOS A TURMA TRICOLOR
	Beep(MI,550);Sleep(0);
	Beep(MI,400);Sleep(0);
	Beep(MI,200);Sleep(0);
	Beep(MI,200);Sleep(0);
	Beep(MI,175);Sleep(0);
	Beep(SOL,200);Sleep(0);
	Beep(MI,150);Sleep(0);
	Beep(RE,1500);Sleep(0);
	
	//SOMOS A VOZ DO CAMPEAO
	Beep(FA,550);Sleep(0);
	Beep(FA,400);Sleep(0);
	Beep(FA,200);Sleep(0);
	Beep(FA,200);Sleep(0);
	Beep(FA,175);Sleep(0);
	Beep(SOL,200);Sleep(0);
	Beep(FA,150);Sleep(0);
	Beep(MI,1500);Sleep(0);
	
	//SOMOS DO POVO O CLAMOR
	Beep(DOm,550);Sleep(0);
	Beep(DOm,400);Sleep(0);
	Beep(DOm,200);Sleep(0);
	Beep(DOm,200);Sleep(0);
	Beep(DOm,175);Sleep(0);
	Beep(REm,200);Sleep(0);
	Beep(DOm,150);Sleep(0);
	Beep(SI,1500);Sleep(0);
	
	//NINGUEM NOS VENCE EM VIBRACÃO
	Beep(LA,550);Sleep(0);
	Beep(LA,400);Sleep(0);
	Beep(LA,200);Sleep(0);
	Beep(LA,200);Sleep(0);
	Beep(DOm,200);Sleep(0);
	Beep(SI,150);Sleep(0);
	Beep(LA,150);Sleep(0);
	Beep(SOL,1500);Sleep(0);
	
	//VAMOS AVANTE ESQUADRAO
	Beep(MI,550);Sleep(0);
	Beep(MI,400);Sleep(0);
	Beep(MI,200);Sleep(0);
	Beep(MI,200);Sleep(0);
	Beep(MI,175);Sleep(0);
	Beep(SOL,200);Sleep(0);
	Beep(MI,150);Sleep(0);
	Beep(RE,1500);Sleep(0);
	
	//VAMOS SERAS UM VENCEDOR
	Beep(LA,550);Sleep(0);
	Beep(LA,400);Sleep(0);
	Beep(LA,200);Sleep(0);
	Beep(LA,200);Sleep(0);
	Beep(DOm,200);Sleep(0);
	Beep(SI,150);Sleep(0);
	Beep(LA,150);Sleep(0);
	Beep(SOLsus,1500);Sleep(0); 
	
	//VAMOS CONQUISTAR ESSE TENTO
	Beep(LA,550);Sleep(0);
	Beep(LA,400);Sleep(0);
	Beep(SI,200);Sleep(0);
	Beep(DOm,150);Sleep(0);
	Beep(DOm,150);Sleep(0);
	Beep(SI,200);Sleep(0);
	Beep(LA,250);Sleep(0);
	Beep(DOm,450);Sleep(0);	
	Beep(SOL,1200);Sleep(0); 
	
	//BAHIA,BAHIA,BAHIA
	Beep(SI,300);Sleep(0);
	Beep(REm,230);Sleep(0);
	Beep(SOL,450);Sleep(100);
	Beep(SI,300);Sleep(0);
	Beep(REm,230);Sleep(0);
	Beep(SOL,450);Sleep(100);
	Beep(SI,300);Sleep(0);
	Beep(REm,230);Sleep(0);
	Beep(SOL,1000);Sleep(300);

	
	//OUVE ESSA VOZ QUE É SEU ALENTO
	Beep(LA,550);Sleep(0);
	Beep(LA,400);Sleep(0);
	Beep(SI,200);Sleep(0);
	Beep(DOm,150);Sleep(0);
	Beep(DOm,150);Sleep(0);
	Beep(SI,200);Sleep(0);
	Beep(LA,250);Sleep(0);
	Beep(DOm,450);Sleep(0);	
	Beep(SOL,1200);Sleep(300);
	
	//BAHIA,BAHIA,BAHIA
	Beep(SI,300);Sleep(0);
	Beep(REm,230);Sleep(0);
	Beep(SOL,450);Sleep(100);
	Beep(SI,300);Sleep(0);
	Beep(REm,230);Sleep(0);
	Beep(SOL,450);Sleep(100);
	Beep(SI,300);Sleep(0);
	Beep(REm,230);Sleep(0);
	Beep(SOL,1000);Sleep(300);   
	
	//Mais um, mais um Bahia
	Beep(SOL,400);Sleep(0);
	Beep(RE,500);Sleep(300);
	Beep(LA,300);Sleep(0);
	Beep(SOL,300);Sleep(100);
	Beep(MI,250);Sleep(0);
	Beep(SOL,150);Sleep(0);
	Beep(SOL,150);Sleep(600);
	
	
	//Mais um mais um título de glória
	Beep(SI,400);Sleep(0);
	Beep(REm,550);Sleep(300);
	Beep(REm,250);Sleep(0);
	Beep(DOm,250);Sleep(0);
	Beep(SI,250);Sleep(0);
	Beep(LA,250);Sleep(0);
	Beep(SOL,250);Sleep(0);
	Beep(MI,300);Sleep(100);
	Beep(LA,800);Sleep(50);
	Beep(SOL,500);Sleep(300);	
	
	//Mais um, mais um Bahia
	Beep(SOL,400);Sleep(0);
	Beep(RE,500);Sleep(300);
	Beep(LA,300);Sleep(0);
	Beep(SOL,300);Sleep(100);
	Beep(MI,250);Sleep(0);
	Beep(SOL,150);Sleep(0);
	Beep(SOL,150);Sleep(600);   
	
	//É assim que se resume a sua história.
	Beep(SOL,400);Sleep(0);
	Beep(SOL,400);Sleep(0);
	Beep(LA,400);Sleep(0);
	Beep(LA,400);Sleep(0);
	Beep(LA,400);Sleep(0);
	Beep(LA,400);Sleep(0);
	Beep(SI,400);Sleep(0);
	Beep(SI,400);Sleep(0);
	Beep(LA,400);Sleep(0);
	Beep(SOL,400);Sleep(0);
	Beep(DOm,1400);Sleep(0);
	Beep(DOm,800);Sleep(0);
	
	
	gotoxy(80,25);
	getch();
}

int quadradoselecao_menu()
{
	int i;
	char SELECAO_MENU='v';
 
	 //Quinas
    gotoxy(PX_MENU,PY_MENU); printf("%c",NO); //NO
    gotoxy(PX_MENU,PY_MENU+ALTURA_MENU); printf("%c",SO); //SO
    
    
	//Linhas horizontais
	for(i=PX_MENU+1;i<=PX_MENU+COMPRIMENTO_MENU-1;i++)
	{
		gotoxy(i,PY_MENU); printf("%c",LINHA_HORIZONTAL);
		gotoxy(i,PY_MENU+ALTURA_MENU); printf("%c",LINHA_HORIZONTAL);
    }
    
    //Linhas verticais
    for(i=PY_MENU+1;i<=PY_MENU+ALTURA_MENU-1;i++)
    {
        gotoxy(PX_MENU,i); printf("%c",LINHA_VERTICAL);
		gotoxy(PX_MENU+COMPRIMENTO_MENU,i); printf("%c",LINHA_VERTICAL);	
    }
    
    //Quinas
	gotoxy(PX_MENU+COMPRIMENTO_MENU,PY_MENU); printf("%c",NE); //NE
	gotoxy(PX_MENU+COMPRIMENTO_MENU,PY_MENU+ALTURA_MENU); printf("%c",SE); //SE
    gotoxy(80,25);
  
}

int movimentoquadrado_menu()
{
	 char escolha=1,opcao;
	  
	
	while (escolha)
	{	
			
		opcao=getch();
	
	//DIREITA	
	if (opcao=='D') 
	{	
		if (escolha!=3)		
	    {
	    NE=32;
		SE=32;
		SO=32;
		NO=32;
		LINHA_HORIZONTAL=32;
		LINHA_VERTICAL=32;
	    quadradoselecao_menu();
	
	    NE=191;
		SE=217;
		SO=192;
		NO=218;
		LINHA_HORIZONTAL=196;
		LINHA_VERTICAL=179;
		PX_MENU=PX_MENU+25;
	    quadradoselecao_menu();
		escolha=escolha+1;
		gotoxy(80,25);
			
		}
		else 
		{
		}	 
	}
	
	//ESQUERDA
	else if (opcao=='A')
	{
     if (escolha!=1)		
	    {
	    NE=32;
		SE=32;
		SO=32;
		NO=32;
		LINHA_HORIZONTAL=32;
		LINHA_VERTICAL=32;
	    quadradoselecao_menu();
	    
	    NE=191;
		SE=217;
		SO=192;
		NO=218;
		LINHA_HORIZONTAL=196;
		LINHA_VERTICAL=179;
		PX_MENU=PX_MENU-25;
	    quadradoselecao_menu();
		escolha=escolha-1;
		gotoxy(80,25);
		;		
		}
		
	}
	
	 else if (opcao==ENTER)	
	 
	 {
     	if (escolha==3)
     	{
     		exit(0);
     	}
	 	if (escolha==2)
	 	{
	 		cabecalho();
			instrucao();
			laco_menu=1;
			PX_MENU=PX_MENUA;
		
		//	cabecalho();
		//	menu();   
		//	quadradoselecao_menu();
		//	movimentoquadrado_menu();	
				
	 	}
	 	if (escolha==1);
		{	
		
			menuW=0;		
			dificuldade();
			srand( (unsigned)time(NULL) );
			TEMA=((rand()%5)+1);			
			NUMERO_PALAVRA=(TEMA*3+DIFICULDADE-3);		
	    //	carregar();
	    	cabecalho();	     
	 		textbackground(BLUE);
			escolha=0;
			laco_menu=0;
				
		} 
		
      }
    
     }
	
} 

int main(void)
{
		
	
	laco_menu=1;
 	TEMA=1;
 	ACERTOS=0;
	ERROS=0;
 	GANHOU=0;
 	LETRAS=0;
 	
	while(laco_menu)
	{
	//MENU
	
	cabecalho();
	menu();
	caps();
	quadradoselecao_menu();
	movimentoquadrado_menu();
    }
    
	//DESENHO DO JOGO
	forca();
	tema();
	contagem();
	desenho_palavra();
	quadroletras_usadas();
	
	//JOGO
	do
	{	
		letra_usuario=getch();
		analise_letra();
		
		if((ERROS==7)||(contP==ACERTOS)) laco_jogo=0;
		if(ACERTOS==contP) laco_jogo=0;
				
	}
	while(laco_jogo);
	
	//FIM DE JOGO
	system("CLS");
	cabecalho();
	int alt=15, comp=23 ;
	
	gotoxy(comp,alt);   printf(" __        __  __      __  __  __  ");
	gotoxy(comp,alt+1); printf("|_ ||\\/|  |  \\|_     |/  \\/ _ /  \\ ");	
	gotoxy(comp,alt+2); printf("|  ||  |  |__/|__  __)\\__/\\__)\\__/ ");
	gotoxy(80,25);
	Sleep(3000); 	
   
	
}

