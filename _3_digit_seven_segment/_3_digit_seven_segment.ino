// Pin digit controller
#define DIGIT1 2
#define DIGIT2 5
#define DIGIT3 6

// Pin to light up the segment
#define SEG_A 3
#define SEG_B 7
#define SEG_C 11
#define SEG_D 9
#define SEG_E 8
#define SEG_F 4
#define SEG_G 12
#define SEG_DP 10

// Pin for segments in sequence
const int segs[7] = {SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G};

// Segments that make each number
const byte numbers[10] = {0b0111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b0000111, 0b1111111, 0b1101111};

void setup() {
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
  pinMode(DIGIT1, OUTPUT);
  pinMode(DIGIT2, OUTPUT);
  pinMode(DIGIT3, OUTPUT);
}

void lightDigit1(byte number) {
  digitalWrite(DIGIT1, LOW);
  digitalWrite(DIGIT2, HIGH);
  digitalWrite(DIGIT3, HIGH);
  lightSegments(number);
}

void lightDigit2(byte number) {
  digitalWrite(DIGIT1, HIGH);
  digitalWrite(DIGIT2, LOW);
  digitalWrite(DIGIT3, HIGH);
  lightSegments(number);
}

void lightDigit3(byte number) {
  digitalWrite(DIGIT1, HIGH);
  digitalWrite(DIGIT2, HIGH);
  digitalWrite(DIGIT3, LOW);
  lightSegments(number);
}

void lightSegments(byte number) {
  for (int i = 0; i < 7; i++) {
    int bit = bitRead(number, i);
    digitalWrite(segs[i], bit);
  }
}

void loop() {
  for (int digit1=0; digit1 < 10; digit1++) {
    for (int digit2=0; digit2 < 10; digit2++) {
      for (int digit3=0; digit3 < 10; digit3++) {
        unsigned long startTime = millis();
        
        for (unsigned long elapsed=0; elapsed < 600; elapsed = millis() - startTime) {
          lightDigit1(numbers[digit1]);
          delay(5);
          lightDigit2(numbers[digit2]);
          delay(5);
          lightDigit3(numbers[digit3]);
          delay(5);   
        }  
      }
    }
  }
}
