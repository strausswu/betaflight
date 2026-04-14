/*
 * Tomato Clock (Pomodoro) for Betaflight
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

void tomatoClockInit(void);
void tomatoClockLoop(void);
bool isTomatoWorkMode(void);
uint32_t getTomatoCountdown(void);
