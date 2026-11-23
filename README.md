# Various Arduino Projects

A collection of Arduino sketches written from 2016 onward while learning embedded programming and
building hobby hardware. It starts with blinking LEDs and grows to seven-segment clocks, servo
robots, tone detection with digital signal processing, and hand-written serial and SPI protocols.
The sketches are organized by the hardware or technique they explore.

Each sketch is a standalone Arduino project. Open the `.ino` file in the Arduino IDE, select the
board, and upload.

## Contents

### Seven-segment displays (`SevenSegmentProjects/`)

| Sketch | What it does |
|---|---|
| `ClockV1` | A six-digit clock on an Arduino UNO that multiplexes a common-cathode seven-segment display directly from the pins. Its header notes that it loses less than one second every four days |
| `ClockV2`, `clockDemo`, `FHEDemo` | A nine-character clock and alarm (`HH.MM.SSA`) built on a `SevenSegmentDriver` display library, with a millisecond tick, a 12-hour time format, and an alarm flag. `FHEDemo` adds a timer |
| `EmryVDay` | A themed display sketch built on the same driver, with a ticking buzzer and a song played at a set tempo |
| `TimeBomb` | A large standalone sketch (about 1,500 lines) that drives a nine-digit display pin by pin, with a 12-hour clock, an alarm clock, scrolling text, and a ticking sound effect |
| `StringReceiveAndDisplay` | Scrolls text received over the serial port across the display |
| `ColorDisplay` | Receives color values over the serial port and shows them on the display |

### LEDs (`LEDProjects/`, `Ornament/`)

| Sketch | What it does |
|---|---|
| `my_first_code` | The first program in the collection: patterns on ten LEDs, with each pin handled individually |
| `Light_Show`, `Light_Show_with_arrays` | The same light show, then rewritten with an array of pins to remove the repetition |
| `RGB/RainbowDisplay`, `RGB/SendTheColor` | Drive an RGB LED through random and fading colors using an `RGBLedDriver` library |
| `Ornament/ornament1` | A 16-pixel NeoPixel ring for a holiday ornament, stepping through a palette of 12 colors. A copy of the Adafruit NeoPixel library is included |

### Servos and motion (`ServoProjects/`)

| Sketch | What it does |
|---|---|
| `Servo` | A basic servo sweep |
| `DigitalAnalogClock/DgtlAnlgClk` | A servo moved by a debounced switch |
| `Freddy_the_Frog` | Four servos, one per leg, with routines to extend and contract the left and right sides |
| `LaserPointer/Laser1` | A laser on a two-servo pan and tilt mount, with routines to flash, move to a point, draw a circle, sweep, fire at random targets, and raster a region |
| `LaserPointer/LaserControler` | The same pan and tilt laser, extended with buttons and a joystick for manual control |
| `Rudder/Experiment` | A short test that reads an analog input and prints the value over serial |

### Sound (`SoundProjects/`)

| Sketch | What it does |
|---|---|
| `Buzzer/Buzztest` | A table of note frequencies and a tune played on a piezo buzzer |
| `Microphone` | Reads a microphone on an analog pin and prints the level over serial |

### Signal processing (`ArensProject/`)

| Sketch | What it does |
|---|---|
| `ArensProject` | Detects a tone in a sampled signal. It samples the analog input at 3 kHz, mixes it down at the target frequency, filters it with a sinc low-pass FIR filter, decimates, and compares the level to a dB threshold. Parameters such as the target frequency, bandwidth, and filter length are set at the top of the file |
| `ESP32_Sampler` | The same approach retuned for an ESP32, with a 1 kHz sample rate and a 300 Hz target |

### Communication protocols (`UARTProjects/`, `dacSPI/`)

| Sketch | What it does |
|---|---|
| `UARTmanual` | Builds a serial packet bit by bit on a pin, with a hand-timed bit period, instead of using the hardware UART |
| `dacSPI` | Sends command and voltage-code packets to a DAC using a software SPI transmitter with configurable clock edge, bit order, and baud rate, stepping the output through its range |

### Patterns and templates

| Sketch | What it does |
|---|---|
| `StateMachineBasic/StateMachineTemplate` | A starting point for a state machine that runs on a fixed 50 ms tick, with named states and the last state tracked |
| `Debounce/debounce` | A button debouncing example |

## Libraries

Several sketches use libraries that are not included in this repository: `SevenSegmentDriver`,
`RGBLedDriver`, `DSP`, `softwareSPItx`, and `ArduinoStdInt`. Install them into your Arduino
libraries folder before building those sketches. The one third-party library that is bundled is
Adafruit NeoPixel, inside `Ornament/`. Sketches that need only the standard Arduino libraries
(`Servo`, for example) build as they are.

## Notes

These sketches are a learning record, kept mostly as they were written. Several carry experiments,
tuning notes, and commented-out code. Pin assignments are set at the top of each sketch and match
the hardware it was written for, so check them before wiring.
