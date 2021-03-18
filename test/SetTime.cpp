#include "SetTime.h"

#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include "DateTime_TC.h"
#include "Devices/LiquidCrystal_TC.h"
#include "TankControllerLib.h"

unittest(test) {
  LiquidCrystal_TC* lcd = LiquidCrystal_TC::instance();
  TankControllerLibTest tc;
  SetTime* test = new SetTime(&tc);
  tc.setNextState(test);

  DateTime_TC now = DateTime_TC::now();
  // the default time is the code compile time
  assertTrue(now.year() > 2020);

  // get currently displayed lines
  std::vector<String> lines = lcd->getLines();
  assertEqual("Year (YYYY):    ", lines.at(0));
  test->setValue(2020);
  lines = lcd->getLines();
  assertEqual("Month (1-12):   ", lines.at(0));
  test->setValue(03);
  lines = lcd->getLines();
  assertEqual("Day (1-31):     ", lines.at(0));
  test->setValue(18);
  lines = lcd->getLines();
  assertEqual("Hour (0-23):    ", lines.at(0));
  test->setValue(13);
  lines = lcd->getLines();
  assertEqual("Minute (0,59):  ", lines.at(0));
  test->setValue(15);

  // a year ago ensures that it preceeds the compile time
  now = DateTime_TC::now();
  char buffer[17];
  strcpy(buffer, "YYYY-MM-DD hh:mm");
  now.toString(buffer);
  assertEqual("2020-03-18 13:15", buffer);

  assertTrue(tc.isOnMainMenu());
}

unittest_main()