# Checklist de Soldadura - Paso a Paso

Esta guía está pensada para que vayas tachando (haciendo clic en las cajitas) a medida que avanzás con tu placa perforada de 20x10. El orden es fundamental para no cruzarte con cables y hacer las pruebas de a poco sin quemar nada.

> [!TIP]
> **Regla de oro:** Soldá siempre del componente más bajo (resistencias, puentes de cable corto) al más alto (zócalos, capacitores grandes). Nunca sueldes la Nucleo, el Bluetooth, el LCD o la EEPROM directamente a la placa; **usá tiras de pines hembra (zócalos)** para poder enchufarlos y desenchufarlos.

## Fase 1: Distribución y Alimentación (Lo más importante)

- [ ] **1. Presentación en seco:** Colocá los zócalos de la Nucleo, del LCD y de los módulos en la placa perforada *sin soldar*. Asegurate de que todo entra bien y tenés espacio para rutear cables.
- [ ] **2. Rieles de alimentación:** Elegí una línea entera de agujeritos (o un cable pelado largo) para que sea tu **GND (Tierra)** común, y otra para los **3.3V** o **5V**. Soldá estos rieles primero.
- [ ] **3. Soldar zócalo principal:** Soldá los pines hembra donde va a ir enchufada la Nucleo.
- [ ] **4. Conectar la Nucleo a los rieles:** Tirá un cable desde el pin GND de la Nucleo hasta tu "riel GND", y otro desde el pin de 5V/3.3V al riel de VCC.

---

## Fase 2: LEDs de Estado (Salidas más fáciles)

> [!CAUTION]
> Recordá que todos los LEDs **deben llevar una resistencia limitadora (ej. 220Ω - 330Ω) en serie** conectada al pin de la Nucleo, para no quemar el micro. La pata corta del LED (Cátodo) va a GND.

- [ ] **1. LED PWR (PA5):** Soldar resistencia al pin PA5 -> Ánodo del LED -> Cátodo al riel GND.
- [ ] **2. LED ALERTA (PB10):** Soldar resistencia al pin PB10 -> Ánodo del LED -> Cátodo al riel GND.
- [ ] **3. LED RUN (PB11):** Soldar resistencia al pin PB11 -> Ánodo del LED -> Cátodo al riel GND.
- [ ] **4. LEDs de Sectores (PA6, PA7, PB6, PB7):** Repetir el proceso para los 4 LEDs direccionales.

---

## Fase 3: Interfaz de Usuario (Entradas)

- [ ] **1. Botones (UP, DOWN, ENTER):** Soldar los botones. Una pata va al riel GND. La otra pata va a los pines PB0, PB1 y PB2 de la Nucleo respectivamente.
- [ ] **2. DIP Switch de 4 posiciones:** Soldar el switch. Todas las patitas de un lado van puenteadas al riel GND. Las 4 patitas del otro lado van a los pines PC0, PC1, PC2 y PC3.

---

## Fase 4: Buzzer y Sensores

- [ ] **1. Buzzer (PB12):** Soldar el positivo del buzzer a PB12 y el negativo a GND. *(Si el buzzer pide mucha corriente, deberías agregar un transistor NPN de por medio, pero probá directo primero)*.
- [ ] **2. Joystick (PA0 y PA1):** Soldar zócalo de 5 pines para el joystick. Conectar VCC y GND. Conectar VRx a PA0 y VRy a PA1.
- [ ] **3. LDR (PA4):** Soldar el sensor de luz y una resistencia de 10kΩ haciendo un divisor de tensión. El punto medio (donde se unen el LDR y la resistencia) va cableado al pin PA4 de la Nucleo.

---

## Fase 5: Módulos de Comunicación

- [ ] **1. EEPROM (I2C1):** Soldar un zócalo de 4 pines. Conectar VCC y GND. Conectar el pin SCL del módulo al PB8 de la Nucleo. Conectar SDA al PB9.
- [ ] **2. Bluetooth (USART1):** Soldar un zócalo de 4 o 6 pines. Conectar VCC y GND. **¡Cruzar los cables!** El pin RXD del Bluetooth va al PA9 (TX) de la Nucleo. El pin TXD del Bluetooth va al PA10 (RX) de la Nucleo.

---

## Fase 6: Pantalla LCD (El jefe final)

- [ ] **1. Zócalo del LCD:** Soldar tira de pines hembra de 16 posiciones.
- [ ] **2. Alimentación del LCD:** Conectar VSS (pin 1) a GND. Conectar VDD (pin 2) a los 5V de la Nucleo.
- [ ] **3. Potenciómetro de contraste (10kΩ):** Soldarlo cerca del LCD. Una pata lateral a VDD, la otra a GND. El pin del medio va al pin **V0** (pin 3) del LCD.
- [ ] **4. Control (RS, R/W, E):**
  - R/W (pin 5) se conecta directo al riel GND.
  - RS (pin 4) se conecta al PC4 de la Nucleo.
  - E (pin 6) se conecta al PC5 de la Nucleo.
- [ ] **5. Bus de Datos 4-bits:** Conectar los pines del LCD D4, D5, D6 y D7 (pines 11 al 14) hacia los pines PC6, PC7, PC8 y PC9 de la Nucleo respectivamente. *(Los pines D0 a D3 del LCD se dejan vacíos)*.
- [ ] **6. Backlight:** Conectar el Ánodo (pin 15) a 5V a través de una resistencia de 220Ω, y el Cátodo (pin 16) a GND.

---

## Fase 7: Prueba de Humo y Encendido

- [ ] **1. Test de Cortocircuito:** **ANTES DE ENCHUFAR LA NUCLEO Y LOS MÓDULOS AL USB**, agarrá un multímetro en modo "continuidad" (el que hace *bip*). Tocá tu riel de VCC (5V/3.3V) y tu riel de GND. **NO debería hacer bip**. Si hace bip, tenés un corto y si la enchufás se quema. Revisá toda la placa.
- [ ] **2. Colocar la Nucleo:** Enchufá solo la Nucleo en su zócalo y conectala al USB. ¿Prenden las luces de la Nucleo? Perfecto.
- [ ] **3. Módulos y LCD:** Desconectá el USB. Enchufá el LCD, el Bluetooth y la EEPROM en sus zócalos. Volvé a enchufar el USB. Si la pantalla prende y el Bluetooth titila, ¡terminaste con éxito!
