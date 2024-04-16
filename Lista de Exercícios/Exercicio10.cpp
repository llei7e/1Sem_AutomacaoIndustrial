int entrada = A0;
int barulho = 3;


void setup(){
    Serial.begin(9600);
    pinMode(entrada,INPUT);
    pinMode(barulho,OUTPUT);
}

void loop(){
    int res = analogRead(entrada);

    int iluminar = map(res, 1, 310, 0, 255);

    Serial.println(iluminar);

    if(iluminar > iluminar/2)
        tone(barulho,100,50);


}