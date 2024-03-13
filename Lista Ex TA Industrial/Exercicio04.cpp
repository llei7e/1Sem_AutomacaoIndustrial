int vermelho = 3;
int amarelo = 4;
int verde = 5;
float tempo = 5;


void setup (){
    for(int i = 3; i<=5; i++){
        pinMode(i,OUTPUT);
    }
}

void loop(){
     tempo = 5;
  	ligaLeds(vermelho,1);
    ligaLeds(amarelo,1);
    ligaLeds(verde,1);
  	
  	for(int i = 0; tempo < 5000;i++){
        ligaLeds(vermelho,1.15);
        ligaLeds(amarelo,1.15);
        ligaLeds(verde,1.15);
        tempo = tempo*1.15;
    }
}

void ligaLeds(int cor, int multiplicador){
        digitalWrite(cor,1);
        delay(tempo);
        digitalWrite(cor,0);
}