#include <NewPing.h>

#define TRIGGER_PIN 12
#define ECHO_PIN 13
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(115200);
}

void loop() {
  delay(50);

  int uS = sonar.ping();

  Serial.println("Ping: ");
  Serial.println(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");
}
