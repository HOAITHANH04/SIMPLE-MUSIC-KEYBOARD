// Định nghĩa các chân
int buttonPins[] = {2, 3, 4, 5, 6, 7, 8, 9};  // Các nút nhấn nối với các chân D2 đến D9
int buzzerPin = 10;  // Chân buzzer nối với D10
int ledPin = 11;  // Chân LED nối với D11

// Các tần số tương ứng với các nốt nhạc (C, D, E, F, G, A, B, C)
int noteFrequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

// Độ dài các nốt (nốt dài hơn sẽ dễ phân biệt hơn)
int noteDurations[] = {500, 400, 300, 400, 500, 300, 400, 500};  // Đơn vị là mili giây

void setup() {
  // Thiết lập các chân nút nhấn là INPUT
  for (int i = 0; i < 8; i++) {
    pinMode(buttonPins[i], INPUT);
  }

  // Thiết lập chân buzzer và LED là OUTPUT
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    // Kiểm tra nếu nút nhấn i được nhấn
    if (digitalRead(buttonPins[i]) == HIGH) {
      tone(buzzerPin, noteFrequencies[i]);  // Phát âm thanh tương ứng với tần số
      digitalWrite(ledPin, HIGH);  // Bật LED khi phát âm thanh
      delay(noteDurations[i]);  // Đợi theo thời gian của nốt nhạc
      noTone(buzzerPin);  // Dừng phát âm thanh sau thời gian đã chỉ định
      digitalWrite(ledPin, LOW);  // Tắt LED sau khi phát xong nốt nhạc
    }
  }
}
