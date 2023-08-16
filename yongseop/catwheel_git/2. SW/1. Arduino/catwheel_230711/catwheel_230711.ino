const int led = 12; // 모터 ON, OFF
const int LED2=11; // 모터 속도 제어
const int sw1 = 2; // 모터 ON, OFF
const int switchPin = 3; // 모터 속도 제어
boolean toggle_state = false; //

const int maxSpeed = 255;
const int speedIncrement = 25;

int speed = 0;
bool switchState = false; // sw1 눌림 상태
bool lastSwitchState = false;
bool switchState2 = false;
// switchPin 눌림 상태
bool lastSwitchState2 = false;
bool ledState = false; // led 켜짐 상태

const int enA = 10; // 모터 속도조절
const int in1 = 8; // 정, 역회전 기준1
const int in2 = 9; // 정, 역회전 기준2

void setup() {
  pinMode(sw1, INPUT_PULLUP);
  pinMode(switchPin, INPUT_PULLUP);
  analogWrite(LED2, speed);
  pinMode(led, OUTPUT);
}

void loop() {
switchState = digitalRead(sw1);

if (switchState != lastSwitchState) {
  if (switchState == LOW) {
    ledState = !ledState;
    digitalWrite(led, ledState);
  }
  lastSwitchState = switchState;
  delay(50);
}

  switchState = digitalRead(switchPin);

  if (switchState2 != lastSwitchState2) {
    if (switchState2 == LOW) {
      speed += speedIncrement;
      if (speed > maxSpeed) {
        speed = 0;
      }
      analogWrite(LED2, speed);
    }
    lastSwitchState2 = switchState2;
    delay(100);  // 디바운싱을 위한 지연 시간
  }

  digitalWrite(in1, ledState);
  digitalWrite(in2, LOW);
  analogWrite(enA, speed);
}
