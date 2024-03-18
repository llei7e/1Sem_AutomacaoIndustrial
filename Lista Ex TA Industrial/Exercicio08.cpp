int ledV = 4;
int botao = 6;

bool botaoPress = true;

void setup(){
  pinMode(ledV, OUTPUT);
  pinMode(botao, INPUT);
}

void loop(){
  
  bool estadoBotao = digitalRead(botao);
  
  if (estadoBotao && botaoPress){
	    digitalWrite(ledV,1);
        delay(2000); 
        digitalWrite(ledV,0);
        botaoPress = false;

  }else if(!estadoBotao)
    	botaoPress = true;

}