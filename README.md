# ESP32 Internet Info Display

This project uses a cheap ESP32 Screen to display information from the internet, such as the current time.

![image](https://user-images.githubusercontent.com/1562562/221344692-7dd359d3-2e64-4a09-850b-b619477c5043.png)

This project is a Work in Progress!

## Help Support what I do!

[If you enjoy my work, please consider becoming a Github sponsor!](https://github.com/sponsors/witnessmenow/)

## Hardware Required

This project is designed to make use of basically ready to go hardware, so is very easy to get up and running

Currently this project runs on two types of hardware:

### "Cheap Yellow Display" (CYD)

An ESP32 With Built in 320x240 LCD with Touch Screen (ESP32-2432S028R), buy from wherever works out cheapest for you:

- [Aliexpress\*](https://s.click.aliexpress.com/e/_DkSpIjB)
- [Aliexpress\*](https://s.click.aliexpress.com/e/_DkcmuCh)
- [Aliexpress](https://www.aliexpress.com/item/1005004502250619.htm)
- [Makerfabs](https://www.makerfabs.com/sunton-esp32-2-8-inch-tft-with-touch.html)

### Matrix panel (ESP32 Trinity)

It's built to work with the [ESP32 Trinity](https://github.com/witnessmenow/ESP32-Trinity), an open source board I created for controlling Hub75 Matrix panels, but it will does work with any ESP32 that breaks out enough pins.

The display it uses is a 64x64 HUB75 Matrix Panel.

All the parts can be purchased from Makerfabs.com:

- [ESP32 Trinity](https://www.makerfabs.com/esp32-trinity.html)
- [64 x 64 Matrix Panel](https://www.makerfabs.com/64x64-rgb-led-matrix-3mm-pitch.html)
- Optional: [5V Power Supply](https://www.makerfabs.com/5v-6a-ac-dc-power-adapter-with-cable.html) - You can alternatively use a USB-C power supply

\* = Affilate Link

### BYOD (Bring your own display)

I've tried to design this project to be modular and have abstracted the display code behind an interface, so it should be pretty easy to get it up and running with a different type of display.

## Project Setup

These steps only need to be run once.

### Step 1 - Flash the Project

Flash the project directly from your browser [here](https://witnessmenow.github.io/Spotify-Diy-Thing) (Chrome & Edge only)

or

Jump to the "code" section below

### Step 2 - Adding your Wifi Details

The device is now flashed with the code, but it doesn't know what your Wifi details are.

In order to enter your wifi details, the project will host its own wifi network. Connect to it using your phone.

- SSID: ESP32InfoDisplay
- Password: display123

You should be automatically redirected to the config page.

- Click Config
- Enter your Wifi details (2.4Ghz only)
- Click save

Note: If you ever need to get back into this config section, click reset button (the button closest to the side) twice.

### Step 3 - Displaying Information

The final step is to connect the device to the internet and start displaying information such as the current time.

Your project should now be setup and will start displaying the current time!

## Code

If you want to program this project manually, there are two options

### PlatformIO

PlatformIO is the easiest way to code this project.

In the [platformio.ini](platformio.ini), there are several environments defined for the different boards

| Environment | Description                                                                                                                  |
| ----------- | ---------------------------------------------------------------------------------------------------------------------------- |
| env:cyd     | For the [Cheap Yellow Display](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display)                                   |
| env:cyd2usb | For the Cheap Yellow Display with two USB ports                                                                              |
| env:trinity | For the [ESP32 Trinity](https://github.com/witnessmenow/ESP32-Trinity) (or generic ESP32 wired to the matrix panel the same) |

When you select the environment, it will automatically install the right libraries and set the configurations in the code.

### Arduino IDE

If you want to use the Arduino IDE, you will need to do the following to get it working

The following libraries need to be installed for this project to work:

| Library Name/Link                                                                | Purpose                                    | Library manager                 |
| -------------------------------------------------------------------------------- | ------------------------------------------ | ------------------------------- |
| [ArduinoJson](https://github.com/bblanchon/ArduinoJson)                          | For parsing JSON data                      | Yes ("Arduino Json")            |
| [JPEGDEC](https://github.com/bitbank2/JPEGDEC)                                   | For decoding images                        | Yes ("JPEGDEC")                 |
| [WifiManager - By Tzapu](https://github.com/tzapu/WiFiManager)                   | Captive portal for configuring the WiFi    | Yes ("WifiManager")             |
| [ESP_DoubleResetDetector](https://github.com/khoih-prog/ESP_DoubleResetDetector) | Detecting double pressing the reset button | Yes ("ESP_DoubleResetDetector") |

#### Cheap Yellow Display Specific libraries

| Library Name/Link                              | Purpose                         | Library manager  |
| ---------------------------------------------- | ------------------------------- | ---------------- |
| [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI) | For controlling the LCD Display | Yes ("tft_espi") |

#### Matrix Panel Specific libraries

| Library Name/Link                                                                                 | Purpose                          | Library manager          |
| ------------------------------------------------------------------------------------------------- | -------------------------------- | ------------------------ |
| [ESP32-HUB75-MatrixPanel-I2S-DMA](https://github.com/mrfaptastic/ESP32-HUB75-MatrixPanel-I2S-DMA) | For controlling the LED Matrix   | Yes ("ESP32 MATRIX DMA") |
| [Adafruit GFX library](https://github.com/adafruit/Adafruit-GFX-Library)                          | Dependency of the Matrix library | Yes ("Adafruit GFX")     |

#### Cheap Yellow Display Display Config

The CYD version of the project makes use of [TFT_eSPI library by Bodmer](https://github.com/Bodmer/TFT_eSPI).

TFT_eSPI is configured using a "User_Setup.h" file in the library folder, you will need to replace this file with the one in the `DisplayConfig` folder of this repo.

#### Display Selection

At the top of the `ESP32InfoDisplay.ino` file, there is a section labeled "Display Type", follow the instructions there for how to enable the different displays.

Note: By default it will use the Cheap Yellow Display
