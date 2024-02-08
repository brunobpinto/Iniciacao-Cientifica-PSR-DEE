int moduloRele = 41;
void setup() {
  // put your setup code here, to run once:
  pinMode(moduloRele,OUTPUT); // Modulo Rele definido como pin do tipo OUTPUT. Ele é quem vai receber o sinal
  digitalWrite(moduloRele, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(moduloRele, LOW);
}
