/*
 * Tomato Clock (Pomodoro) for Betaflight
 * 25 minutes work / 5 minutes rest
 */

#include <stdint.h>
#include <stdbool.h>
#include "drivers/light_led.h"
#include "drivers/time.h"

#define WORK_TIME_SEC   (25 * 60)
#define REST_TIME_SEC   (5 * 60)

static uint32_t countdown = WORK_TIME_SEC;
static bool isWorking = true;
static uint32_t lastUpdate = 0;

void tomatoClockInit(void) {
    LED0_INIT();
    countdown = WORK_TIME_SEC;
    isWorking = true;
}

void tomatoClockLoop(void) {
    uint32_t currentTime = millis();
    
    if (currentTime - lastUpdate >= 1000) {
        lastUpdate = currentTime;
        
        if (countdown > 0) {
            countdown--;
            if (countdown % 2 == 0) {
                LED0_TOGGLE();
            }
        } else {
            isWorking = !isWorking;
            countdown = isWorking ? WORK_TIME_SEC : REST_TIME_SEC;
            #ifdef BEEPER
            BEEP_ON();
            delay(500);
            BEEP_OFF();
            #endif
        }
    }
}

bool isTomatoWorkMode(void) {
    return isWorking;
}

uint32_t getTomatoCountdown(void) {
    return countdown;
}
