
# 🔐 Digital Combination Lock Using Arduino

An Arduino-based digital security system that uses password authentication to control access through a keypad, LCD display and servo motor. The project is designed and simulated using **Autodesk Tinkercad**.

## 📸 Circuit Diagram

![Digital Combination Lock Circuit](Digital-Locker%20CIRCUIT.png)

## 📐 Schematic Diagram

The electronic schematic of the Digital Combination Lock project.

📄 [View Schematic Diagram (PDF)](schematic-diagram.pdf)

## 🚀 Project Overview

The Digital Combination Lock is an electronic security system that allows users to enter a password using a 4×4 keypad.

The Arduino UNO processes the entered password and verifies whether it is correct.

- Correct password: Access is granted and the servo motor unlocks the system.
- Incorrect password: Access is denied and the system provides an error indication.

## ✨ Features

- Password-based authentication
- 4×4 matrix keypad input
- LCD display for user interaction
- Servo motor-based locking mechanism
- Buzzer alerts
- Red and green LED status indicators
- Arduino-based control system
- Tinkercad circuit simulation

## 🧰 Components Used

| Component    | Purpose                   |
| ------------ | ------------------------- |
| Arduino UNO  | Main controller           |
| 4×4 Keypad   | Password input            |
| LCD Display  | Displays system messages  |
| Servo Motor  | Locking mechanism         |
| Buzzer       | Audio alerts              |
| Red LED      | Access denied indication  |
| Green LED    | Access granted indication |
| Resistors    | Circuit protection        |
| Breadboard   | Circuit connections       |
| Jumper Wires | Electrical connections    |

## ⚙️ Working Principle

1. The system starts and initializes the LCD, keypad and servo motor.
2. The user enters a password through the keypad.
3. Arduino reads the entered password.
4. The entered password is compared with the configured password.
5. If the password is correct, the servo motor activates the unlocking mechanism and the green LED indicates successful access.
6. If the password is incorrect, access is denied and the red LED and buzzer provide an alert.

## 💻 Source Code

The Arduino source code is available here:

📄 [View Arduino Source Code](digital-combination-lock.ino)

## 🛠️ Development Platform

- Arduino UNO
- Arduino programming (C/C++)
- Autodesk Tinkercad Circuits

## 📂 Repository Structure

```text
digital-combination-lock/
│
├── digital-combination-lock.ino
├── Digital-Locker CIRCUIT.png
├── schematic-diagram.pdf
└── README.md
```

## 🎯 Project Objective

To understand the practical implementation of embedded systems, password authentication, digital input/output interfacing and servo motor control using Arduino.

## 👨‍💻 Author

**Mohith Suryanarayana Gedela**

GitHub: [@mohith511](https://github.com/mohith511)

---

⭐ If you find this project interesting, consider giving this repository a star!
