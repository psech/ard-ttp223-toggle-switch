uint8_t TOUCH_PIN   = 28;
uint8_t LED_PIN     = 24;

uint8_t touched   = 0;
uint8_t ledOn     = 0;
bool newTouch     = 1;

void setup() {
  Serial.begin(9600);

  pinMode(TOUCH_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  touched = digitalRead(TOUCH_PIN);

  debug_log();

  if (touched && newTouch) {
    newTouch = !newTouch;
    ledOn = !ledOn;
    digitalWrite(LED_PIN, ledOn);
  }

  if(!touched && !newTouch) {
    newTouch = !newTouch;
  }

  delay(50);
}

void debug_log() {
  Serial.print("Is Touched = ");
  Serial.println(touched);
  Serial.print("New Touch = ");
  Serial.println(newTouch);
}
