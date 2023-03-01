#include <Encoder.h>
#include <Keyboard.h>

//핀 설정
int btA = 4;
int btB = 5;
int btC = 6;
int btD = 7;

int fxL = 8;
int fxR = 9;

int start = 10;

Encoder volL(2, 14);
Encoder volR(3, 15);

//키 설정
int btAkey = 's';
int btBkey = 'd';
int btCkey = 'k';
int btDkey = 'l';

int fxLkey = 'c';
int fxRkey = 'm';

int startkey = 176;

int volLcwkey = 119;
int volLccwkey = 113;
int volRcwkey = 112;
int volRccwkey = 111;

//모드 설정
int mode = 0; //0:SDVX 1:ADOFAI

void setup() {
  pinMode(btA, INPUT_PULLUP);
  pinMode(btB, INPUT_PULLUP);
  pinMode(btC, INPUT_PULLUP);
  pinMode(btD, INPUT_PULLUP);
  pinMode(fxL, INPUT_PULLUP);
  pinMode(fxR, INPUT_PULLUP);
  pinMode(start, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  
  //start 키를 누른 채로 전원 인가시 ADOFAI 키로 설정
  if (digitalRead(start) == LOW) {
    mode = 1;
    btAkey = 'd';
    btBkey = 216;
    btCkey = 215;
    btDkey = 'k';
    
    fxLkey = 176;
    fxRkey = 32;
    
    startkey = 177;
    
    volLcwkey = 217;
    volLccwkey = 218;
    volRcwkey = 218;
    volRccwkey = 217;
  }
  
  //오류로 인한 원치 않는 키보드 입력으로 코드 업로드가 어려울 경우, 디지털 16번 핀을 GND에 연결
  while (digitalRead(16) == LOW) {
    
  }
  
  //start 버튼 입력으로 ADOFAI 모드 변경 후, 버튼 입력을 중지할때까지 대기
  while (digitalRead(start) == LOW) {
    
  }
  Keyboard.begin();
}



int volLold = volL.read();
int volRold = volR.read();

void loop() {
  //BT 버튼 입력 처리
  if (digitalRead(btA) == LOW) {
    Keyboard.press(btAkey);
  }
  else {
    Keyboard.release(btAkey);
  }
  
  if (digitalRead(btB) == LOW) {
    Keyboard.press(btBkey);
  }
  else {
    Keyboard.release(btBkey);
  }

  if (digitalRead(btC) == LOW) {
    Keyboard.press(btCkey);
  }
  else {
    Keyboard.release(btCkey);
  }

  if (digitalRead(btD) == LOW) {
    Keyboard.press(btDkey);
  }
  else {
    Keyboard.release(btDkey);
  }
  
  //FX 버튼 입력 리처리
  if (digitalRead(fxL) == LOW) {
    Keyboard.press(fxLkey);
  }
  else {
    Keyboard.release(fxLkey);
  }
  if (digitalRead(fxR) == LOW) {
    Keyboard.press(fxRkey);
  }
  else {
    Keyboard.release(fxRkey);
  }
  
  //Start 버튼 입력 처리
  if (digitalRead(start) == LOW) {
    Keyboard.press(startkey);
  }
  else {
    Keyboard.release(startkey);
  }
  
  //아날로그 디바이스 입력 처리
  //volL 엔코더 입력 처리
  if (volL.read() > volLold) {
    volLold = volL.read();
    Keyboard.release(volLccwkey);
    Keyboard.press(volLcwkey);
  }
  else if (volL.read() < volLold) {
    volLold = volL.read();
    Keyboard.release(volLcwkey);
    Keyboard.press(volLccwkey);
  }
  else {
    Keyboard.release(volLcwkey);
    Keyboard.release(volLccwkey);
  }
  //volR 엔코더 입력 처리
  if (volR.read() > volRold) {
    volRold = volR.read();
    Keyboard.release(volRccwkey);
    Keyboard.press(volRcwkey);
  }
  else if (volR.read() < volRold) {
    volRold = volR.read();
    Keyboard.release(volRcwkey);
    Keyboard.press(volRccwkey);
  }
  else {
    Keyboard.release(volRcwkey);
    Keyboard.release(volRccwkey);
  }
}
