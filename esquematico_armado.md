# Mapa de Conexiones - SRAGV (STM32F103RB)

Este documento detalla todas las conexiones necesarias para soldar los componentes en tu placa perforada (perfboard), basándose exactamente en la configuración actual de tu archivo `.ioc`.

> [!TIP]
> **Recomendación para soldar:** Soldá primero zócalos o tiras de pines hembra para la Nucleo y los módulos (Bluetooth, LCD, EEPROM). No sueldes los módulos directamente a la placa, así si alguno falla, lo podés cambiar fácil.

---

## 1. Módulos de Comunicación

### 📡 Módulo Bluetooth (HM-10 / BT05)
Usa la interfaz `USART1`. Recuerda cruzar los pines de TX y RX.
| Pin Nucleo | Pin Módulo | Notas |
| :--- | :--- | :--- |
| **PA9** (USART1_TX) | **RXD** | Transmisión del micro al Bluetooth |
| **PA10** (USART1_RX) | **TXD** | Recepción del micro desde el Bluetooth |
| 5V / 3.3V | VCC | Chequear el voltaje de alimentación del módulo |
| GND | GND | Tierra común |

### 💾 Módulo EEPROM (AT24C02)
Usa la interfaz `I2C1`.
| Pin Nucleo | Pin Módulo | Notas |
| :--- | :--- | :--- |
| **PB8** (I2C1_SCL) | **SCL** | Reloj del I2C |
| **PB9** (I2C1_SDA) | **SDA** | Datos del I2C |
| 3.3V / 5V | VCC | Alimentación |
| GND | GND | Tierra común |

---

## 2. Sensores (Entradas Analógicas)

### 🕹️ Joystick (Simulador de Viento)
| Pin Nucleo | Pin Módulo | Notas |
| :--- | :--- | :--- |
| **PA0** (JOY_X) | **VRx** | Eje X (Velocidad/Dirección) |
| **PA1** (JOY_Y) | **VRy** | Eje Y (Velocidad/Dirección) |
| 3.3V / 5V | VCC | Alimentación |
| GND | GND | Tierra común |

### ☀️ LDR (Sensor de Luz)
Suele usarse un divisor de tensión con una resistencia de 10kΩ.
| Pin Nucleo | Conexión LDR | Notas |
| :--- | :--- | :--- |
| **PA4** (ADC3) | **Punto medio** | Conectar entre el LDR y la resistencia (la resistencia va a GND, el LDR a 3.3V) |

---

## 3. Interfaz de Usuario (Entradas)

Todos los botones y dip-switches están configurados como **Active Low** (el micro lee `0` cuando se presionan). Deben conectarse de manera que al pulsar o activar el switch, el pin se conecte a **GND**.

> [!IMPORTANT]
> Se asume que el microcontrolador tiene las resistencias Pull-Up internas activadas en estos pines (en el .ioc). Si no es así (o si ves que "se presionan solos" por ruido eléctrico), deberás agregar resistencias Pull-Up externas (ej. 10kΩ a 3.3V) en cada uno de estos pines.

| Pin Nucleo | Función | Conexión Física |
| :--- | :--- | :--- |
| **PB0** | Botón UP | Pin -> Botón -> GND |
| **PB1** | Botón DOWN | Pin -> Botón -> GND |
| **PB2** | Botón ENTER | Pin -> Botón -> GND |
| **PC0** | DIP Switch 1 | Pin -> Switch -> GND |
| **PC1** | DIP Switch 2 | Pin -> Switch -> GND |
| **PC2** | DIP Switch 3 | Pin -> Switch -> GND |
| **PC3** | DIP Switch 4 | Pin -> Switch -> GND |

---

## 4. Indicadores y Actuadores (Salidas)

Todos los LEDs y el buzzer están configurados como **Active High** (el micro envía `1` / 3.3V para encenderlos).

> [!CAUTION]
> **OBLIGATORIO:** Colocar una resistencia limitadora de corriente (ej. 220Ω o 330Ω) en serie con cada LED para no quemar el LED ni el pin del microcontrolador.
> **Para el Buzzer:** Si es un buzzer pasivo o consume más de 20mA, se recomienda usar un transistor (ej. 2N2222) para activarlo, ya que el pin del micro no puede entregar mucha corriente.

### 🚥 LEDs de Estado General
| Pin Nucleo | Componente | Conexión |
| :--- | :--- | :--- |
| **PA5** | LED 1 (PWR) | Pin -> Resistencia -> Ánodo LED (Cátodo a GND) |
| **PB10** | LED 2 (ALERTA) | Pin -> Resistencia -> Ánodo LED (Cátodo a GND) |
| **PB11** | LED 3 (RUN) | Pin -> Resistencia -> Ánodo LED (Cátodo a GND) |

### 🧭 LEDs de Sectores de Riego
| Pin Nucleo | Componente | Conexión |
| :--- | :--- | :--- |
| **PA6** | LED Norte | Pin -> Resistencia -> Ánodo LED (Cátodo a GND) |
| **PA7** | LED Sur | Pin -> Resistencia -> Ánodo LED (Cátodo a GND) |
| **PB6** | LED Este | Pin -> Resistencia -> Ánodo LED (Cátodo a GND) |
| **PB7** | LED Oeste | Pin -> Resistencia -> Ánodo LED (Cátodo a GND) |

### 🔊 Alarma Sonora
| Pin Nucleo | Componente | Conexión |
| :--- | :--- | :--- |
| **PB12** | Buzzer | Pin -> Positivo del Buzzer (Negativo a GND) |

---

## 5. Pantalla LCD 16x2

El LCD se comunica en modo paralelo de 4 bits.

> [!NOTE]
> No olvides conectar el potenciómetro de 10kΩ al pin **V0** del LCD para ajustar el contraste, de lo contrario podrías ver solo cuadrados negros o nada en absoluto.

| Pin Nucleo | Pin LCD | Nombre | Notas |
| :--- | :--- | :--- | :--- |
| **PC4** | 4 | **RS** (Register Select) | |
| **PC5** | 6 | **E** (Enable) | |
| **PC6** | 11 | **D4** (Data 4) | |
| **PC7** | 12 | **D5** (Data 5) | |
| **PC8** | 13 | **D6** (Data 6) | |
| **PC9** | 14 | **D7** (Data 7) | |
| GND | 1 | **VSS** | Tierra |
| 5V | 2 | **VDD** | Alimentación lógica (Usá los 5V de la Nucleo) |
| Potenciómetro | 3 | **V0** | Contraste (punto medio del pot) |
| GND | 5 | **R/W** | Lectura/Escritura (siempre en GND para escribir) |
| 5V / Resistencia | 15 | **A** (Ánodo) | Backlight positivo (suele requerir resistencia de ~220Ω) |
| GND | 16 | **K** (Cátodo) | Backlight negativo |

*(Los pines de datos D0 a D3 del LCD, pines 7 al 10, se dejan sin conectar en modo de 4 bits).*
