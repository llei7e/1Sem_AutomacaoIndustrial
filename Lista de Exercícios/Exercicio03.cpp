int red = 3;
int yellow = 4;
int green = 5;

String opcao = "";


void setup () {
    Serial.begin(9600);
    
    for(int i = 3; i<=5; i++){
        pinMode(i,OUTPUT);
    }

}

void loop () {

    if(Serial.available() > 0){
        opcao = Serial.readString();

     if (opcao == "r" || opcao == "R"){
           digitalWrite(green, 0);
           digitalWrite(yellow,0);
           digitalWrite(red,1);
           Serial.println("Led Vermelho Ligado");
        }else if (opcao == "y" || opcao == "Y"){
            digitalWrite(green, 0);
            digitalWrite(red,0);
            digitalWrite(yellow,1);
            Serial.println("Led Amarelo Ligado");
        }else if(opcao == "g" || opcao == "G"){
            digitalWrite(yellow, 0);
            digitalWrite(red,0);
            digitalWrite(green,1);
            Serial.println("Led Verde Ligado");
        }else
        Serial.println("Opcao Indesejada");
    }  
    
}