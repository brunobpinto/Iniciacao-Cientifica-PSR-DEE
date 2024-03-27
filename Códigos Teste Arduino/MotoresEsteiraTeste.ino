#include <AFMotor.h>

AF_DCMotor motorA(4);
AF_DCMotor motorB(3);

void setup() { 
  // Setup code here, to run once:
  motorA.setSpeed(255); // Valor da velocidade entre 0 e 255
  motorB.setSpeed(255);
  Serial.begin(9600);
}

void loop() { 
  // Main code here, to run repeatedly:
  //motorA.run(FORWARD); // Código para ligar o motor. BACKWARD e FORWARD
  motorB.run(FORWARD);
  Serial.println("Motores Ligados");
  delay(5000); // Delay em milisegundos

  

}
