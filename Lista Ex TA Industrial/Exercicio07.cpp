int led = 4;

int botao = 6;
int pressBotao = 0;

void setup(){
    pinMode(led,OUTPUT);
    pinMode(botao,INPUT);
}

void loop(){
    bool estadoBotao = digitalRead(botao);

    if(estadoBotao == 1 ){
      pressBotao++;
    }
  	if(pressBotao > 0){  
  	piscaLed();
    }
}

void piscaLed (){
   		digitalWrite(led,0);
        delay(1000/(pressBotao*2));
        digitalWrite(led, 1);
        delay(1000/(pressBotao*2));
}