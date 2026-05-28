# Arduino Joystick Controls Cursor

A simple desktop cursor controller built using an Arduino Uno and a joystick module.

## Features

* Cursor movement using joystick input
* USB serial communication
* Simple and lightweight setup
* Beginner-friendly embedded systems project

## Hardware Used

* Arduino Uno
* Joystick module
* USB cable

## Installation

1. Clone the repository:

```bash
git clone https://github.com/your-username/Arduino-joystick-controls-cursor.git
```

2. Open the project in VS Code or Arduino IDE.

3. Install the Arduino IDE:

* https://www.arduino.cc/en/software

4. Connect your Arduino Uno using USB.

5. Upload the Arduino code to the board.

6. Run the desktop application/script.

## How It Works

The joystick sends analog input values to the Arduino.
The Arduino processes the values and sends movement data to the computer through USB serial communication.
The desktop application then converts the data into cursor movement.

## Project Structure

```txt
Arduino-joystick-controls-cursor/
│
├── arduino/
│   └── cursor-mover.ino
│
├── script/
│   └── python-script.py
│
├── README.md
```

## Future Improvements

* Mouse click support
* Cursor smoothing
* Gesture controls
* OLED display integration
* AI desktop assistant integration
