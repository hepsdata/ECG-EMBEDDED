# 심전도(ECG) 무선 모니터링 시스템

## 프로젝트 개요
본 프로젝트는 심전도(ECG) 센서를 통해 심장의 전기적 활동 데이터를 수집하고, 아두이노를 이용하여 ADC로 변환한 뒤 ZigBee 기반의 무선 통신으로 LCD에 실시간으로 데이터를 전송하여 모니터링합니다. 이 시스템은 환자의 이동성을 제한하지 않으면서 지속적인 심장 건강 모니터링을 가능하게 합니다.

## 구성요소 및 기능
- [Arduino Uno (R3)](https://store.arduino.cc/usa/arduino-uno-rev3) - 2개
- [XBee ZigBee TH(S2C) - XB24CZ7WIT-004](https://www.digi.com/products/models/xb24cz7wit-004) - 2개
- [아두이노 호환 XBee 쉴드 XBee Shield 3.0](https://www.adafruit.com/product/126) - 2개
- [TFT LCD 쉴드 arduino 2.4inch Color Touch TFT LCD Shield](https://www.sparkfun.com/products/retired/12757) - 2개
- [PSL-iECG2(소형 2채널 심전도 및 심박 측정 모듈)](http://www.pulsesensor.com) - 2개

## 시스템 작동 원리
- PSL-ECG2와 Arduino를 연결하여 0 ~ 3.3V 사이의 ECG 전압 데이터를 획득합니다.
- 이 데이터는 ZigBee를 이용하여 무선으로 전송됩니다.
- 전송받은 데이터는 LCD 화면에 실시간으로 시각화됩니다.

## 설치 및 사용법
(설치 과정, 라이브러리 설치, 코드 업로드 방법 등을 자세히 설명합니다.)

## 부가적인 기능
- **SETUP Button**: 새로운 측정을 시작하고 기존 데이터를 CSV 파일로 저장합니다.
- **STOP Button**: 측정을 일시정지하고 재개합니다.
- **ECG Signal Visualization**: ECG 데이터와 R-Peak을 시각화하여 보여줍니다.

## 데이터 저장 및 분석
- 측정된 데이터는 `ECG_[timestamp].csv` 형식으로 SD 카드에 저장됩니다.
- `file_log.txt`에 모든 CSV 파일명이 저장되어, 필요한 데이터 파일을 쉽게 찾을 수 있습니다.

## 프로젝트 고찰 및 지속 가능성
- 본 시스템은 환자의 이동성을 제약하지 않으면서 지속적인 모니터링을 가능하게 합니다.
- 스마트 병원 시스템과 연동하여 위치 추적과 연계할 수 있는 가능성이 있습니다.
- 의료 정보 교환 표준인 HL7을 적용하지 않아 보안상의 개선이 필요합니다.
