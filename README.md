# RhythmGameKeyboard
atmega32u4 기반 아두이노를 사용한 리듬게임용 키보드.

BT버튼 4개, FX버튼 2개, start버튼 1개, 아날로그 노브 2개로 구성되어 있음.
start버튼을 누른 채로 아두이노에 전원을 인가하면 ADOFAI(A Dance Of Fire And Ice)모드로, 그렇지 않으면 SDVX(사운드 볼텍스) 모드로 진입.

# 사용 부품
1 * Arduino Pro Micro

2 * 로터리 엔코더(~PEC12R-4220F-N0024~/PEC16R-4020F-N0024)

6 * 키보드 청축 스위치 (BT 버튼, FX 버튼)

1 * 키보드 흑축 스위치 (START버튼)

5 * 정사각형 키캡

2 * 직사각형 키캡

# 참고사항
업로드를 하려면 아두이노 IDE 라이브러리 폴더에 Encoder 라이브러리가 포함되어 있어야 함.
