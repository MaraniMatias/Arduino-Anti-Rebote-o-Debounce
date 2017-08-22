# Arduino-Anti-Rebote-o-Debounce.

Pushbuttons often generate spurious open/close transitions when pressed, due to mechanical and physical issues: these transitions may be read as multiple presses in a very short time fooling the program

# Install

1. Navigate to the [Releases](https://github.com/MaraniMatias/Arduino-Anti-Rebote-o-Debounce/releases) page.
2. Download the latest release.
3. Extract the zip file
4. Move the "Debounce" folder that has been extracted to your libraries directory.

## Example.

```c++
#include <Debounce.h>

short int pinBtn = 8;
Debounce myBtn(pinBtn);

void setup() {
  //pinMode(pinBtn, OUTPUT); // include in "Debounce myBtn(pinBtn);"
}

void loop() {
  int btnArdu = digitalRead(pinBtn);
  int btn = myBtn.read();
  Serial.print(btnArdu);
  Serial.print(" ~ ");
  Serial.println(btn);
  delay(100); // Just so you can see. Solo para ver los valores
}
```

| digitalRead | btnRead |
| :---------- | :------ |
|      0      |    0    |
|      1      |    1    |
|      1      |    0    |
|      1      |    0    |
|      0      |    0    |
|      1      |    1    |
