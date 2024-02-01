#include <AFMotor.h>

AF_DCMotor motorA(2);
void setup() { 
  // Setup code here, to run once:
  motorA.setSpeed(255); // Valor da velocidade entre 0 e 255
  Serial.begin(9600);
}

void loop() { 
  // Main code here, to run repeatedly:
  motorA.run(FORWARD); // Código para ligar o motor. BACKWARD e FORWARD
  Serial.println("Motor Ligado");
  delay(5000); // Delay em milisegundos

  motorA.run(RELEASE); // Código para parar o motor.
  Serial.println("Motor Desligado");
  delay(5000);

}
