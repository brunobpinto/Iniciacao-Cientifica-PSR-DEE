#include <AFMotor.h>

AF_DCMotor motorA(2);
int sensorProximidade = 31;
int status = 1;
unsigned long instanteAnterior = 0;

void setup() {
  // Setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorProximidade, INPUT); // Define que tipo de pino é: INPUT ou OUTPUT
  digitalRead(sensorProximidade) == LOW;
  motorA.setSpeed(255); // Valor da velocidade entre 0 e 255
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
    if ((instanteAtual - instanteAnterior) >= 5000){ // Esteira fica parada até o delay passar
      status = 3; 
      instanteAnterior = instanteAtual;
    }
  }

  if (status == 3){ // Status 3: Esperando a torrada passar. O sinal mudar de LOW para HIGH
    motorA.run(FORWARD); // Código para ligar o motor. BACKWARD e FORWARD
    Serial.println("Motor Ligado: Esperando a Torrada Passar");
     if (valorDigital == HIGH){ // HIGH é quando está distante. LOW é quando está perto. Se o valor for HIGH no sensor, significa que a torrada passou e agora o programa vira status 1 e fica a procura da proxima. 
      status = 1; 
    }
  }
}
