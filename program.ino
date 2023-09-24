const int trigPin = 6;
const int echoPin = 7;
const int LEDlampRed = 9;
const int LEDlampYellow = 10;
const int LEDlampGreen = 11;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDlampRed, OUTPUT);
  pinMode(LEDlampYellow, OUTPUT);
  pinMode(LEDlampGreen, OUTPUT);
}

void loop() {
  long duration_in_digit, distance_in_cm;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration_in_digit = pulseIn(echoPin, HIGH); // in microseconds

  Serial.println(duration_in_digit);

  distance_in_cm = (duration_in_digit * 0.034) / 2;  // Speed of sound wave divided by 2 (go and back)

  if (distance_in_cm > 50) {
    digitalWrite(LEDlampGreen, LOW);
    digitalWrite(LEDlampYellow, LOW);
    digitalWrite(LEDlampRed, LOW);
  } else if (distance_in_cm <= 50 && distance_in_cm > 20) {
    digitalWrite(LEDlampGreen, HIGH);
    digitalWrite(LEDlampYellow, LOW);
    digitalWrite(LEDlampRed, LOW);
  } else if (distance_in_cm <= 20 && distance_in_cm > 5) {
    digitalWrite(LEDlampYellow, HIGH);
    digitalWrite(LEDlampGreen, HIGH);
    digitalWrite(LEDlampRed, LOW);
  } else if (distance_in_cm <= 0) {
    digitalWrite(LEDlampGreen, LOW);
    digitalWrite(LEDlampYellow, HIGH);
    digitalWrite(LEDlampRed, LOW);
  } else {
    digitalWrite(LEDlampGreen, HIGH);
    digitalWrite(LEDlampYellow, HIGH);
    digitalWrite(LEDlampRed, HIGH);
    delay(100);
    digitalWrite(LEDlampRed, LOW);
  }

  Serial.print(distance_in_cm);
  Serial.println(" cm");

  delay(300);
}