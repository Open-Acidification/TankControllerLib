/**
 * SetPHSetPoint.cpp
 */

#include "SetPHSetPoint.h"

void SetPHSetPoint::handleKey(char key) {
  switch (key) {
    case 'D':  // Don't save (cancel)
      returnToMainMenu();
      break;
    default:
      break;
  };
}