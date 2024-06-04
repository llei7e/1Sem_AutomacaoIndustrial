#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2);

int btVerde = 34;
int btVermelho = 35;
int btAmarelo = 32;
int btAzul = 33;

String msg = "";
String newMsg = "ola";
String msg2 = "";
String newMsg2 = "ola";

int cont = 0;
int contAct = 0;
int contador = 0;
int entrada = 0;
int timer = 0;
int valor = 0;
int zeraSeg = 0;

int tempo1 = 0;
int tempo2 = 0;
int seg1 = 0;
int seg2 = 0;
int minuto1 = 0;
int minuto2 = 0;
int hora1 = 0;
int hora2 = 0;

bool estadobtAzul = 0;
bool estadobtAmarelo = 0;
bool estadobtVerde = 0;
bool estadobtVermelho = 0;

void setup(){
  for(int i = 32; i<=34; i++){
    pinMode(i,OUTPUT);
  }

  LCD.init();
  LCD.backlight();
  Serial.begin(115200);
  escrever(3,0,"Bem Vindo!");
  delay(1000);
}




void loop(){
  setEstadoBt();

  if(entrada == 0){
  confereBtMenu(estadobtAzul, estadobtAmarelo);
  delay(120);
  mostrarMenu(cont);
  }

  if(estadobtVerde == 1){
    entrada = 1;
  }

  if(entrada == 1){
    confereBtMsg(msg,estadobtVerde);
    mostrarAct(contAct, estadobtAzul, estadobtVerde, estadobtAmarelo);
  }

  if(estadobtVermelho == 1){
    entrada = 0;
  }

  Serial.println(valor);
}






void escrever(int col, int lin, String msg){
  LCD.clear();
  LCD.setCursor(col, lin);
  LCD.print(msg);
}


void setEstadoBt(){
  estadobtAzul = digitalRead(btAzul);
  estadobtAmarelo = digitalRead(btAmarelo);
  estadobtVerde = digitalRead(btVerde);
  estadobtVermelho = digitalRead(btVermelho);
}


void confereBtMenu(int estadobtAzul, int estadobtAmarelo){
  if(estadobtAzul == 1){
    if(cont == 2){
        cont = 0;
        delay(100);
    }else 
    cont++;
    delay(100);
  }
  if(estadobtAmarelo == 1){
    if(cont == 0){
        cont = 2;
        delay(100);
    }else 
    cont--;
    delay(100);
  }
}


void mostrarMenu(int cont){
  if(cont == 0){
    msg = "1.Contar ao Clicar";
    if(msg == newMsg){}
    else{
    escrever(0,0, msg);
    LCD.setCursor(0,1);
    LCD.print("ar");
    newMsg = msg;
    }
  }
  if(cont == 1){
    msg = "2. Relogio";
    if(msg == newMsg){}
    else{
    escrever(0,0, msg);
    newMsg = msg;
    }
  }
  if(cont == 2){
    msg = "3. Zerar Dados";
    if(msg == newMsg){}
    else{
    escrever(0,0, msg);
    newMsg = msg;
    }
  }
}


void confereBtMsg(String msg, int estadobtVerde){
  if(estadobtVerde == 1){
    if(msg == "1.Contar ao Clicar"){
      contAct = 1;
      delay(100);
    }
    if(msg == "2. Relogio"){
      contAct = 2;
      delay(100);
    }
    if(msg == "3. Zerar Dados"){
      contAct = 3;
      delay(100);
    }
  }
}


void mostrarAct(int contAct, int estadobtAzul, int estadobtVerde, int estadobtAmarelo){
    if(contAct == 1){
      if(estadobtAzul == 1){
        contador++;
        delay(120);
      }
      LCD.setCursor(0,1);
      LCD.print("Clicks: ");
      LCD.print(contador);
        
      msg = "Contar ao Clicar";
      if(msg == newMsg){}
      else{
      escrever(0,0, msg);
      newMsg = msg;
      }

      if(estadobtAmarelo == 1){
        contador = 0;
        escrever(0,0, msg);
      }
    }

    if(contAct == 2){
      if(valor == 0){
        setTempo();
        printTempo();
        msg = "Relogio";
        if(msg == newMsg){}
        else{
        escrever(0,0, msg);
        newMsg = msg;
        }
      }

      if(estadobtAzul == 1){
        valor = 1;
      }

      if(valor == 1){
        if(zeraSeg == 0){
        tempo1 = 0;
        tempo2 = 0;
        zeraSeg++;}
        if(tempo1 == 5){
          tempo1 = 0;
          tempo2++;
          }
          if(tempo2 == 3){
            tempo2 = 0;
            tempo1 = 0;
            seg1++;
          }
          if(seg1 == 9){
            seg1 = 0;
            seg2++;
          }
          if(seg2 == 6){
            seg2 = 0;
            minuto1++;
          }
          if(minuto1 == 9){
            minuto1 = 0;
            minuto2++;
          }
          if(minuto2 == 6){
            minuto2 = 0;
            hora1++;
          }
          if(hora1 == 9){
            hora1 = 0;
            hora2++;
          }
          printTempo();

          if(estadobtAmarelo == 1){
            valor = 0;
            zeraSeg = 0;
          }
        }
        tempo1++;
    }

    if (contAct == 3){
      msg = "Deseja zerar";
      msg2 = "todos os dados?";

      if(msg == newMsg && msg2 == newMsg2){}
      else{
      escrever(0,0, msg);
      LCD.setCursor(0,1);
      LCD.print("todos os dados?");
      newMsg = msg;
      newMsg2 = msg2;
      }
      if(estadobtVerde == 1){
        timer++;
        if(timer == 3000){
        tempo1 = 0;
        tempo2 = 0;
        seg1 = 0;
        seg2 = 0;
        minuto1 = 0;
        minuto2 = 0;

        contador = 0;
        entrada = 0;
        escrever(1,0,"Dados Zerados!");
        delay(1000);
        }
      }
    }
  }


void setTempo(){
  if(tempo1 == 8){
    tempo1 = 0;
    tempo2++;
  }
  if(tempo2 == 5){
    tempo2 = 0;
    seg1++;
  }
  if(seg1 == 9){
    seg1 = 0;
    seg2++;
  }
  if(seg2 == 6){
    seg2 = 0;
    minuto1++;
  }
  if(minuto1 == 9){
    minuto1 = 0;
    minuto2++;
  }
  if(minuto2 == 6){
    minuto2 = 0;
    hora1++;
  }
  if(hora1 == 9){
    hora1 = 0;
    hora2++;
  }
}


void printTempo(){
  LCD.setCursor(0,1);
  LCD.print(hora2);
  LCD.print(hora1);
  LCD.print(":");
  LCD.print(minuto2);
  LCD.print(minuto1);
  LCD.print(":");
  LCD.print(seg2);
  LCD.print(seg1);
}