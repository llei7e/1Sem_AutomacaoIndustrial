int vermelho = 3;
int amarelo = 4;
int verde = 5;
float tempo = 5000;


void setup (){
    for(int i = 3; i<=5; i++){
        pinMode(i,OUTPUT);
    }
}

void loop(){
     tempo = 5000;
  	ligaLeds(vermelho,1);
    ligaLeds(amarelo,1);
    ligaLeds(verde,1);
  	
  	for(int i = 0; tempo > 5;i++){
        ligaLeds(vermelho,0.80);
        ligaLeds(amarelo,0.80);
        ligaLeds(verde,0.80);
        tempo = tempo*0.80;
    }
}

void ligaLeds(int cor, int multiplicador){
        digitalWrite(cor,1);
        delay(tempo);
        digitalWrite(cor,0);
}