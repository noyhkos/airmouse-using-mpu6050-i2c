# Air Mouse Project
[MPU6050 센서를 활용한 에어마우스 프로젝트] 

## 하드웨어 스펙
센서: MPU6050
보드: ST Nucleo-F103RB
칩셋: STM32F103RB

## 개요
1. MPU6050 x,y,z축 가속도 측정
2. I2C 통신을 이용하여 보드에 전송
3. Byte 데이터 파싱 후 버튼 클릭 정보와 함께 Window로 전송(UART통신)
4. cpp 베이스 실행파일로 UART 수신 후 마우스 제어

## 기타
보드개발: STM CubeIDE(main.c)
마우스 제어프로그램 개발: Visual Studio 2022(main.cpp, serial.h)

