int led1 = 8;
int led2 = 9;
int sw = 2;

unsigned long previousMillis = 0;
const long interval = 1000;

bool ledState = LOW;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  pinMode(sw, INPUT_PULLUP);
}

void loop() {

  // LED1 ON/OFF every 1 seconds
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    ledState = !ledState;
    digitalWrite(led1, ledState);
  }

  // LED2 controlled by switch
  if (digitalRead(sw) == LOW) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }
}