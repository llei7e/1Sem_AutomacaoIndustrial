//Definindo variáveis
int bits = 0;
int led = 3;

//void Setup
void setup(){
	pinMode(led, OUTPUT);
  
  //Monitor Serial
  Serial.begin(9600);
}

//void loop
void loop(){
	Serial.println(bits);
  	bits = analogRead(bits)/4;

  zeroCem();
  cemZero();
}
void zeroCem (){
  for(int i =0;i<255;i++){
  analogWrite(led,i);
    delay(10);
  }
}

void cemZero(){
  for(int j = 255;j>1;j--){
    analogWrite(led,j);
    delay(10);
  }
}