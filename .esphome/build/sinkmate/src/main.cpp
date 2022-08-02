// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
using namespace switch_;
logger::Logger *logger_logger;
web_server_base::WebServerBase *web_server_base_webserverbase;
captive_portal::CaptivePortal *captive_portal_captiveportal;
wifi::WiFiComponent *wifi_wificomponent;
mdns::MDNSComponent *mdns_mdnscomponent;
ota::OTAComponent *ota_otacomponent;
api::APIServer *api_apiserver;
using namespace api;
using namespace sensor;
preferences::IntervalSyncer *preferences_intervalsyncer;
gpio::GPIOSwitch *gpio_gpioswitch;
esphome::esp8266::ESP8266GPIOPin *esphome_esp8266_esp8266gpiopin;
adc::ADCSensor *adc_adcsensor;
esphome::esp8266::ESP8266GPIOPin *esphome_esp8266_esp8266gpiopin_2;
const uint8_t ESPHOME_ESP8266_GPIO_INITIAL_MODE[16] = {255, 255, OUTPUT, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
const uint8_t ESPHOME_ESP8266_GPIO_INITIAL_LEVEL[16] = {255, 255, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
#define yield() esphome::yield()
#define millis() esphome::millis()
#define micros() esphome::micros()
#define delay(x) esphome::delay(x)
#define delayMicroseconds(x) esphome::delayMicroseconds(x)
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ========== AUTO GENERATED CODE BEGIN ===========
  // esp8266:
  //   board: nodemcuv2
  //   framework:
  //     version: 3.0.2
  //     source: ~3.30002.0
  //     platform_version: platformio/espressif8266 @ 3.2.0
  //   restore_from_flash: false
  //   early_pin_init: true
  //   board_flash_mode: dout
  esphome::esp8266::setup_preferences();
  // async_tcp:
  //   {}
  // esphome:
  //   name: sinkmate
  //   build_path: .esphome/build/sinkmate
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   name_add_mac_suffix: false
  App.pre_setup("sinkmate", __DATE__ ", " __TIME__, false);
  // switch:
  // logger:
  //   id: logger_logger
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   deassert_rts_dtr: false
  //   hardware_uart: UART0
  //   level: DEBUG
  //   logs: {}
  //   esp8266_store_log_strings_in_flash: true
  logger_logger = new logger::Logger(115200, 512, logger::UART_SELECTION_UART0);
  logger_logger->pre_setup();
  logger_logger->set_component_source("logger");
  App.register_component(logger_logger);
  // web_server_base:
  //   id: web_server_base_webserverbase
  web_server_base_webserverbase = new web_server_base::WebServerBase();
  web_server_base_webserverbase->set_component_source("web_server_base");
  App.register_component(web_server_base_webserverbase);
  // captive_portal:
  //   id: captive_portal_captiveportal
  //   web_server_base_id: web_server_base_webserverbase
  captive_portal_captiveportal = new captive_portal::CaptivePortal(web_server_base_webserverbase);
  captive_portal_captiveportal->set_component_source("captive_portal");
  App.register_component(captive_portal_captiveportal);
  // wifi:
  //   ap:
  //     ssid: Sinkmate Fallback Hotspot
  //     password: ks0R9p1oTwJk
  //     id: wifi_wifiap
  //     ap_timeout: 1min
  //   id: wifi_wificomponent
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: NONE
  //   fast_connect: false
  //   output_power: 20.0
  //   networks:
  //   - ssid: Starlink_legacy
  //     password: fredfontaine
  //     id: wifi_wifiap_2
  //     priority: 0.0
  //   use_address: sinkmate.local
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("sinkmate.local");
  wifi::WiFiAP wifi_wifiap_2 = wifi::WiFiAP();
  wifi_wifiap_2.set_ssid("Starlink_legacy");
  wifi_wifiap_2.set_password("fredfontaine");
  wifi_wifiap_2.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap_2);
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid("Sinkmate Fallback Hotspot");
  wifi_wifiap.set_password("ks0R9p1oTwJk");
  wifi_wificomponent->set_ap(wifi_wifiap);
  wifi_wificomponent->set_ap_timeout(60000);
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_NONE);
  wifi_wificomponent->set_fast_connect(false);
  wifi_wificomponent->set_output_power(20.0f);
  wifi_wificomponent->set_component_source("wifi");
  App.register_component(wifi_wificomponent);
  // mdns:
  //   id: mdns_mdnscomponent
  //   disabled: false
  mdns_mdnscomponent = new mdns::MDNSComponent();
  mdns_mdnscomponent->set_component_source("mdns");
  App.register_component(mdns_mdnscomponent);
  // ota:
  //   password: sinkmate
  //   id: ota_otacomponent
  //   safe_mode: true
  //   port: 8266
  //   reboot_timeout: 5min
  //   num_attempts: 10
  ota_otacomponent = new ota::OTAComponent();
  ota_otacomponent->set_port(8266);
  ota_otacomponent->set_auth_password("sinkmate");
  ota_otacomponent->set_component_source("ota");
  App.register_component(ota_otacomponent);
  if (ota_otacomponent->should_enter_safe_mode(10, 300000)) return;
  // api:
  //   password: sinkmate
  //   id: api_apiserver
  //   port: 6053
  //   reboot_timeout: 15min
  api_apiserver = new api::APIServer();
  api_apiserver->set_component_source("api");
  App.register_component(api_apiserver);
  api_apiserver->set_port(6053);
  api_apiserver->set_password("sinkmate");
  api_apiserver->set_reboot_timeout(900000);
  // sensor:
  // preferences:
  //   id: preferences_intervalsyncer
  //   flash_write_interval: 60s
  preferences_intervalsyncer = new preferences::IntervalSyncer();
  preferences_intervalsyncer->set_write_interval(60000);
  preferences_intervalsyncer->set_component_source("preferences");
  App.register_component(preferences_intervalsyncer);
  // switch.gpio:
  //   platform: gpio
  //   pin:
  //     number: 2
  //     mode:
  //       output: true
  //       analog: false
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     id: esphome_esp8266_esp8266gpiopin
  //     inverted: false
  //   name: LED
  //   inverted: true
  //   disabled_by_default: false
  //   id: gpio_gpioswitch
  //   restore_mode: RESTORE_DEFAULT_OFF
  //   interlock_wait_time: 0ms
  gpio_gpioswitch = new gpio::GPIOSwitch();
  gpio_gpioswitch->set_component_source("gpio.switch");
  App.register_component(gpio_gpioswitch);
  App.register_switch(gpio_gpioswitch);
  gpio_gpioswitch->set_name("LED");
  gpio_gpioswitch->set_disabled_by_default(false);
  gpio_gpioswitch->set_inverted(true);
  esphome_esp8266_esp8266gpiopin = new esphome::esp8266::ESP8266GPIOPin();
  esphome_esp8266_esp8266gpiopin->set_pin(2);
  esphome_esp8266_esp8266gpiopin->set_inverted(false);
  esphome_esp8266_esp8266gpiopin->set_flags(gpio::Flags::FLAG_OUTPUT);
  gpio_gpioswitch->set_pin(esphome_esp8266_esp8266gpiopin);
  gpio_gpioswitch->set_restore_mode(gpio::GPIO_SWITCH_RESTORE_DEFAULT_OFF);
  // sensor.adc:
  //   platform: adc
  //   pin:
  //     number: 17
  //     mode:
  //       analog: true
  //       input: true
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     id: esphome_esp8266_esp8266gpiopin_2
  //     inverted: false
  //   name: Flow Sensor
  //   disabled_by_default: false
  //   force_update: false
  //   id: adc_adcsensor
  //   unit_of_measurement: V
  //   accuracy_decimals: 2
  //   device_class: voltage
  //   state_class: measurement
  //   raw: false
  //   update_interval: 60s
  adc_adcsensor = new adc::ADCSensor();
  adc_adcsensor->set_update_interval(60000);
  adc_adcsensor->set_component_source("adc.sensor");
  App.register_component(adc_adcsensor);
  App.register_sensor(adc_adcsensor);
  adc_adcsensor->set_name("Flow Sensor");
  adc_adcsensor->set_disabled_by_default(false);
  adc_adcsensor->set_device_class("voltage");
  adc_adcsensor->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  adc_adcsensor->set_unit_of_measurement("V");
  adc_adcsensor->set_accuracy_decimals(2);
  adc_adcsensor->set_force_update(false);
  esphome_esp8266_esp8266gpiopin_2 = new esphome::esp8266::ESP8266GPIOPin();
  esphome_esp8266_esp8266gpiopin_2->set_pin(17);
  esphome_esp8266_esp8266gpiopin_2->set_inverted(false);
  esphome_esp8266_esp8266gpiopin_2->set_flags(gpio::Flags::FLAG_INPUT);
  adc_adcsensor->set_pin(esphome_esp8266_esp8266gpiopin_2);
  adc_adcsensor->set_output_raw(false);
  // socket:
  //   implementation: lwip_tcp
  // network:
  //   {}
  // =========== AUTO GENERATED CODE END ============
  App.setup();
}

void loop() {
  App.loop();
}
