//Cory Stanford
//CS3310
//Selection Sort
//Final Presentation Project
#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0);

#define NUM_VALUES 20

uint8_t data[NUM_VALUES];
uint8_t step_i = 0;
uint8_t step_j = 1;
uint8_t min_idx = 0;
bool sortingDone = false;

void drawBars(uint8_t* array, int size) {
  u8g2.clearBuffer();
  for (int i = 0; i < size; i++) {
    int barWidth = (128 / size) - 1;
    int x = i * (barWidth + 1);
    int y_draw = 64 - array[i];
    u8g2.drawBox(x, y_draw, barWidth, array[i]);
  }
  u8g2.sendBuffer();
}

bool selectionSortStep(uint8_t* array, uint8_t size) {
  bool didSwap = false;

  if (step_j >= size) {
    if (min_idx != step_i) {
      uint8_t temp = array[step_i];
      array[step_i] = array[min_idx];
      array[min_idx] = temp;
      didSwap = true;
    }
    step_i++;
    step_j = step_i + 1;
    min_idx = step_i;
    return didSwap;
  }

  if (array[step_j] < array[min_idx]) {
    min_idx = step_j;
  }

  step_j++;
  return false;
}

void setup() {
  u8g2.begin();
  randomSeed(analogRead(0));

  for (int i = 0; i < NUM_VALUES; i++) {
    data[i] = random(10, 60);
  }

  drawBars(data, NUM_VALUES);
  delay(1000);
}

void loop() {
  for (;;) {
    selectionSortStep(data, NUM_VALUES);
    drawBars(data, NUM_VALUES);
    delay(10);
    if (step_i >= NUM_VALUES - 1) {
      sortingDone = true;
    }
  }
}
