# Mvb4Qt - A Lightweight Multi-functional Vehicle Bus Library
`MVB` `Qt` `Communication`
![logo](https://github.com/vehicle-net/mvb4qt/blob/master/logo.png)
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

```c++
// get the mvb manager
QMvbCardManager *manager = QMvbCardManager::getManager();
// add a new mvb card
QMvbCard *card = manager->addMvbCard("random", new QRandomMvbDriver(), new QLittleEndianProtocol());

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

card->setDebugMode(true); // set the debug mode
card->setInterval(2048);  // set the refresh interval
card->start();  // start the mvb card
```

## How to get the signal?

```c++
double vehicleSpeed = card->getQuint16(0x01, 0) * 0.1;
bool doorOpen = card->getBool(0x02, 2, 1);
bool doorClose = card->getBool(0x03, 4, 7);
quint32 mileage = card->getQuint32(0x03, 28);
```

## Feedback

