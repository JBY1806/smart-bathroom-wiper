#include <DHT.h>
#include <Servo.h>
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

Servo myservo; 
int distance = 0;   //거리 변수
int pos = 0; 
int servoPin = 6;  //서보모터 핀 할당

void setup() {
  Serial.begin(9600);
  pinMode(servoPin, OUTPUT);
  myservo.attach(servoPin);
  dht.begin();
}

void loop() {
  float hum = dht.readHumidity();                     //습도값 저장
  int volt = map(analogRead(A0), 0, 1023, 0, 5000);   
  distance = (27.61 / (volt - 0.1696)) * 1000;        //거리값 저장
  if (isnan(hum) || isnan(distance)) {
    Serial.println("Failed to read from DHT sensor or distance sensor!");
    return;
  }

  Serial.print("humidity:");          
  Serial.println(hum);                  // 습도값을 시리얼 모니터에 출력
  delay(100);                       // 센서값 간격 0.1초로 설정
  Serial.print(distance);  //거리값을 시리얼 모니터에 출력
  Serial.print(" cm");
  Serial.println(" ");
  delay(100);                       // 센서값 간격 0.1초로 설정

  
  if (hum > 70 && distance < 15) {        //습도가 80이상이고 거리가 40cm미만이면 for문 동작(와이퍼 2번 왕복 운동)
    for (pos = 60; pos <= 180; pos += 1) {
      myservo.write(pos);
      delay(10);
    }
    for (pos = 180; pos >= 60; pos -= 1) {
      myservo.write(pos);
      delay(10);
    }

    for (pos = 60; pos <= 180; pos += 1) {
      myservo.write(pos);
      delay(10);
    }
    for (pos = 180; pos >= 60; pos -= 1) {
      myservo.write(pos);
      delay(10);
    }

    delay(30000);                  // 와이퍼 2번 왕복 운동 후, 5분 딜레이. 5분 후 다시 loop문으로 이동
  }
}
