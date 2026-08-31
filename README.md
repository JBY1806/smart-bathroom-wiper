# Smart Bathroom Wiper (화장실 스마트 와이퍼)

> Arduino-based automatic mirror wiper — activates a servo motor only when humidity > 80% AND user proximity < 40cm are both met. Capstone design project (team of 3), Sep–Dec 2023.

## 개요
종합설계(3인 팀, 2023.09~12) 프로젝트 — 샤워 후 김 서린 거울을 자동으로 닦는 장치입니다. 습기 부식을 피해 회로를 거울 뒷면에 배치했고, 기존 특허 조사로 차별점을 확인한 뒤 완성품 기능 테스트로 검증했습니다.

## 동작 로직
- DHT11 습도 센서 + 적외선 거리 센서(아날로그) 동시 판정: **습도 80% 초과 AND 접근 40cm 이내**일 때만 서보 모터로 와이퍼 작동
- 반복 오작동 방지 5분 딜레이
- 센서 read 실패 시 안전 처리(isnan 가드)

| 파일 | 내용 |
|---|---|
| `Smart_Bathroom_Wiper.ino` | 최종본 |
| `early_prototype.ino` | 초기 프로토타입 (비교용) |

## 환경
Arduino Uno · DHT11 · IR distance sensor · Servo
