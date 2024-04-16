int entrada = A0;

void setup(){
    Serial.begin(9600);
    pinMode(entrada,INPUT);
}

void loop(){
    int celsius = map(((analogRead(entrada) - 20) * 3.04), 0, 1023, -40, 125);

    Serial.print(celsius);
    Serial.print("º Celsius");

}