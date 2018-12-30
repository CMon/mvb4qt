# Mvb4Qt
A lightweight **library** for **multi-functional vehicle bus**.
![logo](./logo.png)
## Introduction
**Mvb4Qt** is a lightweight library for multi-functional vehicle bus, which can help users to quickly realize MVB communication development under the Qt framework. This library is highly efficient and stable, and can be used for laboratory test as well as for production environment.
## Features
* Non-blocking MVB communication
* Multi-threaded communication management
* Multi-card integrated management
* Communication protocol configuration
* Support customized driver
* Support customized protocol
* Support Qt4 and Qt5
## How to build?
If you have Qt Creator installed in your environment, open the project via src/mvb4qt.pro file. If you can only build from the command line, follow the instructions below. After the build is successful, please copy the compiled library file(.a or .lib) and all the header files to the corresponding location in your environment.
```console
$ cd src
$ qmake
$ make
```
## How to use?
Add `LIBS += -lMvb4Qt` to the .pro file, then use the library as follows:

![flow](./docs/flow.png)
1. Add a MVB card using the method `addCard()` of the `QMvbCardManager` class. Because `QMvbCardManager` is a singleton, users don't need to instantiate it. Instead, using the static method `getManager()` of `QMvbCardManager` to get a pointer of it, and also users don't need to consider its memory release.
```c++
QMvbCardManager *manager = QMvbCardManager::getManager();
QMvbCard *card = manager->addMvbCard("random", new QRandomMvbDriver(), new QLittleEndianProtocol());
```
2. Configure the basic parameters of the MVB card, such as the device address, the type of physical layer and the cache size. Each parameter has a default value,It is unnecessary to set them if there is no special requirement.
```c++
card->getMvbRegister()->setDeviceId(0x01);
card->getMvbRegister()->setPhyMode(Mvb4Qt::MvbEmdMode);
card->getMvbRegister()->setBufferSize(Mvb4Qt::MaxMvbBuffer);
```
3. Source port and sink ports can be added by the method `addSourcePort()` and `addSinkPort()`. Both methods have four parameters, namely port address, port size, feature cycle and group name. If there are so many ports defined in your project, it is necessary to group by name and search by name. After the ports are added, the initial value will be set to 0 whether it is source port or sink port. If there are special needs, they can be set to other value you want.
```c++
// add sink ports
card->getMvbRegister()->addSinkPort(0x01, 8, 128, "acu");
card->getMvbRegister()->addSinkPort(0x02, 16, 256, "tcu");
card->getMvbRegister()->addSinkPort(0x03, 32, 512, "bcu");

// add source ports
card->getMvbRegister()->addSourcePort(0x11, 32, 128, "hmi");
card->getMvbRegister()->addSourcePort(0x012, 32, 256, "hmi");
card->getMvbRegister()->addSourcePort(0x013, 32, 512, "hmi");

// set the initial value
card->setQuint8(0x11, 0, 0xFF);
card->setQuint8(0x12, 14, 0xFE);
card->setQuint8(0x13, 31, 0xEE);
```
---
4. After setting the MVB parameters, users need to call the method `configure()` of `QMvbCard`, which will write all the configuration information to the real card. It should be noted that it must be done when the card is stopped.
```c++
card->configure();
```
5. After configuring the card, start the card with the method `start()` of `QMvbCard`. The data of ports would by refreshed every 50 milliseconds. If users require specified refresh time, it can be set by the method `setInterval()` of `QMvbCard`, and also it must be done when the card is stopped.
```c++
card->setInterval(2048);
card->start();
```
6. This library provides a variety of signal acquisition methods, which are convenient for users to get signal type of bool, int and uint.
```c++
bool doorOpen = card->getBool(0x02, 2, 1);
bool doorClose = card->getBool(0x03, 4, 7);
qint16 vehicleSpeed = card->getQint16(0x01, 0);
quint32 mileage = card->getQuint32(0x03, 28);
```
Here is only description of the basic use of the library, if you involves more in-depth use and specific implementation methods, please check the help documentation.
## Getting Help
If you have questions, you can reach out to our mailing: deng_ran@foxmail.com

Or you can submit questions directly through the `issues` of this project.
