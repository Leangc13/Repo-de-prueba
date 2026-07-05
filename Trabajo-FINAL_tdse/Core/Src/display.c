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

/********************** inclusions *******************************************/
/* Project includes */
#include "main.h"

/* Application & Tasks includes */
#include "display.h"

/********************** macros and definitions *******************************/

/********************** internal data declaration ****************************/
extern I2C_HandleTypeDef hi2c1;

/********************** internal functions declaration ***********************/

/********************** internal data definition *****************************/

/********************** external data declaration ****************************/

/********************** external functions definition ************************/

void lcd_send_cmd(char cmd)
{
	char data_u, data_l;
	uint8_t data_t[4];
	
	/* PCF8574 mappings: D7 D6 D5 D4 BL EN RW RS */
	data_u = (cmd & 0xf0);
	data_l = ((cmd << 4) & 0xf0);
	
	/* Send upper nibble */
	data_t[0] = data_u | 0x0C;  /* en=1, rs=0, bl=1 */
	data_t[1] = data_u | 0x08;  /* en=0, rs=0, bl=1 */
	/* Send lower nibble */
	data_t[2] = data_l | 0x0C;  /* en=1, rs=0, bl=1 */
	data_t[3] = data_l | 0x08;  /* en=0, rs=0, bl=1 */
	
	HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, (uint8_t *)data_t, 4, 100);
}

void lcd_send_data(char data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	
	data_u = (data & 0xf0);
	data_l = ((data << 4) & 0xf0);
	
	/* Send upper nibble */
	data_t[0] = data_u | 0x0D;  /* en=1, rs=1, bl=1 */
	data_t[1] = data_u | 0x09;  /* en=0, rs=1, bl=1 */
	/* Send lower nibble */
	data_t[2] = data_l | 0x0D;  /* en=1, rs=1, bl=1 */
	data_t[3] = data_l | 0x09;  /* en=0, rs=1, bl=1 */
	
	HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, (uint8_t *)data_t, 4, 100);
}

void lcd_init(void)
{
	/* 4 bit initialisation */
	HAL_Delay(50);  /* wait for >40ms */
	lcd_send_cmd(0x30);
	HAL_Delay(5);   /* wait for >4.1ms */
	lcd_send_cmd(0x30);
	HAL_Delay(1);   /* wait for >100us */
	lcd_send_cmd(0x30);
	HAL_Delay(10);
	lcd_send_cmd(0x20);  /* 4bit mode */
	HAL_Delay(10);

	/* display initialisation */
	lcd_send_cmd(0x28); /* Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters) */
	HAL_Delay(1);
	lcd_send_cmd(0x08); /* Display on/off control --> D=0,C=0, B=0  ---> display off */
	HAL_Delay(1);
	lcd_send_cmd(0x01); /* clear display */
	HAL_Delay(1);
	HAL_Delay(1);
	lcd_send_cmd(0x06); /* Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift) */
	HAL_Delay(1);
	lcd_send_cmd(0x0C); /* Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits) */
}

void lcd_send_string(char *str)
{
	while (*str)
		lcd_send_data(*str++);
}

void lcd_set_cursor(int row, int col)
{
	/* Select Row and Column */
	switch (row)
	{
		case 0:
			col |= 0x80;
			break;
		case 1:
			col |= 0xC0;
			break;
	}
	lcd_send_cmd(col);
}

void lcd_clear(void)
{
	lcd_send_cmd(0x01); /* clear display */
	HAL_Delay(2);       /* Command takes a bit longer */
}

/********************** internal functions definition ************************/

/********************** end of file ******************************************/
