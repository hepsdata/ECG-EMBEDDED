# ECG Wireless Transmission System Code Documentation

This repository contains the code for the ECG Wireless Transmission System. There are two main components of the system: the sender and the receiver. The `Sender.ino` is responsible for collecting ECG data and sending it wirelessly, and the `Receiver.ino` is for receiving the ECG data and displaying it on the LCD.

## Sender.ino

### Overview

`Sender.ino` reads ECG data from the ECG sensor module, processes it via an Arduino board, and sends it to the `Receiver.ino` through ZigBee wireless communication.

### Setup

Ensure that the SPFD5408, SD, and TimerOne libraries are installed before uploading the code to your Arduino Uno (R3). Connect the ECG sensor module and the XBee ZigBee module as per the circuit diagram provided in the project documentation.

### Usage

Once the Arduino is powered on and running `Sender.ino`, it will begin reading ECG data and transmitting it at regular intervals.

## Receiver.ino

### Overview

`Receiver.ino` listens for incoming ECG data sent by `Sender.ino`. It processes the received data and displays the ECG waveform on a connected TFT LCD shield.

### Setup

Similar to `Sender.ino`, you must have the required libraries installed. The TFT LCD shield should be connected to the Arduino Uno (R3) correctly, and the XBee ZigBee module should be configured to receive data.

### Usage

Upon receiving ECG data, `Receiver.ino` will update the display in real-time. Interact with the system through the UI buttons on the TFT LCD shield to pause or resume the data display.

## Configuration

Both `Sender.ino` and `Receiver.ino` are designed to work out of the box with minimal configuration. However, if you change any hardware components, you may need to update the pin configurations at the top of each sketch.

## Additional Notes

- The code is adapted from the original files provided by Physio Lab, with significant modifications made to tailor it to the project's requirements.
- For in-depth information on the original code, refer to the shared repository link provided in the project overview section.

## References

- Original `2Ch_PSL_Serial.ino` code provided by Physio Lab can be found in the "아두이노 소스.zip" archive at the following [shared folder](https://mybox.naver.com/share/list?shareKey=qwT2ayhcpdvQ5wsZ12FuLiQF-HgwW
