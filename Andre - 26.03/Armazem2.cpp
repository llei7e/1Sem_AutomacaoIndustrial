#define foto A0

const int ledVav[] = {9,10,11};
const int buzz = 2;

int sensor = 0;

int level = 0;
int levelLast = 0;

void setup()
{
  for (int i=0; i<3; i++){
    pinMode(ledVav[i], OUTPUT);
  }
  pinMode(buzz, OUTPUT);

  Serial.begin(9600);
}


void loop(){

  levelLast = level;
  
  sensor = analogRead(foto);
  Serial.println(sensor);

  if(sensor > 478){ 
    acender(0,0,254);
    level=1;
  } else if (sensor <= 479 && sensor > 394 ){
    acender(254,0,254);
    level=2;
  } else if (sensor <= 394 ){
    acender(254,0,0);
    level = 3;
  }

  if (levelLast != level) {
    if (level == 1){
      tone(buzz, 70, 200);
    }

    if(level == 2){
      tone(buzz, 150, 200);
    }

    if(level == 3){
      tone(buzz, 220, 200);
    }
  }
}

void acender(int vermelho, int azul, int verde){
  analogWrite(ledVav[0],vermelho);
  analogWrite(ledVav[1],azul);
  analogWrite(ledVav[2],verde);
}