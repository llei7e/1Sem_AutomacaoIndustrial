int led = 3;

int botao1 = 6;
int botao2 = 4;

void setup(){
    pinMode(led, OUTPUT);

    pinMode(botao1, INPUT);
    pinMode(botao2, INPUT);
}

void loop(){
    bool estadoBotao1 = digitalRead(botao1);
    bool estadoBotao2 = digitalRead(botao2);

    if(estadoBotao1 && !estadoBotao2){
        digitalWrite(led,1);
        
    }
        digitalWrite(led,0);

    if(estadoBotao2 && !estadoBotao1) {
        digitalWrite(led,1);
        
    }
        digitalWrite(led,0);

}