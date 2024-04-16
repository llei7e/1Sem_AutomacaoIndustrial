int botao = 6;
int cont = 0;

void setup () {
    Serial.begin(9600);
    pinMode(botao,INPUT);

}

void loop () {

    bool estadoBotao = digitalRead(botao);

    if(estadoBotao == 1)
        cont++;
        delay(100);
    if(cont%2 == 0 && cont != 0)
        Serial.println("1");
    else
        Serial.println("0");
}