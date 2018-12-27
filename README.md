# Mvb4Qt
![logo](./logo.png)
## Introduction
**Mvb4Qt** is a lightweight multi-functional vehicle bus Library based on Qt, which can help users to quickly realize MVB communication development under Qt framework. The library is highly efficient and stable, and can be used for laboratory test development as well as for practical industrial sites.
## Features
* Non-blocking MVB communication
* Multi-thread communication management
* Multi-card integrated management
* Communication protocol configuration
* Support for custom card drivers
* Support custom card communication protocol
* Support virtual communication test
## How to build?
```console
$ qmake
$ make
$ make install
```
## How to use?
### Developers can use the library as follows:
![flow](./docs/flow.png)
1. Add a MVB card using the method `addCard()` of the `QMvbCardManager` class. Because `QMvbCardManager` is a singleton, developers don't not need to instantiate it. Instead, using the static method `getManager()` of `QMvbCardManager` to get a pointer of itself, and also developers don't need to consider its memory release.
```c++
  QMvbCardManager *manager = QMvbCardManager::getManager();
  QMvbCard *card = manager->addMvbCard("random", new QRandomMvbDriver(), new QLittleEndianProtocol());
```
---
2. Configure the basic parameters of the MVB card, such as the device address, physical layer, and cache size. Each parameter has a default value, Developers don't need to set them if there is no special requirement.
```c++
  card->getMvbRegister()->setDeviceId(0x01);
  card->getMvbRegister()->setPhyMode(Mvb4Qt::MvbEmdMode);
```
---
3. Sources port and sink ports can be added by the method `addSourcePort()` and the method `addSinkPort()`. Both methods have four parameters, namely port address, port size, feature period and grouping name. If there are so many ports defined in your project, it is necessary to group by name and search by name. After the ports are added, the initial value will be set to 0 whether it is source port or sink port. If there are special needs, they can be set to other values you want.
```c++
// add sink ports
card->getMvbRegister()->addSinkPort(0x01, 8, 128, "acu");
card->getMvbRegister()->addSinkPort(0x02, 16, 256, "tcu");
card->getMvbRegister()->addSinkPort(0x03, 32, 512, "bcu");

// add source ports
card->getMvbRegister()->addSourcePort(0x11, 32, 128, "hmi");
card->getMvbRegister()->addSourcePort(0x012, 32, 256, "hmi");
card->getMvbRegister()->addSourcePort(0x013, 32, 512, "hmi");


// set the initial value of source port before start the mvb card
card->setQuint8(0x11, 0, 0xFF);
card->setQuint8(0x12, 14, 0xFE);
card->setQuint8(0x13, 31, 0xEE);
```
---
5. After setting the MVB parameters, users need to call the method `configure()` of `QMvbCard`, which will write all the configuration information to the real card. It should be noted that it must be called when the card is stopped.
```c++
  card->configure();
```
---
6. After configuring the card, start the card with the method `start()` of `QMvbCard`. The mvb card is refreshed every 50 milliseconds. If users require specified refresh time, it can be set by the `setInterval()` method of `QMvbCard`.
```c++
  card->setInterval(2048);  // set the refresh interval
  card->start();  // start the mvb card
```
---
7. The library provides a variety of signal acquisition methods, which are convenient for users to get signal of bool, int and uint.
```c++
  double vehicleSpeed = card->getQuint16(0x01, 0) * 0.1;
  bool doorOpen = card->getBool(0x02, 2, 1);
  bool doorClose = card->getBool(0x03, 4, 7);
  quint32 mileage = card->getQuint32(0x03, 28);
```
---
## Feedback
