#include "NumberCollectorState.h"

#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include <iostream>

unittest(ADigit_NoDecimal) {
  TestNumCollectorState testNoDecimal;
  testNoDecimal.setExpectedDigits(3);
  assertEqual(0, testNoDecimal.getValue());
  testNoDecimal.handleKey('1');
  testNoDecimal.handleKey('2');
  testNoDecimal.handleKey('3');
  assertEqual(123, testNoDecimal.getValue());
  assertEqual(123, testNoDecimal.getStoredValue());
}

unittest(ADigit_WithDecimal) {
  TestNumCollectorState testDecimal;
  testDecimal.setExpectedDigits(4);
  testDecimal.handleKey('1');
  testDecimal.handleKey('2');
  testDecimal.handleKey('*');
  testDecimal.handleKey('3');
  testDecimal.handleKey('4');
  assertEqual(12.34, testDecimal.getValue());
  assertEqual(12.34, testDecimal.getStoredValue());
}

unittest(ADigit_MultipleDecimals) {
  TestNumCollectorState testDecimal;
  testDecimal.setExpectedDigits(4);
  testDecimal.handleKey('1');
  testDecimal.handleKey('2');
  testDecimal.handleKey('*');
  testDecimal.handleKey('*');
  testDecimal.handleKey('3');
  testDecimal.handleKey('*');
  testDecimal.handleKey('4');
  assertEqual(12.34, testDecimal.getValue());
  assertEqual(12.34, testDecimal.getStoredValue());
}

unittest(backSpace) {
  TestNumCollectorState testNoDecimal;
  testNoDecimal.handleKey('1');
  testNoDecimal.handleKey('2');
  testNoDecimal.handleKey('B');
  assertEqual(1, testNoDecimal.getValue());

  TestNumCollectorState testDecimal;
  testDecimal.handleKey('1');
  testDecimal.handleKey('*');
  testDecimal.handleKey('2');
  testDecimal.handleKey('3');
  testDecimal.handleKey('B');
  assertEqual(1.2, testDecimal.getValue());
}

unittest(clear) {
  TestNumCollectorState testDecimal;
  testDecimal.handleKey('1');
  testDecimal.handleKey('2');
  testDecimal.handleKey('C');
  assertEqual(0, testDecimal.getValue());
}

unittest(AllDone) {
  TestNumCollectorState testDecimal;
  testDecimal.setExpectedDigits(4);
  testDecimal.handleKey('1');
  testDecimal.handleKey('2');
  testDecimal.handleKey('3');
  assertEqual(0, testDecimal.getStoredValue());
  testDecimal.handleKey('A');
  assertEqual(123, testDecimal.getStoredValue());
}

unittest(printing) {
}

unittest_main()
