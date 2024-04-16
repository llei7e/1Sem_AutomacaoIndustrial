int ledBuiltin = 11;
int valor = 0;

void setup () {
    Serial.begin(9600);
    pinMode(ledBuiltin,OUTPUT);

}

void loop () {
    analogWrite(ledBuiltin,valor);
    Serial.print("ledBuiltin: Ligado, valor: ");
    Serial.println(valor);

    valor++;
    if(valor == 255)
    valor = 0;
}