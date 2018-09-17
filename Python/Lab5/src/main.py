import sys
from PyQt5.QtWidgets import QMainWindow, QApplication, QWidget, QAction, QTableWidget, QTableWidgetItem, QVBoxLayout, \
    QLineEdit, QPushButton, QGridLayout, QGroupBox, QTextEdit, QLabel, QAbstractItemView
from PyQt5.QtGui import QIcon, QColor
from PyQt5.QtCore import pyqtSlot, Qt


class App(QWidget):
    def __init__(self):
        super().__init__()
        self.title = 'Hello world'
        self.left = 10
        self.top = 10
        self.width = 640
        self.height = 480
        self.goods = []

        self.readGoods()
        self.initUI()
        self.resetFields()
        self.addToOrderBtn.setDisabled(True)
        self.backBtn.setVisible(False)
        self.successLabel.setVisible(False)

    def readGoods(self):
        with open("src/input.txt", "r") as f:
            n = int(f.readline())
            for i in range(n):
                title = f.readline().strip()
                description = f.readline().strip()
                cost = int(f.readline())
                self.goods.append({
                    "title": title,
                    "description": description,
                    "cost": cost
                })

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)

        self.createGridLayout()
        self.setLayout(self.gridLayout)

        self.show()

    def createGridLayout(self):
        self.gridLayout = QGridLayout()
        self.gridLayout.setSpacing(10)

        self.createTable()

        self.descriptionTextLabel = QLabel("Описание товара")
        self.descriptionText = QLineEdit()

        self.orderInfoLabel = QLabel("Информация о заказе")
        self.orderInfo = QTextEdit()

        self.totalCostLabel = QLabel("Стоимость заказа")
        self.totalCost = QLineEdit()

        self.successLabel = QLabel("Заказ успешно оформлен")

        self.addToOrderBtn = QPushButton("Добавить")
        self.newOrderBtn = QPushButton("Новый заказ")
        self.saveOrderBtn = QPushButton("Сохранить заказ")
        self.backBtn = QPushButton("Назад")
        self.addToOrderBtn.clicked.connect(self.onAddToOrderBtnClick)
        self.newOrderBtn.clicked.connect(self.resetFields)
        self.saveOrderBtn.clicked.connect(self.onSaveOrderBtnClick)
        self.backBtn.clicked.connect(self.onBackBtnClick)

        self.gridLayout.addWidget(self.orderInfoLabel, 1, 0)
        self.gridLayout.addWidget(self.orderInfo, 2, 0, 1, 1)
        self.gridLayout.addWidget(self.tableWidget, 2, 1, 1, 2)
        self.gridLayout.addWidget(self.descriptionTextLabel, 3, 1, 1, 2)
        self.gridLayout.addWidget(self.descriptionText, 4, 1, 1, 2)
        self.gridLayout.addWidget(self.totalCostLabel, 3, 0)
        self.gridLayout.addWidget(self.totalCost, 4, 0, 1, 1)
        self.gridLayout.addWidget(self.addToOrderBtn, 5, 0)
        self.gridLayout.addWidget(self.newOrderBtn, 5, 1)
        self.gridLayout.addWidget(self.saveOrderBtn, 5, 2)
        self.gridLayout.addWidget(self.backBtn, 6, 0)
        self.gridLayout.addWidget(self.successLabel, 6, 1)

    def onAddToOrderBtnClick(self):
        self.orderInfo.append(self.goods[self.tableWidget.currentRow()]["title"] + " " + str(self.goods[self.tableWidget.currentRow()]["cost"]))
        self.totalCost.setText(str(int(self.totalCost.text()) + self.goods[self.tableWidget.currentRow()]["cost"]))

    def onSaveOrderBtnClick(self):
        with open("src/output.txt", "w") as f:
            f.writelines(self.orderInfo.toPlainText())

        self.backBtn.setVisible(True)
        self.successLabel.setVisible(True)

    def onBackBtnClick(self):
        self.resetFields()
        self.backBtn.setVisible(False)
        self.successLabel.setVisible(False)

    def createTable(self):
        self.tableWidget = QTableWidget()
        self.tableWidget.setRowCount(len(self.goods))
        self.tableWidget.setColumnCount(2)
        self.tableWidget.setSelectionBehavior(QAbstractItemView.SelectRows)
        self.tableWidget.setHorizontalHeaderLabels(["Товар", "Цена"])

        for i in range(len(self.goods)):
            self.tableWidget.setItem(i, 0, QTableWidgetItem(self.goods[i]["title"]))
            self.tableWidget.setItem(i, 1, QTableWidgetItem(str(self.goods[i]["cost"])))
            self.tableWidget.item(i, 0).setBackground(QColor(220, 220, 220) if i % 2 == 0 else QColor(255, 255, 255))
            self.tableWidget.item(i, 1).setBackground(QColor(220, 220, 220) if i % 2 == 0 else QColor(255, 255, 255))

        self.tableWidget.clicked.connect(self.on_click)

    def resetFields(self):
        self.orderInfo.setText("")
        self.totalCost.setText("0")

    @pyqtSlot()
    def on_click(self):
        self.addToOrderBtn.setDisabled(False)
        for currentQTableWidgetItem in self.tableWidget.selectedItems():
            self.descriptionText.setText(self.goods[currentQTableWidgetItem.row()]["description"])


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())
