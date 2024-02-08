#include <AFMotor.h>

AF_DCMotor motorA(2);
int sensorProximidade = 31;
int moduloRele = 41;
int status = 1;
unsigned long instanteAnterior = 0;
bool delayStatus4 = false; // Variavel booleana para detectar se o delay foi concluido ou não.

void setup() {
  // Setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorProximidade, INPUT); // Define que tipo de pino é: INPUT ou OUTPUT
  digitalRead(sensorProximidade) == LOW;
  motorA.setSpeed(255); // Valor da velocidade entre 0 e 255
  pinMode(moduloRele,OUTPUT); // Modulo Rele definido como pin do tipo OUTPUT. Ele é quem vai receber o sinal
  digitalWrite(moduloRele, HIGH);
}

void loop() {
  // Main code here, to run repeatedly:
  unsigned long instanteAtual = millis();
  int valorDigital = digitalRead(sensorProximidade);

  if (status == 1){ // Status 1: Até o sensor detectar proximidade
    motorA.run(FORWARD); // Código para ligar o motor. BACKWARD e FORWARD
    Serial.println("Motor Ligado: Esperando Sinal do Sensor");
    if (valorDigital == LOW){
      status = 2;
      instanteAnterior = instanteAtual;
    }
  }

  if (status == 2){ // Status 2: Houve mudanca no sinal de proximidade. Para o motor e espera.
    motorA.run(RELEASE); // Código para parar o motor.
    Serial.println("Motor Desligado: Objeto Perto");
    if ((instanteAtual - instanteAnterior) >= 2000){ // Esteira fica parada até o delay passar
      if (delayStatus4 == true){
        status = 4; 
        delayStatus4 = false;
        instanteAnterior = instanteAtual;
      }
      else{
        status = 3; 
        instanteAnterior = instanteAtual;
      }
    }
  }

  if (status == 3){ // Status 3: Objeto parado por 2 segundos. Hora de colocar o molho
    digitalWrite(moduloRele, LOW); // Modulo Rele conecta a alimentacao negativa da bomba de Molho. Sinal HIGH ou LOW.
    Serial.println("Bomba Molho: Ligada");
    if ((instanteAtual - instanteAnterior) >= 500){ // Esteira fica parada até o delay passar
      digitalWrite(moduloRele, HIGH); // Modulo Rele desliga a Bomba de Molho.
      status = 2; 
      instanteAnterior = instanteAtual;
      delayStatus4 = true;
    }
  }

  if (status == 4){ // Status 4: Esperando a torrada passar. O sinal mudar de LOW para HIGH
    motorA.run(FORWARD); // Código para ligar o motor. BACKWARD e FORWARD
    Serial.println("Motor Ligado: Esperando a Torrada Passar");
    if ((instanteAtual - instanteAnterior) >= 1000){ // Esteira não detecta o pão. Espera um delay ate estar no Status 1 e ficar a procura do sinal
      status = 1; 
    }
  }
  
}