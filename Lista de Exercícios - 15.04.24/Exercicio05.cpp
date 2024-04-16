int green = 3;
int red = 4;
int yellow = 5;

int botao1 = 6;
int botao2 = 7;



void setup () {
    Serial.begin(9600);
    
    for(int i = 3; i<=5; i++){
        pinMode(i,OUTPUT);
    }

}

void loop () {
    bool estadoBotao1 = digitalRead(botao1);
    bool estadoBotao2 = digitalRead(botao2);

    if(estadoBotao1 != estadoBotao2){
        Serial.println("XOR");
        digitalWrite(red,0);
        digitalWrite(yellow,0);
        digitalWrite(green,1);
    }
    if(estadoBotao1 == 0 && estadoBotao2 == 0){
        digitalWrite(green,0);
        digitalWrite(red,0);
        digitalWrite(yellow,0);
    }
    if(estadoBotao1 == 1 && estadoBotao2 == 1){
        Serial.println("AND");
        digitalWrite(green,0);
        digitalWrite(yellow,1);
    }
    if(estadoBotao1 == 1 || estadoBotao2 == 1){
        Serial.println("OR");
        digitalWrite(green,0);
        digitalWrite(yellow,0);
        digitalWrite(red,1);
    }
}
