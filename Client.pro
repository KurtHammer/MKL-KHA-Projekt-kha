QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    figur.cpp \
    main.cpp\
    chessboardwidget.cpp\
    simpleclient.cpp \
    spiel.cpp \
    utilities.cpp

HEADERS += \
    board.h \
    chessboardwidget.h\
    figur.h \
    simpleclient.h \
    spiel.h \
    utilities.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

DISTFILES += \
    ../chess/Figuren/black_bishop.svg \
    ../chess/Figuren/black_king.svg \
    ../chess/Figuren/black_knight.svg \
    ../chess/Figuren/black_pawn.svg \
    ../chess/Figuren/black_queen.svg \
    ../chess/Figuren/black_rook.svg \
    ../chess/Figuren/white_bishop.svg \
    ../chess/Figuren/white_king.svg \
    ../chess/Figuren/white_knight.svg \
    ../chess/Figuren/white_pawn.svg \
    ../chess/Figuren/white_queen.svg \
    ../chess/Figuren/white_rook.svg
