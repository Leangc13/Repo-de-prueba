# Diagrama Esquemático de Conexiones - SRAGV

A continuación tenés un diagrama visual interactivo de cómo están conectados todos los componentes a la placa Nucleo. Podés usar esto como una referencia rápida mientras armás tu placa perforada.

```mermaid
graph LR
    %% NUCLEO MCU
    subgraph Nucleo[STM32F103RB]
        %% Pines
        PA0[PA0 - JOY_X]
        PA1[PA1 - JOY_Y]
        PA4[PA4 - ADC3]
        
        PB0[PB0 - BTN_UP]
        PB1[PB1 - BTN_DOWN]
        PB2[PB2 - BTN_ENTER]
        
        PC0[PC0 - DIP1]
        PC1[PC1 - DIP2]
        PC2[PC2 - DIP3]
        PC3[PC3 - DIP4]
        
        PA5[PA5 - LED_PWR]
        PB10[PB10 - LED_ALERTA]
        PB11[PB11 - LED_RUN]
        
        PA6[PA6 - LED_N]
        PA7[PA7 - LED_S]
        PB6[PB6 - LED_E]
        PB7[PB7 - LED_W]
        
        PB12[PB12 - BUZZER]
        
        PA9[PA9 - USART1_TX]
        PA10[PA10 - USART1_RX]
        
        PB8[PB8 - I2C1_SCL]
        PB9[PB9 - I2C1_SDA]
        
        %% LCD Pines
        PC4[PC4 - LCD_RS]
        PC5[PC5 - LCD_EN]
        PC6[PC6 - LCD_D4]
        PC7[PC7 - LCD_D5]
        PC8[PC8 - LCD_D6]
        PC9[PC9 - LCD_D7]
    end

    %% Módulos Externos
    subgraph Sensores
        Joy[Joystick]
        LDR[Sensor LDR + Resistencia]
    end

    subgraph Botones [Botones y DIP]
        BUP((Btn UP))
        BDOWN((Btn DOWN))
        BENT((Btn ENTER))
        DIP[DIP Switch 4 Pos]
    end

    subgraph Salidas [LEDs y Buzzer]
        LPWR((LED PWR))
        LALERT((LED ALERTA))
        LRUN((LED RUN))
        LN((LED N))
        LS((LED S))
        LE((LED E))
        LW((LED W))
        BUZ((Buzzer))
    end

    subgraph Comunicacion
        BT[Módulo Bluetooth HM-10]
        EE[Módulo EEPROM AT24C02]
    end
    
    subgraph Pantalla
        LCD[LCD 16x2]
    end

    %% Conexiones Sensores
    Joy -- VRx --> PA0
    Joy -- VRy --> PA1
    LDR -- Divisor V. --> PA4

    %% Conexiones Botones
    BUP -- GND --> PB0
    BDOWN -- GND --> PB1
    BENT -- GND --> PB2
    DIP -- GND --> PC0
    DIP -- GND --> PC1
    DIP -- GND --> PC2
    DIP -- GND --> PC3

    %% Conexiones Salidas
    PA5 -- Resistencia --> LPWR
    PB10 -- Resistencia --> LALERT
    PB11 -- Resistencia --> LRUN
    
    PA6 -- Resistencia --> LN
    PA7 -- Resistencia --> LS
    PB6 -- Resistencia --> LE
    PB7 -- Resistencia --> LW
    
    PB12 --> BUZ

    %% Conexiones Comunicación
    PA9 -- TX -> RX --> BT
    PA10 -- RX <- TX --> BT
    
    PB8 -- SCL --> EE
    PB9 -- SDA --> EE

    %% Conexiones LCD
    PC4 --> LCD
    PC5 --> LCD
    PC6 --> LCD
    PC7 --> LCD
    PC8 --> LCD
    PC9 --> LCD
```

> [!NOTE]
> Las conexiones de alimentación (**GND**, **3.3V**, **5V**) fueron omitidas de las líneas de este gráfico para no sobrecargarlo, pero recordá que TODOS los módulos y sensores comparten el mismo **GND**.
