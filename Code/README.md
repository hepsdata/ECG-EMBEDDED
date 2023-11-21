# ECG 무선 전송 시스템 코드 문서화

이 저장소에는 ECG 무선 전송 시스템을 위한 코드가 포함되어 있다. 이 시스템에는 두 가지 주요 구성 요소가 있다: 송신기와 수신기. `Sender.ino`는 ECG 데이터를 수집하여 무선으로 전송하는 역할을 하며, `Receiver.ino`는 ECG 데이터를 수신하고 LCD에 표시하는 역할을 한다.

## Sender.ino

### 개요

`Sender.ino`는 ECG 센서 모듈에서 데이터를 읽고, 아두이노 보드를 통해 처리한 후 ZigBee 무선 통신을 통해 `Receiver.ino`로 전송한다.

### 설정

코드를 아두이노 Uno (R3)에 업로드하기 전에 TimerOne 라이브러리가 설치되어 있는지 확인하세요. 프로젝트 문서에 제공된 회로도에 따라 ECG 센서 모듈과 XBee ZigBee 모듈을 연결.

### 사용법

아두이노가 전원을 받고 `Sender.ino`를 실행하면, 정기적으로 ECG 데이터를 읽고 전송을 시작한다.

## Receiver.ino

### 개요

`Receiver.ino`는 `Sender.ino`에서 보낸 들어오는 ECG 데이터를 수신합니다. 수신된 데이터를 처리하고 연결된 TFT LCD 쉴드에 ECG 파형을 표시한다.

### 설정

SPFD5408, SD 라이브러리가 설치되어 있어야 합니다. TFT LCD 쉴드는 아두이노 Uno (R3)에 올바르게 연결되어야 하며, XBee ZigBee 모듈은 데이터 수신을 위해 구성되어야 한다.

### 사용법

ECG 데이터를 수신하면 `Receiver.ino`는 실시간으로 디스플레이를 업데이트합니다. TFT LCD 쉴드의 UI 버튼을 통해 데이터 표시를 일시 정지하거나 재개할 수 있다.

## 구성

`Sender.ino`와 `Receiver.ino`는 최소한의 구성으로 즉시 사용할 수 있도록 설계되었다. 하드웨어 구성 요소를 변경하는 경우, 각 스케치 상단에 있는 핀 구성을 업데이트해야 할 수도 있다.

## 추가 사항

- 코드는 Physio Lab에서 제공한 원본 파일을 기반으로 하며, Zigbee 모듈의 기본 전송속도 9600bps에 맞게 수정을 거쳤다.
- 원본 코드에 대한 자세한 정보는 프로젝트 개요 섹션에서 제공된 공유 링크를 참조.

## 참조

- Physio Lab에서 제공한 원본 `2Ch_PSL_Serial.ino` 코드는 다음의 [공유 폴더](https://mybox.naver.com/share/list?shareKey=qwT2ayhcpdvQ5wsZ12FuLiQF-HgwWd8uWTQ1AJ6EfsAD&resourceKey=YWxsc2l4NnwzNDcyNDc3NTYxMzczODQ0NzkyfER8MTA5NjU1ODc)에서 "아두이노 소스.zip" 아카이브 내에서 찾을 수 있다.
