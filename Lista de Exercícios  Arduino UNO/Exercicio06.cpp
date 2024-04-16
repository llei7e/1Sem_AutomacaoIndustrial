int entrada = A0;

void setup () {
    Serial.begin(9600);
    
    pinMode(entrada, INPUT);
}

void loop () {
    int valor = analogRead(entrada);

    Serial.println(valor);
}