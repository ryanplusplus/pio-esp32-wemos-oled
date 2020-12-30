#include <Arduino.h>
#include <Adafruit_SSD1306.h>

extern "C" {
#include <stddef.h>
#include "tiny_timer.h"
#include "tiny_time_source.h"
#include "tiny_heartbeat.h"
}

static tiny_timer_group_t timer_group;

static Adafruit_SSD1306 display = Adafruit_SSD1306(64, 48, &Wire);

void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.display();

  tiny_timer_group_init(&timer_group, tiny_time_source_init());
  tiny_heartbeat_init(&timer_group, 1000);
}

void loop()
{
  tiny_timer_group_run(&timer_group);
}
