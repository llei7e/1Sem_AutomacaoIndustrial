int pot = A0;
int led = 3;

void setup () {
    Serial.begin(9600);
    pinMode(led,OUTPUT);
    pinMode(pot, INPUT);
}

void loop () {
    int valor = (analogRead(pot)-3)/4;
    Serial.println(valor);
    analogWrite(led, valor);
}