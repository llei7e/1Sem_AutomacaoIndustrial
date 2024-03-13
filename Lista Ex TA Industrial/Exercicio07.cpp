int led = 4;

int botao = 6;
int pressBotao = 0;

void setup(){
    pinMode(led,OUTPUT);
    pinMode(botao,INPUT);

}

void loop(){
    bool estadoBotao = digitalRead(botao);

    if(estadoBotao == 1){
        pressBotao++;
    }
        switch(pressBotao){

            case 1:
            piscaLed();
            break;

            case 2:
            piscaLed2();
            break;

            case 5:
            piscaLed3();
            break;
        }
}

void piscaLed (){
        digitalWrite(led, 1);
        delay(1000/2);
        digitalWrite(led,0);
        delay(1000);
   
}

void piscaLed2() {
        digitalWrite(led, 1);
        delay(1000/3);
        digitalWrite(led,0);
        delay(1000/3);
        digitalWrite(led, 1);
        delay(1000/3);
        digitalWrite(led,0);
   }

void piscaLed3() {
        digitalWrite(led, 1);
        delay(1000/9);
        digitalWrite(led,0);
        delay(1000/9);
        digitalWrite(led, 1);
        delay(1000/9);
        digitalWrite(led,0);
        delay(1000/9);
        digitalWrite(led, 1);
        delay(1000/9);
        digitalWrite(led,0);
        delay(1000/9);
        digitalWrite(led, 1);
        delay(1000/9);
        digitalWrite(led,0);
        delay(1000/9);
        digitalWrite(led, 1);
        delay(1000/9);
        digitalWrite(led,0);
}