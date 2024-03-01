#include "chessboardwidget.h"
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <iostream>
//#include "simpleclient.h"
#include <QLineEdit>

ChessboardWidget::ChessboardWidget(QWidget *parent) : QWidget(parent)/*, client(new Client(this))*/ {

    QGridLayout *layout = new QGridLayout(this);

    layout->setSpacing(0); // Abstand Felader

    QStringList colors = {"#FFFFFF", "#808080"};

    QPixmap blackpawnPixmap(":/Figuren/black_pawn.svg");
    QPixmap blackrookPixmap(":/Figuren/black_rook.svg");
    QPixmap blackknightPixmap(":/Figuren/black_knight.svg");
    QPixmap blackbishopPixmap(":/Figuren/black_bishop.svg");
    QPixmap blackqueenPixmap(":/Figuren/black_queen.svg");
   // QPixmap blackkingPixmap(":/Figuren/black_king.svg");
    QPixmap whitepawnPixmap(":/Figuren/white_pawn.svg");
    QPixmap whiterookPixmap(":/Figuren/white_rook.svg");
    QPixmap whiteknightPixmap(":/Figuren/white_knight.svg");
    QPixmap whitebishopPixmap(":/Figuren/white_bishop.svg");
    QPixmap whitequeenPixmap(":/Figuren/white_queen.svg");
    QPixmap whitekingPixmap(":/Figuren/white_king.svg");

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            QPushButton *button = new QPushButton(this);
            button->setFixedSize(100, 100); // Größe der Felder
            button->setStyleSheet(QString("background-color: %1").arg(colors[(row + col) % 2]));

            layout->addWidget(button, row, col);

            QLabel *label = new QLabel(this);
            if ((row == 0 && col == 0) || (row == 0 && col == 7)){          // Startposition Turm Schwarz
                label->setPixmap(blackrookPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if((row == 0 && col == 1) || (row == 0 && col == 6)){     // Startposition Springer Schwarz
                label->setPixmap(blackknightPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if((row == 0 && col == 2) || (row == 0 && col == 5)){     // Startposition Läufer Schwarz
                label->setPixmap(blackbishopPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if(row == 0 && col == 3){                                 // Startposition Dame Schwarz
                label->setPixmap(blackqueenPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
           /* }else if(row == 0 && col == 4){                                 // Startposition Dame Schwarz
                label->setPixmap(blackkingPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);*/
            }else if(row == 1){                                             // Startposition Bauer Schwarz
                label->setPixmap(blackpawnPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if((row == 7 && col == 0) || (row == 7 && col == 7)){     // Startposition Turm Weiß
                label->setPixmap(whiterookPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if((row == 7 && col == 1) || (row == 7 && col == 6)){     // Startposition Springer Weiß
                label->setPixmap(whiteknightPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if((row == 7 && col == 2) || (row == 7 && col == 5)){     // Startposition Läufer Weiß
                label->setPixmap(whitebishopPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if(row == 7 && col == 3){                                 // Startposition Dame Weiß
                label->setPixmap(whitequeenPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
         //   }else if(row == 7 && col == 4){                                 // Startposition König Weiß
          //      label->setPixmap(blackkingPixmap);
           //     label->setAlignment(Qt::AlignCenter);
            //    layout->addWidget(label, row, col);
            }else if(row == 6){                                             // Startposition Bauer Weiß
                label->setPixmap(whitepawnPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }
            }
        }
    // Hier könntest du die Signale und Slots für die Buttons verbinden

    // Neustart-Button erstellen und hinzufügen
    QPushButton *restartButton = new QPushButton("Neustart", this);
    layout->addWidget(restartButton, 0, 8); // Zum Layout hinzufügen, Position (8, 0)

    connect(restartButton, &QPushButton::released, this, &ChessboardWidget::handleButton);

    // Aufgeben-Button erstellen und hinzufügen
    QPushButton *surrenderButton = new QPushButton("Aufgeben", this);
    layout->addWidget(surrenderButton, 0, 9); // Zum Layout hinzufügen, Position

    setMinimumSize(sizeHint());
    setMaximumSize(sizeHint());

}
void ChessboardWidget::handleButton(){
    std::cout << "Button gedrückt im widget" << std::endl;
   // client->Clientn--;
 //   client->setneustart();
    emit buttonpressed();
}

void ChessboardWidget::restartGame() {
    // Logik für Neustart des Spiels hier einfügen
}

void ChessboardWidget::surrenderGame() {
    // Logik für Aufgeben des Spiels hier einfügen
}
