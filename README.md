# 심전도(ECG) 무선 모니터링 시스템

## 프로젝트 개요
본 프로젝트는 심전도(ECG) 센서를 통해 심장의 전기적 활동 데이터를 수집하고, 아두이노를 이용하여 ADC로 변환한 뒤 ZigBee 기반의 무선 통신으로 LCD에 실시간으로 데이터를 전송하여 모니터링합니다. 이 시스템은 환자의 이동성을 제한하지 않으면서 지속적인 심장 건강 모니터링을 가능하게 합니다.

## 구성요소 및 기능
- [Arduino Uno (R3)](https://store-usa.arduino.cc/products/arduino-uno-rev3?selectedStore=us) - 2개
- [XBee ZigBee TH(S2C) - XB24CZ7WIT-004](https://www.devicemart.co.kr/goods/view?no=1327243) - 2개
- [아두이노 호환 XBee 쉴드 XBee Shield 3.0](https://www.devicemart.co.kr/goods/view?no=31025) - 2개
- [TFT LCD 쉴드 arduino 2.4inch Color Touch TFT LCD Shield](https://www.devicemart.co.kr/goods/view?no=1377405)) - 2개
- [PSL-iECG2(소형 2채널 심전도 및 심박 측정 모듈)](https://www.devicemart.co.kr/goods/view?no=1278024) - 2개

### 코드 참조

본 프로젝트의 Sender 코드는 Physio Lab에서 제공한 "2Ch_PSL_Serial.ino" 파일을 기반으로 하며, 해당 파일은 "아두이노 소스.zip" 아카이브 내에 포함되어 있습니다. 아래 링크에서 원본 코드와 관련 자료를 확인할 수 있습니다.

- [원본 코드 링크](https://mybox.naver.com/share/list?shareKey=qwT2ayhcpdvQ5wsZ12FuLiQF-HgwWd8uWTQ1AJ6EfsAD&resourceKey=YWxsc2l4NnwzNDcyNDc3NTYxMzczODQ0NzkyfER8MTA5NjU1ODc)

Sender.ino 코드는 프로젝트의 Zigbee Interface 기본 통신속도인 9600bps에 맞춰 수정되었습니다.

## 시스템 작동 원리
- PSL-ECG2와 Arduino를 연결하여 0 ~ 3.3V 사이의 ECG 전압 데이터를 획득합니다.
- 이 데이터는 ZigBee를 이용하여 무선으로 전송됩니다.
- 전송받은 데이터는 LCD 화면에 실시간으로 시각화됩니다.

## 설치 및 사용법

### 필요한 라이브러리 설치하기

프로젝트를 위해서는 다음 라이브러리가 필요합니다:

1. **SPFD5408 Library**: Arduino TFT LCD 스크린을 제어하기 위한 라이브러리입니다.
   - GitHub 페이지: [SPFD5408 Library](https://github.com/JoaoLopesF/SPFD5408)
   - 설치 방법:
     ```
     git clone https://github.com/JoaoLopesF/SPFD5408.git
     ```
   - 또는 Arduino IDE의 라이브러리 관리자를 이용하여 설치할 수 있습니다.

2. **SD Library for Arduino**: SD 카드와 상호작용하기 위한 라이브러리입니다.
   - GitHub 페이지: [SD Library for Arduino](https://github.com/arduino-libraries/SD)
   - 설치 방법:
     ```
     git clone https://github.com/arduino-libraries/SD.git
     ```
   - 또는 Arduino IDE의 라이브러리 관리자를 이용하여 설치할 수 있습니다.

### 처음 사용시 설정

- 아두이노 보드와 연결한 후, LCD 화면이 정상적으로 작동하는지 확인합니다.
- SD 카드가 제대로 포맷되었고, 아두이노 보드의 SD 카드 슬롯에 올바르게 삽입되었는지 확인합니다.
- 시리얼 모니터를 통해 시스템 로그와 상태 메시지를 확인할 수 있습니다.


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
