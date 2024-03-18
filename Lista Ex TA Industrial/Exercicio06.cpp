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
        pressBotao++;
    }
    switch(pressBotao){
            case 1:
            digitalWrite(verde,0);
            digitalWrite(vermelho,1);
            delay(200);
            break;
            case 2:
            digitalWrite(vermelho,0);
            digitalWrite(amarelo,1);
            delay(200);
            break;
            case 3:
            digitalWrite(amarelo,0);
            digitalWrite(verde,1);
            delay(200);
            pressBotao = 0;
            break;
           
        }
}
//terminar