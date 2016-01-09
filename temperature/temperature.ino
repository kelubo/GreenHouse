#include <OneWire.h>
#include <DallasTemperature.h>
     
#define ONE_WIRE_BUS 2    //定义单总线连接的端口
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
     
void setup(void)
  {
    Serial.begin(9600);
    Serial.println("Dallas Temperature IC Control Library Demo");
    sensors.begin();    //启动单总线
  }
     
void loop(void)
  {
    Serial.print("Requesting temperatures...");
    sensors.requestTemperatures();    //发送温度测量请求命令
    Serial.println("DONE");
     
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.print(sensors.getTempCByIndex(0));    //获取0号传感器温度数据并发送
    Serial.println("C");
    delay(1000);   //一秒刷新一次
    Serial.print("Temperature for the device 2 (index 0) is: ");
    Serial.print(sensors.getTempCByIndex(1));    //获取1号传感器温度数据并发送
    Serial.println("C");
    delay(1000);   //一秒刷新一次
  }
