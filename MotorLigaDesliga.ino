#include <AFMotor.h>

AF_DCMotor motorA(1);
void setup() { 
  // Setup code here, to run once:
  motorA.setSpeed(200); // Valor da velocidade entre 0 e 255
}

void loop() { 
  // Main code here, to run repeatedly:
  motorA.run(FORWARD); // Código para ligar o motor. BACKWARD e FORWARD
  delay(10000); // Delay em milisegundos

  motorA.run(RELEASE); // Código para parar o motor.
  delay(5000);
}
