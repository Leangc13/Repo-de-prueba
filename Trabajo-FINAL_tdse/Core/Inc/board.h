/*
 * Copyright (c) 2026 Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @author : Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>
 */

#ifndef BOARD_H_
#define BOARD_H_

/********************** CPP guard ********************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************** inclusions *******************************************/

/********************** macros ***********************************************/
#define NUCLEO_F103RB		(0)
#define BOARD (NUCLEO_F103RB)

/* SRAGV Board Definitions mapped to standard NUCLEO-F103RB */
#if (BOARD == NUCLEO_F103RB)

/* Inputs: Buttons (Active Low - internal pull-up assumed) */
#define BTN_UP_PIN			GPIO_PIN_0
#define BTN_UP_PORT			GPIOB
#define BTN_UP_PRESSED		GPIO_PIN_RESET
#define BTN_UP_HOVER		GPIO_PIN_SET

#define BTN_DOWN_PIN		GPIO_PIN_1
#define BTN_DOWN_PORT		GPIOB
#define BTN_DOWN_PRESSED	GPIO_PIN_RESET
#define BTN_DOWN_HOVER		GPIO_PIN_SET

#define BTN_ENTER_PIN		GPIO_PIN_2
#define BTN_ENTER_PORT		GPIOB
#define BTN_ENTER_PRESSED	GPIO_PIN_RESET
#define BTN_ENTER_HOVER		GPIO_PIN_SET

/* Inputs: DIP Switches */
#define DIP1_PIN			GPIO_PIN_0
#define DIP1_PORT			GPIOC
#define DIP2_PIN			GPIO_PIN_1
#define DIP2_PORT			GPIOC
#define DIP3_PIN			GPIO_PIN_2
#define DIP3_PORT			GPIOC
#define DIP4_PIN			GPIO_PIN_3
#define DIP4_PORT			GPIOC
#define DIP_ON				GPIO_PIN_RESET
#define DIP_OFF				GPIO_PIN_SET

/* Outputs: Status LEDs (Active High) */
#define LED_PWR_PIN			GPIO_PIN_5 /* PA5 is built-in LD2 */
#define LED_PWR_PORT		GPIOA
#define LED_RUN_PIN			GPIO_PIN_10
#define LED_RUN_PORT		GPIOB
#define LED_ALERTA_PIN		GPIO_PIN_11
#define LED_ALERTA_PORT		GPIOB
#define LED_ON				GPIO_PIN_SET
#define LED_OFF				GPIO_PIN_RESET

/* Outputs: Sector LEDs (Active High) */
#define SECT_N_PIN			GPIO_PIN_6
#define SECT_N_PORT			GPIOA
#define SECT_S_PIN			GPIO_PIN_7
#define SECT_S_PORT			GPIOA
#define SECT_E_PIN			GPIO_PIN_6
#define SECT_E_PORT			GPIOB
#define SECT_W_PIN			GPIO_PIN_7
#define SECT_W_PORT			GPIOB
#define SECT_ON				GPIO_PIN_SET
#define SECT_OFF			GPIO_PIN_RESET

/* Outputs: Buzzer (Active High) */
#define BUZZER_PIN			GPIO_PIN_12
#define BUZZER_PORT			GPIOB
#define BUZZER_ON			GPIO_PIN_SET
#define BUZZER_OFF			GPIO_PIN_RESET

/* ADC Channels for Wind and Light mapped */
/* PA0 (A0) -> ADC1_IN0 (Wind Speed) */
/* PA1 (A1) -> ADC1_IN1 (Wind Direction) */
/* PA4 (A2) -> ADC1_IN4 (Light Sensor) */

#endif

/********************** typedef **********************************************/

/********************** external data declaration ****************************/

/********************** external functions declaration ***********************/

/********************** End of CPP guard *************************************/
#ifdef __cplusplus
}
#endif

#endif /* BOARD_H_ */

/********************** end of file ******************************************/
