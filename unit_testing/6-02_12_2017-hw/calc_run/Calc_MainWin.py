# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Calc_MainWin.ui'
#
# Created: Thu Oct 26 14:34:56 2017
#      by: PyQt4 UI code generator 4.11.3
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.resize(572, 685)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.pushButton_k1 = QtGui.QPushButton(self.centralwidget)
        self.pushButton_k1.setGeometry(QtCore.QRect(10, 80, 130, 130))
        font = QtGui.QFont()
        font.setPointSize(26)
        self.pushButton_k1.setFont(font)
        self.pushButton_k1.setObjectName(_fromUtf8("pushButton_k1"))
        self.pushButton_k2 = QtGui.QPushButton(self.centralwidget)
        self.pushButton_k2.setGeometry(QtCore.QRect(150, 80, 130, 130))
        font = QtGui.QFont()
        font.setPointSize(26)
        self.pushButton_k2.setFont(font)
        self.pushButton_k2.setObjectName(_fromUtf8("pushButton_k2"))
        self.pushButton_k3 = QtGui.QPushButton(self.centralwidget)
        self.pushButton_k3.setGeometry(QtCore.QRect(290, 80, 130, 130))
        font = QtGui.QFont()
        font.setPointSize(26)
        self.pushButton_k3.setFont(font)
        self.pushButton_k3.setObjectName(_fromUtf8("pushButton_k3"))
        self.pushButton_div = QtGui.QPushButton(self.centralwidget)
        self.pushButton_div.setGeometry(QtCore.QRect(430, 80, 130, 130))
        font = QtGui.QFont()
        font.setPointSize(26)
        self.pushButton_div.setFont(font)
        self.pushButton_div.setObjectName(_fromUtf8("pushButton_div"))
        self.label_results = QtGui.QLabel(self.centralwidget)
        self.label_results.setGeometry(QtCore.QRect(10, 10, 551, 51))
        font = QtGui.QFont()
        font.setPointSize(24)
        self.label_results.setFont(font)
        self.label_results.setFrameShape(QtGui.QFrame.Panel)
        self.label_results.setFrameShadow(QtGui.QFrame.Sunken)
        self.label_results.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_results.setObjectName(_fromUtf8("label_results"))
        self.pushButton_k4 = QtGui.QPushButton(self.centralwidget)
        self.pushButton_k4.setGeometry(QtCore.QRect(10, 220, 130, 130))
        font = QtGui.QFont()
        font.setPointSize(26)
        self.pushButton_k4.setFont(font)
        self.pushButton_k4.setObjectName(_fromUtf8("pushButton_k4"))
        self.pushButton_k5 = QtGui.QPushButton(self.centralwidget)
        self.pushButton_k5.setGeometry(QtCore.QRect(150, 220, 130, 130))
        font = QtGui.QFont()
        font.setPointSize(26)
        self.pushButton_k5.setFont(font)
        self.pushButton_k5.setObjectName(_fromUtf8("pushButton_k5"))
        self.pushButton_k6 = QtGui.QPushButton(self.centralwidget)
        self.pushButton_k6.setGeometry(QtCore.QRect(290, 220, 130, 130))
        font = QtGui.QFont()
        font.setPointSize(26)
        self.pushButton_k6.setFont(font)
        self.pushButton_k6.setObjectName(_fromUtf8("pushButton_k6"))
        self.pushButton_mult = QtGui.QPushButton(self.centralwidget)
        self.pushButton_mult.setGeometry(QtCore.QRect(430, 220, 130, 130))
        font = QtGui.QFont()
        font.setPointSize(26)
        self.pushButton_mult.setFont(font)
        self.pushButton_mult.setObjectName(_fromUtf8("pushButton_mult"))
        self.pushButton_k7 = QtGui.QPushButton(self.centralwidget)
        self.pushButton_k7.setGeometry(QtCore.QRect(10, 360, 130, 130))
        font = QtGui.QFont()
        font.setPointSize(26)
        self.pushButton_k7.setFont(font)
        self.pushButton_k7.setObjectName(_fromUtf8("pushButton_k7"))
        self.pushButton_k8 = QtGui.QPushButton(self.centralwidget)
        self.pushButton_k8.setGeometry(QtCore.QRect(150, 360, 130, 130))
        font = QtGui.QFont()
        font.setPointSize(26)
        self.pushButton_k8.setFont(font)
        self.pushButton_k8.setObjectName(_fromUtf8("pushButton_k8"))
        self.pushButton_k9 = QtGui.QPushButton(self.centralwidget)
        self.pushButton_k9.setGeometry(QtCore.QRect(290, 360, 130, 130))
        font = QtGui.QFont()
        font.setPointSize(26)
        self.pushButton_k9.setFont(font)
        self.pushButton_k9.setObjectName(_fromUtf8("pushButton_k9"))
        self.pushButton_min = QtGui.QPushButton(self.centralwidget)
        self.pushButton_min.setGeometry(QtCore.QRect(430, 360, 130, 130))
        font = QtGui.QFont()
        font.setPointSize(26)
        self.pushButton_min.setFont(font)
        self.pushButton_min.setObjectName(_fromUtf8("pushButton_min"))
        self.pushButton_C = QtGui.QPushButton(self.centralwidget)
        self.pushButton_C.setGeometry(QtCore.QRect(10, 500, 130, 130))
        font = QtGui.QFont()
        font.setPointSize(26)
        self.pushButton_C.setFont(font)
        self.pushButton_C.setObjectName(_fromUtf8("pushButton_C"))
        self.pushButton_k0 = QtGui.QPushButton(self.centralwidget)
        self.pushButton_k0.setGeometry(QtCore.QRect(150, 500, 130, 130))
        font = QtGui.QFont()
        font.setPointSize(26)
        self.pushButton_k0.setFont(font)
        self.pushButton_k0.setObjectName(_fromUtf8("pushButton_k0"))
        self.pushButton_plus = QtGui.QPushButton(self.centralwidget)
        self.pushButton_plus.setGeometry(QtCore.QRect(290, 500, 130, 130))
        font = QtGui.QFont()
        font.setPointSize(26)
        self.pushButton_plus.setFont(font)
        self.pushButton_plus.setObjectName(_fromUtf8("pushButton_plus"))
        self.pushButton_equal = QtGui.QPushButton(self.centralwidget)
        self.pushButton_equal.setGeometry(QtCore.QRect(430, 500, 130, 130))
        font = QtGui.QFont()
        font.setPointSize(26)
        self.pushButton_equal.setFont(font)
        self.pushButton_equal.setObjectName(_fromUtf8("pushButton_equal"))
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 572, 25))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow", None))
        self.pushButton_k1.setText(_translate("MainWindow", "1", None))
        self.pushButton_k2.setText(_translate("MainWindow", "2", None))
        self.pushButton_k3.setText(_translate("MainWindow", "3", None))
        self.pushButton_div.setText(_translate("MainWindow", "/", None))
        self.label_results.setText(_translate("MainWindow", "0", None))
        self.pushButton_k4.setText(_translate("MainWindow", "4", None))
        self.pushButton_k5.setText(_translate("MainWindow", "5", None))
        self.pushButton_k6.setText(_translate("MainWindow", "6", None))
        self.pushButton_mult.setText(_translate("MainWindow", "x", None))
        self.pushButton_k7.setText(_translate("MainWindow", "7", None))
        self.pushButton_k8.setText(_translate("MainWindow", "8", None))
        self.pushButton_k9.setText(_translate("MainWindow", "9", None))
        self.pushButton_min.setText(_translate("MainWindow", "-", None))
        self.pushButton_C.setText(_translate("MainWindow", "C", None))
        self.pushButton_k0.setText(_translate("MainWindow", "0", None))
        self.pushButton_plus.setText(_translate("MainWindow", "+", None))
        self.pushButton_equal.setText(_translate("MainWindow", "=", None))

