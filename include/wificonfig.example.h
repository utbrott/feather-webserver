#ifndef WIFICONFIG_H
#define WIFICONFIG_H

/**
 * @brief WiFi network name (SSID)
 * @note Used to connect to a WiFi network
 */
#define WIFI_SSID "YOUR_NETWORK_NAME"
/**
 * @brief WiFi network password
 * @note Used to connect to a WiFi network.
 */
#define WIFI_PASS "YOUR_NETWORK_PASS"

/**
 * @brief Hardware pinout for WiFi expansion board
 * @note See: https://learn.adafruit.com/adafruit-feather-m0-wifi-atwinc1500
 */
#define WIFISHIELD_PINS 8, 7, 4, 2

#endif /* WIFICONFIG_H */