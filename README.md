# Selection Sort on a Microcontroller

This project demonstrates the Selection Sort algorithm running on an Arduino Nano microcontroller, visualized on a 128x64 SSD1306 OLED display. It’s a hands-on way to explore how sorting algorithms work step-by-step in low-level systems with limited resources.

## Project Overview

- Algorithm: Selection Sort
- Language: Embedded C (Arduino)
- Hardware: Arduino Nano (ATmega328P), SSD1306 OLED screen (I2C)
- Graphics Library: [U8g2](https://github.com/olikraus/u8g2)
- Goal: Visually demonstrate how Selection Sort operates in real time

##️ Demo

Each iteration of the Selection Sort is animated on the OLED screen using vertical bars to represent array values. The sorting happens one step per frame, allowing viewers to clearly observe comparisons and swaps.

## How It Works

- On startup, the Arduino fills an array with 20 random values (10–60).
- In each loop iteration:
  - It compares array values and tracks the smallest in the unsorted portion.
  - When the inner loop finishes, it swaps the minimum into place.
  - A delay gives time for each step to be visible on the OLED.
- The process continues until the array is sorted.

## Why Selection Sort?

Selection Sort has:
- Time Complexity: O(n²) – for all best, average, and worst cases.
- Space Complexity: O(1) – sorts in place with no extra memory.
- Though inefficient for large data, its simplicity and predictability make it great for embedded demos and educational tools.

As Donald Knuth states in The Art of Computer Programming:

> "The simplest of the sorting algorithms, selection sort has the virtue of simplicity and a well-defined number of data movements."

```
## Requirements

- Arduino Nano or compatible board
- SSD1306 OLED screen (I2C)
- Arduino IDE
- U8g2 library (install via Library Manager)

## Getting Started

1. Clone the repo or download the `.ino` sketch
2. Open it in the Arduino IDE
3. Connect your OLED to SDA/SCL (A4/A5 on Nano)
4. Upload the sketch
5. Watch the sorting animation begin!

## References

- Cormen et al., Introduction to Algorithms
- Donald Knuth, The Art of Computer Programming, Vol. 3
- Atmel AVR Instruction Set Manual (Microchip)
- U8g2 OLED Library: https://github.com/olikraus/u8g2

---