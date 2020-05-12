#define LEDpin 6                // Пин ИК диода
#define PIN_PHOTO_SENSOR A0     // Пин фоторезистора
#define PHOTO_SENSOR_VALUE 300  // Пороговое Значение фотодатчика при срабатывании
#define DELAY_TUNER_PIN 7       // Пин подключения переменного резистора для управления задержкой
#define MIN_DELAY 100           // Минимально возможная задержка
#define MAX_DELAY 1000          // Максимально возможная задержка

void setup() {

    pinMode(LEDpin, OUTPUT); //led

}

void loop() {
    int delay_time = map(analogRead(DELAY_TUNER_PIN), 0, 1023, MIN_DELAY, MAX_DELAY);
    if (analogRead(PIN_PHOTO_SENSOR) < PHOTO_SENSOR_VALUE) {
        
        delay(delay_time);
        
        takePhoto();
        
    }

}


// Функция управления фотиком Nikon по ИК
// https://www.christidis.info/index.php/personal-projects/arduino-nikon-infrared-command-code

void takePhoto(void) {
  int i;
  for (i = 0; i < 76; i++) {
    digitalWrite(LEDpin, HIGH);
    delayMicroseconds(7);
    digitalWrite(LEDpin, LOW);
    delayMicroseconds(7);
  }
  delay(27);
  delayMicroseconds(810);
  for (i = 0; i < 16; i++) {
    digitalWrite(LEDpin, HIGH);
    delayMicroseconds(7);
    digitalWrite(LEDpin, LOW);
    delayMicroseconds(7);
  }
  delayMicroseconds(1540);
  for (i = 0; i < 16; i++) {
    digitalWrite(LEDpin, HIGH);
    delayMicroseconds(7);
    digitalWrite(LEDpin, LOW);
    delayMicroseconds(7);
  }
  delayMicroseconds(3545);
  for (i = 0; i < 16; i++) {
    digitalWrite(LEDpin, HIGH);
    delayMicroseconds(7);
    digitalWrite(LEDpin, LOW);
    delayMicroseconds(7);
  }
}
