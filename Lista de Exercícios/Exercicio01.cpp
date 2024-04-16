void setup () {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);

}

void loop () {
    digitalWrite(LED_BUILTIN,1);
    Serial.println("ledBuiltin: Ligado");
  	delay(500);
  	digitalWrite(LED_BUILTIN,0);
 	 Serial.println("ledBuiltin: Desligado");
  	delay(500);
}