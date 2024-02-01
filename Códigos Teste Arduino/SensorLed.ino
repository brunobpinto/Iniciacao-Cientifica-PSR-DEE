int LED = 13;
int SENSOR = A1;

void setup() {
  // Setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
}

void loop() {
  // Main code here, to run repeatedly:
  if (digitalRead(SENSOR) == LOW) {
    digitalWrite(LED, LOW);
  }
  else {
    digitalWrite(LED, HIGH);
  }
}