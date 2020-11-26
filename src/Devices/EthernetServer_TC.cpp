#include "Devices/EthernetServer_TC.h"

//  class variables
EthernetServer_TC* EthernetServer_TC::_instance = nullptr;

//  class methods
/**
 * accessor for singleton
 */
EthernetServer_TC* EthernetServer_TC::instance() {
  if (!_instance) {
    _instance = new EthernetServer_TC(80);
  }
  return _instance;
}

//  instance methods
EthernetServer_TC::EthernetServer_TC(uint16_t port) : EthernetServer(port) {
  begin();
  Serial.print(F("Ethernet Server is listening on port 80 of ??????"));
  //   Need Mock board for .localIP to work
  //   Serial.println(Ethernet.localIP());
}

void EthernetServer_TC::handleRequest() {
  // listen for incoming clients
  EthernetClient rpc_client = available();  // Raspberry Pi Client
  if (rpc_client) {
    // NEED TO IMPLIMENT
    // HandleRequest(rpc_client);

    // give the web browser time to receive the data
    // delay(ONE_SECOND_DELAY_IN_MILLIS);
    // close the connection:
    rpc_client.stop();
    Serial.println(F("rpc_client disconnected"));
  }
}