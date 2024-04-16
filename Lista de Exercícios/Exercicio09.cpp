int entrada = A0;
int led = 3;


void setup(){
    Serial.begin(9600);
    pinMode(entrada,INPUT);
    pinMode(led,OUTPUT);
}

void loop(){
    int res = analogRead(entrada);

    int iluminar = map(res, 1, 310, 0, 255);

    analogWrite(led,iluminar);

    Serial.println(iluminar);

}