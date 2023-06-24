QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    campfire.cpp \
    cardbutton.cpp \
    cardwidget.cpp \
    combatroom.cpp \
    creaturewidget.cpp \
    game/cards/AbstractCard.cpp \
    game/cards/CardGroup.cpp \
    game/cards/DamageInfo.cpp \
    game/cards/red/Strike_Red.cpp \
    game/characters/AbstractPlayer.cpp \
    game/characters/Ironclad.cpp \
    game/core/AbstractCreature.cpp \
    game/dungeon/Dungeon.cpp \
    game/monsters/AbstractMonster.cpp \
    game/monsters/EnemyMoveInfo.cpp \
    game/monsters/MonsterGroup.cpp \
    game/monsters/SpireShield.cpp \
    game/rooms/AbstractRoom.cpp \
    game/rooms/CampfireRoom.cpp \
    game/rooms/EliteRoom.cpp \
    game/rooms/ShopRoom.cpp \
    getcard.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    mapwidget.cpp \
    menu.cpp \
    shop.cpp \
    statebar.cpp \
    usecard.cpp

HEADERS += \
    campfire.h \
    cardbutton.h \
    cardwidget.h \
    combatroom.h \
    creaturewidget.h \
    game/cards/AbstractCard.h \
    game/cards/CardGroup.h \
    game/cards/DamageInfo.h \
    game/cards/red/Strike_Red.h \
    game/characters/AbstractPlayer.h \
    game/characters/Ironclad.h \
    game/core/AbstractCreature.h \
    game/dungeon/Dungeon.h \
    game/monsters/AbstractMonster.h \
    game/monsters/EnemyMoveInfo.h \
    game/monsters/MonsterGroup.h \
    game/monsters/SpireShield.h \
    game/rooms/AbstractRoom.h \
    game/rooms/CampfireRoom.h \
    game/rooms/EliteRoom.h \
    game/rooms/ShopRoom.h \
    getcard.h \
    mainwindow.h \
    map.h \
    mapwidget.h \
    menu.h \
    shop.h \
    statebar.h \
    usecard.h

FORMS += \
    campfire.ui \
    cardwidget.ui \
    combatroom.ui \
    creaturewidget.ui \
    getcard.ui \
    mainwindow.ui \
    mapwidget.ui \
    menu.ui \
    shop.ui \
    statebar.ui \
    usecard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
