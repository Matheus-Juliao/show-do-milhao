#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

//Prot�tipo da fun��o
void introducao();
char perguntas(char resposta, int vidas, float premio, int pergunta, char *simMinusculo, char *simMaiusculo, int ajuda);
void informacaoAjudaUniversitario(int ajuda);
int atualizaAjuda(char resposta, char *simMinusculo, char *simMaiusculo, int vidas, int ajuda);
char ajudaDosUniversitarios(char *respostasMaiusculas, int pergunta, char resposta, char *simMinusculo, char *simMaiusculo, int vidas, int ajuda);
void piscaTela(char resposta, char *respostasMinusculas, char *respostasMaiusculas, int pergunta, int vidas);
int compararResposta(char resposta, char *respostasMinusculas, char *respostasMaiusculas, int pergunta, int vidas);
float somaPremio(float premio, char resposta, int pergunta, int vidas, char *respostasMinusculas, char *respostasMaiusculas);
int atualizaVidas(int vidas,int pergunta, char resposta, char *respostasMaiusculas, char *respostasMinusculas);
void fimDeJogo(int vidas, int pergunta, float premio);
void perguntasFacieis(int pergunta);
void perguntasMedias (int pergunta);
void perguntasDificieis (int pergunta);

int main() {
	
	int vidas = 3, pergunta = 0, ajuda = 2;
	float premio = 1000; 
	char resposta;
	char simMinusculo[4] = "sim";
	char simMaiusculo[4] = "SIM";  
								   //1   2   3   4   5   6   7   8   9  10   1   2   3   4   5   6   7   8   9  10   1   2   3   4   5   6   7   8   9  10 */ 
	char respostasMinusculas[30] = {'d','a','e','c','c','a','b','e','b','c','c','a','e','b','c','a','c','b','d','c','b','a','c','d','c','b','b','a','b','d'};
	char respostasMaiusculas[30] = {'D','A','E','C','C','A','B','E','B','C','C','A','E','B','C','A','C','B','D','C','B','A','C','D','C','B','B','A','B','D'};
	
	setlocale(LC_ALL, "Portuguese");
    introducao();
	
	while(vidas > 0 && pergunta < 30) {	
		resposta = perguntas(resposta, vidas, premio, pergunta, simMinusculo, simMaiusculo, ajuda);
		ajuda = atualizaAjuda(resposta, simMinusculo, simMaiusculo, vidas, ajuda);
		resposta = ajudaDosUniversitarios(respostasMaiusculas, pergunta, resposta, simMinusculo, simMaiusculo, vidas, ajuda);
		piscaTela(resposta, respostasMinusculas, respostasMaiusculas, pergunta, vidas);
		pergunta = compararResposta(resposta, respostasMinusculas, respostasMaiusculas, pergunta, vidas);
		premio = somaPremio(premio, resposta, pergunta, vidas, respostasMinusculas, respostasMaiusculas);
		vidas = atualizaVidas(vidas, pergunta, resposta, respostasMaiusculas, respostasMinusculas);
		fimDeJogo(vidas, pergunta, premio);		
	}
	return 0;
}

void introducao() {
	cout << "" << endl; 
	system("color 06");
	cout << "			 ## ##    ##  ##   ## ##   ##   ##            ## ##    ## ##             ## ##    ## ##    ## ###   ## ##      ##     ## ##  " << endl;
	cout << "			##   ##   ##  ##  ##   ##  ##   ##            ##  ##  ##   ##           ##   ##   ##  ##   ##  ##  ##   ##    ####   ##   ## " << endl;
	cout << "			####      ##  ##  ##   ##  ##   ##            ##  ##  ##   ##           ##        ##  ##   ##      ##        ##  ##  ##   ## " << endl;
	cout << "			 #####    ######  ##   ##  ## # ##            ##  ##  ##   ##           ##  ###   ## ##    ## ##   ##  ###   ##  ##  ##   ## " << endl;
	cout << "			    ###   ##  ##  ##   ##  # ### #            ##  ##  ##   ##           ##   ##   ## ##    ##      ##   ##   ######  ##   ## " << endl;
	cout << "			##   ##   ##  ##  ##   ##   ## ##             ##  ##  ##   ##           ##   ##   ##  ##   ##  ##  ##   ##   ##  ##  ##   ## " << endl;
	cout << "			 ## ##    ##  ##   ## ##   ##   ##            ## ##    ## ##             ## ##    ##  ##   ## ###   ## ##    ##  ##   ## ##  " << endl << endl;
	cout << "\t\t\t\t\t\t\t\t     >> REGRAS DO JOGO <<" << endl;
	cout << "\t\t\t\t\t\t\t\t    >> VOC� TEM 3 VIDAS <<" << endl;
	cout << "\t\t\t\t\t\t      >> VOC� PODE PEDIR AJUDA AOS UNIVERSIT�RIOS 2 VEZES <<" << endl;
	cout << "\t\t\t\t\t         >> AO FINAL DO JOGO APARECER� QUANTO VOC� GANHOU EM DINHEIRO <<" << endl;
	cout << "\t\t\t\t\t\t         >> VOC� PODE GANHAR AT� 30 MIL REAIS EM DINHEIRO <<" << endl;
	cout << "\t\t\t\t\t\t\t         >> TEMA: CONHECIMENTO GERAIS <<" << endl;             
	cout << "" << endl;                                                                
	PlaySound(TEXT("abertura.wav"), NULL, SND_FILENAME);
	system("color 07");
	system("pause");
}

char perguntas(char resposta, int vidas, float premio, int pergunta, char *simMinusculo, char *simMaiusculo, int ajuda) {
	
	if(vidas > 0) {
		
		perguntasFacieis(pergunta);
		perguntasMedias(pergunta);
		perguntasDificieis(pergunta);
        printf("VALENDO R$ %.2f", premio);
		informacaoAjudaUniversitario(ajuda);
		PlaySound(TEXT("pergunta.wav"), NULL, SND_FILENAME);
		cout << "RESPOSTA: ";
		fflush(stdin);// Limpar buffer de teclado
		scanf("%c",&resposta);
		return resposta;
	}
}

void informacaoAjudaUniversitario(int ajuda) {
	if(ajuda > 1) {
		cout << "\n\nVOC� PODE PEDIR AJUDA " << ajuda << " VEZES AOS UNIVERSIT�RIOS! PARA PEDIR AJUDA DIGITE - 'SIM' " << endl << endl; 
	} else if(ajuda == 1) {
		cout << "\n\nVOC� PODE PEDIR AJUDA MAIS " << ajuda << " VEZ AOS UNIVERSIT�RIOS! PARA PEDIR AJUDA DIGITE - 'SIM' " << endl << endl; 
	} else {
		cout << "\n\nVOC� N�O PODE PEDIR MAIS AJUDA AOS UNIVERSIT�RIOS!!!" << endl << endl; 
	}
}

int atualizaAjuda(char resposta, char *simMinusculo, char *simMaiusculo, int vidas, int ajuda) {
	if((resposta == *simMinusculo || resposta == *simMaiusculo) && (vidas > 0)) {
		ajuda--;
		return ajuda;
	} else {
		return ajuda;
	}
}

char ajudaDosUniversitarios(char *respostasMaiusculas, int pergunta, char resposta, char *simMinusculo, char *simMaiusculo, int vidas, int ajuda) { 
	if(((resposta == *simMinusculo) || (resposta == *simMaiusculo)) && (vidas > 0) && ajuda >= 0) {
		cout << "\nDE ACORDO COM OS UNIVERSIT�RIOS A RESPOSTA CORRETA � A LETRA: " << respostasMaiusculas[pergunta] << endl << endl; 
		cout << "QUAL � A SUA RESPOSTA? ";
		fflush(stdin);// Limpar buffer de teclado
		scanf("%c",&resposta);
		return resposta;
	} else {
		return resposta;
	}	
}

void piscaTela(char resposta, char *respostasMinusculas, char *respostasMaiusculas, int pergunta, int vidas) {
	if((resposta == respostasMinusculas[pergunta] || resposta == respostasMaiusculas[pergunta]) && (vidas > 0)) {
		cout << "" << endl << endl;
		cout << "  	   ####   #######  ######   ######    ###               #####    #######  ####     ######   #####    #####    ######    ###	    " << endl;
		cout <<	" 	 ##  ##   ##       ##  ##  ## ## ##  ## ##              ##  ##   ##      ##   ##   ##  ##  ### ###  ##   ##  ## ## ##  ## ##	" << endl;
		cout <<	" 	##        ##       ##  ##     ##    ##   ##             ##  ##   ##      ##        ##  ##  ##   ##  ##          ##    ##   ##	" << endl;
		cout <<	" 	##        ####     #####      ##    ##   ##             #####    ####     #####    #####   ##   ##   #####      ##    ##   ##	" << endl;
		cout <<	" 	##        ##       ####       ##    #######             ####     ##           ##   ##      ##   ##       ##     ##    #######	" << endl;
		cout <<	" 	 ##  ##   ##       ## ##      ##    ##   ##             ## ##    ##      ##   ##   ##      ### ###  ##   ##     ##    ##   ##	" << endl;
		cout <<	" 	   ####   #######  ##  ##    ####   ##   ##             ##  ##   #######  #####    ##       #####    #####     ####   ##   ##	" << endl << endl;
		for(int i = 0; i < 3; i++) {
			system("color 2F");
		    //Sleep(25);	
		    system("color 0F");
		}	
		PlaySound(TEXT("resposta-certa.wav"), NULL, SND_FILENAME);
	    PlaySound(TEXT("aplausos.wav"), NULL, SND_FILENAME);
	    
	} else {
		cout << "" << endl << endl;
		cout <<	"          #####    ######    ####    #####     ####     ####    ######     ##              ######   #####    #####      ##     ####       ##	" << endl;
		cout <<	"          ##  ##   ##       ##  ##   ##  ##   ##  ##   ##  ##     ##      ####             ##       ##  ##   ##  ##    ####    ## ##     ####	" << endl;
		cout <<	"          ##  ##   ##       ##       ##  ##   ##  ##   ##         ##     ##  ##            ##       ##  ##   ##  ##   ##  ##   ##  ##   ##  ##	" << endl;
		cout <<	"          #####    ####      ####    #####    ##  ##    ####      ##     ######            ####     #####    #####    ######   ##  ##   ######	" << endl;
		cout <<	"          ####     ##           ##   ##       ##  ##       ##     ##     ##  ##            ##       ####     ####     ##  ##   ##  ##   ##  ##	" << endl;
		cout <<	"          ## ##    ##       ##  ##   ##       ##  ##   ##  ##     ##     ##  ##            ##       ## ##    ## ##    ##  ##   ## ##    ##  ##	" << endl;
		cout <<	"          ##  ##   ######    ####    ##        ####     ####      ##     ##  ##            ######   ##  ##   ##  ##   ##  ##   ####     ##  ##	" << endl << endl;
	    for(int i = 0; i < 3; i++) {
			system("color 4F");
		    //Sleep(25);	
		    system("color 0F");
		}
		PlaySound(TEXT("voce-errou.wav"), NULL, SND_FILENAME);
		PlaySound(TEXT("plateia-triste.wav"), NULL, SND_FILENAME);
	}
}

int compararResposta(char resposta, char *respostasMinusculas, char *respostasMaiusculas, int pergunta, int vidas) {
	
	if((resposta == respostasMinusculas[pergunta] || resposta == respostasMaiusculas[pergunta]) && (vidas > 0)) {
		pergunta++;
		return pergunta;	
	} else if ((resposta != respostasMinusculas[pergunta] || resposta != respostasMaiusculas[pergunta]) && (vidas > 0)){
		cout << "A resposta correta � a letra ' "<< respostasMaiusculas[pergunta] << " '" << endl << endl;
		pergunta++;
		return pergunta;		
	}
}

float somaPremio(float premio, char resposta, int pergunta, int vidas, char *respostasMinusculas, char *respostasMaiusculas) {
	pergunta--;
	if((resposta == respostasMinusculas[pergunta] || resposta == respostasMaiusculas[pergunta]) && (vidas > 0)) {
		premio = 1000 + premio;
		return premio;
	} else {
		return premio;
	}
}

int atualizaVidas(int vidas,int pergunta, char resposta, char *respostasMaiusculas, char *respostasMinusculas) {
	pergunta--;	
	if((resposta != respostasMinusculas[pergunta] && resposta != respostasMaiusculas[pergunta]) && (vidas > 0)) {
		vidas--;
		if((resposta != respostasMinusculas[pergunta] && resposta != respostasMaiusculas[pergunta]) && (vidas == 0)) {
			cout << "\n                                                        ******* SUAS VIDAS ACABARAM, FIM DE JOGO!!! *******\n\n" << endl;
			system("PAUSE");
		return vidas;
		} else {
			cout << "RESTAM " << vidas << " VIDAS!!!\n\n";
			system("PAUSE");
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			return vidas;	
		}
	} else {
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
		system("PAUSE");
		return vidas;
	}
}

void fimDeJogo(int vidas, int pergunta, float premio) {
	if(vidas <= 0 || pergunta == 30) {
		premio -= 1000; 
		if(premio > 0) {	
		cout << "\n                                                                             FIM DE JOGO!!!" << endl;
		printf("                                                                     PARAB�NS VOC� GANHOU R$ %.2f", premio);
		PlaySound(TEXT("aplausos.wav"), NULL, SND_FILENAME);
		PlaySound(TEXT("abertura.wav"), NULL, SND_FILENAME);
		} else {	
			cout << "\n                                                                         FIM DE JOGO!!!" << endl;
			cout << "                                                                    VOC� N�O GANHOU NADA!!!" << endl;
		PlaySound(TEXT("plateia-triste.wav"), NULL, SND_FILENAME);	
		PlaySound(TEXT("abertura.wav"), NULL, SND_FILENAME);	
		}
	}
}

void perguntasFacieis (int pergunta) {
	if(pergunta == 0 && pergunta <= 9) {
		cout << "" << endl;
		cout << "                                                                     ________________________ " << endl;
		cout << "                                                                    |PERGUNTAS DE NIVEL F�CIL| " << endl;
		cout << "                                                                                                  " << endl;
		cout << "\n1 - PERGUNTA" << endl << endl;
		cout << "QUAL BICHO TRANSMITE A DOEN�A DE CHAGAS?" << endl << endl;
		cout << "A - BARATA" << endl;
		cout << "B - ABELHA" << endl;
		cout << "C - PULGA" << endl;
		cout << "D - BARBEIRO" << endl;
		cout << "E - PERNILONGO" << endl << endl;
	}
	
	if(pergunta == 1 && pergunta <= 9) {
		cout << "\n2 - PERGUNTA" << endl << endl;
		cout << "O QUE � CIP�?" << endl << endl;
		cout << "A - PLANTA" << endl;
		cout << "B - COMIDA" << endl;
		cout << "C - ANIMAL" << endl;
		cout << "D - MINERAL" << endl;
		cout << "E - INSETO" << endl << endl;
	}
	
	if(pergunta == 2 && pergunta <= 9) {
		cout << "\n3 - PERGUNTA" << endl << endl;
		cout << "O QUE � VIA-L�CTEA" << endl << endl;
		cout << "A - CARRO" << endl;
		cout << "B - COMIDA" << endl;
		cout << "C - MARCA DE LEITE" << endl;
		cout << "D - CIVILIZA��O ANTIGA" << endl;
		cout << "E - GAL�XIA" << endl << endl;
	}		
	
	if(pergunta == 3 && pergunta <= 9) {
		cout << "\n4 - PERGUNTA" << endl << endl;
		cout << "QUAL � O ANIMAL QUE REPRESENTA O SIGNO DE TOURO?" << endl << endl;
		cout << "A - HIPOP�TAMO " << endl;
		cout << "B - CAVALO" << endl;
		cout << "C - TOURO" << endl;
		cout << "D - GALO" << endl;
		cout << "E - CACHORRO" << endl << endl;
    }
    
    if(pergunta == 4 && pergunta <= 9) {
		cout << "\n5 - PERGUNTA" << endl << endl;
		cout << "QUEM � A MULHER DO TARZAN?" << endl << endl;
		cout << "A - DIANA" << endl;
		cout << "B - LOUIS LAINE" << endl;
		cout << "C - JANE" << endl;
		cout << "D - CHITA " << endl;
		cout << "E - JULIA ROBERTS" << endl << endl;
	}
    
    if(pergunta == 5 && pergunta <= 9) {
		cout << "\n6 - PERGUNTA" << endl << endl;
        cout << "QUE FRUTA � RESSECADA PARA SE TORNAR UMA AMEIXA SECA?" << endl << endl;
		cout << "A - AMEIXA" << endl;
		cout << "B - UVA" << endl;
		cout << "C - PESS�GO" << endl;
		cout << "D - MEL�O" << endl;
		cout << "E - MANGA" << endl << endl;
	}
	
	if(pergunta == 6 && pergunta <= 9) {
		cout << "\n7 - PERGUNTA" << endl << endl;
		cout << "QUANTAS FOLHAS TEM UM TREVO DE SORTE?" << endl << endl;
		cout << "A - TR�S" << endl;
		cout << "B - QUATRO" << endl;
		cout << "C - CINCO" << endl;
		cout << "D - SEIS" << endl;
		cout << "E - DUAS" << endl << endl;
	}
    
    if(pergunta == 7 && pergunta <= 9) {
		cout << "\n8 - PERGUNTA" << endl << endl;
        cout << "QUAL A CAPITAL DOS ESTADOS UNIDOS?" << endl << endl;
		cout << "A - NOVA YORK" << endl;
		cout << "B - MIAMI" << endl;
		cout << "C - CHICAGO" << endl;
		cout << "D - LOS ANGELES" << endl;
		cout << "E - WASHINGTON" << endl << endl;
	}
	
	if(pergunta == 8 && pergunta <= 9) {
		cout << "\n9 - PERGUNTA" << endl << endl;
        cout << "DE ONDE AS ABELHAS EXTRAEM O MEL?" << endl << endl;
		cout << "A - DAS ROCHAS" << endl;
		cout << "B - DAS FLORES" << endl;
		cout << "C - DA TERRA" << endl;
		cout << "D - DA �GUA" << endl;
		cout << "E - DA GRAMA" << endl << endl;
	}

    if(pergunta == 9 && pergunta <= 9) {
		cout << "\n10 - PERGUNTA" << endl << endl;
        cout << "QUAL ANIMAL DA FAUNA BRASILEIRA EST� RETRATADO NA NOTA DE DEZ REAIS?" << endl << endl;
		cout << "A - JABUTI" << endl;
		cout << "B - ON�A" << endl;
		cout << "C - ARARA" << endl;
		cout << "D - JACAR�" << endl;
		cout << "E - CORUJA" << endl << endl;
	}	    
}

void perguntasMedias (int pergunta) {
	if(pergunta == 10 && pergunta <= 19) {
	    cout << "" << endl;
		cout << "                                                                        ________________________ " << endl;
		cout << "                                                                       |PERGUNTAS DE NIVEL M�DIO| " << endl;
		cout << "                                                                                                  " << endl;
		cout << "\n11 - PERGUNTA" << endl << endl;
		cout << "QUAL A CAPITAL DO CHILE?" << endl << endl;
		cout << "A - PEQUIM" << endl;
		cout << "B - MADRI" << endl;
		cout << "C - SANTIAGO" << endl;
		cout << "D - CABUL" << endl;
		cout << "E - BUENOS AIRES" << endl << endl;
	}
	
	if(pergunta == 11 && pergunta <= 19) {
		cout << "\n12 - PERGUNTA" << endl << endl;
		cout << "QUAL A PROFISS�O DOS SETE AN�ES?" << endl << endl;
		cout << "A - MINERADORES" << endl;
		cout << "B - LENHADORES" << endl;
		cout << "C - AGRICULTORES" << endl;
		cout << "D - PASTORES" << endl;
		cout << "E - PEDREIROS" << endl << endl;
	}
	
	if(pergunta == 12 && pergunta <= 19) {
		cout << "\n13 - PERGUNTA" << endl << endl;
		cout << "A QUE CONTINENTE PERTENCE O RIO AMAZONAS?" << endl << endl;
		cout << "A - OCEANIA" << endl;
		cout << "B - AFRICANO" << endl;
		cout << "C - EUROPEU" << endl;
		cout << "D - ASI�TICO" << endl;
		cout << "E - AMERICA DO SUL" << endl << endl;
	}
	
	if(pergunta == 13 && pergunta <= 19) {
		cout << "\n14 - PERGUNTA" << endl << endl;
		cout << "EM UM ANO BISSEXTO QUE M�S TEM UM DIA A MAIS?" << endl << endl;
		cout << "A - MAR�O" << endl;
		cout << "B - FEVEREIRO" << endl;
		cout << "C - ABRIL" << endl;
		cout << "D - OUTUBRO" << endl;
		cout << "E - SETEMBRO" << endl << endl;
	}
	
	if(pergunta == 14 && pergunta <= 19) {
		cout << "\n15 - PERGUNTA" << endl << endl;
		cout << "QUEM DA TURMA DA M�NICA � METIDO A CIENTISTA?" << endl << endl;
		cout << "A - CEBOLINHA" << endl;
		cout << "B - CASC�O" << endl;
		cout << "C - FRANJINHA" << endl;
		cout << "D - HOR�CIO" << endl;
		cout << "E - M�NICA" << endl << endl;
	}
	
	if(pergunta == 15 && pergunta <= 19) {
		cout << "\n16 - PERGUNTA" << endl << endl;
		cout << "QUAL ANIMAL N�O PARTICIPA DA CADEIA ALIMENTAR TERRESTRE?" << endl << endl;
		cout << "A - CARAMUJO" << endl;
		cout << "B - GAVI�O" << endl;
		cout << "C - SAPO" << endl;
		cout << "D - COBRA" << endl;
		cout << "E - LAGARTO" << endl << endl;
	}
	
	if(pergunta == 16 && pergunta <= 19) {
		cout << "\n17 - PERGUNTA" << endl << endl;
		cout << "QUAL DESSAS FRASES EST� IMPRESSA EM TODAS AS C�DULAS DO REAL?" << endl << endl;
		cout << "A - DEUS TE ACOMPANHE" << endl;
		cout << "B - O SENHOR � MEU PASTOR " << endl;
		cout << "C - DEUS SEJA LOUVADO" << endl;
		cout << "D - DEUS TE CRIE" << endl;
		cout << "E - DEUS TE ABEN��E" << endl << endl;
	}
	
	if(pergunta == 17 && pergunta <= 19) {
		cout << "\n18 - PERGUNTA" << endl << endl;
		cout << "QUAL EQUIPAMENTO SUAVIZA A QUEDA DOS CORPOS NO AR?" << endl << endl;
		cout << "A - CAPACETE" << endl;
		cout << "B - P�RA-QUEDAS" << endl;
		cout << "C - LEVITA��O" << endl;
		cout << "D - B�IA" << endl;
		cout << "E - GUARDA-CHUVA" << endl << endl;
	}
	
	if(pergunta == 18 && pergunta <= 19) {
		cout << "\n19 - PERGUNTA" << endl << endl;
		cout << "O GALO � MASCOTE DE QUAL TIME DE FUTEBOL?" << endl << endl;
		cout << "A - ATL�TICO PARANAENSE" << endl;
		cout << "B - BAHIA" << endl;
		cout << "C - FLUMINENSE" << endl;
		cout << "D - ATL�TICO MINEIRO" << endl;
		cout << "E - S�O PAULO" << endl << endl;
	}
	
	if(pergunta == 19 && pergunta <= 19) {
		cout << "\n20 - PERGUNTA" << endl << endl;
		cout << "QUAL DESSES ALIMENTOS � UM PRATO TIPICO �RABE?" << endl << endl;
		cout << "A - FEIJOADA" << endl;
		cout << "B - ACARAJ�" << endl;
		cout << "C - ESFIRRA" << endl;
		cout << "D - LASANHA" << endl;
		cout << "E - MACARRAO " << endl << endl;
	}
}

void perguntasDificieis (int pergunta) {
	if(pergunta == 20 && pergunta <= 29) {
		cout << "" << endl;
		cout << "                                                                       __________________________ " << endl;
		cout << "                                                                      |PERGUNTAS DE NIVEL DIF�CIL| " << endl;
		cout << "                                                                                                  " << endl;
		cout << "\n21 - PERGUNTA" << endl << endl;
		cout << "QUAL DESSES RIOS N�O EST� LOCALIZADO NO BRASIL?" << endl << endl;
		cout << "A - ARAGUAIA" << endl;
		cout << "B - DAN�BIO" << endl;
		cout << "C - CAPIBARIBE" << endl;
		cout << "D - PARAGUA�U" << endl;
		cout << "E - NEGRO" << endl << endl;
	}
	
	if(pergunta == 21 && pergunta <= 29) {
		cout << "\n22 - PERGUNTA" << endl << endl;
		cout << "QUANTOS TIMES DISPUTAM AS SEMIFINAIS DE UM CAMPEONATO?" << endl << endl;
		cout << "A - QUATRO" << endl;
		cout << "B - OITO" << endl;
		cout << "C - DOIS" << endl;
		cout << "D - SEIS" << endl;
		cout << "E - DEZ" << endl << endl;
	}
	
	if(pergunta == 22 && pergunta <= 29) {
		cout << "\n23 - PERGUNTA" << endl << endl;
		cout << "QUEM DIRIGE UMA ESCOLA �?" << endl << endl;
		cout << "A - THE LEADER" << endl;
		cout << "B - THE PRINCIPAL" << endl;
		cout << "C - THE DIRECTOR" << endl;
		cout << "D - THE PRODUCER" << endl;
		cout << "E - THE INSPECTOR" << endl << endl;
	}
	
	if(pergunta == 23 && pergunta <= 29) {
		cout << "\n24 - PERGUNTA" << endl << endl;
		cout << "QUAL A ORIGEM DO LE�O?" << endl << endl;
		cout << "A - AM�RICA DO NORTE" << endl;
		cout << "B - AM�RICA CENTRAL" << endl;
		cout << "C - AM�RICA DO SUL" << endl;
		cout << "D - �FRICA E �SIA" << endl;
		cout << "E - POLO NORTE" << endl << endl;
	}
	
	if(pergunta == 24 && pergunta <= 29) {
		cout << "\n25 - PERGUNTA" << endl << endl;
		cout << "QUAL A SOMA, EM RADIANOS, DOS �NGULOS INTERNOS DE UM TRI�NGULO?" << endl << endl;
		cout << "A - QUATRO PIS" << endl;
		cout << "B - MEIO PI" << endl;
		cout << "C - UM PI" << endl;
		cout << "D - DOIS PIS" << endl;
		cout << "E - SEIS PIS" << endl << endl;
	}
	
	if(pergunta == 25 && pergunta <= 29) {
		cout << "\n26 - PERGUNTA" << endl << endl;
		cout << "A OXIDA��O � O PROCESSO PELA QUAL SE FORMA A?" << endl << endl;
		cout << "A - AREIA " << endl;
		cout << "B - FERRUGEM" << endl;
		cout << "C - POEIRA" << endl;
		cout << "D - PEDRA" << endl;
		cout << "E - LIQU�DO" << endl << endl;
	}
	
	if(pergunta == 26 && pergunta <= 29) {
		cout << "\n27 - PERGUNTA" << endl << endl;
		cout << "NO BRASIL, A DEZEMBRADA FOI UM CONJUNTO DE OPERA��ES DA CAMPANHA CONTRA?" << endl << endl;
		cout << "A - COL�MBIA" << endl;
		cout << "B - PARAGUAI" << endl;
		cout << "C - ARGENTINA" << endl;
		cout << "D - CHILE" << endl;
		cout << "E - VENEZUELA" << endl << endl;
	}
	
	if(pergunta == 27 && pergunta <= 29) {
		cout << "\n28 - PERGUNTA" << endl << endl;
		cout << "QUAL FOI O �LTIMO PRESIDENTE CIVIL ANTES DO JOGO MILITAR DE 1964?" << endl << endl;
		cout << "A - JO�O GOULART" << endl;
		cout << "B - JO�O FIGUEIREDO" << endl;
		cout << "C - JO�O FRANCO" << endl;
		cout << "D - JO�O GILBERTO" << endl;
		cout << "E - JO�O PEDRO" << endl << endl;
	}
	
	if(pergunta == 28 && pergunta <= 29) {
		cout << "\n29 - PERGUNTA" << endl << endl;
		cout << "QUEM FOI O PERCURSOR DO ILUMINISMO?" << endl << endl;
		cout << "A - MOLI�RE" << endl;
		cout << "B - DESCARTES" << endl;
		cout << "C - PLAT�O" << endl;
		cout << "D - MARQU�S DE POMBAL" << endl;
		cout << "E - CRISTOV�O COLOMBO " << endl << endl;
	}
	
	if(pergunta == 29 && pergunta <= 29) {
		cout << "\n30 - PERGUNTA" << endl << endl;
		cout << "UMA PESSOA METICULOSA � MUITO?" << endl << endl;
		cout << "A - CORAJOSA" << endl;
		cout << "B - DESASTRADA" << endl;
		cout << "C - ATRAPALHADA" << endl;
		cout << "D - CUIDADOSA" << endl;
		cout << "E - RELAXADA" << endl << endl;
	}
}
