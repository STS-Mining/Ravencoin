// Copyright (c) 2011-2016 The Bitcoin Core developers
// Copyright (c) 2017-2021 The Raven Core developers
// Copyright (c) 2024-2025 The Memeium Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MEMEIUM_QT_UTILITYDIALOG_H
#define MEMEIUM_QT_UTILITYDIALOG_H

#include <QDialog>
#include <QObject>

class MemeiumGUI;

namespace Ui
{
class HelpMessageDialog;
}

/** "Help message" dialog box */
class HelpMessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HelpMessageDialog(QWidget* parent, bool about);
    ~HelpMessageDialog();

    void printToConsole();
    void showOrPrint();

private:
    Ui::HelpMessageDialog* ui;
    QString text;

private Q_SLOTS:
    void on_okButton_accepted();
};


/** "Shutdown" window */
class ShutdownWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ShutdownWindow(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::Widget);
    static QWidget* showShutdownWindow(MemeiumGUI* window);

protected:
    void closeEvent(QCloseEvent* event);
};


#endif // MEMEIUM_QT_UTILITYDIALOG_H
