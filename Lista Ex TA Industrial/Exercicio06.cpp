int vermelho = 3;
int amarelo = 4;
int verde = 5;
int botao = 2;

int pressBotao = 0;

void setup(){
    for(int i = 3; i<=5;i++){
        pinMode(i,OUTPUT);
    }
}

void loop(){
    bool estadoBotao = digitalRead(botao);

    if(estadoBotao == 1 && pressBotao == 0){
        digitalWrite(verde,0);
        digitalWrite(vermelho, 1);
        pressBotao = 1;

    }else if (estadoBotao == 1 && pressBotao == 1){
        digitalWrite(vermelho,0);
        digitalWrite(amarelo,1);
        pressBotao = 2;
    }else if (estadoBotao == 1 && pressBotao == 2){
        digitalWrite(amarelo,0);
        digitalWrite(verde,1);
        pressBotao = 0;
    }

}
//terminar