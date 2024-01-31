#include <AFMotor.h>

unsigned long instanteAnterior = 0;
AF_DCMotor motorA(1);

void setup() { 
  // Setup code here, to run once:
  motorA.setSpeed(200); // Valor da velocidade entre 0 e 255
  Serial.begin(9600);
}

void loop() { 
  // Main code here, to run repeatedly:
  unsigned long instanteAtual = millis();
  if (instanteAtual > instanteAnterior + 10000) {
    motorA.run(RELEASE); // Código para parar o motor.
    Serial.println("Motor Desligado"); 
    delay(5000);
    instanteAnterior = instanteAtual;
  }

  motorA.run(FORWARD); // Código para ligar o motor. BACKWARD e FORWARD
  Serial.println("Motor Ligado"); // O Serial.println() adciona um '/n' no final pulando para uma nova linha
}
