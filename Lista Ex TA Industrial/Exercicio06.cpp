int vermelho = 3;
int amarelo = 4;
int verde = 5;
int botao = 2;

int pressBotao = 0;

void setup(){
    for(int i = 3; i<=5;i++){
        pinMode(i,OUTPUT);
    }
        pinMode(botao,INPUT);
}

void loop(){
    bool estadoBotao = digitalRead(botao);

    if(estadoBotao == 1){
        digitalWrite(verde,1);
    }

}
//terminar