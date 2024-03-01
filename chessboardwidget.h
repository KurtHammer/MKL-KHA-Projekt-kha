#ifndef CHESSBOARDWIDGET_H
#define CHESSBOARDWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QGridLayout>
#include <QPushButton>

class ChessboardWidget : public QWidget {
    Q_OBJECT
public:
    explicit ChessboardWidget(QWidget *parent = nullptr);
    void addPiece(const QPixmap &pixmap, QGridLayout *layout, int row, int col);

private slots:
    void restartGame();
    void surrenderGame();
    void handleButton();
private:
    QPushButton *restartButton;
    ChessboardWidget *m_chessboardwidget;
signals:
    void buttonpressed();
};

#endif // CHESSBOARDWIDGET_H
