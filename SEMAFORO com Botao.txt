/*
O semáforo deve conter  as seguintes funções:

Iniciar no amarelo piscante, por 3x.

depois que iniciou, ele vai ficar em repetição.
fazendo a seguinte ordem:

Verde (5s)
Amarelo (3s)
Vermelho (5s)


*/


/*
O semáforo deve conter  as seguintes funções:

Iniciar no amarelo piscante, por 3x.

depois que iniciou, ele vai ficar em repetição.
fazendo a seguinte ordem:

Verde (5s)
Amarelo (3s)
Vermelho (5s)


*/

//Declaração das variáveis GLOBAIS
int vermelho = 3;
int amarelo = 4;
int verde = 5;
int tempo_intermitente = 1000;

int botao = 2;

int vermelhoP = 7;
int verdeP = 6;


//void setup
void setup(){
    //Determina que os pinos 3,4,5 serão saídas.
    pinMode(vermelho, OUTPUT);
    pinMode(amarelo, OUTPUT);
    pinMode(verde, OUTPUT);

    pinMode(vermelhoP, OUTPUT);
    pinMode(verdeP, OUTPUT);

    pinMode(botao, INPUT);

    controlaCor(amarelo, 1000, false);
    controlaCor(amarelo, 1000, false);
    controlaCor(amarelo, 1000, false);

}


//void loop
void loop(){
  	bool estadoBotao = false;
    estadoBotao = digitalRead(botao);
	digitalWrite(vermelhoP, 1);
  	
  	if(estadoBotao == true){
     controlaCor(vermelho, 5000, true);
     controlaVerdeP(5000);
     digitalWrite(vermelho,0);
     controlaCor(verde, 2000, true);
     controlaCor(amarelo, 3000, true);
     digitalWrite(vermelho,1);
	 controlaVerdeP(5000);
     digitalWrite(vermelho,0);
	 controlaCor(verde, 5000, true);
    }else{
     controlaCor(vermelho, 5000, true);
     controlaCor(verde, 5000, true);
    }
  
  	if(estadoBotao == true){
    controlaCor(verde, 2000, true);
    controlaCor(amarelo, 3000, true);
    digitalWrite(vermelho,1);
	controlaVerdeP(5000);
    digitalWrite(vermelho,0);
	controlaCor(verde, 5000, true);
    
    } else{
    controlaCor(verde, 5000, true);
    }
 
    controlaCor(amarelo, 3000, true);
  	digitalWrite(vermelho,1);
	controlaVerdeP(5000);
    digitalWrite(vermelho,0);
	controlaCor(verde, 5000, true);
    controlaCor(amarelo, 3000, true);
  
}




int controlaCor (int cor, int tempo, bool estaNoLoop) {
    digitalWrite(cor, 1);
    delay(tempo);
    digitalWrite(cor, 0);
    
    if(estaNoLoop == false){
        delay(tempo);
        return 0;
        //se bateu aqui, é por que a função foi chamada no setup
    }
    else{
        return 1;
        //se bateu aqui, é por que a função foi chamada no Loop
    }
}

int controlaVerdeP (int tempoLigado) {
	delay(1000);
  	digitalWrite(vermelhoP, 0);
	digitalWrite(verdeP, 1);
	delay(tempoLigado);	

	piscaVerdeP(500);
	digitalWrite(verdeP, 0);
	digitalWrite(vermelhoP, 1);
	
}

int piscaVerdeP (int tempoPisca) {
	digitalWrite(vermelhoP, 0);
	delay(tempoPisca);
	digitalWrite(vermelhoP,1);
	delay(tempoPisca);

	digitalWrite(vermelhoP, 0);
	delay(tempoPisca);
	digitalWrite(vermelhoP,1);
	delay(tempoPisca);

	digitalWrite(vermelhoP, 0);
	delay(tempoPisca);
	digitalWrite(vermelhoP,1);
	delay(tempoPisca);

	
}